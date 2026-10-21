#include <iostream>
using namespace std;

void shellSort(int a[], int n) {
    for (int g = n/2; g > 0; g /= 2)
        for (int i = g; i < n; i++) {
            int x = a[i], j = i;
            while (j >= g && a[j-g] > x) {
                a[j] = a[j-g];
                j -= g;
            }
            a[j] = x;
        }
}

void quickSort(int a[], int l, int r) {
    if (l >= r) return;
    int p = a[r], i = l;
    for (int j = l; j < r; j++)
        if (a[j] < p) {
            int t = a[i]; a[i] = a[j]; a[j] = t;
            i++;
        }
    int t = a[i]; a[i] = a[r]; a[r] = t;
    quickSort(a, l, i-1);
    quickSort(a, i+1, r);
}

int main() {
    int a[] = {8, 3, 7, 4, 2};
    int b[] = {8, 3, 7, 4, 2};
    int n = 5;

    shellSort(a, n);
    quickSort(b, 0, n-1);

    cout << "Shell Sort: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";

    cout << "\nQuick Sort: ";
    for (int i = 0; i < n; i++) cout << b[i] << " ";

    return 0;
}