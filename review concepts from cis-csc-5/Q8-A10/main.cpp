/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Kelly Williams
 *
 * Created on December 4, 2022, 9:42 PM
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

const int RANGE = 127;      // Range of all ASCII characters

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
int strcmp(char [],char [],const char [],const char []);//Replace sort order
int search(char [], char [], int);// Search though ascii array
int search(char [], const char [], int);
void swapIndx(int [][RANGE], char [], int);//switch indices for new sort

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }
    //Exit
    return 0;
}

int  read(char arr[][COLMAX],int &row){
    int col=0;
    
    for(int i=0;i<row;i++){
        cin>>arr[i];
    }
    
    for(int j=0;j<row;j++){
        if(strlen(arr[j])>col){
            col=strlen(arr[j]);                
        }
    }
    
    return col;
}

void sort(char array[][COLMAX], int rowIn, const char replace[], const char with[]){
    char tmp[COLMAX];
    for(int i=0;i<rowIn-1;i++) {
        int min=i;
        for(int j=i+1;j<rowIn;j++) {
            if (strcmp(array[min], array[j], replace, with) > 0) {
                min=j;
            }
        }
        if (min!=i) {
            strcpy(tmp, array[i]);
            strcpy(array[i], array[min]);
            strcpy(array[min], tmp);
        }
    }
}

void print(const char array[][COLMAX], int rowIn, int){
    for (int i=0;i<rowIn;i++){
        cout<<array[i]<<endl;
    }
}

int strcmp(char arrR1[], char arrR2[], const char replace[], const char with[]){
    char ascii[RANGE];          // Array to hold ASCII characters
    int indxArr[RANGE][RANGE];  // Array to hold the indices of replace[] and 
                                //   with[] in ascii array
    char i = 32;                // Start of printable ASCII characters
    int j = 0;                  // Counter for ascii array
    int a = 0;                  // Counter for search
    int b = strlen(replace);
    int c = strlen(with);    
    int cnt = 0;    
    int x = 0;
    int y = 0;
    int z = 0;
    int strComp = 0;
    
    int arrIndx[RANGE];
    int cmpIndx[RANGE];
    char chArr[RANGE];
    char chCmp[RANGE];    
    
    // Fill ASCII table with all possible input characters
    while(i<RANGE){
        ascii[j]=i;
        i++;
        j++;
    }
    // Search through index for character replace

    do{
        indxArr[0][a]=search(ascii,replace,cnt);
        indxArr[1][a]=search(ascii,with,cnt);
        a++;
        cnt++;
    }while(a<b && a<c);
    // Switch Indices
    do{
        swapIndx(indxArr, ascii, x);
        x++;
    }while(x<cnt);
    // Compare arr1 to arr2, reference ascii array
    do{
        arrIndx[z]=search(ascii,arrR1,z);
        cmpIndx[z]=search(ascii,arrR2,z);
        z++;
    }while(z<strlen(arrR1) && strlen(arrR2));
    
    while(arrIndx[y]==cmpIndx[y]){
        y++;
    }
    if(arrIndx[y]!=cmpIndx[y]){
        strComp = arrIndx[y]-cmpIndx[y];
    }
    // Return comp, if -1 arr is before comp else 1
    return strComp;
}

int search(char ascii[], char arr[], int count){
    bool found = false;
    char val;
    int indx = 0;
    int position=-1;        
        
    val = arr[count];
    while(indx < strlen(ascii) && !found){
        if(ascii[indx]==val){
            found=true;
            position = indx;
        }
        indx++;
    }    

    return position;
}

int search(char ascii[], const char arr[], int count){
    bool found = false;
    char val;
    int indx = 0;
    int position=-1;        
        
    val = arr[count];
    while(indx < strlen(ascii) && !found){
        if(ascii[indx]==val){
            found=true;
            position = indx;
        }
        indx++;
    }    

    return position;
}

void swapIndx(int indx[][RANGE], char ascii[], int x){
    char tmp[RANGE];      
    int val1 = indx[0][x];
    int val2 = indx[1][x];

    tmp[x]=ascii[val1];
    ascii[val1]=ascii[val2];
    ascii[val2]=tmp[x];    
}