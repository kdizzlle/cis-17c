/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 2790755
 * Purpose: more test output format
 * Created on February 26, 2023, 6:25 PM
 */

//System Libraries - Post Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries - Post Here

//Global Constants - Post Here
//Only Universal+ Physics/Math/Conversions found here
//No Global Variables
//Higher Dimension arrays requiring definition prior to prototype only.

//Function Prototypes - Post Here

//Execution Begins Here
int main(int argc, char** argv) {
    float number; //set number to be float variable
    //first number
    cin>>number; //input number
    cout<<fixed; //fixed notation
    cout<<setw(9)<<setprecision(0)<<number; //first output precision 0
    cout<<setw(10)<<showpoint<<setprecision(1)<<number; // second output 2 precision
    cout<<setw(10)<<showpoint<<setprecision(2)<<number<<endl; //last output 3 precison. end line
    //second number
    cin>>number; //input number
    cout<<fixed; //fixed notation
    cout<<setw(9)<<noshowpoint<<setprecision(0)<<number; //first output precision 0
    cout<<setw(10)<<showpoint<<setprecision(1)<<number; // second output 2 precision
    cout<<setw(10)<<showpoint<<setprecision(2)<<number<<endl; //last output 3 precison. end line
    //third number
    cin>>number; //input number
    cout<<fixed; //fixed notation
    cout<<setw(9)<<noshowpoint<<setprecision(0)<<number; //first output precision 0
    cout<<setw(10)<<showpoint<<setprecision(1)<<number; // second output 2 precision
    cout<<setw(10)<<showpoint<<setprecision(2)<<number<<endl; //last output 3 precison. end line
    //fourth number
    cin>>number; //input number
    cout<<fixed; //fixed notation
    cout<<setw(9)<<noshowpoint<<setprecision(0)<<number; //first output precision 0
    cout<<setw(10)<<showpoint<<setprecision(1)<<number; // second output 2 precision
    cout<<setw(10)<<showpoint<<setprecision(2)<<number; //last output 3 precison
    //Exit stage left
    return 0;
}