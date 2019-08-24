#include<iostream>
using namespace std;
struct node
{
    int data;
    node * next;
};
class linkedlist
{
    node * head;
public:
    linkedlist()
    {
        head=NULL;
    }
    void insertbeg(int x)
    {
        node * first = new node;
        //cin>>x;
        first->data=x;
        first->next=NULL;
        first->next=head;
        head=first;
    }
    void insertend(int x)
    {
        node * last = new node;
        //cin>>x;
        last->data=x;
        last->next=NULL;
        node* current = head;
        if(head==NULL)
        {
            head=last;
        }
        else
        {
        while(current->next != NULL)
        {
             current =current->next;
        }

        current->next = last;
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
        node * temp=head;
        node * temp2=head;
        while(temp->next->next!=NULL)
            {
                temp=temp->next;
                temp2=temp->next;
            }
            delete temp2;
            temp->next=NULL;
    }
    /*void create()
    {
        cout<<"";
    }*/
    void insertpos(int x,int pos)
    {
        node * temp3=new node;
        node * temp4=new node;
        int i=1;
        temp3=head;
        if(pos==0)
            insertbeg(x);
        else
            {
           while(i<pos)
           {
               temp3=temp3->next;
               i++;
           }
           temp4->data=x;
           temp4->next=temp3->next;
           temp3->next=temp4;
        }

    }
    void delpos(int pos)
    {
        if(head==NULL)
        cout<<"empty"<<endl;
        else
        {
        node* temp3=head;
        node* temp4=head;
        int i=1;
        if(pos==1)
            delbeg();
        else
        {
        while(i<pos)
        {
			if(i==1)
			{
			    temp4=temp4->next;
            }
			else
            {
            temp3=temp3->next;
            temp4=temp3->next;
            }
            i++;
        }
        temp3->next=temp4->next;
        delete(temp4);
        }
        }
    }
    void display()
    {
        node * temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data;
            temp=temp->next;
        }
        if(head==NULL)
        {
            cout<<"Linked list is empty.";
        }
    }

};

int main()
{
    int i,x;
    linkedlist l;
    int pos;



        int ch=1;
        while(ch!=0)
        {


        cout<<"Enter:\n1.Insert at beginning\n2.Insert at end \n3.Insert at any position \n4.Display \n5.Delete at beginning\n6.Delete at end \n7.Delete at pos \n0.Exit"<<endl;
        cin>>ch;

        if(ch==1)
        {
            cout<<"enter value"<<endl;
            cin>>x;
            l.insertbeg(x);
        }

        else if(ch==2)
        {
        cout<<"enter value"<<endl;
        cin>>x;
        l.insertend(x);
        }

        else if(ch==3)
        {
            cout<<"enter position and value"<<endl;
            cin>>pos>>x;
            l.insertpos(x,pos);
        }

        else if(ch==4)
        {
            l.display();
        }
        else if(ch==5)
        {
            l.delbeg();
        }
        else if(ch==6)
        {
            l.delend();
        }
        else if(ch==7)
        {
            cout<<"enter position "<<endl;
            cin>>pos;
            l.delpos(pos);
        }
    }
    //l.display();
}

