#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* buildTree(int nodes[])//{ 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
{
    static int idx = -1;
    idx++;
    if(nodes[idx] == -1)
        return NULL;
    
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = nodes[idx];
    newNode->left = buildTree(nodes);
    newNode->right = buildTree(nodes);
    return newNode;
}

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

int main()
{
    int nodes[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
    struct Node* root = buildTree(nodes);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
}
