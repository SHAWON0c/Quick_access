
#include<bits/stdc++.h>
using namespace std ;

class node{

  public:
      int val ;
      node * left ;
      node * right ;
      node ( int val ){
       this-> val = val ;
       this-> left= NULL;
       this-> right = NULL;
      }


};
node * insert_tree( ){
  int val ;
  cin>> val ;
  node * root ;
  if( val ==-1)root= NULL;
  else root= new node( val );
  queue< node * > q ;
   if(root) q.push(root);

   while(!q.empty()){

        node * p = q.front();
         q.pop();

    int l , r ;
    cin>> l >> r ;

    node * myleft ;
    node * myright ;

    if( l==-1)myleft=NULL;
    else myleft= new node ( l);

    if( r==-1) myright= NULL;
    else myright = new node (r);


    p-> left= myleft ;
    p->right = myright ;

    if(p->left)q.push(p->left);
    if(p->right)q.push(p->right);
   }

   return root ;





}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
     cout << root->val << " ";
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
int main(){
    node * root = insert_tree();

    preorder(root);
    cout<<endl;

    inorder(root);
    cout<<endl;

    postorder(root);
}
