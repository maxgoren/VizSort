visualsort:
	g++ --std=c++17 -c exchange_sorts.cpp
	g++ --std=c++17 -c insertion_sorts.cpp
	g++ --std=c++17 -c heap_sorts.cpp
	g++ --std=c++17 -c merge_sorts.cpp
	g++ --std=c++17 -c partition_sorts.cpp
	g++ --std=c++17 -c vizsorting.cpp
	g++ --std=c++17 -c main.cpp
	g++ *.o -o VisualSort -lsfml-window -lsfml-graphics -lsfml-system
	rm *.o