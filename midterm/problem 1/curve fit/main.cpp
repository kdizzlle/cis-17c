/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on May 9, 2023, 4:38 PM
 */

/*Dr. Mark E. Lehr
  Purpose:  Curve fit of Data Structure empirical timing and/or
            operational analysis
*/
#include<iostream>
#include<iomanip>
using namespace std;

//User Libraries 
#include "mArray.h"

//Global Constants - Physics, Math, Conversions, Dimensions for
//function prototypes only!

//Function Prototypes

//Execution begins here
int main(){
    //Declare the Row and Empirical Data files
    char fn_r[]="r.dat";//r file name
    mArray r(fn_r);     //Independent variable, form of the equation
    char fn_f[]="f.dat";//f file name
    mArray f(fn_f);     //Dependent variable, from empirical data run
    
    //Make the Sum of Squares Calculation c=(rt*r)^-1
    mArray rt(false,r); //Transpose of independent variable
    mArray c=mArray::invMat(rt*r)*rt*f;
    
    //Output the results
    char fn_c[]="c.dat";//c file name
    c.mPrint(fn_c);     //Where curve fit coefficients are printed
    
    return 0;
}