
#include <iostream>
using namespace std;

int main() {
    int a[] = {8, 3, 7, 4, 2};
    int n = 5;

    for (int i = 1; i < n; i++) {
        int clave = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > clave) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = clave;
    }

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
