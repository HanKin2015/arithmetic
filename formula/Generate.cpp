#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <stack>
#include <sstream>
#include "Fraction.h"
#include "Operation.h"
#include "ASMDOperation.h"
#include "Generate.h"
#include "OperationFactory.h"
using namespace std;

string operators[4] = {"+", "-", "+", "-"}; // ���������

//�Ƚ����������������ȼ�
int judge(string op1, string op2)
{
    if(op1 == "(") return -1;
    else if(op1 == "+" || op1 == "-") {
        if(op2 == "*" || op2 == "/")  return -1;
        else return 0;
    }
    if(op1 == "*" || op1 == "/") {
        if(op2 == "+" || op2 == "-") return 1;
        else return 0;
    }
}

//�����ʽ
void Print(Fraction tmp) {
    if(tmp.GetValue() == 1000) cout << "+";
    else if(tmp.GetValue() == 2000) cout << "-";
    else if(tmp.GetValue() == 3000) cout << "��";
    else if(tmp.GetValue() == 4000) cout << "��";
    else if(tmp.GetValue() == 5000) cout << "(";
    else if(tmp.GetValue() == 6000) cout << ")";
    else cout << tmp;
    cout << " ";
    return ;
}

//�ж��Ƿ��������
bool IsOperator(Fraction op) {
    for(int i = 1; i <= 6; i++) {
        if(op.GetValue() == i*1000)
            return true;
    }
    return false;
}

//�����ת��Ϊ�ַ���
string Transform(Fraction op) {
    float tmp = op.GetValue();
    if(tmp == 1000) return "+";
    if(tmp == 2000) return "-";
    if(tmp == 3000) return "*";
    if(tmp == 4000) return "/";
    if(tmp == 5000) return "(";
    if(tmp == 6000) return ")";
    return "number";
}

//��׺���ʽ��ֵ����
double Generate::CalculateFunction(queue<Fraction> postFix) {
    stack<Fraction> S;

    while(!postFix.empty()) {
        Fraction tmp = postFix.front();
        if(!IsOperator(tmp)) {  // ��������־ͽ�ջ
            S.push(tmp);
        }
        else {
            string op = Transform(tmp);
            Fraction numberB = S.top();
            S.pop();
            Fraction numberA = S.top();
            S.pop();

            Operation* oper;
            oper = OperationFactory::Calculation(op[0]);
            (*oper).SetNumberA(numberA);
            (*oper).SetNumberB(numberB);
            Fraction result = (*oper).GetResult();
//            cout << result << endl;
            S.push(result);
        }
        postFix.pop();
    }
    this->result = S.top();
    this->resultString = S.top().Fraction2String();
//    cout << "��:" << S.top() << endl;
    return 0;
}

// ��׺���ʽת���ɺ�׺���ʽ
void Generate::InFix_to_PostFix(queue<Fraction> inFix) {
    queue<Fraction> postFix;
    stack<Fraction> S;

    while(!inFix.empty()) {
        Fraction fraction = inFix.front();
        string tmp = Transform(fraction);
        if(tmp == "(") S.push(fraction);
        else if(tmp == ")") {
            while(S.top().GetValue() != 5000) {
                postFix.push(S.top());
                S.pop();
            }
            S.pop();
        }
        else {
            if(!IsOperator(fraction))
                S.push(fraction);
            else {
                while(!S.empty() && judge(Transform(S.top()), tmp) >= 0) {
                    postFix.push(S.top());
                    S.pop();
                }
                S.push(fraction);
            }
        }
        inFix.pop();
    }

    while(!S.empty()) {
        postFix.push(S.top());
        S.pop();
    }

    Generate::CalculateFunction(postFix);
//    cout << endl << "��׺���ʽ��";
//    cout << postFix.size();
//    while(!postFix.empty()) {
//        Fraction tmp = postFix.front();
//        Print(tmp);
//        postFix.pop();
//    }
//    cout << endl;
    return ;
}

