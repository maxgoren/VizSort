#include "vizsorting.hpp"

void App::exch(int a[], int l, int r) {
    int t = a[l];
    a[l] = a[r];
    a[r] = t;
    lcv = l;
    rcv = r;
    render();
}

int App::partition(int a[], int l, int r) {
    int i = l - 1, j = r, v = a[r];
    for (;;) {
        lcv = l;
        rcv = r;
        while (a[++i] < v);
        while (a[--j] > v);
        if (i >= j) break;
        exch(a, i, j);
        render();
    }
    exch(a, i, r);
    render();
    return i;
}

void App::quicksort(int a[], int l, int r) {
    int *st = new int[r-l];
    int t = 0;
    st[t++] = r;
    st[t++] = l;
    while (t > 0) {
        l = st[--t];
        r = st[--t];
        if (r - l < 9) {
            insertionsort(a, l, r);
        } else {
            int i = medOf3(a, l, r);
            if (i-1 > l) {
                st[t++] = i-1;
                st[t++] = l;
            }
            if (i+1 < r) {
                st[t++] = r;
                st[t++] = i + 1;
            }
        }
    }
}

int App::medOf3(int a[], int l, int r) {
    int m = (l+r)/2;
    if (a[l] > a[m])
        exch(a, l, m);
    if (a[l] > a[r])
        exch(a, l, r);
    if (a[m] < a[r])
        exch(a, m, r);
    render();
    return partition(a, l, r);
}

void App::quicksort(int a[], int l, int r, int d) {
    if (d == 0) {
        heapsort(a, l, r);
    } else if (r - l < 13) {
        insertionsort(a, l, r);
    } else {
        int i = medOf3(a, l, r);
        quicksort(a, l, i-1,d-1);
        quicksort(a, i+1, r,d-1);
    }
}

void App::introsort(int a[], int l, int r) {
    int d = 2*log(r-l);
    quicksort(a, l, r, d);
    lcv = rcv = n+1;
}