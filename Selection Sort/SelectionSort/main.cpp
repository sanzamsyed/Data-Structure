#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void InputArray(int array[], int length)
{
    array[0] = -21;
    
    for(int i = 1; i <= length; i++)
    {
        array[i] = rand() % 20;
    }
}

void ViewElements(int array[],int length)
{
    for(int i = 1; i <= length; i++)
    {
        cout << array[i] << "    ";
    }
    
    cout << endl;
}

void SelectionSort(int array[], int length)
{
    int temp = 0;
    for(int j = length; j >= 2; j-- )
    {
        temp = 1;
        for(int k = 2; k <= j; k++)
        {
            if(array[temp] < array[k])
            {
                temp = k;
            }
            
        }
        
        swap(array[j],array[temp]);

        
        
    }
}


int main()
{
    int length;
    cout << "How many elements ?" << endl;
    cin >> length;
    int array[length];
    InputArray(array,length);
    SelectionSort(array,length);
    ViewElements(array,length);
}