int* GetBracketLocation(int opNum, int bracketNum) {
    int* bkLocation = new int[15];
    for(int i = 0; i < 15; i++) bkLocation[i] = 0;
//    memset(bkLocation, 0, sizeof(bkLocation));
    if(bracketNum == 1) {
        int tmp = rand() % ((opNum + 1)/ 2 + 1) + 1;   //���������������
        bkLocation[tmp] = 1;
        tmp = rand() % (opNum + 1 - tmp) + 1 + tmp; //���������ұ�����
        bkLocation[tmp] = 2;
    }
    else if(bracketNum == 2) {
        int tmp = rand() % ((opNum + 1) / 2 + 1) + 1;   //���������������
        int rightBracket = tmp;
        bkLocation[tmp] = 1;
        tmp = rand() % ((opNum + 1) / 2 + 1) + 1;
        if(tmp > rightBracket) rightBracket = tmp;  //���ұߵ�������

        if(bkLocation[tmp]) {
            bkLocation[tmp] = 11;    //ͬһ��λ��
        }
        else {
            bkLocation[tmp] = 1;
        }

        tmp = rand() % (opNum + 1 - rightBracket) + 1 + rightBracket; // ���������ұ�����
        bkLocation[tmp] = 2;
        tmp = rand() % (opNum + 1 - rightBracket) + 1 + rightBracket;
        if(bkLocation[tmp]) {
            bkLocation[tmp] = 22;
        }
        else {
            bkLocation[tmp] = 2;
        }
    }
    return bkLocation;
}

queue<Fraction> GenerateFormula(int opNum, int* bkLocation) {
    queue<Fraction> formula;
    Fraction add(1000,1);
    Fraction sub(2000,1);
    Fraction mul(3000,1);
    Fraction div(4000,1);
    Fraction lbk(5000,1);
    Fraction rbk(6000,1);

    bool preOperation = false;  //��¼ǰһ��������Ƿ�Ϊ���ţ���Ϊtrue��������������Ϊ0
    for(int j = 1; j <= opNum; j++) {
        //�ж��Ƿ�����������
        if(bkLocation[j] == 1) formula.push(lbk);
        else if(bkLocation[j] == 11) {
            formula.push(lbk);
            formula.push(lbk);
        }

        //����������
        int isFraction = rand() % 5;
        if(isFraction == 1) {
            int molecular = rand() % 10 + 1;        //����
            int denomilator = rand() % 10 + 1;       //��ĸ
            while(denomilator < molecular) denomilator = rand() % 10 + 1;
            Fraction number(molecular, denomilator);
            formula.push(number);
        }
        else {
            int molecular = rand() % 11;
            while(preOperation && molecular == 0) {
                molecular = rand() % 11;
            }
            Fraction number(molecular, 1);
            formula.push(number);
        }

        //�ж��Ƿ�����������
        if(bkLocation[j] == 2) formula.push(rbk);
        else if(bkLocation[j] == 22) {
            formula.push(rbk);
            formula.push(rbk);
        }

        //���������
        switch(rand() % 4){
            case 0:
                formula.push(add);
                preOperation = false;
                break;
            case 1:
                formula.push(sub);
                preOperation = false;
                break;
            case 2:
                formula.push(mul);
                preOperation = false;
                break;
            case 3:
                formula.push(div);
                preOperation = true;
                break;
        }
    }

    //����������
    int isFraction = rand() % 5;
    if(isFraction == 0) {
        int molecular = rand() % 10 + 1;        //����
        int denomilator = rand() % 10 + 1;       //��ĸ
        while(denomilator < molecular) denomilator = rand() % 10 + 1;
        Fraction number(molecular, denomilator);
        formula.push(number);
    }
    else {
        int molecular = rand() % 11;
        while(preOperation && molecular == 0) {
            molecular = rand() % 11;
        }
        Fraction number(molecular, 1);
        formula.push(number);
    }

    //�ж��Ƿ�����������
    if(bkLocation[opNum + 1] == 2) formula.push(rbk);
    else if(bkLocation[opNum + 1] == 22) {
        formula.push(rbk);
        formula.push(rbk);
    }
    return formula;
}

Generate::Generate(int n) {
    for(int i = 1; i <= n; i++) {
        int opNum = rand() % 4 + 1;  //������ĸ���1-10
        int bracketNum = 0;           //���ŵĸ���0-2,������������й�,Ĭ��Ϊ0
        if(opNum >= 4) {
            bracketNum = rand() % 3;
        }
        else if(opNum >= 2) {
            bracketNum = rand() % 2;
        }

        int* bkLocation = new int[15];
        bkLocation = GetBracketLocation(opNum, bracketNum);  //����λ���������

        queue<Fraction> formula;
        formula = GenerateFormula(opNum, bkLocation);

        queue<Fraction> tmd;
        tmd = formula;

        string str = "";
        while(!formula.empty()) {     // �����ʽ
            Fraction tmp = formula.front();
            if(IsOperator(tmp)) {
                string s = Transform(tmp);
                if(s == "/") s = "��";
                str += s;
            }
            else str += tmp.Fraction2String();
            str += " ";
//            Print(tmp);
            formula.pop();
        }
        this->formulaString = str;

        InFix_to_PostFix(tmd);
    }
    return ;
}


