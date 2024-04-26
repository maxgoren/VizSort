#include "vizsorting.hpp"

App::App(int mw, int mh) {
    maxw = mw;
    maxh = mh;
    n = mw/6;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 490;
        cout<<i<<": "<<a[i]<<endl;
    }
    if (!font.loadFromFile("font.ttf")) {
        cout<<"Couldn't load font."<<endl;
    }
    text.setFont(font);
    currentAlgorithm = " N = " + to_string(n);
    sorted = false;
}

void App::start() {
    sf::Event event;
    window = new sf::RenderWindow(sf::VideoMode(maxw, maxh), "VizSort - Sorting Algorithms, Visualized.");
    texture = new sf::RenderTexture();
    texture->create(maxw, maxh);
    window->setFramerateLimit(60);
    while (window->isOpen()) {
        while (window->pollEvent(event)) {
            handleEvent(event);
        }
        render();
    }
    delete window;
    delete texture;
}

void App::handleEvent(sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        window->close();
    }
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code != sf::Keyboard::Escape && event.key.code != sf::Keyboard::R && sorted) {
            currentAlgorithm = "Press 'R' to shuffle array.";
            return;
        }
        switch (event.key.code) {
            case sf::Keyboard::R:
                currentAlgorithm = "Knuth Shuffle, N = " + to_string(n);
                for (int i = 0; i < n; i++) {
                    exch(a, i, rand() % (n - i + 1) + i);
                }
                sorted = false;
                break;
            case sf::Keyboard::M:
                currentAlgorithm = "Mergesort (Topdown), w/ Insertion Sort Cutoff";
                mergesort(a, n);
                sorted = true;
                break;
            case sf::Keyboard::B:
                currentAlgorithm = "Mergesort (Bottom up)";
                bumsort(a, n);
                sorted = true;
                break;
            case sf::Keyboard::T:
                currentAlgorithm = "Mergesort (Tiled Bottom Up)";
                tiledbumsort(a, n);
                sorted = true;
                break;
            case sf::Keyboard::F:
                currentAlgorithm = "Heapsort (Floyd's)";
                floydheapsort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::H:
                currentAlgorithm = "Heapsort";
                heapsort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::Q:
                currentAlgorithm = "Iterative Quicksort, w/ Insertion Sort Cutoff";
                quicksort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::I:
                currentAlgorithm = "Intro sort";
                introsort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::S:
                currentAlgorithm = "Shellsort";
                shellsort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::N:
                currentAlgorithm = "Insertion sort.";
                insertionsort(a, 0, n-1);
                sorted = true;
                break;
            case sf::Keyboard::L:
                currentAlgorithm = "Selection sort";
                selectionsort(a, n);
                break;
            case sf::Keyboard::K:
                currentAlgorithm = "Bubble sort";
                bubblesort(a, n);
                break;
            case sf::Keyboard::Escape:
                window->close();
                break;
            default:
                break;
        }
    }
}


void App::renderSortArray() {
    sf::RectangleShape rect;
    int x = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        rect.setPosition(x, maxh-a[j]);
        rect.setSize(sf::Vector2f(5, a[j]));
        if (i == lcv)
            rect.setFillColor(sf::Color::Red);
        else if (i == rcv)
            rect.setFillColor(sf::Color::Red);
        else
            rect.setFillColor(sf::Color::Green);
        texture->draw(rect);
        x += 6;
        j++;
    }
    texture->display();
}

void App::render() {
    texture->clear(sf::Color::Black);
    renderSortArray();
    text.setString(currentAlgorithm);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Blue);
    text.setStyle(sf::Text::Bold);
    texture->draw(text);
    texture->display();
    sf::Sprite rs(texture->getTexture());
    window->draw(rs);
    window->display();
}

void App::sleep() {
    std::this_thread::sleep_for(150ms);
}