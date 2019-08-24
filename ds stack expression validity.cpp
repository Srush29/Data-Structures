#include<iostream>
using namespace std;

class stack
{
    int top;
    int size;

    char stk[100];
    public:
    stack(int s)
    {
        size = s;
        top = -1;

    }
    void push(char x)
    {
        if(top>=size-1)
        cout<<"stack overflow\n";
        else
        {
        top++;
        stk[top]=x;
        }

    }
    char pop()
    {

        if(top<0)
        cout<<"stack underflow\n";
        else
        return stk[top--];

    }
    char peek()
    {
        return stk[top];
    }
    void display()
    {
        for(int i =0; i< size; i++)
        {
            cout<<stk[i]<<"\t";

        }
        cout<<"\n";

    }
    int isempty()
    {
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
        cout<<"Enter size\n";
        cin>>t;
        stack s1(t);
        cout<<"Enter the brackets Expression:\n";
        cout<<":::::::::::: And \\0 to EXIT ::::::::::::\n";
        char express[30];
        cin>>express;
        for(int i=0;i<30;i++)
        {
            if(express[i]=='\0')
                break;


        else if(express[i]=='[' || express[i]=='(' || express[i]=='{')
            s1.push(express[i]);

        else if(express[i]==']')
        {


            if(s1.peek()=='[')
            {
            s1.pop();
            }
          else
            {
            s1.fail();
            break;
             }

        }

         else if(express[i]==')')
        {


            if(s1.peek()=='(')
            s1.pop();
             else
            {
            s1.fail();
            break;
             }

        }
        else if(express[i]=='}')
        {


            if(s1.peek()=='{')
            s1.pop();
             else
            {
            s1.fail();
            break;
             }

        }

        }
        if(s1.isempty())
        {
        cout<<"Expression are VALID!!";
        }
        else
        cout<<"Expression are INVALID!!";
        return 0;
    }

