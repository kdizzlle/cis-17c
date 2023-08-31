/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on June 9, 2023, 3:36 PM
 */

#include <cstdlib>
#include <iostream>


using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int);


int main(int argc, char** argv) {

    char A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z;
    
    int size = 500;
    string str = " ";
    fstream file;
    file.open( "p1.dat", ios::out );
    map<int, int> stats;
    
    for ( int i = 0; i < size; i++ ) //create random 3 letter initials
    {
        str[0] = (char) ( rand( ) % 26 + 65 );
        str[1] = (char) ( rand( ) % 26 + 65 );
        str[2] = (char) ( rand( ) % 26 + 65 );
        
        file << str[0] << str[1] << str[2] << " " << endl;//store initials in file
        
        Node* root=createNode(str[0]);//first node
        
        //second node
        if(str[1] <= str[0])
        {
            root->left = createNode(str[1]);//node 2 on left
        }
        else if(str[1] > str[0])
        {
            root->right = createNode(str[1]);//node 2 on right
        }
        
        //third node
        if(str[2] <= str[0])//if node 3 is on left of node 1
        {
            if(str[1] <= str[0])//if there is already a left node
            {
                if(str[2] <= str[1])//if left of node 2
                {
                    root->left->left = createNode(str[2]);//node 3 left n1, left n2
                }
                
                else if(str[2] > str[1])//is greater than n2 on left
                {
                    root->left->right = createNode(str[2]);//node 3 left n1, right n2
                }
            }
            
            else if(str[1] > str[0])//if node 2 is on right of node 1
            {
                root->right = createNode(str[2]);//node 3 on right of n1
            }
        }
        
        if(str[2] > str[0])//if node 3 on right of node 1
        {
            if(str[1] <= str[0])//if node 2 is left node 1
            {
                root->right = createNode(str[2]);//node 3 right node 1
            }
            
            else if(str[1] > str[0])//if node 2 is also right node 1
            {
                if(str[2] <= str[1])//if node 3 is left node 2
                {
                    root->right->left = createNode(str[2]);//node 3 right left
                }
                
                else if(str[2] > str[1])//if node 3 is right node 2
                {
                    root->right->right = createNode(str[2]);//node 3 right right
                }
            }
        }
    }
    
    return 0;
}

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}