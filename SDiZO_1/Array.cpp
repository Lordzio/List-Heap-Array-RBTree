#include "stdafx.h"
#include "Array.h"


Array::Array()
{
	arr = new(std::nothrow)int[0];
	asize = 0;
}


Array::~Array()
{
	delete arr;
}

bool Array::Add(int index, int value)
{
	if (index < asize + 1 && index > -1) {
		int *newarr = new(std::nothrow)int[asize + 1];
		newarr[index] = value;
		for (int i = 0, j = 0; i < asize; i++, j++) {
			if (i == index) { j++; }
			newarr[j] = arr[i];
		}
		asize++;
		int *a = arr;
		arr = newarr;
		delete a;
		return true;
	}
	else {
		std::cout << "Nie mozna dodac wartosci pod tym indeksem!\n"; return false;
	}
}

void Array::Remove(int index)
{
	if (index < asize && index >= 0) {
		int *newarr = new(std::nothrow)int[asize - 1];
		for (int i = 0, j = 0; i < asize; i++, j++) {
			if (i == index) { i++; }
			newarr[j] = arr[i];
		}
		asize--;
		int *a = arr;
		arr = newarr;
		delete a;
		std::cout << "Wartosc usunieta.\n";
	}
	else std::cout << "Nie ma takiego indeksu!\n";
}

bool Array::Search(int value)
{
	for (int i = 0; i < asize; i++) {
		if (arr[i] == value) return true;
	}
	return false;
}

int Array::GetValue(int index)
{
	return arr[index];
}

int Array::GetSize()
{
	return asize;
}
