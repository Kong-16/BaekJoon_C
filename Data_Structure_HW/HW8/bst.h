#include <iostream>
#include <string>
using namespace std;
template <class K, class E>
struct Node {
	Node(K ky, E el, Node<K, E>* left = 0, Node<K, E>* right = 0,bool leftT = true, bool rightT = true) : key(ky), element(el), leftChild(left), rightChild(right), leftThread(leftT), rightThread(rightT){}
	Node<K, E>* leftChild;
	K key;
	E element;
	Node<K, E>* rightChild;
	bool leftThread; //thread�� �̾����ִ��� Ȯ����. true�� thread, false�� child Node.
	bool rightThread;
}; 
template <class K, class E>
class BST {
public:
	BST() { root = 0; }
	void Insert(K& newkey, E& el) { Insert(root, newkey, el); }
	void Inorder() { Inorder(root); }
	void Delete(K& oldkey) { Delete(root, root, oldkey); }
	bool Find(const K&, E&);
	void Max() { cout << Max(root); }
	void Min() { cout << Min(root); }
private:
	void Visit(Node<K, E>*);
	void Insert(Node<K, E>*&, K&, E&); // ����
	void Inorder(Node<K, E>*);
	void Delete(Node<K, E>*&, Node<K, E>*&, K&); // ����
	Node<K, E>* Max(Node<K, E>*&); // ����
	Node<K, E>* Min(Node<K, E>*&); // ����
	Node<K, E>* root;
};
template <class K, class E>
void BST<K, E>::Insert(Node<K, E>*& n, K& k, E& el) {
	Node<K, E>* newNode = new Node<K, E>(k,el);
	newNode->key = k;
	newNode->element = el;
	Node<K, E>* temp = root;
	if (root == 0) {// ��Ʈ�� ���� �� ��Ʈ�� �ְ� ������ ���ο��� �̾���.
		root = newNode;
		newNode->rightChild = newNode;
		newNode ->leftChild = newNode;
		return;
	}
	while (temp) {
		if (k > temp->key) {
			
			if (temp->rightThread == true) { // Thread�� ��� �θ��� thread�� �̾��ְ� �θ� false�� �ٲ�. ���� ��� ������ �ڽĳ�� ���ʽ����� �̾���
				newNode->rightChild = temp->rightChild;
				temp->rightThread = false;
				temp->rightChild = newNode;
				newNode->leftChild = temp;
				return;
			}
			temp = temp->rightChild;
		}
		else if (k < temp->key) {
			
			if (temp->leftThread == true) {
				newNode->leftChild = temp->leftChild;
				temp->leftThread = false;
				temp->leftChild = newNode;
				newNode->rightChild = temp;
				return;
			}
			temp = temp->leftChild;
		}
		else {
			cout << "Aleady exist!";
				return;
		}
	}
}
template <class K, class E>
void BST<K, E>::Visit(Node<K, E>* ptr) {
	cout << ptr->key << ':' << ptr->element << ' ';
}
template <class K, class E>
void BST<K, E>::Inorder(Node<K, E>* currentNode) {
	if (currentNode) {
		Inorder(currentNode->leftChild);
		Visit(currentNode);
		Inorder(currentNode->rightChild);
	}
}
template <class K, class E>
bool BST<K, E>::Find(const K& k, E& e) {
	Node<K, E>* temp = root;
	while (temp) {
		if (k > temp->key) {
			temp = temp->rightChild;
		}
		else if (k < temp->key) {
			temp = temp->leftChild;
		}
		else {
			e = temp->element;
			return true;
		}
	}
	return false;
}
template <class K, class E>
void BST<K, E> :: Delete(Node<K, E>*& r, Node<K, E>*& n, K& k) {
	Node<K, E>* temp = r;
	Node<K, E>* pre=0;
	Node<K, E>* parent=0;
	while (temp) {
		if (k > temp->key) {
			pre = temp;
			temp = temp->rightChild;
		}
		else if (k < temp->key) {
			pre = temp;
			temp = temp->leftChild;
		}
		else {
			if (temp->leftThread == true) { 
				if (temp->rightThread == true) { //�ڽ� ��尡 ���� ��
					if (temp == pre->leftChild) {
						pre->leftChild = temp->leftChild;
						pre->leftThread = true;
						delete temp;
						return;
					}
					else {
						pre->rightChild = temp->rightChild;
						pre->rightThread = true;
						delete temp;
					}
				}
				else { //������ �ڽ� ��常 ���� ��
					if (temp == pre->leftChild) {
						pre->leftChild = temp->rightChild;
						delete temp;
						return;
					}
					else {
						pre->rightChild = temp->leftChild;
						delete temp;
						return;
					}
				}
			}
			else {
				if (temp->leftChild->rightThread == true) { // ������ ����� ���� �ڽ��� ������ �ڽ��� ���� ��
					pre = temp;
					temp = temp->leftChild;
					pre->key = temp->key;
					pre->element = temp->element;
					pre->leftChild = temp->leftChild;
					pre->leftThread = temp->leftThread;
				}
				else { // ������ ����� ���� �ڽ��� ������ �ڽ��� ���� ��
					pre = temp;
					temp = temp->leftChild;
					while (temp->rightThread == true) { //������ ��������
						parent = temp;
						temp = temp->rightChild;
					}
					pre->key = temp->key;
					pre->element = temp->element; //����
					if (temp->leftThread == true) { //��ü�� ����� �ڽ��� ���� ��
						parent->rightChild = temp->rightChild;
						parent->rightThread = true;
					}
					else {
						parent->rightChild = temp->leftChild;
					}
					delete temp;
					return;
				}
			}
		}
	}
	cout << "Node does not exist!";
}
template <class K, class E>
Node<K, E>* BST<K, E>:: Max(Node<K, E>*& n) {
	Node<K, E>* temp = root;
	while (temp->rightThread == true)
		temp = temp->rightChild;
	return temp;
}
template <class K, class E>
Node<K, E>* BST<K, E>::Min(Node<K, E>*& n) {
	Node<K, E>* temp = root;
	while (temp->leftThread == true)
		temp = temp->leftChild;
	return temp;
}

