#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void shellSort(vector<int>& datos) {
    int n = static_cast<int>(datos.size());

    for (int salto = n / 2; salto > 0; salto /= 2) {
        for (int i = salto; i < n; i++) {
            int temporal = datos[i];
            int j = i;

            while (j >= salto && datos[j - salto] > temporal) {
                datos[j] = datos[j - salto];
                j -= salto;
            }

            datos[j] = temporal;
        }
    }
}

int main() {
    vector<int> datos = {8, 3, 7, 4, 9, 2, 6, 1, 5};

    cout << "Antes de ordenar: ";
    for (int numero : datos) {
        cout << numero << " ";
    }

    shellSort(datos);

    cout << "\nDespues de ordenar: ";
    for (int numero : datos) {
        cout << numero << " ";
    }

    cout << endl;
    return 0;
}
