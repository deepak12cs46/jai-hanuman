#include<iostream>
#include<cstdio>
using namespace std;
typedef struct bin_tree{
     int data;
     bin_tree * left;
     bin_tree * right;
}node;

void display(node * root)
{
     if(root){
cout<<root->data<<endl;
display(root->left);
display(root->right);
}
}

node *LCA(node *root, node *p, node *q) {
  if (!root) return NULL;
  if (root == p || root == q) return root;
  node *L = LCA(root->left, p, q);
  node *R = LCA(root->right, p, q);
  if (L && R) return root;
  return L ? L : R;
}
int main()
{
 node *head,*ptr;
head=new node;
head->data=5;
head->left=new node;
head->left->data=6;
head->right=new node;
head->right->data=7;
head->left->left=new node;
head->left->left->data=8;
head->left->right=new node;
head->left->right->data=9;
head->right->left=new node;
head->right->left->data=11;
head->right->right=new node;
head->right->right->data=10;
head->left->left->left=head->left->left->right=head->left->right->left=head->left->right->right=NULL;
head->right->left->left=head->right->left->right=head->right->right->left=head->right->right->right=NULL;
display(head);
ptr=new node;
ptr->data=8;
ptr->left=ptr->right=NULL;
ptr=LCA(head,head->left,ptr);
cout<<" lca is  "<<ptr->data;

     return 0;
}
