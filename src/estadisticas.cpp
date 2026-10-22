
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    ifstream f("results/comparacion.csv");
    string linea, campo;
    vector<double> tiempos;

    getline(f, linea);

    while (getline(f, linea)) {
        stringstream s(linea);
        for (int i = 0; i < 5; i++)
            getline(s, campo, ',');
        tiempos.push_back(stod(campo));
    }

    if (tiempos.empty()) {
        cout << "No hay datos\n";
        return 1;
    }

    sort(tiempos.begin(), tiempos.end());
    double suma = 0, cuadrados = 0;

    for (double x : tiempos) suma += x;
    double promedio = suma / tiempos.size();

    for (double x : tiempos)
        cuadrados += (x - promedio) * (x - promedio);

    cout << "Cantidad: " << tiempos.size() << "\n";
    cout << "Promedio: " << promedio << " ms\n";
    cout << "Mediana: " << tiempos[tiempos.size()/2] << " ms\n";
    cout << "Desviacion estandar: "
         << sqrt(cuadrados / tiempos.size()) << " ms\n";
    cout << "Minimo: " << tiempos.front() << " ms\n";
    cout << "Maximo: " << tiempos.back() << " ms\n";
}
