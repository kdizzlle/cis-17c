/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on April 30, 2023, 8:46 PM
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

using namespace std;

//Function Prototypes
double factorial(float);
float binomial(float, float, float);
float combi(float, float);
float simulatefair(float);
float simulateUnfair(float);

int main(int argc, char** argv) {
    //set the Random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //binomial calculation
    cout << "Binomial Theorem Calculations: " << endl << endl;
    
    //output fair dice results
    cout << "Probability of flipping a coin 4 times and getting 1 tail and 3 heads with a fair coin..." << endl;
    cout << "Binomial Theorem..." << endl;
    cout << setprecision(2) << fixed;
    cout << "P 1 Tail: " << binomial(4,1,0.5) * 100 << "%" << endl;
    cout << "P 3 Head: " << binomial(4,3,0.5) * 100 << "%" << endl;
    
    //output tricked dice results
    cout << endl <<  "Probability of flipping a coin 4 times and getting 1 tail and 3 heads with a tricked coin (60% more likely to be heads)..." << endl;
    cout << "Binomial Theorem..." << endl;
    cout << setprecision(2) << fixed;
    cout << "P 1 Tail: " << binomial(4,1,0.4) * 100 << "%" << endl;
    cout << "P 3 Head: " << binomial(4,3,0.6) * 100 << "%" << endl;
    
    //simulations
    cout << endl << endl << "Simulations for each scenario: " << endl;
    
    //declare and initialize values for simulation
    float total = 10000;
    float t = 0;
    float prob = 0;
    
    //call fair simulate function
    t = simulatefair(total);
    
    //calculate probability
    prob = t/total;
    
    //output simulation
    cout << endl << "Simulation of flipping a coin 4 times and getting 1 tail and 3 heads with a fair coin 10,000 times..." << endl;
    cout << setprecision(0) << fixed;
    cout << "Number of times situation happened out of 10,000: " << t << endl;
    cout << setprecision(2) << fixed;
    cout << "Percentage: " << prob * 100 << "%" << endl;
    
    //call unfair simulate function
    t = simulateUnfair(total);
    
    //calculate probability
    prob = t/total;
    
    //output simulation
    cout << endl << "Simulation of flipping a coin 4 times and getting 1 tail and 3 heads with a tricked coin (60% more likely to be heads) 10,000 times..." << endl;
    cout << setprecision(0) << fixed;
    cout << "Number of times situation happened out of 10,000: " << t << endl;
    cout << setprecision(2) << fixed;
    cout << "Percentage: " << prob * 100 << "%" << endl;
    
    return 0;
}
double factorial(float x) {
    if(x == 0) {
        return 1;
    }
    else if(x <= 1) {
        return x;
    }
    
    return factorial(x-1)*x;
}

float binomial(float N, float M, float P) {
    return (combi(N,M)) * pow((P), M) * pow((1-(P)), (N-M));
}

float combi(float N, float M) {
    return (factorial(N))/((factorial(M))*(factorial(N-M)));
}

float simulatefair(float total) {
    //Declare values
    int chance;
    float head, tail, t;
    //Loop to get some results
    for(int i = 0; i < total; i++) {
        //Initialize head and tail back to 0
        head = 0;
        tail = 0;
        //loop to flip coin 4 times and see if we get 3 heads and 1 tail
        for(int j = 0; j < 4; j++) {
            //Flip coin, odd or even
            chance = (rand() % 2) + 1;
            //If statement to count how many odds and evens
            if(chance % 2 == 0) {
                head++;
            }
            else {
                tail++;
            }
        }
        //see if there's 3 heads and 1 tail
        if(head == 3 && tail ==1) {
            t++;
        }
    }
    //return value
    return t;
}

float simulateUnfair(float total) {
    //Declare values
    int chance;
    float head, tail, t;
    //Loop to get some results
    for(int i = 0; i < total; i++) {
        //Initialize head and tail back to 0
        head = 0;
        tail = 0;
        //loop to flip coin 4 times and see if we get 3 heads and 1 tail
        for(int j = 0; j < 4; j++) {
            //Flip coin, odd or even
            chance = (rand() % 10) + 1;
            //If statement to count how many odds and evens
            if(chance >= 1 && chance <= 6) {
                head++;
            }
            else {
                tail++;
            }
        }
        //see if there's 3 heads and 1 tail
        if(head == 3 && tail ==1) {
            t++;
        }
    }
    //return value
    return t;
}