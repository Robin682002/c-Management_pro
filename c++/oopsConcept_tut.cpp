#include<iostream>
using namespace std;
class ece
{
private:
    int a,b,c;
public:
   void add()
   {
    cout<<"enter values a & b";
    cin>>a>>b;
   }
   void cal()
   {
    c = a+b;
    cout<<"c is "<<c;
   }
}robin;

int main()
{
    robin.add();
    robin.cal();
    return 0;
}