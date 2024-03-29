/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimpleVector.h
 * Author: Kelly Williams
 *
 */

#ifndef SIMPLEVECTORPUSH_H
#define	SIMPLEVECTORPUSH_H

// SimpleVector class template
#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
using namespace std;

template <class T>
class SimpleVector{
    private:
       T *aptr;          // To point to the allocated array
       int arraySize;    // Number of elements in the array
       int maxSize;      // Maximum Array size before copy
       void memError();  // Handles memory allocation errors
       void subError();  // Handles subscripts out of range

    public:
       // Default constructor
       SimpleVector()
          { aptr = 0; arraySize = 0;}

       // Constructor declaration
       SimpleVector(int);
       
       // Constructor declaration
       SimpleVector(const T &);

       // Copy constructor declaration
       SimpleVector(const SimpleVector &);

       // Destructor declaration
       ~SimpleVector();

       // Access to return the array size
       int size() const
          { return arraySize; }
       
       // Access to return the max array size before copy
       int mxSize() const
          { return maxSize; }

       // Access to return a specific element
       T getElementAt(int position);

       // Overloaded [] operator declaration
       T &operator[](const int &);
       
       void push(T&);
};

//***********************************************************
// Push the new value by allocating, copying, then adding
// new value
//***********************************************************

template <class T>
void SimpleVector<T>::push(T &val)
{
   opequals++;
    if(arraySize != maxSize)
    {
         opeq,oplus,opindex,opinc,oplt,opstar = 0;
        opindex++;
        opeq++;
        opinc++;
        aptr[arraySize++]=val;
         //cout << "Total Operations for Optimized Vector: " << opindex+opeq+opinc+oplt+opstar+opequals+oplus << endl;
    }     
    else
    {
       opeq,oplus,opindex,opinc,oplt,opstar = 0;
         opstar++;
        opeq++;
        maxSize*=2;
        //Declare new array pointer
        opstar++;
        T *naptr;

        // Allocate memory for the new array.
        try{
           opeq++;
            opindex++;
          naptr = new T [maxSize];
        }catch (bad_alloc){
          memError();
        }

        //Fill the Array
        //opeq++;
        for (int count = 0; count < arraySize; count++){
           oplt++;
           opinc++;
           opindex+=2;
            opeq++;
            naptr[count]=aptr[count];
        }

        //Add new value and increment the array size
        opindex++;
        opinc++;
        opeq++;
        naptr[arraySize++]=val;

        //Delete the old array and point to new array
        opindex++;
        opeq+=2;
        delete []aptr;
        aptr=0;
        aptr=naptr;
        // cout << "Total Operations for Optimized Vector: " << opindex+opeq+opinc+oplt+opstar+opequals+oplus << endl;
    }
    
   
}

//***********************************************************
// Constructor for SimpleVector class with 1 object
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(const T &d){
   arraySize = 1;
   maxSize=1;
   // Allocate memory for the array.
   try{
      aptr = new T [arraySize];
   }catch (bad_alloc){
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++)
      aptr[count]=d;
}

//***********************************************************
// Constructor for SimpleVector class. Sets the size of the *
// array and allocates memory for it.                       *
//***********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int s){
   arraySize = s;
   maxSize=s;
   // Allocate memory for the array.
   try{
      aptr = new T [s];
   }catch (bad_alloc){
      memError();
   }

   // Initialize the array.
   for (int count = 0; count < arraySize; count++){
      int rdm=rand()%8+2;
       aptr[count]=T(rdm);
   }
}

//*******************************************
// Copy Constructor for SimpleVector class. *
//*******************************************

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj){
   // Copy the array size.
   arraySize = obj.arraySize;
   maxSize=obj.maxSize;
   
   // Allocate memory for the array.
   aptr = new T [arraySize];
   if (aptr == 0)
      memError();
      
   // Copy the elements of obj's array.
   for(int count = 0; count < arraySize; count++)
      *(aptr + count) = *(obj.aptr + count);
}

//**************************************
// Destructor for SimpleVector class.  *
//**************************************

template <class T>
SimpleVector<T>::~SimpleVector(){
   if (arraySize > 0)
      delete [] aptr;
}

//*******************************************************
// memError function. Displays an error message and     *
// terminates the program when memory allocation fails. *
//*******************************************************

template <class T>
void SimpleVector<T>::memError(){
   cout << "ERROR:Cannot allocate memory.\n";
   exit(EXIT_FAILURE);
}

//***********************************************************
// subError function. Displays an error message and         *
// terminates the program when a subscript is out of range. *
//***********************************************************

template <class T>
void SimpleVector<T>::subError(){
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

//*******************************************************
// getElementAt function. The argument is a subscript.  *
// This function returns the value stored at the sub-   *
// cript in the array.                                  *
//*******************************************************

template <class T>
T SimpleVector<T>::getElementAt(int sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

//*******************************************************
// Overloaded [] operator. The argument is a subscript. *
// This function returns a reference to the element     *
// in the array indexed by the subscript.               *
//*******************************************************

template <class T>
T &SimpleVector<T>::operator[](const int &sub){
   if (sub < 0 || sub >= arraySize)
      subError();
   return aptr[sub];
}

#endif	/* SIMPLEVECTORPUSH_H */

