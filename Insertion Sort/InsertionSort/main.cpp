#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>


using namespace std;

void InputArray(int array[], int length)
{
    array[0] = -pow(2,31);
    for(int i = 1; i <= length; i++)
    {
        array[i] = rand() % 20;
    }
}

void InsertionSort(int array[], int length)
{
    int temp;
    int i;
    for(int j = 2; j <= length; j++)
    {
        temp = array[j];
        i = j - 1;
        while(array[i] > temp)
        {
            array[i+1] = array[i];
            i = i - 1;
        }
        
        array[i+ 1] = temp;
    }
}

void DisplayArray(int array[],int length)
{
    for(int i = 1; i <= length; i++)
    {
        cout << array[i] << "   ";
    }
    
    cout << endl;
}


int main()
{
    int length;
    cout << "How many elements ? " << endl;
    cin >> length;
    int array[length];
    InputArray(array,length);
    InsertionSort(array,length);
    cout << "Sorted Array : " << endl;
    DisplayArray(array,length);
}
