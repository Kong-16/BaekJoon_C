#include <iostream>
#include "polya.h"
using namespace std;

istream& operator>> (istream& is, Polynomial& p) {
    // #terms and (coefficoent, exponent)�� pair���� �о���δ�.
    // ���������� �׺��� ����Ǿ��ٰ� �����Ѵ�.
    int noofterms; float coef; int exp;
    is >> noofterms;
    for (int i = 0; i < noofterms; i++) {
        is >> coef >> exp; // ����� ���� pair�� �о���δ�.
        p.NewTerm(coef, exp);
    }
    return is;
}
ostream& operator<< (ostream& os, Polynomial& p) {
    for (int i = 0; i < p.terms; i++) {

    }
    return os;
}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    if (capacity == terms) {
        capacity *= 2; // capacity �� terms�� ���� capacity�� �� �� �ø�.
        termArray = new Term[capacity]; 
    }
    // ���׽� �ڿ� ���ο� ���� �߰��ϴ� �Լ�
}
Polynomial Polynomial::operator+(Polynomial& b)
{
    //���׽��� ������ ���ִ� �Լ�
}
