#include <iostream>
#include <string>
using namespace std;
template <class K, class E>
struct Node {
	Node(K ky, E el, Node<K, E>* left = 0, Node<K, E>* right = 0,bool left = true, bool right = true) : key(ky), element(el), leftChild(left), rightChild(right), leftThread(left), rightThread(right){}
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
private:
	void Visit(Node<K, E>*);
	void Insert(Node<K, E>*&, K&, E&); // ����
	void Inorder(Node<K, E>*);
	Node<K, E>* Delete(Node<K, E>*&, Node<K, E>*&, K&); // ����
	Node<K, E>* Max(Node<K, E>*&); // ����
	Node<K, E>* Min(Node<K, E>*&); // ����
	Node<K, E>* root;
};
template <class K, class E>
void BST<K, E>::Insert(Node<K, E>*& n, K& ky, E& el) {
	Node<K, E>* n = new Node<K, E>(ky, el);
	Node<K, E>* temp = root;
	if (root == 0) {// ��Ʈ�� ���� �� ��Ʈ�� �ְ� ������ ���ο��� �̾���.
		root = n;
		n->rightChild = n;
		n->leftChild = n;
		return;
	}
	while (true) {
		if (k > temp->key) {
			temp = temp->rightChild;
			if (temp.rightThread == true) { // Thread�� ��� �θ��� thread�� �̾��ְ� �θ� false�� �ٲ�. ���� ��� ������ �ڽĳ�� ���ʽ����� �̾���
				n->rightChild = temp->rightChild;
				temp->rightThread = false;
				temp->rightChild = n;
				n->leftChild = temp;
				return;
			}
		}
		else if (k < temp->key) {
			temp = temp->leftChild;
			if (temp->leftThread == true) {
				n->leftChild = temp->leftChild;
				temp->leftThread = false;
				temp->leftChild = n;
				n->rightChild = temp; 
				return;
			}
		}
		else cout << "Aleady exist!"
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
Node<K, E>* BST<K, E> :: Delete(Node<K, E>*& r, Node<K, E>*& n, K& k) {
	Node<K, E>* temp = r;
	Node<K, E>* pre;
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
					}
					else {
						pre->rightChild = temp->leftChild;
						delete temp;
					}
				}
			}
			else {
				if (temp->leftChild->rightThread == true) { // ������ ����� ���� �ڽ��� ������ �ڽ��� ���� ��

				}
				else { // ������ ����� ���� �ڽ��� ������ �ڽ��� ���� ��
					pre = temp;
					temp = temp->leftChild;
					while (temp->rightThread == true) {
						temp = temp->rightChild;

					}
				}
			}
		}
	}
	cout << "Node does not exist!"
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

