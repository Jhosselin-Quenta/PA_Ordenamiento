#include <iostream>
using namespace std;

void quickSort(int a[], int inicio, int fin) {
    if (inicio >= fin) return;

    int pivote = a[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; j++) {
        if (a[j] < pivote) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[fin]);

    quickSort(a, inicio, i);
    quickSort(a, i + 2, fin);
}

int main() {
    int a[] = {8, 3, 7, 4, 2};
    int n = 5;

    quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}  