#include<iostream>
#include "Fraction.h"
#include "Operation.h"
#include "OperationFactory.h"
#include "Generate.h"
#include <iomanip>
#include <sstream>

using namespace std;

bool Judge(Generate formula) {
    cout << "= ";
    string str;
    cin >> str;
    int len = str.length();
    int molecular;      //����
    int denomilator;    //��ĸ
    int number = 0;
    bool flag = false;
    bool isNegative = false;
    for(int i = 0; i < len; i++) {
        char charNumber = str[i];
        int intNumber = charNumber - '0';
        if(charNumber == '/') {
            molecular = number;
            number = 0;
            flag = true;
            continue;
        }
        if(charNumber == '-') {
            isNegative = true;
            continue;
        }
        number = number * 10 + intNumber;
    }
    if(flag) denomilator = number;
    else {
        molecular = number;
        denomilator = 1;
    }
    if(isNegative) molecular *= -1;
//    cout << molecular << ' ' << denomilator << endl;
    Fraction ans(molecular, denomilator);
    if(ans == formula.result) {
        cout << "��ȷ��" << endl << endl;
        return true;
    }
    else {
        cout << "����ȷ����ȷ�� = " << formula.result << endl << endl;
        return false;
    }
}

int main(int argc, char* argv[])
{
    srand((unsigned)time(NULL));  // �������ֵ��̬�仯

    int num = 4;    //������������
//    for (int i = 1; i <= argc; i++) {
//		string str = argv[i];
//		if(str == "-n") {
//			char *tmp = argv[i + 1];
//			num = *tmp - '0';
//		}
//	}

    cout << "���ι���" << num << "���⣬����100�֡�" << endl << endl;
    int rightNum = 0;               // ������ȷ�ĸ���
    float perScore = 100.0 / num;   // ÿ����ռ�з���
	for(int i = 0; i < num; i++) {
        cout << i + 1 << ": ";
        Generate formula;
        cout << formula.formulaString;
        bool flag = Judge(formula);
        if(flag) rightNum++;

	}
	float scores = rightNum * perScore;
	cout << endl << "���ε÷֣�" << fixed << setprecision(2) << scores << "��" << endl;
    return 0;
}


