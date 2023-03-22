/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * Created on 9/17/2022 5:54pm
 * Purpose:  Summing, Finding the Max and Min of an integer array
 * Note:  Look at the output for the format for print
 */

//System Libraries Here
#include <iostream>//cin,cout
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables

//Function Prototypes Here
void read(int arr[],int size)
{
    
    for(int i=0; i < size; i++)//get input until size reached
    {
        cin >> arr[i];
    }
}

int  stat(const int arr[],int size,int& max,int& min)
{
    int sum = 0;
    max = arr[0];
    min = arr[0];
    for (int j = 0; j < size; j++)
    {
        sum += arr[j];
        if (arr[j] > max)
            max = arr[j];
        else if (arr[j] < min)
            min = arr[j];
    }
    return sum;
}

void print(const int arr[],int size,int sum,int max,int min)
{
    for (int i=0; i < size; i++)
    {
        cout << "a[" << i << "] = " << arr[i] << endl;
    }
    cout << "Min  = " << min << endl;
    cout << "Max  = " << max << endl;
    cout << "Sum  = " << sum << endl;
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;
    int array[SIZE];
    int sizeIn,sum,min,max;
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of integers find sum/min/max"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of integers
    cout<<"Now read the Array"<<endl;
    read(array,sizeIn);//Read in the array of integers
    
    //Find the sum, max, and min
    sum=stat(array,sizeIn,max,min);//Output the sum, max and min
    
    //Print the results
    print(array,sizeIn,sum,max,min);//print the array, sum, max and min

    //Exit
    return 0;
}