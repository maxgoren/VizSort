#ifndef vizsorting_hpp
#define vizsorting_hpp
#include <iostream>
#include <thread>
#include <chrono>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

class App {
    private:
        sf::RenderTexture* texture;
        sf::RenderWindow* window;
        int maxw;
        int maxh;
        int *a;
        int n;
        int lcv;
        int rcv;
        int mcv;
        int ssnum;
        sf::Font font;
        sf::Text text;
        bool sorted;
        string currentAlgorithm;
        void heapsort(int a[], int l, int r);
        void floydheapsort(int a[], int l, int r);
        void downheap(int a[], int n, int k);
        void upheap(int a[], int k);
        void exch(int a[], int l, int r);
        void mergesort(int a[], int n);
        void mergesort(int a[], int aux[], int l, int r);
        void merge(int a[], int aux[], int l, int m, int r);
        void quicksort(int a[], int l, int r);
        void quicksortR(int a[], int l, int r);
        int partition(int a[], int l, int r);
        void insertionsort(int a[], int l, int r);
        void shellsort(int a[], int l, int r);
        void introsort(int a[], int l, int r);
        void quicksort(int a[], int l, int r, int d);
        int medOf3(int a[], int l, int r);
        void bumsort(int a[], int n);
        void tiledbumsort(int a[], int n);
        void bubblesort(int a[], int n);
        void exchangesort(int a[], int n);
        void selectionsort(int a[], int n);
        void inssort2(int a[], int n);
        int _medOf3(int a[], int l, int r);
        void cocktail(int a[], int n);
    public:
        App(int mw = 850, int mh = 500);
        void start();
        void handleEvent(sf::Event& event);
        void sleep();
        void render();
        void renderSortArray();
};

#endif