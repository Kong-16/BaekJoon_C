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
void insertionSort(T* arr, int n) { // arr[1:n] 삽입정렬
	for (int i = 2; i <= n; i++) {
		T temp = arr[i]; // 삽입할 데이터
		int j = i - 1;
		while (arr[j] > temp && j > 0) { // temp보다 작은 데이터가 나올 때 까지
			arr[j + 1] = arr[j]; // 이전의 데이터를 한 칸씩 옮김
			j--;
		}
		arr[j + 1] = temp;
	}
}

template <class T>
void quickSort(T* arr, int left, int right) { //arr[left:right] 퀵정렬
	if (left < right) { // right가 left보다 작으면 종료.
		T pivot = arr[left];
		int i = left + 1; int j = right;
		while (i < j) { // i와 j가 엇갈리면 종료.
			while (arr[i] < pivot && i < right + 1) i++;
			while (arr[j] > pivot && j > left) j--;
			if (i < j) swap(arr[i], arr[j]); 
		} // while종료시 j는 가장 오른쪽에 위치한 pivot보다 작은 수. 
		swap(a[left], a[j]);//따라서 arr[j]와 pivot의 위치인 arr[left] 바꿔주면 arr[left]가 제자리로 감.
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

template <class T>
void merge(T* initArr, T* mergedArr, int l, int m, int n) {//initArr[l:m], initArr[m+1:n]을 정렬해 mergedArr[l:n]에 저장.
	int i1, iResult, i2;
	i1 = iResult = l;
	i2 = m + 1;

	while (i1 <= m && i2 <= n) { //두 배열 비교해 작은 값 부터 순서대로 저장.
		if (initArr[i1] < initArr[i2]) mergedArr[iResult++] = initArr[i1++];
		else mergedArr[iResult++] = initArr[i2++];
	}
	copy(initArr + i1, initArr + m + 1, mergedArr + iResult); //m과 n의 길이가 다를 경우 한 쪽이 먼저 끝남. 나머지 값 삽입.
	copy(initArr + i2, initArr + n + 1, mergedArr + iResult);
}

template <class T>
void mergePass(T* initArr, T* resultArr, int n, int s) { // s개 단위로 정렬된 배열을 2s개 단위로 정렬된 배열로 만들어 resultArr에 저장..
	for (int i = 1; i <= n - 2 * s + 1; i += 2 * s) merge(initArr, resultArr, i, i + s - 1, i + 2 * s - 1);
	if ((i + s - 1) < n) merge(initArr, resultArr, i, i + s, n);
	else copy(initArr + i, initArr + n + 1, resultArr + i);
}

template <class T>
void mergeSort(T* arr, int n) { //arr[1:n] 합병정렬
	T* tempArr = new T[n + 1];
	for (int l = 1; l < n; l *= 2) {
		mergePass(arr, tempArr, n, l);
		l *= 2;
		mergePass(tempArr, arr, n, l);
	}
	delete[] tempArr;
}

template <class T>
void rmergeSort(T* arr, int left, int right) { //arr[left:right] 재귀합병정렬
	if (left >= right) return;
	int mid = (left + right) / 2; // 배열의 절반
	rmergeSort(arr, left, mid); 
	rmergeSort(arr, mid + 1, right); //각 절반을 매개변수로 재귀적 호출 -> 절반씩 쪼개짐
	merge(arr, arr, left, mid, right); //다 쪼개질 경우 merge로 합쳐서 arr에 저장
}




template <class T>
void nmergeSort(T* arr,int end) { //arr[1:end] 자연합병정렬
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