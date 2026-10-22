#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream f("results/comparacion.csv");
    ofstream out("results/estadisticas.csv");
    string linea;
    vector<double> v;
    double ms;

    getline(f, linea);
    while (getline(f, linea)) {
        for (int i=0; i<4; i++)
            linea = linea.substr(linea.find(',')+1);
        ms = stod(linea.substr(0, linea.find(',')));
        v.push_back(ms);
    }

    sort(v.begin(), v.end());
    double suma=0, d=0;
    for (double x:v) suma+=x;
    double prom=suma/v.size();
    for (double x:v) d+=(x-prom)*(x-prom);

    out << "cantidad,media,mediana,desviacion,minimo,maximo\n"
        << v.size() << "," << prom << ","
        << (v[269]+v[270])/2 << ","
        << sqrt(d/v.size()) << "," << v.front()
        << "," << v.back() << "\n";

    cout << "Estadisticas guardadas\n";
}
