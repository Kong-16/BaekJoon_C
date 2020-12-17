#pragma once
#include <iostream>
#include <ctime>

using namespace std;

class MergeSort
{
private:
	int size;
	int* array;
	int* temp;
public:
	MergeSort(int* _array, int _size) : array(_array), size(_size)
	{
		temp = new int[_size];
	}
	~MergeSort() { delete[] temp; }
	int GetNumber() { return size; }
	void CheckLyn()
	{
		int i = 0, up = 0, down = size - 1;
		while (i < size)
		{
			while (i < size)
			{
				*(temp + up++) = *(array + i++);
				if (*(array + i) < *(array + i - 1))
					break;
			}
			while (i < size)
			{
				*(temp + down--) = *(array + i++);
				if (*(array + i) < *(array + i - 1))
					break;
			}
		}
	}
	void Merge()
	{
		int* begin = temp;
		int* end = temp + size - 1;
		int i = 0;
		while (i < size)
		{
			if (*begin < *end)
			{
				*(array + i++) = *(begin++);
				if (*begin < *(begin - 1))
				{
					do { *(array + i++) = *(end--); } while (*end > *(end + 1) && i < size);
					break;
				}
			}
			else
			{
				*(array + i++) = *(end--);
				if (*end < *(end + 1))
				{
					do { *(array + i++) = *(begin++); } while (*begin < *(begin - 1) && i < size);
					break;
				}
			}
		}
		if (begin > end)
			return;
		for (; i < size; ++i)
			*(array + i) = *(end--);
		for (int i = 0; i < size; ++i)
			*(temp + i) = *(array + i);
		Merge();
	}
	void CheckSort()
	{
		bool sorted = true;
		for (int i = 0; i < size - 1; ++i)
		{
			if (array[i] > array[i + 1]) sorted = false;
			if (!sorted) break;
		}
		if (sorted) cout << "정렬 완료" << endl;
		else cout << "정렬오류 발생" << endl;
	}
	void ShowData()
	{
		for (int i = 0; i < size; ++i)
			cout << *(array + i) << " ";
		cout << endl;
	}
};

int* CreateData(int num)
{
	int* data = new int[num];
	srand((unsigned)time(NULL));
	for (int i = 0; i < num; ++i)
	{
		data[i] = rand();
	}
	return data;
}

int main(void)
{
	MergeSort m(CreateData(1000), 1000);
	double start_time = clock();

	m.CheckLyn();
	m.Merge();
	cout << "MergeSort의 실행시간 ( N = " << m.GetNumber() << ") : "
		<< clock() - start_time << endl;
	m.CheckSort();

}