#include <iostream>
using namespace std;

class stack
{
 int stk[100], top;
 public:
 stack()
 {
  top = -1;
 }
 void push(int x)
 {
     top++;
  stk[top]=x;
 }
 int pop()
 {
  return stk[--top];
 }
};
int main()
{
 int n, i;
 stack s;
 cout<<"Limit: ";
 cin>>n;
 for(i=n;i>0;i++)
 {
  s.push(i);
 }
 int fact = 1;
 while(n!=0)
 {
     fact=fact*s.pop();
     n--;
 }
 cout<<"Factorial: "<<fact<<endl;
 return 0;
}
