/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on April 16, 2023, 10:33 PM
 */

//System Libraries
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char** argv) {
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
     
         stack.pop();
    stack.pop();
 
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    }
    
    return 0;
}