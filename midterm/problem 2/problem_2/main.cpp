/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Edited By: Kelly Williams
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
int opeq, oplus, opindx, oprel, optot, opmin, opdiv; //for operational analysis
//in order: equalities, plus, index, relative operators, total operations, subtraction, division

//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void bublSrt(int [],int);
void selSort(int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=200;
    int array[SIZE],brray[SIZE];
    int lowRng=0,highRng=SIZE;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);

    
    //select value to search for
    int value=rand()%(highRng-lowRng+1)+lowRng;
    //set timer
    int beg = time();

    //do bubble sort
    bublSrt(array,SIZE);
    
    //end timer
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //output runtime for bubble sort
    cout << "Bubble Sort Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-beg).count() << "ns" << endl;
    
    //bubble sort operational analysis
    optot = opeq + oplus + opindx + oprel + opmin + opdiv;
    cout << "Bubble Sort Total Operations: " << optot << endl;
    
    //reset operational variables
    optot, opeq, oplus, opindx, oprel, opmin, opdiv = 0;
    
    //start timer
    std::chrono::steady_clock::time_point begins = std::chrono::steady_clock::now();

    //do selection sort
    selSort(brray,SIZE);
    
    //end timer
    std::chrono::steady_clock::time_point ends = std::chrono::steady_clock::now();
    //output runtime for selection sort
    cout << "Selection Sort Runtime: " << std::chrono::duration_cast<std::chrono::milliseconds>(ends-begins).count() << "ns" << endl;
    
    //selection sort operational analysis
    optot = opeq + oplus + opindx + oprel + opmin + opdiv;
    cout << "Selection Sort Total Operations: " << optot << endl;

    //Exit
    return 0;
}

void bublSrt(int a[],int n){
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        swap=false;
        opeq++;
        //Check the list and Swap when necessary
        opeq++;
        oprel++;
        opmin++;
        for(int i=0;i<n-1;i++){
            oplus++;
            
            opindx++;
            oprel++;
            opindx++;
            oplus++;
            if(a[i]>a[i+1]){
                int temp=a[i];
                opeq++;
                opindx++;
                
                a[i]=a[i+1];
                
                opindx++;
                opeq++;
                opindx++;
                oplus++;
                
                a[i+1]=temp;
                opindx++;
                oplus++;
                opeq++;
                
                swap=true;
                opeq++;
            }
        }
    }while(swap);
}

void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    opeq++;
    oprel++;
    opmin++;
    for(int pos=0;pos<n-1;pos++){
        oplus++;
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        opeq++;
        opindx++;
        opeq++;
        
        opeq++;
        oplus++;
        oprel++;
        for(int i=pos+1;i<n;i++){
            oplus++;
            
            if(a[i]<min){
                opindx++;
                oprel++;
                
                min=a[i];
                opeq++;
                opindx++;
                
                indx=i;
                opeq++;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        opeq++;
        opindx++;
        
        a[pos]=min;
        opindx++;
        opeq++;
    }
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}