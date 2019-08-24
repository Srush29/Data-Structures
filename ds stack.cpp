#include<iostream>
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
        cout<<"OVERFLOW\n";

        else
            top++;
            stk[top]=x;

    }
    int pop()
    {
        if(top<0)
        cout<<"UNDERFLOW\n";
        else
        return
        stk[top--];
    }
    void display()
    {
        if(top<0)
        cout<<"stack is empty\n";
        else if(top==size-1)
        cout<<"stack is full\n";
        else
        {
            int i;
            for(i=0; i<=top; i++)
            {
                cout<<stk[i]<<"\t";
            }
            cout<<"\n";
        }
    }
};
int main()
{
    int size,num,opt=1;
    cout<<"enter size:\n";
    cin>>size;
    stack s1(size);
    while(opt==1)
    {
        cout<<"Want the option AGAIN!!?1.yes/0.no\n";
        cin>>opt;
        if(opt != 1)
            break;
        int ch;
        cout<<"Which one you want?\n1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n";
        cout<<"WARNING!!:::::ONLY use the numbers listed::::::\n";
        cin>>ch;
        if(ch==1)
        {
            cout<<"enter the value you have to push \n";
            cin>>num;
            s1.push(num);
        }
        else if(ch==2)
        {
            cout<<":::::::::::::::::::::::::POP:::::::::::::::::::::::::\n";
            s1.pop();

        }
        else if(ch==3)
        {
            s1.display();
        }
        else if(ch==4)
        {
            break;
        }
    }
    return 0;
}
