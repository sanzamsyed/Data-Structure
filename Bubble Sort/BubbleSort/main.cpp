//
//  main.cpp
//  BubbleSort
//
//  Created by Arnob's on 5/8/17.
//  Copyright © 2017 Arnob's. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

int noOfComparison;
int noOfDataMovement;
double timeNeeded;
clock_t start;
clock_t finish;

void ArrayInput(int array[], int length)
{
    for(int i = 0; i < length; i++)
    {
        array[i] = rand() % 100;
    }
}

void BubbleSort(int array[],int length)
{
    start = clock();
    
    int lastSwapIndex;
    int temp;
    int k = length;
    int pass = 1;
    
    while(k!=0)
    {
        lastSwapIndex = 0;
        for(int i = 0; i < k - 1; i++)
        {
            noOfComparison++;
            if(array[i] > array[i+1])
            {
                noOfDataMovement++;
                temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                lastSwapIndex = i + 1;
            }
        }
        
        k = lastSwapIndex;
    }
    
    cout << "During pass " << pass << endl;
    
    for(int i = 0 ; i < length; i++)
    {
        cout << array[i] << "   ";
    }
    
    cout << endl << endl;
    pass++;
    
    finish = clock();
    
    timeNeeded = ((double)finish - start)/CLOCKS_PER_SEC;
}

void Display(int array[], int length)
{
    cout << "Sorted Array : " << endl;
    for(int i = 0; i < length; i++)
    {
        cout << array[i] << "   ";
    }
    
    cout << endl << endl << endl;
    
    cout << "Number of Data Comparison :  " << noOfComparison << endl;
    cout << "Number of Data Movement :  " <<noOfDataMovement << endl;
    cout << "Required Time :  " <<timeNeeded  <<" Seconds " << endl;
}

int main()
{
    int length = 8;
    //cout << "How many elements ? " << endl;
    //cin >> length;
    int array[] = {4,7,3,1,5,8,2,6};
    
    //ArrayInput(array,length);
    BubbleSort(array,length);
    Display(array,length);
    
    return 0;
}
