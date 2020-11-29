#pragma once
#include <vector>
using namespace std;

class Heap
{
private:
	vector<int> data;
public:
	int get();
	int get_recursive();
	void put(int item);
	void put_recursive(int item);
	int size();
	void print();
private:
	void reheap_down(int root, int bottom);
	void reheap_up(int root, int bottom);
};

int Heap::get()
{
	int item = -1;
	if (data.size() != 0) {
		item = data[0];
		data[0] = data.back();
		data.pop_back();
		int here = 0;
		while (true) {
			int left = 2 * here + 1, right = 2 * here + 2;
			if (left >= data.size()) {
				break;
			}
			int next = here;
			if (data[next] < data[left]) {
				next = left;
			}
			if (right < data.size() && data[next] < data[right]) {
				next = right;
			}
			if (next == here) {
				break;
			}
			swap(data[here], data[next]);
			here = next;
		}
	}
	return item;
}

int Heap::get_recursive()
{
	int item = -1;
	if (data.size() != 0) {
		item = data[0];
		data[0] = data.back();
		data.pop_back();
		reheap_down(0, data.size() - 1);
	}
	return item;
}

void Heap::reheap_down(int root, int bottom)
{
	int max, left, right;

	left = 2 * root + 1;
	right = 2 * root + 2;
	if (left <= bottom) {
		if (left == bottom) {
			max = left;
		}
		else {
			if (data[left] <= data[right]) {
				max = right;
			}
			else {
				max = left;
			}
		}
		if (data[root] < data[max]) {
			swap(data[root], data[max]);
			reheap_down(max, bottom);
		}
	}
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Heap::put(int item)
{
	data.push_back(item);
	int i = data.size() - 1;
	while (i > 0 && data[(i - 1) / 2] < data[i]) {
		swap(data[i], data[(i - 1) / 2]);
		i = (i - 1) / 2;
	}
}

void Heap::put_recursive(int item)
{
	data.push_back(item);
	reheap_up(0, data.size() - 1);
}

void Heap::reheap_up(int root, int bottom)
{
	int parent;
	if (bottom > root) {
		parent = (bottom - 1) / 2;
		if (data[parent] < data[bottom]) {
			swap(data[parent], data[bottom]);
			reheap_up(root, parent);
		}
	}
}

int Heap::size() { return data.size(); }

void Heap::print()
{
	for (int i = 0; i < data.size(); i++) {
		cout << data[i] << ' ';
	}
	cout << endl;
}