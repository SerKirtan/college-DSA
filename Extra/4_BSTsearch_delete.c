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
    printf(" %d->", root->data);
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

struct Node* inorderSuccessor(struct Node* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root , int data)
{
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
       root->right = deleteNode(root->right, data);
    else { //Node with one or no child
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = inorderSuccessor(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
void performOperations(struct Node* root)
{
    int size , ch = 0;
    printf("Enter how many nodes you want in the BST : ");
    scanf("%d" , &size);
    int nodes[size];
    printf("Enter the node values : ");
    for ( int i = 0; i < size ; i ++)
    {
        scanf("%d" , &nodes[i]);
        root = insert(root , nodes[i]);
    }
    inorder(root);
    while(ch != 4)
    {
        int data;
        printf("\n\n1] Display Tree (Inorder)\n2]Search node\n3]Delete node\n4]End program\nEnter Operation : ");
        scanf("%d" , &ch);
        switch(ch)
        {
        case 1: 
            inorder(root);
            break;
        case 2:
            printf("\nEnter which element you want to search : ");
            scanf("%d", &data);
            if(search(root , data))
                printf("\nElement found!");
            else
                printf("Element not found!");
            break;
        case 3:
            printf("\nEnter which element you want to delete : ");
            scanf("%d", &data);
            root = deleteNode(root , data);
            printf("Deleted!");
            break;
        case 4:
            break;
        default: printf("\nInvalid input!");
        }
    }
}

int main()
{
    struct Node* root = NULL;
    performOperations(root);
}
