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
    for (int i = 0; i < p.terms; i++) {
        if (p.termArray[i].coef != 1) os << p.termArray[i].coef;
        else if (p.termArray[i].coef != -1) os << '-';
        os << "x^" << p.termArray[i].exp << ' ';
    }
    return os;
}

Polynomial::Polynomial() :capacity(1), terms(0)
{
    termArray = new Term[capacity];
}
void Polynomial::NewTerm(const float theCoeff, const int theExp)
{
    if (terms == capacity)
    {//termArray�� ũ�⸦ �� ��� Ȯ��
        capacity *= 2;
        Term* temp = new Term[capacity]; // ���ο� �迭
        copy(termArray, termArray + terms, temp);
        delete[] termArray; // ���� �޸𸮸� ��ȯ
        termArray = temp;
    }
    termArray[terms].coef = theCoef;
    termArray[terms++].exp = theExp;
}
Polynomial Polynomial::operator+(Polynomial& b)
{
    Polynomial c; // ���� ����
    int aPos = 0, bPos = 0;
    while ((aPos < terms) && (bPos < b.terms)) //�ϳ��� ���׽��� ��� ���� ���� �� ����
        if (termArray[aPos].exp == b.termArray[bPos].exp) { //������ ���� �� ������� ����
            float t = termArray[aPos].coef + b.termArray[bPos].coef;
            if (t) c.NewTerm(t, termArray[aPos].exp); //t�� 0�϶��� ���� ����.
            aPos++; bPos++;
        }
        else if (termArray[aPos].exp < b.termArray[bPos].exp) {
            c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
            bPos++;
        }
        else {
            c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
            aPos++;
        }
    // ���� �� ���� ����
    for (; aPos < terms; aPos++)
        c.NewTerm(termArray[aPos].coef, termArray[aPos].exp);
    for (; bPos < b.terms; bPos++)
        c.NewTerm(b.termArray[bPos].coef, b.termArray[bPos].exp);
    return c;
}


Polynomial Polynomial::operator/(Polynomial& b)
{
    Polynomial c;  // *this�� b�� �������� ����� c�� �����Ϸ��� �Ѵ�.
    Polynomial copyb; // b�� �纻
    
    int expDiff,cpos = 0;
    float coefDiff;
    while (termArray[0].exp >= b.termArray[0].exp) { //���� ���׽��� �ְ����� ������ ������ ���׽��� �ְ����� �������� ���� �� ����.
        expDiff = termArray[0].exp - b.termArray[0].exp;
        coefDiff = termArray[0].coef / b.termArray[0].coef;
        c.NewTerm(coefDiff, expDiff); //������ ��� c�� ����.
        for (int i = 0; i < b.terms; i++) { //b�� �� ������.
            copyb.NewTerm(b.termArray[i].coef, b.termArray[i].exp);
        }
        for (int i = 0; i < b.terms; i++) { 
            copyb.termArray[i].exp += expDiff; //������ ���̸�ŭ ���ؼ� �ְ����� ���� ����.
            copyb.termArray[i].coef *= -coefDiff; //����� ���̸�ŭ ���ؼ� �ְ����� ��� ���߰� ���� ���� ���� ����.
        }
        *this = *this + copyb; // ���� ����. �ְ������� �����ǰ� �������� Ŭ������ �ٽ� ����.
    }
    return c;
}
