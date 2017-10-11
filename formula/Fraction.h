#ifndef FRACTION_H_
#define FRACTION_H_
#include <iostream>
using  namespace std;

class Fraction {

public:
    Fraction(int molecular = 1, int denomilator = 1);    //���캯��
    virtual ~Fraction() {};    //�麯��
    float GetValue() const;    //��ȡ����ֵ
    void Simplification();     //����
    void Show();               //��ʾ����
    friend ostream& operator <<(ostream& os, Fraction& f);
    //�����������������
    Fraction operator +(const Fraction& f)const;
    Fraction operator -(const Fraction& f)const;
    Fraction operator *(const Fraction& f)const;
    Fraction operator /(Fraction f)const;
    //���رȽϲ�����,�����������żӷ�ʱ�жϷ���
    bool operator ==(const Fraction& f)const;
    bool operator >(const Fraction& f)const;
    bool operator <(const Fraction& f)const;
    Fraction GetReciprocal();//��ȡ�����ĵ���
    void ChangeValue(int molecular, int denomilator); //�ı䵱ǰ�������Ӻͷ�ĸ

    string Fraction2String();

protected:

private:
    int molecular;      //����
    int denomilator;    //��ĸ
    bool isNegative;  //�Ƿ�Ϊ����
};
#include "Fraction.cpp"
#endif;


