/**
 *  OOP244 Workshop 10 lab: DynaCopy
 *  File	dynacopy.cpp
 *  Version 1.0
 *  Author Arash Kheirollahi
 *  Description:
 *      The header file for DynaCopy functions
 *      
 *  Revision History:
 *  -----------------------------------------------------------
 *  Name            Date            Reason
 *  0.01           2025-08-7      workshop submission
 ___________________________________________________________ */


#if !defined(DYNACOPY_H)
#define DYNACOPY_H
#include <iostream>
using std::cout;
using std::endl;

 
 namespace seneca{
     
    template <typename T>
    T* dynaCopy(T*& ref , const T* src , int size);


    template <typename T>
    T* dynaCopy(const T* src , int size){
        T* newArr = nullptr;
        dynaCopy(newArr , src , size);
        return newArr;
    }

    template <typename T>
    T* dynaCopy(T*& ref , const T* src , int size){
        delete [] ref;
        ref = nullptr;

        if(src){
            ref = new T[size];
            for (int i = 0; i < size; i++)
            {
                ref[i] = src[i];
            }
        }
        return ref;        
    }

    template <typename T>
    void prnArray(const T* src , int size){
        for (int i = 0; i < size; i++)
        {
            cout << src[i];
            if (i < size - 1) cout << ", ";
        }

        cout << endl;  
    }

 }
 
 #endif // DYNACOPY_H
 