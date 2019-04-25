#include <stdio.h>
#include <iostream>

using namespace std;

int  size;
int *stackAr;
int top = -1;

void push()
{
    if(top == size - 1)
    {
        cout << "Stack overflow! " << endl;
    }
    
    else
    {
        int element;
        cout <<"What's the element you want to enter ? " << endl;
        cin >> element;
        top++;
        stackAr[top] = element;
    }
        
}

void pop()
{
    if(top == -1)
    {
        cout << "Stack is Empty! " << endl;
    }
    
    else
    {
        cout << "The popped out element is  " << stackAr[top] << " " << endl;
        top--;
    }
    
}

void display()
{
    if(top == -1 )
    {
        cout << "Stack is Empty :( " << endl;
    }
    
    else
    {
        for(int i = top; i >= 0; i--)
        {
            cout << stackAr[i] << "     ";
        }
        
        cout << endl;
    }
}

int main()
{
    int length;
    cout << "Stack's Size? " << endl;
    cin >> length;
    int array[length];
    size = length;
    stackAr = array;
    
    while(true)
    {
        cout << "Press 1 to Enter an Element " << endl;
        cout << "Press 2 to Delete an Element " << endl;
        cout << "Press 3 to Display your  Stack " << endl;
        cout << "Press 4 to Quit" << endl;
        cout << endl << endl;
        
        int userInput;
        cin >> userInput;
        
        if(userInput == 1)
        {
            push();
            cout << endl;
        }
        else if(userInput == 2)
        {
            pop();
            cout << endl;
        }
        else if(userInput == 3)
        {
            display();
            cout << endl;
        }
        
        else if(userInput == 4)
        {
            break;
        }
        
        else
        {
            cout << "Wrong chocie! Try again! " << endl;
            cout << endl;
        }
        
        
        
    }
    
}
