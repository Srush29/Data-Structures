#include<iostream>
using namespace std;
int siz = 3;
 class queue1
 {
     int r,f;
     int que[10];


  public:
      queue1()
      {
          f=r=-1;
      }



    int overflow()
    {
        if(f==(r+1)%siz)
            return 1;//overflow
        else
            return 0;
    }
        int underflow()
        {
            if(f==-1 && r==-1 )
            {
                f=-1;
                r=-1;
                return 1;
            }
            else
            {
                return 0;
            }

        }

    void del()
    {
       int x;
       if (underflow()==0)
       {
           x=que[f];
           if(f==r)
           {
            f=r=-1;
           }
            else
            {
                cout<<"element deleted is "<<x<<endl;
                f=(f+1)%siz;
            }

        }
        else{cout<<"Underflow"<<endl;}
    }

    void in(int a)
    {

        int var=overflow();

        if(overflow() == 1)
        {
            cout<<"Queue Overflow"<<endl;
        }
        else
        {
            if(f==-1 && r==-1)
            {
                f++;
                r++;
                que[r]=a;
            }
            else
            {
                r=(r+1)%siz;
                que[r]=a;
            }
        }
    }
    void display()
    {
        cout<<"front = "<<f<<endl;
        cout<<"rear ="<<r<<endl;

        int i;
        if(f==-1 && r==-1)
            cout<<"Queue is Empty"<<endl;
        else
        {
if(f<=r)
{
for(i=f;i<=r;i++)
{
cout<<"\nElement "<<i<<" is "<<que[i]<<endl;
}
}
else
{


              for(i=f;i<=siz-1;i++)
             {
        cout<<"\nElement "<<i<<" is "<<que[i]<<endl;
             }
             for(i=0;i<=r;i++)
             {
           cout<<"\nElement "<<i<<" is "<<que[i]<<endl;
             }
  }
        }
     }


};
    int main()
    {
            int choice,element;

            cout<<"Enter the size of the Queue"<<endl;
            cin>>siz;

            cout<<endl<<"SIZE OF THE QUEUE IS"<<siz<<endl;

            queue1 obj;

            do
            {

                cout<<"Enter choice "<<endl<<" 1 for Insert"<<endl<<"2 for Deleting"<<endl<<"3 for Display"<<endl<<"4 for Exit"<<endl;
                cin>>choice;

                    switch(choice)
                    {
                        case 1:
                            cout<<"Enter element to enter"<<endl;
                            cin>>element;
                            obj.in(element);
                            break;
                        case 2:
                            obj.del();
                            break;
                        case 3:
                            obj.display();
                            break;
                        case 4:
                            break;
                        default:
                            cout<<"Enter a valid option"<<endl;
                            break;
                    }

                }while(choice!=4);
        }
