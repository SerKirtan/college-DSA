#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

void preorder( struct Node* root)
{
    if(root == NULL){
        //printf(" -1");
        return;
    }
    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder( struct Node* root)
{
    if(root == NULL){
        //printf(" -1");
        return;
    }
    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void postorder( struct Node* root)
{
    if(root == NULL){
        //printf(" -1");
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

struct node *newNode(int data) {
  struct Node* temp = malloc(sizeof(struct Node));
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

struct Node* insert(struct Node* root , int data)
{
    if(root == NULL)
        return newNode(data);
    if(data < root->data)
        root->left = insert(root->left , data);
    else    
        root->right = insert(root->right , data);
    return root;
}

struct Node* buildBST(struct Node* root)
{
    int size;
    printf("Enter how many nodes you want to enter : ");
    scanf("%d", &size);
    int nodes[size];
    printf("Enter values : ");
    for(int i = 0 ; i < size ; i++)
    {
        scanf("%d" , &nodes[i]);
        root = insert( root , nodes[i] );
    }
    return root;
}

int main()
{
    struct Node* root = NULL;
    root = buildBST(root);
    printf("\nPreorder transversal");
    preorder(root);
    printf("\nInorder transversal");
    inorder(root);
    printf("\nPostorder transversal");
    postorder(root);
}
