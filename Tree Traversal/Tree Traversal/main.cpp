#include <stdio.h>
#include <iostream>
#include <queue>


using namespace std;

struct Node
{
    int data;
    Node * leftChild;
    Node * rightChild;
};

Node * root = NULL;

void Insert(int newData)
{
    Node * newChild = new Node;
    newChild -> data = newData;
    newChild -> leftChild = NULL;
    newChild -> rightChild = NULL;
    
    if(root == NULL)
    {
        root = newChild;
    }
    
    else
    {
        Node * temp;
        temp = root;
        while(true)
        {
            if(newChild -> data <= temp -> data)
            {
                if(temp -> leftChild == NULL)
                {
                    temp -> leftChild = newChild;
                    return;
                }
                else
                {
                    temp = temp -> leftChild;
                }
            }
            
            else
            {
                if(temp -> rightChild == NULL)
                {
                    temp -> rightChild = newChild;
                    return;
                }
                
                else
                {
                    temp = temp -> rightChild;
                }
            }
        }
    }
}

void Preorder(Node *root)
{
    if (root == NULL) return;
    printf("%d ", root->data);
    Preorder(root->leftChild);
    Preorder(root->rightChild);
}

void Inorder(Node *root)
{
    if (root == NULL) return;
    Inorder(root->leftChild);
    printf("%d ", root->data);
    Inorder(root->rightChild);
}

void Postorder(Node *root)
{
    if (root == NULL) return;
    Postorder(root->leftChild);
    Postorder(root->rightChild);
    printf("%d ", root->data);
}


void Postorder(Node * root)
{
    if(root == NULL)
    {
        return;
    }
    Postorder(root -> leftChild);
    Postorder(root -> rightChild);
    cout << root -> data << endl;
}

void Inorder(Node * root)
{
    if(root == NULL)
    {
        return;
    }
    
    Inorder(root -> leftChild);
    cout << root -> data << endl;
    Inorder(root -> rightChild);
}

void Levelorder(Node* root) {
    if (root == NULL) return;
    queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        struct Node* x = q.front();
        q.pop();
        printf("%d ", x->data);
        if (x -> leftChild != NULL) q.push(x->leftChild);
        if (x -> rightChild != NULL) q.push(x->rightChild);
    }
}


int main()
{
    Insert(38);
    Insert(67);
    Insert(39);
    Insert(78);
    Insert(56);
    
    cout << "Preorder :  " << endl;
    Preorder(root);
    cout << endl;
    cout << "Postorder :  " << endl;
    Postorder(root);
    cout << endl;
    cout << "Levelorder :  " << endl;
    Levelorder(root);
    cout << endl;
    
}
