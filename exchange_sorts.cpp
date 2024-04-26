#include "vizsorting.hpp"

void App::selectionsort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i; j < n; j++) {
            if (a[j] < a[min])
                min = j;
        }
        exch(a, i, min);
    }
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
}