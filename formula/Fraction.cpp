#include "Fraction.h"
#include <cmath>
#include <cstdlib>
#include <sstream>
#define eps 1e-7

//շת����������Լ��
int GCD(int a, int b) {
    return b == 0 ? a : GCD(b, a % b);
}

//���������
ostream& operator<<(ostream& os, Fraction& f) {  //f����һ������
    f.Simplification();     //����
    if(f.isNegative) {      //����
        if(f.denomilator == 1)
            os << "-" << f.molecular;
        else
            os << "-" << f.molecular << "/" << f.denomilator;
    }
    else {                  //����
        if(f.denomilator == 1)
            os << f.molecular;
        else
            os << f.molecular << "/" << f.denomilator;
    }
    return os;
}

//���캯����Ĭ�Ϸ���Ϊ��1
Fraction::Fraction(int a, int b): isNegative(false) {
    while(b == 0) {
        cout << "��ĸ����Ϊ0�������������ĸ:" << endl;
        cin >> b;
    }
    this->molecular = abs(a);
    this->denomilator = abs(b);
    if(a < 0 && b < 0)
        this->isNegative = false;
    else if(a < 0 || b < 0)
        this->isNegative = true;
    else
        this->isNegative = false;
    this->Simplification();
}

//�õ�����ֵ
float Fraction::GetValue() const {
    return this->molecular / (float)denomilator;
}

//��������Լ��
void Fraction::Simplification() {
    int a = molecular, b = denomilator;
    int ret = GCD(a, b);
    molecular /= ret;
    denomilator /= ret;
}

//�������
void Fraction::Show() {
    cout << *this;
}

//���ؼӺ�
Fraction Fraction::operator +(const Fraction &f) const {
    Fraction temp;
    if(isNegative == f.isNegative) { //ͬ�����
        temp.molecular = molecular * f.denomilator + denomilator * f.molecular;
        temp.denomilator = denomilator * f.denomilator;
        temp.isNegative = isNegative;
    }
    else {    // ��ͬ��
        temp.molecular = abs(molecular * f.denomilator - denomilator * f.molecular);
        temp.denomilator = abs(denomilator * f.denomilator);
        if(this->GetValue() > f.GetValue())
            temp.isNegative = isNegative;
        else
            temp.isNegative = f.isNegative;
    }
    return temp;
}

//���ؼ���
Fraction Fraction::operator -(const Fraction &f) const {
    Fraction temp;
    if(isNegative == f.isNegative) { //ͬ�����
        temp.molecular = abs(molecular * f.denomilator - denomilator * f.molecular);
        temp.denomilator = denomilator * f.denomilator;
        if(GetValue() >= f.GetValue())
            temp.isNegative = false;
        else
            temp.isNegative = true;
    }
    else {  //������
        temp.molecular = molecular * f.denomilator + denomilator * f.molecular;
        temp.denomilator = denomilator * f.denomilator;
        temp.isNegative = isNegative;
    }
    return temp;
}

//���س˺�
Fraction Fraction::operator *(const Fraction &f) const {
    Fraction temp;
    temp.molecular = molecular * f.molecular;
    temp.denomilator = denomilator * f.denomilator;
    //������ȷ������
    if(isNegative == f.isNegative) //ͬ����˷���Ϊ��
        temp.isNegative = false;
    else
        temp.isNegative = true;
    return temp;
}

//���س���
Fraction Fraction::operator /(Fraction f) const {
    Fraction temp, r;
    r = f.GetReciprocal();  //������ת��Ϊ�˷�
    temp = *this * r;
    return temp;
}

//����
Fraction Fraction::GetReciprocal() {
    Fraction temp;
    temp.denomilator = molecular;
    temp.molecular = denomilator;
    temp.isNegative = isNegative;
    return temp;
}

//���صȺ�
bool Fraction::operator ==(const Fraction &f) const {
    if(isNegative != f.isNegative) //��ͬ�ſ϶������
        return false;
    if(abs(GetValue() - f.GetValue()) < eps)
        return true;
    else
        return false;
}

//����С��
bool Fraction::operator <(const Fraction &f) const {
    if(isNegative == f.isNegative) { //ͬ�űȽϴ�С

        if(GetValue() < f.GetValue()) {
            if(isNegative)
                return false;
            else
                return true;
        }
        else if(GetValue() > f.GetValue()) {
            if(isNegative)
                return true;
            else
                return false;
        }
        else//��ȵķ���
            return false;
    }
    else if(isNegative)//������
        return true;
    else// �����Ҹ�
        return false;
}

//���ش��ڷ���
bool Fraction::operator >(const Fraction& f)const { //���ں�С�ںŸպ��෴
    return (f < *this);
}

//�ı䵱ǰ�������Ӻͷ�ĸ
void Fraction::ChangeValue(int a, int b) {
    *this = Fraction(a, b);
}

//����ת��Ϊ�ַ���
string Fraction::Fraction2String() {
    this->Simplification();
    string str = "";
    if(this->isNegative && this->molecular != 0) str += "-";    // ��ֹ����-0���
    stringstream ss;
    ss << this->molecular;
    str += ss.str();
    ss.str("");
    if(this->denomilator != 1) {
        ss << this->denomilator;
        str += "/";
        str += ss.str();
        ss.str("");
    }
    return str;
}

