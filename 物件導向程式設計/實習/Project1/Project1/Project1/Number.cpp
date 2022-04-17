#include "Number.h"

Number::Number()
{
}

Number::Number(string a) : num(a) {};

Number& Number::operator=(Number a) 
{
	num = a.getNum();
	decimal = a.getDecimal();
	return *this;
}

Number Number::operator+(Number a)
{
	return Number();
}

Number Number::operator-(Number a)
{
	return Number();
}

Number Number::operator*(Number a)
{
	return Number();
}

Number Number::operator/(Number a)
{
	return Number();
}

Number Number::operator!()
{
	return Number();
}

string Number::calculate()
{
    /*
#include<iostream>
#include<sstream>
    using namespace std;

    int order(char op);
    string infixToPofix(string infix);
    int pofixComput(string pofix);

    int main()
    {
        string input;

        while (getline(cin, input))
        {
            string pofix = infixToPofix(input);//���Ǧ����Ǧ� 
            cout << pofixComput(pofix) << endl;//��Ǧ��B�� 
        }
    }

    int order(char op)
    {
        switch (op)
        {
        case'(':
            return -1;
            break;
        case '+':
        case '-':
            return 0;
            break;
        default:// * / %
            return 1;
        }
    }

    string infixToPofix(string infix)
    {
        istringstream isstream(infix);
        ostringstream pofix;
        string word;
        char opStack[1000];
        int top_Op = 0;

        while (isstream >> word)
        {
            if (isdigit(word[0]))
            {
                pofix << word << " ";//�Ʀr������X 
            }
            else//�B��l 
            {
                switch (word[0])
                {
                case '(': //���A�������i�J���| 
                    opStack[top_Op++] = word[0];

                    break;

                case ')': //�k�A�� �A��X�ܥ��A������
                    while (opStack[top_Op - 1] != '(')//�@��'('�f�t�@��')'�Atop_Op-1���j��-1 
                    {
                        pofix << opStack[--top_Op] << " ";
                    }

                    top_Op--;//���A������X  ���L

                    break;

                case '+': case'-': case '*': case '/': case '%'://�[����l 
                    if (top_Op - 1 >= 0)//�קK�W�X�}�C�d�� 
                        while (order(opStack[top_Op - 1]) >= order(word[0]) && top_Op - 1 >= 0)
                        {//�����X  ���|����ۤv�u�����B��l 
                            pofix << opStack[--top_Op] << " ";
                            //cout << "��X" << opStack[top_Op] << "top:" << top_Op;
                        }
                    //��J���|
                    //cout << "��J���|";
                    opStack[top_Op++] = word[0];

                    break;
                }
            }

        }
        //Ū������  ������X������|����
       // cout << "��X�ܪ�" ; 
        while (top_Op - 1 >= 0)
        {
            pofix << opStack[--top_Op] << " ";
            //cout << "��X" << opStack[top_Op];            
        }

        return pofix.str();
    }

    int pofixComput(string pofix)
    {
        int stack[1000];
        int top = 0;
        istringstream read(pofix);
        string word;

        while (read >> word)
        {
            if (isdigit(word[0]))
            {
                stack[top++] = atoi(word.c_str());
            }
            else
            {
                switch (word[0])
                {
                case '+':
                    stack[top - 2] = stack[top - 2] + stack[top - 1];
                    top -= 1;
                    break;
                case '-':
                    stack[top - 2] = stack[top - 2] - stack[top - 1];
                    top -= 1;
                    break;
                case '*':
                    stack[top - 2] = stack[top - 2] * stack[top - 1];
                    top -= 1;
                    break;
                case '/':
                    stack[top - 2] = stack[top - 2] / stack[top - 1];
                    top -= 1;
                    break;
                case '%':
                    stack[top - 2] = stack[top - 2] % stack[top - 1];
                    top -= 1;
                    break;
                }
            }
        }
        return stack[0];
    }
    */
}

ostream& operator << (ostream& out, Number a) {
	out << a.getNum();
	if (a.getDecimal() != "") out << '.' << a.getDecimal();
	return out;
}

