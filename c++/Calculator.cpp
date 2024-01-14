#include<iostream>

using namespace std;

int main()
{
    char op;
    float num1, num2; 
    cout<<"Enter operator: + , - , *, / " ;
    cin>>op;
    cout<<"Enter two number";
    cin>> num1>>num2;
    switch(op)
    {
        case '+':
        cout<<"Result::"<<num1+num2;
        break;
        case '-':
        cout<<"Result::"<<num1-num2;
        break;
        case '*':
        cout<<"Result::"<<num1*num2;
        break;
        case '/':
        cout<<"Result::"<<num1/num2;
        break;
        default:
        cout <<"!error operator is not correct" ;
        break;
    }

    return 0;
}

