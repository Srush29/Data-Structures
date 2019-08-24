#include<iostream>
using namespace std;
int count=1;
struct node
{
    int id;
    string name;
    node*left;
    node*right;
}*root=NULL;
class binarysearchtree
{
  public:
    node* insertion(node* newnode,int x,string n)
    {
        if(newnode == NULL)
        {
            newnode = new node;
            newnode->id = x;
            newnode->name=n;
            newnode->left = NULL;
            newnode->right = NULL;
        }
        else if(x < newnode->id)
            newnode->left = insertion(newnode->left,x,n);
        else if(x > newnode->id)
            newnode->right = insertion(newnode->right,x,n);
        else if(x==newnode->id)
            cout<<"\nDuplicate Elements not Allowed.\n";
        return newnode;
    }
//------------------------------------------------------------------------
    void preorder(node*root)
    {
        if(root!=NULL)
        {
            cout<<"\n"<<root->id<<"::"<<root->name;
            preorder(root->left);
            preorder(root->right);
        }
    }
//------------------------------------------------------------------
    void inorder(node*root)
    {
        if(root!=NULL)
        {
            inorder(root->left);
            cout<<"\n"<<root->id<<"::"<<root->name;
            inorder(root->right);
        }
    }
//-----------------------------------------------------------------------------------------------------
    void postorder(node*root)
    {
        if(root!=NULL)
        {
            postorder(root->left);
            postorder(root->right);
            cout<<"\n"<<root->id<<"::"<<root->name;
        }
    }

//---------------------------------------
node* search1( int x, node *root )
{


             if ( root==NULL ||x == root->id )
                {
                return root;
                }

             if ( x > root->id )
                {
                return search1( x, root->right );

                }



                return search1( x, root->left );



}

};
int main()
{
  binarysearchtree b;
  node*root =  NULL;
  node*temp =  NULL;
  int n,i,x;
  int choice,c=1,s;
  string na;
  //cout<<"Enter Size of Tree:\n";
 // cin>>n;

  while(c==1)
  {
      cout<<"\nEnter Choice:\n1.Insert The Element\n2.Preorder Display\n3.Inorder Display\n4.Postorder Display\n5.Search The Element\n0.Exit\n";
      cin>>choice;
      if(choice==1)
        {
        cout<<"\nEnter Element:\n";
        cin>>x;
        cout<<"\nEnter Name:\n";
        cin>>na;
        root = b.insertion(root,x,na);
        }
      else if(choice==2)
        b.preorder(root);
      else if(choice==3)
        b.inorder(root);
      else if(choice==4)
        b.postorder(root);
      else if(choice==5)
      {
        cout<<" Enter Number to be searched : ";
                    cin>>s;


                        cout << "For id "<<s<<" Name is "<< b.search1(s,root)->name << endl;


      }

      else
        {break;}
        cout<<"\nDo You Want the Menu again?\n1.Yes\n0.No\n";
        cin>>c;
  }
  return 0;
}



