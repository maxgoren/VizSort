#include "vizsorting.hpp"

void App::inssort2(int a[], int n) {
    for (int i = 0; i < n; i++)
        for (int j = i; j > 0 && a[j-1] > a[j]; j--)
            exch(a, j, j-1);
}

void App::insertionsort(int a[], int l, int r) {
    for (int i = l; i <= r; i++) {
        int j = i, v = a[i];
        while (j > l && a[j-1] > v) {
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
        lcv = i;
        rcv = j;
        render();
    }
    lcv = rcv = n + 1;
}

void App::shellsort(int a[], int l, int r) {
    int h;
    for (int h = 1; h < (r-l)/9; h = 3*h+1);
    for (; h > 0; h /= 3) {
        for (int i = l+h; i <= r; i++) {
            int j = i, v = a[j];
            while (j >= l+h && a[j-h] > v) {
                a[j] = a[j-h];
                j -= h;
            }
            a[j] = v;
            lcv = j;
            rcv = j-h;
            render();
        }
    }
    lcv = rcv = n+1;
}