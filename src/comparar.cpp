#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void shellSort(int a[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;

            while (j >= gap && a[j - gap] > temp) {
                a[j] = a[j - gap];
                j -= gap;
            }
            a[j] = temp;
        }
    }
}

void quickSort(int a[], int l, int r) {
    int i = l, j = r;
    int p = a[(l + r) / 2];

    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;

        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if (l < j) quickSort(a, l, j);
    if (i < r) quickSort(a, i, r);
}

int main() {
    int a[] = {8, 3, 7, 4, 2};
    int b[] = {8, 3, 7, 4, 2};
    int n = 5;

    auto inicio = steady_clock::now();
    shellSort(a, n);
    auto fin = steady_clock::now();

    cout << "Shell Sort: ";
    for (int x : a) cout << x << " ";
    cout << "\nTiempo: "
         << duration<double, milli>(fin - inicio).count()
         << " ms\n";

    inicio = steady_clock::now();
    quickSort(b, 0, n - 1);
    fin = steady_clock::now();

    cout << "Quick Sort: ";
    for (int x : b) cout << x << " ";
    cout << "\nTiempo: "
         << duration<double, milli>(fin - inicio).count()
         << " ms\n";

    return 0;
}