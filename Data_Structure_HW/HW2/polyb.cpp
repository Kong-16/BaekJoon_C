#include <iostream>
#include "polyb.h"
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
    //.....
        return os;
}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    // ���׽� �ڿ� ���ο� ���� �߰��ϴ� �Լ�
}
Polynomial Polynomial::operator+(Polynomial& b)
{
    //���׽��� ������ ���ִ� �Լ�
}

Polynomial Polynomial::operator/(Polynomial& b)
{
    Polynomial c;  // *this�� b�� �������� ����� c�� �����Ϸ��� �Ѵ�.
   // .....
        return c;
}
