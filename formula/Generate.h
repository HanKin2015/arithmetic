#ifndef GENERATE_H_
#define GENERATE_H_
#include <iostream>
#include <queue>
#include "Fraction.h"
using  namespace std;

class Generate {

public:
    Generate(int n = 1);    //���캯��
    double CalculateFunction(queue<Fraction> postFix);  //������
    void InFix_to_PostFix(queue<Fraction> inFix);  //�沨��ʽ
    virtual ~Generate() {};    //�麯��

protected:

public:
    Fraction result;      //���
    string resultString;
    string formulaString;
};
#include "Generate.cpp"
#endif;


