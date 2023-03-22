/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly williams
 *
 * Created on March 2, 2023, 11:40 PM
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int c;
    int i;
    int n;
    int m=1;
    int sum = 0;
    cout << "please enter the index of summation: ";
    cin >> m;
    cout << endl <<"please enter the limit of summation: ";
    cin >> n;
    cout << endl << "please enter the constant you would like to sum: ";
    cin >> c;
    cout << endl << "thank you :)" << endl << "using for loop: " << endl;
    //using for loop
    for (int i=1; i<=n; i++){
        if (m == i){
            sum = sum + c;
            m++;
        }
    }
    
    cout << sum << endl;
   //reset values 
    m = 1;
    sum = 0;
    //derived formula
    sum = c*n - c*(m-1);
    
    cout << "using formula: " << endl;
    cout << sum;
    return 0;
}

