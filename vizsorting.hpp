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
        int *a; //array to be sorted
        int n;  //number of items in array
        int lcv; //left colored value
        int rcv; //right colored value
        int mcv; //middle colored value
        int ssnum;
        sf::Font font; 
        sf::Text text;
        bool sorted; //state of values held in a
        string currentAlgorithm;    //for displaying algorithm being used
        void exch(int a[], int l, int r);
        //heapsorts
        void downheap(int a[], int n, int k);
        void upheap(int a[], int k);
        void heapsort(int a[], int l, int r);
        void floydheapsort(int a[], int l, int r);
        //mergesorts
        void mergesort(int a[], int n);
        void mergesort(int a[], int aux[], int l, int r);
        void bumsort(int a[], int n);
        void tiledbumsort(int a[], int n);
        void merge(int a[], int aux[], int l, int m, int r);
        //quicksorts
        void quicksort(int a[], int l, int r);
        void quicksortR(int a[], int l, int r);
        void introsort(int a[], int l, int r);
        void introsortR(int a[], int l, int r, int d);
        int findPivot(int a[], int l, int r);
        int _medianOfMedians(int a[], int l, int r);
        int partition(int a[], int l, int r);
        //Other sorts
        void shellsort(int a[], int l, int r);
        void insertionsort(int a[], int l, int r);
        void insertionsortNA(int a[], int n);
        void selectionsort(int a[], int n);
        void bubblesort(int a[], int n);
        void exchangesort(int a[], int n);
        void cocktail(int a[], int n);

        void showHelp();
    public:
        App(int mw = 850, int mh = 500);
        void start();
        void handleEvent(sf::Event& event);
        void sleep();
        void render();
        void renderSortArray();
};

#endif