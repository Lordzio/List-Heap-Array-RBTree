#pragma once
class Array
{
private:

	int *arr;
	int asize;

public:
	Array();
	~Array();
	bool Add(int index, int value);
	void Remove(int index);
	bool Search(int value);
	int GetValue(int index);
	int GetSize();
};

