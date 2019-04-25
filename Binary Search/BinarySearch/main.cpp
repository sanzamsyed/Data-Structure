#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

void InputArray(int array[], int length)
{
    array[0] = - pow(2,31);
    for(int i = 1; i <= length; i++)
    {
        array[i] = rand() % 20;
    }
    
}

void ViewElements(int array[], int length)
{
    for(int i = 1; i <= length; i++)
    {
        cout << array[i] << "    ";
    }
    
    cout << endl;
}

void InsertionSort(int array[], int length)
{
    int temp = 0;
    int  i = 0;
    for(int j = 2; j <= length; j++)
    {
        temp = array[j];
        i = j - 1;
        
        while(array[i] > temp)
        {
            array[i+1] = array[i];
            i = i - 1;
        }
           array[i+1] = temp;
        
        
    }
 
}

void BinarySearch(int array[], int length, int searchItem)
{
    int start = 0;
    int end = length;
    int mid = 0;
    bool found = false;
    while(start <= end)
    {
        mid = (start + end)/2;
        
        if(searchItem == array[mid])
        {
            found = true;
            cout << "Element found at index " << mid << " ! " << endl;
            break;
        }
        
        else if(searchItem > array[mid])
        {
            start = mid + 1;
        }
        
        else
        {
            end = mid - 1;
        }
        
    }
    
    if(!found) cout << "Element not found :( " << endl;
}



int main()
{
    int length;
    int searchItem;
    cout << "How many elements ? " << endl;
    cin >> length;
    int array[length];
    InputArray(array,length);
    InsertionSort(array,length);
    ViewElements(array,length);
    cout << "What's the number you want to search ? " << endl;
    cin >> searchItem;
    BinarySearch(array,length,searchItem);
    
    
}
