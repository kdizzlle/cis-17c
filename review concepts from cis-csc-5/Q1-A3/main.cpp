/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * Created on 3/5/23
 * Purpose:  Sorting an array of characters if specified correctly
 */

//System Libraries Here
#include <iostream>//cout,cin
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions

//Function Prototypes Here
int  read(char ray[])//reads the array and returns its size
{
    string r; //name string
    cin >> r; //get input
    strcpy(ray, r.c_str()); //copy string to array
    return r.length(); //returns length of array
}

void sort(char ray[],int size)//selection sort
{
    int minIndex,minValue;
    //exchanges elements
    for (int start=0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = ray[start];
        //sequences thru array, looks for smallest value and stores
        for (int index = start + 1; index < size; index++)
        {
            if (ray[index] < minValue)
            {
                minValue = ray[index];
                minIndex = index;
            }
        }
        swap(ray[minIndex], ray[start]);
    }
}

void print(const char ray[],int size) //prints all elements of the array
{
    for (int i=0; i < size; i++)//for each element
    {
        cout << ray[i]; //output current element
    }
    cout << endl;
}

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;//Larger than needed
    char array[SIZE]; //Character array larger than needed
    int sizeIn,sizeDet;//Number of characters to be read, check against length
    
    //Input the size of the array you are sorting
    cout<<"Read in a 1 dimensional array of characters and sort"<<endl;
    cout<<"Input the array size where size <= 20"<<endl;
    cin>>sizeIn;
    
    //Now read in the array of characters and determine it's size
    cout<<"Now read the Array"<<endl;
    sizeDet=read(array);//Determine it's size
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size to sort
    if(sizeDet==sizeIn)
    {
        sort(array,sizeIn); //Sort the array
        print(array,sizeIn);//Print the array
    }
    else
    {
        cout<<(sizeDet<sizeIn?"Input size less than specified.":
            "Input size greater than specified.")<<endl;
    }
    
    //Exit
    return 0;
}