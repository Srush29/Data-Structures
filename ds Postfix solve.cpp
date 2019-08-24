#include<iostream>
#include<cmath>
using namespace std;

class stack
{
    int top;
    int size;

    int stk[100];
    public:
    stack(int s)
    {
        size = s;
        top = -1;

    }
    void push(int x)
    {
        if(top>=size-1)
        cout<<"stack overflow\n";
        else
        {
        top++;
        stk[top]=x;
        }

    }
    int pop()
    {
        if(top<0)
        cout<<"stack underflow\n";
        else
        return stk[top--];
    }
    int peek()
    {
        return stk[top];
    }
    void display()
    {
        for(int i =0; i< size; i++)
        {
            cout<<stk[i]<<"\t";

        }
        cout<<endl;

    }
    int emptyi()
    {
        cout<<top;
        if(top<0)
        return 1;
        else
        return 0;
    }
    void fail()
    {
        top=99;
    }
};
int main()
{
    int t;
        cout<<"Enter size"<<endl;
    cin>>t;
    stack s1(t);

        cout<<"Enter the expression.";
        char express[30];
        cin>>express;
        for(int i=0;i<30;i++)
        {

            if(express[i]>='0' && express[i]<='9')
            {
                s1.push(express[i]-48);
            }

            else if(express[i]=='+'||express[i]=='-'||express[i]=='*'||express[i]=='/'||express[i]=='^')
            {
                if(express[i]=='+')
                {
                    int x = s1.peek();
                    s1.pop();
                    int y = s1.peek();
                    s1.pop();
                    s1.push(x+y);

                }
                if(express[i]=='-')
                {
                    int x = s1.peek();
                    s1.pop();
                    int y = s1.peek();
                    s1.pop();
                    s1.push(y-x);

                }
                if(express[i]=='*')
                {
                    int x = s1.peek();
                    s1.pop();
                    int y = s1.peek();
                    s1.pop();
                    s1.push(x*y);

                }
                if(express[i]=='/')
                {
                    int x = s1.peek();
                    s1.pop();
                    int y = s1.peek();
                    s1.pop();
                    s1.push(y/x);

                }
                if(express[i]=='^')
                {
                    int x = s1.peek();
                    s1.pop();
                    int y = s1.peek();
                    s1.pop();
                    s1.push(pow(y,x));
                }
            }
        }
        cout<<"ans is "<<s1.peek();
        return 0;
}
