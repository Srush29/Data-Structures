#include<iostream>
using namespace std;
class queue
{
    int front,rear;
    int size;
    int que[50];
    public:
    queue(int s)
    {
        size = s;
        front = rear = -1;

    }
    void insert(int x)
    {
        if(rear==size-1)
            cout<<"OVERFLOW\n";
        else if(front==-1 && rear==-1)
        {
            front=rear=0;
            que[rear]=x;
        }

        else
        {
          rear++;
            que[rear]=x;
        }

    }
    int del()
    {int temp;
        if(front<0&&rear<0)
        cout<<"UNDERFLOW\n";

        else if(front==rear)
            {temp=que[front];
            front=rear=-1;}
        else
            temp=que[front];
            front++;
        return temp;}

    void display()
    {
        if(front==-1 && rear==-1)
        cout<<"queue is empty\n";
        //else if(rear==size-1)
        //cout<<"queue is full\n";
        else
        {
            int i;
            for(i=front; i<=rear; i++)
            {
                cout<<que[i]<<"\t";
            }
        }
    }
};
int main()
{
    int size,num,opt=1;
    cout<<"enter size:\n";
    cin>>size;
    queue q1(size);
    while(opt==1)
    {
        cout<<"\nWant the option AGAIN!!?1.yes/0.no\n";
        cin>>opt;
        if(opt != 1)
            break;
        int ch;
        cout<<"Which one you want?\n1.INSERT\n2.DELETE\n3.DISPLAY\n4.EXIT\n";
        cout<<"WARNING!!:::::ONLY use the numbers listed::::::\n";
        cin>>ch;
        if(ch==1)
        {
            cout<<"enter the value you have to INSERT \n";
            cin>>num;
            q1.insert(num);
        }
        else if(ch==2)
        {
            cout<<":::::::::::::::::::::::::DELETING:::::::::::::::::::::::::\n";
            cout<<q1.del();

        }
        else if(ch==3)
        {
            q1.display();
        }
        else if(ch==4)
        {
            break;
        }
    }
    return 0;
}
