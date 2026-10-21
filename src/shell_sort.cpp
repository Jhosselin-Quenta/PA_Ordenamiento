#include <iostream>
#include <vector>

using namespace std;

struct Estadisticas {
    unsigned long long comparaciones = 0;
    unsigned long long movimientos = 0;
};

void shellSort(vector<int>& datos, Estadisticas& stats) {
    int n = static_cast<int>(datos.size());

    for (int salto = n / 2; salto > 0; salto /= 2) {
        for (int i = salto; i < n; ++i) {
            int temporal = datos[i];
            int j = i;

            while (j >= salto) {
                ++stats.comparaciones;

                if (datos[j - salto] > temporal) {
                    datos[j] = datos[j - salto];
                    ++stats.movimientos;
                    j -= salto;
                } else {
                    break;
                }
            }

            datos[j] = temporal;
            ++stats.movimientos;
        }
    }
}

int main() {
    vector<int> datos = {8, 3, 7, 4, 9, 2, 6, 1, 5};

    cout << "Antes de ordenar: ";
    for (int numero : datos) cout << numero << " ";

    Estadisticas stats;
    shellSort(datos, stats);

    cout << "\nDespues de ordenar: ";
    for (int numero : datos) cout << numero << " ";

    cout << "\nComparaciones: " << stats.comparaciones;
    cout << "\nMovimientos: " << stats.movimientos << endl;

    return 0;
}
