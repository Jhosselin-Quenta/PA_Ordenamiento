#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <algorithm>
#include <random>
#include <string>
using namespace std;

struct M {
    long long comp = 0, interc = 0;
    int prof = 0;
};

void shell(vector<int>& a, M& m) {
    for (int g = a.size()/2; g > 0; g /= 2)
        for (int i = g; i < a.size(); i++)
            for (int j = i; j >= g; j -= g) {
                m.comp++;
                if (a[j-g] <= a[j]) break;
                swap(a[j-g], a[j]);
                m.interc++;
            }
}

void quick(vector<int>& a, int l, int r, M& m, int d=1) {
    if (l >= r) return;
    m.prof = max(m.prof, d);
    int i=l, j=r, p=a[l+(r-l)/2];
    while (i <= j) {
        while (i <= r && (++m.comp, a[i] < p)) i++;
        while (j >= l && (++m.comp, a[j] > p)) j--;
        if (i <= j) {
            if (i < j) swap(a[i],a[j]), m.interc++;
            i++; j--;
        }
    }
    if (l < j) quick(a,l,j,m,d+1);
    if (i < r) quick(a,i,r,m,d+1);
}

int main() {
    const int semilla = 12345;
    mt19937 gen(semilla);
    ofstream f("results/comparacion.csv");
    if (!f) { cout << "Error al crear CSV\n"; return 1; }

    ifstream h("results/commit.txt");
    string hash = "pendiente";
    if (h) getline(h,hash);

    f << "metodo,n,patron,repeticion,ms,comparaciones,"
         "intercambios,profundidad,semilla,commit,ordenado\n";

    for (int n : {1000,10000,100000})
      for (string pat : {"aleatorio","ascendente","descendente"}) {
        vector<int> base(n);
        for (int i=0;i<n;i++) base[i]=i;
        if (pat=="aleatorio") shuffle(base.begin(),base.end(),gen);
        if (pat=="descendente") reverse(base.begin(),base.end());

        for (int rep=1;rep<=30;rep++)
          for (string alg : {"Shell","Quick"}) {
            vector<int> a=base;
            M m;
            auto ini=chrono::steady_clock::now();
            if (alg=="Shell") shell(a,m);
            else quick(a,0,n-1,m);
            double ms=chrono::duration<double,milli>(
                chrono::steady_clock::now()-ini).count();

            f << alg << "," << n << "," << pat << "," << rep
              << "," << ms << "," << m.comp << "," << m.interc
              << "," << m.prof << "," << semilla << "," << hash
              << "," << is_sorted(a.begin(),a.end()) << "\n";
          }
        cout << "Terminado: " << n << " " << pat << "\n";
      }
    cout << "Resultados guardados en results/comparacion.csv\n";
}
