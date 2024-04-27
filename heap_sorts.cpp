#include "vizsorting.hpp"

void App::downheap(int a[], int n, int k) {
    while (2*k <= n) {
        int j = 2*k;
        if (j < n && a[j] < a[j+1]) j++;
        if (!(a[k] < a[j])) break;
        exch(a, k, j);
        k = j;
        render();
    }
}

void App::upheap(int a[], int k) {
    while (k >= 0 && a[k/2] < a[k]) {
        exch(a, k, k/2);
        k = k/2;
    }
}

void App::floydheapsort(int a[], int l, int r) {
    int n = r-l;
    int *pq = a+l;
    for (int i = n/2; i >= 0; i--)
        downheap(pq, n, i);
    while (n > 0) {
        exch(pq, 0, n--);
        downheap(a, n, 0);
    }
    lcv = rcv = n+1;
}

void App::heapsort(int a[], int l, int r) {
    int n = r-l;
    int *pq = a+l;
    for (int i = 0; i < n+1; i++) 
        upheap(pq, i);
    while (n > 0) {
        exch(pq, 0, n--);
        downheap(a, n, 0);
    }
    lcv = rcv = n+1;
}