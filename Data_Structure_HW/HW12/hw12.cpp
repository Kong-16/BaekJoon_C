#include <iostream>
#include <fstream>
#include <ctime>
#include "sort.h"
using namespace std;

template <class T>
int main(int argc, char* argv[]) {
	int T = atoi(argv[1]); // num of test case
	cout << "T=" << T << endl;
	int N; // �� �׽�Ʈ���̽� �� ���ڵ��� ����
	int i; // iterator
	clock_t result[6]; // result �迭�� �� �˰��� ���� ����ð��� �����ϰ� �˴ϴ�.
	// result[0]: insertion sort
	// result[1]: quick 
	// result[2]: iterative merge sort
	// result[3]: reculsive merge sort
	// result[4]: natural merege sort
	// result[5]: heap sort
	clock_t start;
	clock_t end;
	if (argc < 3) {
		cerr << "wrong argument count" << endl;
		return 1;
	}

	cout << "--INS--|-QUICK-|-MERGE-|-RECMG-|-NATMG-|-HEAP--| " << endl;
	for (i = 2; i < T + 2; i++) {
		// i��° ������ ������ �н��ϴ�.
		ifstream fin(argv[i]);
		fin >> N;
		T* arr = new T[N + 1];
		getdata(fin,arr,N);
		// �� ���� �˰��� �ʿ��� �ڷᱸ���� �����ϰ� �����͸� ����ϴ�.
		// ������� ���� �ð� ������ �����մϴ�.
		/* example
		start = clock();
		�������� ����
		end = clock();
		result[0] = end-start; */
		// ����� ����մϴ�. (�� �κ��� �������� �ʽ��ϴ�)
		cout.precision(5);
		cout << fixed;
		for (int j = 0; j < 6; j++) {
			cout << (double)result[j] / CLOCKS_PER_SEC << "|";
		}
		cout << "N=" << N << endl;
	}
}