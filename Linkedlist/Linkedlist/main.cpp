// Link List -> Insert + Delete + Print
// CSE-2104
// Data Structure Lab
// Assignment - 05
//  Created by Syed Sanzam (16.01.04.042)

#include <stdio.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* link;
};

Node* head = NULL;

void Insert()
{
    Node* newNode = new Node;
    int insertElement;
    cout << "What is the element you want to insert? " << endl;
    cin >> insertElement;
    newNode -> data = insertElement;
    
    if(head == NULL || newNode -> data < head -> data)
    {
        newNode -> link = head;
        head = newNode;
    }
    
    else
    {
        Node* pred = head;
        Node* p = pred -> link;
        
        while(p != NULL && newNode -> data > p -> data)
        {
            pred = p;
            p = p -> link;
        }
        
        pred -> link = newNode;
        newNode -> link = p;
    }
}


void DeleteNode()
{
    int deletePosition;
    cout << "Which node do you want to delete ? " << endl;
    cin >> deletePosition;
    
    if(deletePosition == 1)
    {
        Node* temp = head;
        head = head -> link;
        delete temp;
    }
    else
    {
        Node* temp1 = head;
        Node* temp2;
    
        for(int i = 1; i <= deletePosition - 2; i++)
        {
            temp1 = temp1 -> link;
        }
    
        temp2 = temp1 -> link;
        temp1 -> link = temp2 -> link;
        delete temp2;
    }
}


void PrintList()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << "    ";
        temp = temp -> link;
    }
    
    cout << endl;
}

int main()
{
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    Insert();
    PrintList();
    DeleteNode();
    DeleteNode();
    PrintList();
    
    
}
