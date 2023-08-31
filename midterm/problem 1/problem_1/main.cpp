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
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=6400;
    int array[SIZE],brray[SIZE];
    int lowRng=0,highRng=SIZE;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    
    //Sort the array the for all positions
    mrkSort(array,SIZE);
    
    //select value to search for
    int value=rand()%(highRng-lowRng+1)+lowRng;
    //set timer
    std::chrono::steady_clock::time_point beg = std::chrono::steady_clock::now();
    //do linear search
    linSrch(array,SIZE,value);
    //end timer
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    //output runtime for linear search
    cout << "Linear Search Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(end-beg).count() << "ns" << endl;
    
    //linear search operational analysis
    optot = opeq + oplus + opindx + oprel + opmin + opdiv;
    cout << "Linear Search Total Operations: " << optot << endl;
    
    //reset operational variables
    optot, opeq, oplus, opindx, oprel, opmin, opdiv = 0;
    
    //start timer
    std::chrono::steady_clock::time_point begins = std::chrono::steady_clock::now();
    //do binary search
    binSrch(brray,SIZE,value);
    //end timer
    std::chrono::steady_clock::time_point ends = std::chrono::steady_clock::now();
    //output runtime for binary search
    cout << "Binary Search Runtime: " << std::chrono::duration_cast<std::chrono::nanoseconds>(ends-begins).count() << "ns" << endl;
    
    //binary search operational analysis
    optot = opeq + oplus + opindx + oprel + opmin + opdiv;
    cout << "Binary Search Total Operations: " << optot << endl;

    //Exit
    return 0;
}

//binary search
int  binSrch(int a[],int n, int val){
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    opeq++;
    opeq++;
    opmin++;
    //Loop until value found not indexes
    do{
        //from while
        oprel++;
        opeq++;
        //continue
        int middle=(highEnd+lowEnd)/2;
        opeq++;
        opdiv++;
        if(val==a[middle])
        {
            opeq++;
            opindx++;
            return middle;
        }
        else if(val>a[middle])
        {
            oprel++;
            opindx++;
            lowEnd=middle+1;
            opeq++;
            oplus++;
        }
        else 
        {
            highEnd=middle-1;
            opeq++;
            opmin++;
        }
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

//linear search
int  linSrch(int a[],int n, int val){
    
    opeq++; //from index=0
    oprel++; //from indx<n
    
    for(int indx=0;indx<n;indx++){
        oplus++; //from indx++
        if(val==a[indx])return indx;
        opeq++; //from val==
        opindx++; //from a[indx]
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}