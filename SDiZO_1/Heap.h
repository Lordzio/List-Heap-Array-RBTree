#pragma once
class Heap
{
private:

	int *arr;
	int hsize;
	void FixUp(int);
	void FixDown();

public:

	Heap();
	~Heap();
	bool Add(int value);
	void Remove(int value);
	int Search(int value);
	void Display();
};

