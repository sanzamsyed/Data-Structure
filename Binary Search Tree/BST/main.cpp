#include <stdio.h>
#include <iostream>

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

void Search(int searchItem)
{

    
    if(root == NULL)
    {
        cout << "No element on the tree!" << endl;
    }
    
    else
    {
        Node * temp = NULL;
        temp = root;
        while(true)
        {
            if(searchItem <= temp -> data)
            {
                if(temp -> data == searchItem)
                {
                    cout << "Element found!"<< endl;
                    break;
                }
                else
                {
                    temp = temp -> leftChild;
                }
                
                if(temp == NULL)
                {
                    cout << "Not found!" << endl;
                    break;
                }
            }
            
            else
            {
                if(temp -> data == searchItem)
                {
                    cout <<"Element found!" << endl;
                    break;
                }
                
                else
                {
                    temp = temp -> rightChild;
                }
                
                if(temp == NULL)
                {
                    cout <<"Not found! " << endl;
                    break;
                }
            }
        }
    }
}


int main()
{
    root = NULL;
    
    Insert(324);
    Insert(54);
    Insert(29);
    Insert(74);
    Insert(1864);
    Search(325);
    Search(54);
    Search(30);
    
}
