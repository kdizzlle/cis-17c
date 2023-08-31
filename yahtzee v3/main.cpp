/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on April 23, 2023, 8:37 PM
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <iterator>
#include <ctime>
#include <map>
#include <numeric> 

using namespace std;

int roll (int);
void displayHand (list<int>);
void listArray(list<int>, int []);


/*
 * 
 */
int main(int argc, char** argv) {

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    list <int> hand;
    int take;
    int dice=5;
    int size=5;
    int handArr[size];
    //welcome message and menu

    cout << "Welcome to Yahtzee!\n";
    
    while(dice > 0)//while there's still dice to be rolled
    {
            
        cout << "\nShaking the cup...\n"
                "\nOn the table:\n";
        //roll the dice
        map <int, int> table;
        for (int i=0; i<dice; i++)
        {
            table.insert(pair<int, int>(i, roll(6)));
        }
   
        
        //output the dice rolls
        map<int, int>::iterator it;
        for (it = table.begin(); it != table.end(); it++)
        {
            cout << it->second << " ";
        }
    
        displayHand(hand);
    
        cout << endl << "Which dice would you like to take? Type 0 to reroll when done taking dice.\n"
                "Dice number: ";
        int n=1;
        for (it = table.begin(); it != table.end(); it++)
        {
            cout << n << " ";
            n++;
        }
        cout << endl;
        while(cin >> take)
        {
            if (take != 0)//if they choose to take dice
            {
                hand.push_back(table.at(take-1));
                table.erase(take-1);
                dice--;
            }
            else{//no dice taken
                cout << "Done taking dice.\n";
                break;
            }
        }
        displayHand(hand);
    }
    
    listArray(hand, handArr);
    

    
        return 0;
}

//dice roller
int roll(int sides)
{
    return 1 + ((double) rand()) / RAND_MAX * sides;
}

void displayHand(list<int> hand)
{
    hand.sort();
    cout << "\nIn your hand:\n";
    for (auto i : hand)
    cout << i << " ";
}

//turn list into array
void listArray(list<int> hand, int array[])
{
    int temp;
    for (int i=0; i<5; i++)
    {
        temp = hand.front();//assign first list term to temp int
        array[i] = temp;//set array value to temp int
        hand.pop_front();//remove first list term
    }
}