#include <stdio.h>
#include <iostream>
#define size 5

using namespace std;


int front = -1;
int back = -1;
int queue[size];



void Enqueue()
{
    if(back == size - 1)
    {
        cout << "Queue is full, sorry ! " << endl;
    }
    
    else
    {
        
        if(front == - 1)
        {
            front = 0;
        }
        
        
        int element;
        cout << "Put the element you want to enter : " << endl;
        cin >> element;
        back++;
        queue[back] = element;
    }
    
}

void Dequeue()
{
    if(front == - 1 || front > back)
    {
        cout << "Queue is Empty! " << endl;
    }
    
    else
    {
        cout << "Deleted element is : " << queue[front];
        front++;
    }
}

void Display()
{
    cout << "Your Queue at this moment is : " << endl;
    if(front == - 1 || front > back )
    {
        cout << "Queue is Empty ! " << endl;
    }
    
    else
    {
        for(int i = front; i <= back; i++)
        {
            cout << queue[i] << "    ";
        }
        
        cout << endl;
        
    }
}

int main()
{
    
    
    int userInput = 0;
    
    while(true)
    {
        cout << "Press 1 to Insert " << endl;
        cout << "Press 2 to Delete " << endl;
        cout << "Press 3 to Display " << endl;
        cout << "Press 4 to Quit " << endl;
        cout << endl << endl;
        cin >> userInput;
        
        if(userInput == 1)
        {
            Enqueue();
            cout << endl;
        }
        
        else if(userInput == 2)
        {
            Dequeue();
            cout << endl;
        }
        
        else if(userInput == 3)
        {
            Display();
            cout << endl;
        }
        
        else if(userInput == 4)
        {
            break;
        }
        
        else
        {
            cout << "Wrong input! " << endl << "Try again :) " << endl;
            
        }
        
}
    
}
