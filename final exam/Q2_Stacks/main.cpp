/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * cis/csc 17c final
 * q2 - stacks
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

//global constants
int number_of_h=0;
int number_of_g=0;

//function prototypes
float g(float);
float h(float);

int main(int argc, char** argv) {

    float angDeg = 46;
    float angRad = angDeg * atan(1) / 45;
    
    number_of_g=0;
    number_of_h=0;
    
    cout << "Angle = " << angDeg << " sinh = " << sinh(angRad) << " our h = " << h(angRad) << endl;
    cout<<"h\t"<<number_of_h<<endl<<"g\t"<<number_of_g<<endl;
    
    number_of_g=0;
    number_of_h=0;
    
    cout << "Angle = " << angDeg << " cosh = " << cosh(angRad) << " our g = " << g(angRad) << endl;
    cout<<"h\t"<<number_of_h<<endl<<"g\t"<<number_of_g<<endl;
    return 0;
}

float g(float angle)
{
    number_of_g++;
    float t = 1e-6;
    
    if (angle > -t && angle < t)
        return 1 + angle * angle / 2;
    
    float bd = h(angle / 2);
    
    return 1 + 2 * bd * bd;
}

float h(float angle)
{
    number_of_h++;
    float t = 1e-6;
    
    if (angle > -t && angle < t)
        return angle + angle * angle * angle / 6;
    
    return 2 * h(angle / 2) * g(angle / 2);
}