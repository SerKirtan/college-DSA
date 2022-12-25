#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Queue{
    struct Node* data;
    struct Queue* next;
}*front , *rear;

void push(struct Node* data)
{
    struct Queue* add = malloc(sizeof(struct Queue));
    struct Queue* ptr = rear;
    add->data = data;
    add->next = NULL;
    if( rear ==  NULL && front == NULL)
        rear = front = add;
    else{
        rear = add;
        ptr->next = rear;
        rear->next = NULL;
    }
}

struct Node* pop()
{
    if(front == NULL)
        printf("\nQueue is empty!");
    else{
        struct Queue* temp = front;
        front = front->next;
        return temp->data;
    }
}

struct Node* buildTree(struct Node* root)//{ 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
{
    int temp;
    scanf("%d" , &temp);
    if(temp == -1)
        return NULL;
    
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = temp;
    printf("Enter the left of %d :" , temp);
    newNode->left = buildTree(root);
    printf("Enter the right of %d :" , temp);
    newNode->right = buildTree(root);
    return newNode;
}

void levelOrder(struct Node* root)
{
    front = rear = NULL;
    push(root);
    push(NULL);
    while (front != NULL)
    {
        struct Node* currNode = pop();
        if(currNode == NULL)
        {
            printf("\n");
            if(front == NULL)
                break;
            else
                push(NULL);
        }
        else
        {
            printf("%d ", currNode->data);
            if(currNode->left != NULL)
                push(currNode->left);
            if(currNode->right != NULL)
                push(currNode->right);
        }
    }
}

int main()
{
    int nodes[] = { 1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1 };
    struct Node* root = NULL;
    printf("Enter element : ");
    root = buildTree(root);
    levelOrder(root);
}
