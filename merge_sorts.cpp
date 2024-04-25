#include "vizsorting.hpp"

void App::merge(int a[], int aux[], int l, int m, int r) {
    for (int k = l; k < r; k++)
        aux[k] = a[k];
    for (int i = l, j = m, k = l; k < r; k++) {
        if (i == m) { a[k] = aux[j++]; continue; }
        if (j == r) { a[k] = aux[i++]; continue; }
        a[k] = (aux[j] > aux[i]) ? aux[i++]:aux[j++];
        lcv = i;
        rcv = j;
        render();
    }
}

void App::mergesort(int a[], int aux[], int l, int r) {
    if (r - l < 13) {
        insertionsort(a, l, r+1);
        return;
    }
    int m = (l+r)/2;
    mergesort(a, aux, l, m);
    mergesort(a, aux, m, r);
    merge(a, aux, l, m, r);
}
void App::mergesort(int a[], int n) {
    int *aux = new int[n];
    mergesort(a, aux, 0, n);
    lcv = rcv = n + 1;
}

void App::bumsort(int a[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++)
        aux[i] = a[i];
    for (int w = 1; w < n; w = 2*w) {
        for (int b = 0; b < n; b = b + 2*w) {
            int l = b, m = l+w, r = min(l+w+w, n);
            merge(a, aux, l, m, r);
        }
    }
    lcv = rcv = n + 1;
}

//This is _not_ Timsort. I can't believe that needs to be said.
void App::tiledbumsort(int a[], int n) {
    for (int i = 0; i < n; i += 9) {
        insertionsort(a, i, i+9);
    }
    int *aux = new int[n];
    for (int i = 0; i < n; i++)
        aux[i] = a[i];
    for (int w = 9; w < n; w = 2*w) {
        for (int b = 0; b < n; b = b + 2*w) {
            int l = b, m = l+w, r = min(l+w+w, n);
            merge(a, aux, l, m, r);
        }
    }
    lcv = rcv = n + 1;
}