#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

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

int search( struct Node* root , int data)
{
    if(root == NULL)
        return 0;
    if( data < root->data)  
        return search( root->left , data);
    else if ( data == root->data)
        return 1;
    else if (data > root->data)
        return search(root->right , data);
}

int main()
{
    int data;
    struct Node* root = NULL;
    int nodes[] = { 4 , 7 , 21 , 6 , 9 , 1};
    for(int i = 0 ; i < sizeof(nodes)/sizeof(int) ; i++)
        root = insert( root , nodes[i] );
    inorder(root);
    printf("Enter which element you want to search : ");
    scanf("%d" , &data);
    int temp = search (root , data);
    printf("Function end!");
    if(temp == 1)
        printf("\nFOUND!");
    else
        printf("\nNot found!");
}
