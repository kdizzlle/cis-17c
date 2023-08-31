/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on April 16, 2023, 10:32 PM
 */

//System Libraries
#include <algorithm>
#include <iostream>

using namespace std;

void show(int *,int);

int main(int argc, char** argv) {
    
    int a[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
   
    // size of the array
    int asize = sizeof(a) / sizeof(a[0]);
    cout << "The array before sorting is : \n";
   
    // print the array
    show(a, asize);
 
      // sort the array
    sort(a, a + asize);
 
    cout << "\n\nThe array after sorting is :\n";
   
    // print the array after sorting
    show(a, asize);
    
    return 0;
}
void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}