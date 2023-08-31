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
void selSort(int [],int);
int findPattern(int [], list<int>);
int arraySum(int []);
void threekind(int []);
void fourkind(int []);
void fullhouse(int []);
void smstrt(int []);
void lrgstrt(int []);
void yahtzee(int []);
void chance(int []);
//void prntAry(int [],int);


/* need to make a score system
 * and validation of the player's hand
 * so when they player get s a full hand
 * sort the hand in ascending order
 * then pattern recognition and assign points
 * if no pattern, sum dice of the same number
 * highest sum is points
 * output results to user
 * 
 */
int main(int argc, char** argv) {

    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    list <int> hand;
    int take;
    int turn=0;
    //int hkey=0;
    int dice=5;
    int size=5;
    int handArr[size];
    //bool another;
    //welcome message and menu

    cout << "Welcome to Yahtzee!\n"
            "You have 3 turns to create a pattern and earn points.\n"
            "The patterns and points are:\n"
            "3 of a kind      | total of all 5 dice\n"
            "4 of a kind      | total of all 5 dice\n"
            "Full house       | 25 points\n"
            "Small straight   | 30 points\n"
            "Large straight   | 40 points\n"
            "YAHTZEE          | 50 points\n"
            "You can also sum all 5 of your dice for points if you cannot make a pattern.\n"
            "\n On the first turn, roll all 5 dice and set keepers aside.\n"
            "On the second turn, reroll ANY and ALL dice you want. Set keepers aside.\n"
            "On the third and final turn, reroll ANY and ALL dice you want and see your score.\n"
            "\n Let's Begin!\n";
    //this is where the game begins
    //game loops until player takes all the dice into their hand
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
    selSort(handArr, size);
    //prntAry(handArr, size);
    
    findPattern(handArr, hand);
    return 0;
}

//dice roller
int roll(int sides)
{
    return 1 + ((double) rand()) / RAND_MAX * sides;
}

//display hand function
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

//sort list array
void selSort(int a[],int n){
    //Loop and declare variables
    int indx,min;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        min=a[pos];indx=pos;
        for(int i=pos+1;i<n;i++){
            if(a[i]<min){
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
    }
}
/*
void prntAry(int a[],int n){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
    }
    cout<<endl;
}*/

//point system
int findPattern(int array[], list<int>list)
{
    
    bool pattern;
    //find if there are repeated numbers (mode) for 3/4 of a kind
    int count=1;
    int max=0;
    int mode=array[0];
    for (int i=0; i<4; i++)
    {
        if(array[i] == array[i+1])//if numbers match
        {
            count++;
            if(max < count)
            {
                max=count;
                mode = array[i];
            }
        }
        else
            count=1;
    }
    //find if there is a second mode
    count = 1;
    int nModes = 1;
    for(int i=0; i<4; i++)
    {
        if (array[i] == array[i+1])
        {
            count++;
            if(max == count)
                nModes++;
            else
                count = 1;
        }
    }
    
    if (max == 3)//3 of a kind and full house
    {
        if(nModes==1)
        {
            threekind(array);
            return 0;
        }
        
        if(nModes==2)
        {
            fullhouse(array);
            return 0;
        }
        
    }
    
    if (max == 4)//4 of a kind
    {
        fourkind(array);
        return 0;
    }
    
    if (max == 5)//yahtzee!
    {
        yahtzee(array);
        return 0;
    }
    
            //for the straights
        
        list.sort();//sort the hand list
        list.unique();//remove all duplicate numbers
        int listSz = list.size();
        int strt[listSz];
        listArray(list, strt);
        
        selSort(strt, listSz);
        int j=0;
        //for small straight
        if(strt[j]==1 && strt[j+1]==2 && strt[j+2]==3 && strt[j+3]==4)
        {
            smstrt(array);
            return 0;
        }
        if(strt[j]==2 && strt[j+1]==3 && strt[j+2]==4 && strt[j+3]==5)
        {
            smstrt(array);
            return 0;
        }
        if(strt[j]==3 && strt[j+1]==4 && strt[j+2]==5 && strt[j+3]==6)
        {
            smstrt(array);
            return 0;
        }
        if(strt[j]==1 && strt[j+1]==3 && strt[j+2]==4 && strt[j+3]==5 && strt[j+4]==6)
        {
            smstrt(array);
            return 0;
        }
    
        //for large straight
        else if(strt[j]==1 && strt[j+1]==2 && strt[j+2]==3 && strt[j+3]==4 && strt[j+4]==5)
        {
            lrgstrt(array);
            return 0;
        }
        else if(strt[j]==2 && strt[j+1]==3 && strt[j+2]==4 && strt[j+3]==5 && strt[j+4]==6)
        {
            lrgstrt(array);
            return 0;
        }
    
        //if no pattern is found, then go for chance


            chance(array);
            
          // cout << "max: " << max << endl << endl;
}


void threekind(int array[])
{
    int points=0;
    points = arraySum(array);
    cout << "\nYou got a 3 of a kind! That gives you " << points << " points.\n"
            "Thanks for playing!\n";
}
void fourkind(int array[])
{
    int points;
    points = arraySum(array);
    cout << "\nYou got a 4 of a kind! That gives you " << points << " points.\n"
            "Thanks for playing!\n";
}
void fullhouse(int array[])
{
    int points;
    points = 25;
    cout << "\nYou got a full house! That gives you " << points << " points.\n"
            "Thanks for playing!\n";
}
void smstrt(int array[])
{
    int points;
    points = 30;
    cout << "\nYou got a small straight! That gives you " << points << " points.\n"
            "Thanks for playing!\n";
}
void lrgstrt(int array[])
{
    int points;
    points = 40;
    cout << "\nYou got a large straight! That gives you " << points << " points.\n"
            "Thanks for playing!\n";
}
void yahtzee(int array[])
{
    int points;
    points = 50;
    cout << "\nYou got a YAHTZEE! That gives you " << points << " points.\n"
            "Thanks for playing! You're a real winner!\n";
}
void chance(int array[])
{
    int points;
    points = arraySum(array);
    cout << "\nNo pattern :( Chance gives you " << points << " points.\n"
            "Thanks for playing!\n";
}

int arraySum(int a[])
{
    int sum=0;
    for (int i=0; i<5; i++)
    {
        sum = sum+a[i];
    }
    return sum;
}