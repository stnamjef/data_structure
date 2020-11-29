#include <iostream>
#include "heap.h"
using namespace std;

int main()
{
	Heap heap;
	heap.put_recursive(7);
	heap.put_recursive(8);
	heap.put_recursive(6);
	heap.put_recursive(6);
	heap.put_recursive(6);
	heap.put_recursive(6);
	heap.put_recursive(5);
	heap.put_recursive(8);

	heap.print();

	int size = heap.size();
	for (int i = 0; i < size; i++) {
		cout << heap.get() << ' ';
	}
	cout << endl;

	Heap heap2;
	heap2.put(7);
	heap2.put(8);
	heap2.put(6);
	heap2.put(6);
	heap2.put(6);
	heap2.put(6);
	heap2.put(5);
	heap2.put(8);

	size = heap2.size();
	for (int i = 0; i < size; i++) {
		cout << heap2.get() << ' ';
	}

	return 0;
}