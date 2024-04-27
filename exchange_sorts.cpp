#include "vizsorting.hpp"

void App::selectionsort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        mcv = min;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
                mcv = min;
            }
            lcv = i;
            rcv = j;
            render();
        }
        exch(a, i, min);
    }
    lcv = rcv = 1337;
    mcv = 1337;
}

void App::bubblesort(int a[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int j = 0; j < n; j++) {
            if (a[j+1] < a[j]) {
                exch(a, j+1, j);
                sorted = false;
            }
        }
    }
    lcv = rcv = 1337;
    mcv = 1337;
}

void App::exchangesort(int a[], int n ) {
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (a[j] < a[i]) {
                exch(a, i, j);
            }
        }
    }
    lcv = rcv = 1337;
    mcv = 1337;
}

void App::cocktail(int a[], int n) {
    bool sorted = false;
    int l = 0;
    int r = n;
    while (!sorted) {
        sorted = true;
        for (int i = l; i < r-1; i++)
            if (a[i+1] < a[i]) {
                exch(a, i, i+1);
                sorted = false;
            }
        r--;
        for (int i = r-1; i > l; i--) {
            if (a[i] < a[i-1]) {
                exch(a, i, i-1);
                sorted = false;
            }
        }
        l++;   
    }
    lcv = rcv = 1337;
    mcv = 1337;
}