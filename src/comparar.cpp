#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;

void shell(vector<int>& a) {
    int n = a.size();
    for (int s=n/2; s>0; s/=2)
        for (int i=s; i<n; i++) {
            int x=a[i], j=i;
            while (j>=s && a[j-s]>x)
                a[j]=a[j-s], j-=s;
            a[j]=x;
        }
}

void quick(vector<int>& a, int l, int r) {
    if (l>=r) return;
    int p=a[r], i=l-1;
    for (int j=l; j<r; j++)
        if (a[j]<p) swap(a[++i],a[j]);
    swap(a[i+1],a[r]);
    quick(a,l,i);
    quick(a,i+2,r);
}

int main() {
    ofstream f("results/comparacion.csv");
    f << "metodo,tamano,tiempo_ms\n";

    for (int n : {100,1000,5000}) {
        vector<int> original(n);
        for (int i=0; i<n; i++) original[i]=(i*37+13)%1000;

        vector<int> a=original;
        auto t=chrono::steady_clock::now();
        shell(a);
        double s=chrono::duration<double,milli>(
            chrono::steady_clock::now()-t).count();

        a=original;
        t=chrono::steady_clock::now();
        quick(a,0,n-1);
        double q=chrono::duration<double,milli>(
            chrono::steady_clock::now()-t).count();

        cout << "N=" << n << " Shell=" << s
             << " ms Quick=" << q << " ms\n";
        f << "Shell Sort," << n << "," << s << "\n";
        f << "Quick Sort," << n << "," << q << "\n";
    }
}