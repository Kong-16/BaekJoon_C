#ifndef SUBWAY_H
#define	SUBWAY_H
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node {
	Node<T>* next;
	Node<T>* prev;
	int lineNum;
	string lineName;
public:
	Node();

};


#endif