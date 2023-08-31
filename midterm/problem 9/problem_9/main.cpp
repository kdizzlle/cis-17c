/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 */

#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;

float powerN(float x, unsigned int n)
{
    if(n == 0)return 1;
    return powerN(x,n-1)*x;
}

float powerLn(float x, unsigned int n)
{
    float a;
    if(n == 0) return 1;
    
    a = powerLn(x,n/2);
    if(n%2 == 0){
        return a*a;
    }
    else
        return a*a*x; 
}


int main(int argc, char** argv) 
{
    
    float x;
    unsigned int n = 1;
    cout << "Enter a value for x: " << endl;
    cin >> x;
    
    cout << "Enter a value for n (natural number): " << endl;
    cin >> n;
    cout << "Power function using O(logn) recusion: " << powerLn(x,n) << endl;
    cout << "Power function using O(n) recusion: " << powerN(x,n) << endl;

    return 0;
}
