#ifndef Sort_H__
#define Sort_H__
#include <algorithm>
using namespace std;

template <class T>
void getdata(istream& is,T* arr, int n) {
	T data;
	for (int i = 1; i <= n; i++) {
		is >> data;
		arr[i] = data;
	}
}

template <class T>
class myHeap {
public:
	int capacity;
	int heapSize;
	T* heap;
	myHeap(int x);
	void changeSize();
};

template <class T>
void insertionSort(T* arr, int n) { // arr[1:n] ��������
	for (int i = 2; i <= n; i++) {
		T temp = arr[i]; // ������ ������
		int j = i - 1;
		while (arr[j] > temp && j > 0) { // temp���� ���� �����Ͱ� ���� �� ����
			arr[j + 1] = arr[j]; // ������ �����͸� �� ĭ�� �ű�
			j--;
		}
		arr[j + 1] = temp;
	}
}

template <class T>
void quickSort(T* arr, int left, int right) { //arr[left:right] ������
	if (left < right) { // right�� left���� ������ ����.
		T pivot = arr[left];
		int i = left + 1; int j = right;
		while (i < j) { // i�� j�� �������� ����.
			while (arr[i] < pivot && i < right + 1) i++;
			while (arr[j] > pivot && j > left) j--;
			if (i < j) swap(arr[i], arr[j]); 
		} // while����� j�� ���� �����ʿ� ��ġ�� pivot���� ���� ��. 
		swap(a[left], a[j]);//���� arr[j]�� pivot�� ��ġ�� arr[left] �ٲ��ָ� arr[left]�� ���ڸ��� ��.
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

template <class T>
void merge(T* initArr, T* mergedArr, int l, int m, int n) {//initArr[l:m], initArr[m+1:n]�� ������ mergedArr[l:n]�� ����.
	int i1, iResult, i2;
	i1 = iResult = l;
	i2 = m + 1;

	while (i1 <= m && i2 <= n) { //�� �迭 ���� ���� �� ���� ������� ����.
		if (initArr[i1] < initArr[i2]) mergedArr[iResult++] = initArr[i1++];
		else mergedArr[iResult++] = initArr[i2++];
	}
	copy(initArr + i1, initArr + m + 1, mergedArr + iResult); //m�� n�� ���̰� �ٸ� ��� �� ���� ���� ����. ������ �� ����.
	copy(initArr + i2, initArr + n + 1, mergedArr + iResult);
}

template <class T>
void mergePass(T* initArr, T* resultArr, int n, int s) { // s�� ������ ���ĵ� �迭�� 2s�� ������ ���ĵ� �迭�� ����� resultArr�� ����..
	for (int i = 1; i <= n - 2 * s + 1; i += 2 * s) merge(initArr, resultArr, i, i + s - 1, i + 2 * s - 1);
	if ((i + s - 1) < n) merge(initArr, resultArr, i, i + s, n);
	else copy(initArr + i, initArr + n + 1, resultArr + i);
}

template <class T>
void mergeSort(T* arr, int n) { //arr[1:n] �պ�����
	T* tempArr = new T[n + 1];
	for (int l = 1; l < n; l *= 2) {
		mergePass(arr, tempArr, n, l);
		l *= 2;
		mergePass(tempArr, arr, n, l);
	}
	delete[] tempArr;
}

template <class T>
void rmergeSort(T* arr, int left, int right) { //arr[left:right] ����պ�����
	if (left >= right) return;
	int mid = (left + right) / 2; // �迭�� ����
	rmergeSort(arr, left, mid); 
	rmergeSort(arr, mid + 1, right); //�� ������ �Ű������� ����� ȣ�� -> ���ݾ� �ɰ���
	merge(arr, arr, left, mid, right); //�� �ɰ��� ��� merge�� ���ļ� arr�� ����
}




template <class T>
void nmergeSort(T* arr,int end) { //arr[1:end] �ڿ��պ�����
	int capacity = 10;
	int heapSize = 1;
	int* incIndex = new int[capacity + 1];
	incIndex[0] = -1;
	for (int i = 1; i <= end; i++) {
		if (arr[i] > arr[i + 1]) {
			incIndex[heapSize++] = i;
			if (heapSize == capacity) {
				capacity *= 2;
				int* temp = new int[capacity + 1];
				copy(incIndex, incIndex + heapSize, temp);
				incIndex = temp;
				delete[] temp;
			}
		}
	}
}

template <class T>
void adjust(T* arr, int root, int n) {

}
#endif