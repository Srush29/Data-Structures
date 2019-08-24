#include<iostream>
using namespace std;
struct node
{
    int data;
    node * next;
    node *prev;
};
class doublylinkedlist
{
    node * head;
    public:
    doublylinkedlist()
    {
        head=NULL;
    }
    int check()
{
    node* temp=head;
    int check=0;
    while(temp!=NULL)
    {
        temp=temp->next;
        check++;
    }
    return check;
}

    void insertbeg(int x)

    {

        node *temp=new node;

        node *temp1=new node;

        temp1=head;

        temp->data=x;

        temp->next=NULL;

        temp->prev=NULL;

        if(head==NULL)

            head=temp;

        else

        {

            temp1->prev=temp;

            temp->next=head;

            head=temp;

        }



    }

    void insertend(int x)

    {

        node *temp=new node;
        node *temp1=new node;

        temp1=head;

        temp->data=x;

        temp->next=NULL;

        if(head==NULL)

            head=temp;

        else

        {


            while(temp1->next!=NULL)

            {

                temp1=temp1->next;

            }

            temp->prev=temp1;

            temp1->next=temp;

        }

    }

    void insertpos(int x,int pos)
    {
        node *temp=head;
        node *ptr=new node;
        int c;

        c=check();
            if(c>pos)
            {
                cout<<"Element not FOUND!!"<<"\n";
            }
            else
            {


        ptr->data=x;
        temp=head;
        for(int i=0;i<pos;i++)
           {
               temp=temp->next;
           }

           ptr->prev=temp->prev;
           ptr->next=temp->next;
           temp->next=ptr;
            }
    }

    void delbeg()
    {
        node * temp=head;
        if(head!=NULL)
            {
                head=head->next;
                delete temp;
            }
        else
            cout<<"node not present";
    }

    void delend()
    {
        node* temp;
        node* temp1;
        temp=head;
        temp1=head;
        if(head==NULL)
        cout<<"list empty"<<"\n";
        else
        {
        while(temp1->next!=NULL)
        {
            temp=temp->next;
            temp1=temp->next;
        }
        temp->next=NULL;
        cout<<"Element deleted="<<temp1->data<<"\n";
        delete(temp1);
        }
    }
    void delpos(int pos)
    {
        node* temp;
        node* temp1;
        temp=head;
        temp1=head;
        int i,c;
        if(head==NULL)
        cout<<"list empty"<<"\n";
        else
        {
            c=check();
            cout<<c;
            if(c>pos)
            {
                cout<<"Element does not exist"<<"\n";
                return;
            }
            else if(pos==1)
            {
            delbeg();
            }
            else
            {
            for(i=1;i<pos;i++)
            {
                if(i==1)
                {
                    temp1=temp1->next;
			    }
                else
                {
                temp=temp->next;
                temp1=temp->next;
                }
            }
            temp->next=temp1->next;
            cout<<"Element deleted="<<temp1->data<<"\n";
            delete(temp1);
            }
        }
    }
    void create()
{
    int n,i,x;
    cout<<"Enter no. of nodes you want to create"<<"\n";
    cin>>n;
    cout<<"Enter Elements:"<<"\n";
    for(i=0;i<n;i++)
    {
         cin>>x;
         insertend(x);
    }

}

    void display()

    {

        node *temp=new node;

        temp=head;

        if(head==NULL)

            cout<<"\nEmpty List";

        else

        {

            while(temp!=NULL)

        {

            cout<<temp->data<<"<-->";

            temp=temp->next;

        }

        cout<<"NULL";

        }

    }

    void revdisplay()

    {

        node *temp=new node;

        temp=head;

        if(head==NULL)

            cout<<"\nEmpty List";

        else

        {

            while(temp->next!=NULL)

        {
            temp=temp->next;
        }

        while(temp!=NULL)
        {

            cout<<temp->data<<"<-->";

            temp=temp->prev;

        }

        cout<<"NULL";

        }

    }
};

int main()
{

    doublylinkedlist b1;
    int value,pos,choice=0;

    do
    {
    cout<<"1.Insert element at the beginning"<<"\n"<<"2.Insert element at position from 1"<<"\n"<<"3.Insert element at the end"<<"\n"
    <<"4.Display"<<"\n"<<"5.Display in reverse"<<"\n"<<"6.Delete at the beginning"<<"\n"<<"7.Delete at the end"<<"\n"
    <<"8.Delete at a position"<<"\n"<<"9.Insert N number of elements"<<"\n"<<"10.Exit"<<"\n";
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter the value you want to insert:"<<"\n";
        cin>>value;
        b1.insertbeg(value);
    }

    else  if(choice==2)
    {
        cout<<"Enter the position at which you want to enter the element"<<"\n";
        cin>>pos;
        cout<<"Enter the value you want to insert:"<<"\n";
        cin>>value;
        b1.insertpos(value,pos);
    }

    else  if(choice==3)
    {
        cout<<"Enter the value you want to insert:"<<"\n";
        cin>>value;
        b1.insertend(value);
    }

    else  if(choice==4)
    b1.display();
    else  if(choice==5)
    b1.revdisplay();
    else  if(choice==6)
    b1.delbeg();
    else  if(choice==7)
    b1.delend();
    else  if(choice==8)
    {
        cout<<"Enter the position at which you want to enter the element"<<"\n";
        cin>>pos;
        b1.delpos(pos);
    }

    else  if(choice==9)
    b1.create();
    }while(choice!=10);
    return 0;
}

