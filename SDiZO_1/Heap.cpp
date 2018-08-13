#include "stdafx.h"
#include "Heap.h"




void Heap::FixUp(int position)
{
	while(position != 0){
		double parent = ceil((position - 1) / 2);

		if (arr[position] > arr[(int)parent]) {
			int buf = arr[(int)parent];
			arr[(int)parent] = arr[position];
			arr[position] = buf;
		}

		position = (int)parent;
	}
}

void Heap::FixDown()
{
	bool fixed = false;
	while (!fixed) {
		fixed = true;

		for (int i = 0; i < hsize; i++) {
			double lch = ceil((2 * i) + 1), rch = ceil((2 * i) + 2);

			if (arr[(int)lch] > arr[i] && lch < hsize) {
				int buf = arr[(int)lch];
				arr[(int)lch] = arr[i];
				arr[i] = buf;
				fixed = false;
				break;
			}

			if (arr[(int)rch] > arr[i] && rch < hsize) {
				int buf = arr[(int)rch];
				arr[(int)rch] = arr[i];
				arr[i] = buf;
				fixed = false;
				break;
			}
		}

	}
}

Heap::Heap()
{
	arr = new(std::nothrow)int[0];
	hsize = 0;
}


Heap::~Heap()
{
	delete arr;
}

bool Heap::Add(int value)
{
	int *newarr = new(std::nothrow)int[hsize + 1];
	newarr[hsize] = value;
	for (int i = 0; i < hsize; i++) {
		newarr[i] = arr[i];
	}
	hsize++;
	int *a = arr;
	arr = newarr;
	delete a;
	FixUp(hsize - 1);
	return true;
}

void Heap::Remove(int value){
	int index = Search(value);
	bool removed = false;

	while (index != -1) {
		int *newarr = new(std::nothrow)int[hsize - 1];
		for (int i = 0, j = 0; j < hsize - 1; i++, j++) {
			if (i == index) { i++; }
			newarr[j] = arr[i];
		}
		hsize--;
		int *a = arr;
		arr = newarr;
		delete a;

		FixDown();
		std::cout << "Wartosc usunieta.\n";
		removed = true;
		index = Search(value);
	}
	if(!removed) std::cout << "Nie ma takiej wartosci!\n";
}

void Heap::Display()
{
	if (hsize > 0) {
		int j = 0, power = 1;
		std::cout << arr[0] << "|#|";
		for (int i = 1; i < hsize; i++) {
			j++;
			if (pow(2, power) == j) {
				std::cout << arr[i] << "|#|";
				power++;
				j = 0;
			}
			else std::cout << arr[i] << "|";
		}
	}
}


int Heap::Search(int value) {
	for (int i = 0; i < hsize; i++) {
		if (arr[i] == value) {
			return i;
		}
	}
	return -1;
}


