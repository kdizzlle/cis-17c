/* 
 * File:   main.cpp
 * Author: Kelly Williams
 * Created on 9/18/2022 5:52pm
 * Purpose:  Even, Odd Vectors and Array Columns Even, Odd
 * Note:  Check out content of Sample conditions in Hacker Rank
 * Input size of integer array, then array, output columns of Even, Odd
 * Vectors then Even, Odd 2-D Array
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <vector>  //vectors<>
#include <iomanip> //Format setw(),right
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=2;//Only 2 columns needed, even and odd

//Function Prototypes Here
void read(vector<int> &, vector<int> &);
void copy(vector<int>, vector<int>,int [][COLMAX]);
void prntVec(vector<int>, vector<int>,int);//int n is the format setw(n)
void prntAry(const int [][COLMAX],int,int,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=80;           //No more than 80 rows
    int array[ROW][COLMAX];     //Really, just an 80x2 array, even vs. odd
    vector<int> even(0),odd(0); //Declare even,odd vectors
    
    //Input data and place even in one vector odd in the other
    read(even,odd);
    
    //Now output the content of the vectors
    //          setw(10)
    prntVec(even,odd,10);//Input even, odd vectors with setw(10);
    
    //Copy the vectors into the 2 dimensional array
    copy(even,odd,array);
    
    //Now output the content of the array
    //                              setw(10)
    prntAry(array,even.size(),odd.size(),10);//Same format as even/odd vectors
    
    //Exit
    return 0;
}
void read(vector<int> &even, vector<int> &odd){
    int n; //Numbers of integers
    cout<<"Input the number of integers to input."<<endl;
    cin>>n;
    int tarr[n]; // temp array for the vector 
    cout<<"Input each number."<<endl;
    for(int i=0; i<n; i++){ //Collects the numbers from the user
        cin>>tarr[i];
    }
    for(int i=0; i<n; i++){ //Inputs the arrays into the vectors depending on the type of number
        if(tarr[i]%2==0){
            even.push_back(tarr[i]);
        }else {
            odd.push_back(tarr[i]);
    }
}
}
void copy(vector<int> even, vector<int> odd,int array[][COLMAX]){
    int es, os;
    es=even.size(); //Even size
    os=odd.size(); //Odd Size
    for(int i=0; i<es; i++){
        array[i][0]=even[i];
    }
    for(int i=0; i<os; i++){
        array[i][1]=odd[i];
    }
}
void prntVec(vector<int> even, vector<int> odd, int s){
    int es, os; //Even Size and Odd Size
    bool change=true;
    es=even.size();
    os=odd.size();
    change=((es==os)?true:false);
    if(change){ //If there is no change is needed 
        cout<<setw(s)<<"Vector"<<setw(s)<<"Even"<<setw(s)<<"Odd"<<endl;
        for(int i=0; i<es; i++){
            cout<<setw(20)<<even[i]<<setw(10)<<odd[i]<<endl;
        }
    }else if(es>os){
        int extra;
        extra=es-os;
        cout<<setw(s)<<"Vector"<<setw(s)<<"Even"<<setw(s)<<"Odd"<<endl;
        for(int i=0; i<es-extra; i++){
            cout<<setw(20)<<even[i]<<setw(10)<<odd[i]<<endl;
        }
        for(int i=es-extra; i<es; i++){
            cout<<setw(20)<<even[i]<<"          "<<endl;
        }
    }else if(os>es){
        int extra;
        extra=os-es;
        cout<<setw(s)<<"Vector"<<setw(s)<<"Even"<<setw(s)<<"Odd"<<endl;
        for(int i=0; i<os-extra; i++){
            cout<<setw(20)<<even[i]<<setw(10)<<odd[i]<<endl;
        }
        for(int i=os-extra; i<os; i++){
            cout<<setw(30)<<odd[i]<<endl;
        }
    }
    
}
void prntAry(const int array[][COLMAX],int es,int os,int s){
    cout<<setw(s)<<"Array"<<setw(s)<<"Even"<<setw(s)<<"Odd"<<endl;
    if (es>os){
        int extra;
        extra=es-os;
        for(int i=0; i<os; i++){
            cout<<setw(s*2)<<array[i][0]<<setw(s)<<array[i][1]<<endl;
        }
        for(int i=es-extra; i<es; i++){
            cout<<setw(20)<<array[i][0]<<"          "<<endl;
        }
    }else{
        int extra;
        extra=os-es;
        for(int i=0; i<es; i++){
            cout<<setw(s*2)<<array[i][0]<<setw(s)<<array[i][1]<<endl;
        }
        for(int i=os-extra; i<os; i++){
            cout<<setw(30)<<array[i][1]<<endl;
        }
    }
}
