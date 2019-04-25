#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#define size 10

using namespace std;

struct HashNode
{
    int key;
    int value;
    HashNode * link;
};

HashNode * head = NULL;

HashNode Hash_Table[size];

int HashFunction(int n)
{
    return n % size;
}

void Insert(int n)
{
    int pos = HashFunction(n);
    
    if(Hash_Table[pos].value == 0)
    {
        Hash_Table[pos].value = n;
        Hash_Table[pos].key = pos;
    }
    else
    {
        HashNode* newNode = new HashNode;
        newNode -> value = n;
        newNode -> key = pos;
        newNode -> link = Hash_Table[pos].link;
        Hash_Table[pos].link = newNode;
    }
}



void Search(int n)
{
    int pos  = n % size;
    
    if(Hash_Table[pos].value == n)
    {
        cout << "Found!" << endl;
    }
    else
    {
        head = Hash_Table[pos].link;
        while(head != NULL)
        {
            if(head -> value == n)
            {
                cout << "Found!" << endl;
                break;
            }
            else
            {
                head = head -> link;
            }
        }
        
        if(head == NULL) cout << "Not found!" << endl;
    }
}

void Display(int n)
{
    if(Hash_Table[n].value != 0)
    {
        cout << Hash_Table[n].value << endl;
        if(Hash_Table[n].link != NULL)
        {
            HashNode* temp = NULL;
            temp = Hash_Table[n].link;
            while(temp != NULL)
            {
            
                cout << temp -> value << endl;
                temp = temp -> link;

            }
        }
    }
    
    else if(Hash_Table[n].value == 0)
    {
        cout << "No entry found!" << endl;
    }
}
int main()
{
    Insert(43);
    Insert(9);
    Insert(213);
    Insert(30);
    Insert(40);
    Insert(50);
    //Search(30);
    //Search(40);
    //Search(50);
    //Search(49);
    //Search(509);
    //Search(432);
    
    Display(0);
}
