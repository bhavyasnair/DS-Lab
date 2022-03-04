#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*left;
struct node*right;
};
int n,i=0;
struct node*root;
struct node*search(struct node*root,int x)
{
if(root==NULL||root->data==x)
return root;
else if(root->data<x)
return search(root->right,x);
else
return search(root->left,x);
}
struct node*new_node(int x)
{
struct node*p;
p=(struct node*)malloc(sizeof(struct node));
if(p==NULL)
{
printf("\nunable to allocate memory\n");
exit(0);
}
p->data=x;
p->left=NULL;
p->right=NULL;
return p;
}
struct node*insert(struct node*root,int x)
{
if(root==NULL)
return new_node(x);
else if(root->data>x)
root->left=insert(root->left,x);
else
root->right=insert(root->right,x);
return root;
}
struct node*minimum(struct node*root)
{
if(root==NULL)
  return NULL;
if(root->left==NULL)
return root;
return minimum(root->left);
}
void inorder(struct node*root)
{
if(root!=NULL)
{
inorder(root->left);
printf("%d",root->data);
inorder(root->right);
}
}
struct node*delet(struct node*root,int x)
{
if(root==NULL)
return NULL;
if(root->data>x)
root->left=delet(root->left,x);
else if(root->data<x)
root->right=delet(root->right,x);
else
{
if(root->left==NULL&&root->right==NULL)
{
free(root);
return NULL;
}
else if(root->right==NULL||root->left==NULL)
{
struct node*temp;
if(root->left==NULL)
temp=root->right;
if(root->right==NULL)
temp=root->left;
free(root);
return temp;
}
else
{
struct node*temp;
temp=minimum(root->right);
root->data=temp->data;
root->right=delet(root->right,temp->data);
}
}
return root;
}

int main()
{
int choice,x;
printf("\nenter the number of nodes:");
scanf("%d",&n);
printf("\n1.insert\n2.delete\n3.search\n4.inorder traversal\n5.exit\n");
do
{
printf("\nenter the choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
if(i==n)
printf("\nno more insertion possible\n");
else
{
printf("\nenter data to be inserted:");
scanf("%d",&x);
if(root==NULL)
root=new_node(x);
else
insert(root,x);
i++;
printf("\nnode inserted\n");
}
break;
case 2:
 printf("\nenter data to be deleted:");
 scanf("%d",&x);
 root=delet(root,x);
 i--;
 printf("\nnode deleted\n");
 break;
case 3:
 printf("\nenter data to be searched:");
 scanf("%d",&x);
 if(search(root,x)==NULL)
 printf("\nNot found\n");
 else
 printf("\nfound\n");
 break;
 case 4:
 printf("\ninorder traversal\n");
 inorder(root);
 break;

case 5:
 exit(0);
default:
 printf("invalid choice");
 break;
 }
 }
 while(1);
 }
