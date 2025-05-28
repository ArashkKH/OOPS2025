/* Citation and Sources...
-----------------------------------------------------------
Workshop 02
Module: The dma module, which defines a Samples structure and manages its dynamic memory
Filename: dma.cpp
-----------------------------------------------------------
Author: Arash Kheirollahi
Student number: 146,731,245
Email: akheirollahi@myseneca.ca
Subject: OOP244NFF
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V0.1    2025/5/22 Workshop Initiation
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/

#include "dma.h"
#include "cstdio"
using namespace std;

namespace seneca {
    Samples* CreateSamples(const char* title){
        Samples* result = new Samples();
        // allocating Title
        size_t len = strlen(title) + 1;
        result->m_title = new char[len];
        strcpy(result->m_title, title);
        // setting m_Data
        result->m_data = nullptr;
        result->m_size = 0;
        // returning the pointer
        return result;
    }

    void add(Samples& S, const int data[], int size) {
        if (S.m_data == nullptr) {
            S.m_data = new int[size];
            for (int i = 0; i < size; ++i) {
                S.m_data[i] = data[i];
            }
            S.m_size = size;
        } else {
            append(S.m_data, S.m_size, data, size);
            S.m_size += size;
        }
    }

    void append(int*& data, int size, const int appendedData[], int dataSize) {
        int* newData = new int[size + dataSize];
        // Copy existing values
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        // Append new values
        for (int i = 0; i < dataSize; ++i) {
            newData[size + i] = appendedData[i];
        }
        // Free old array
        delete[] data;
        // Update pointer
        data = newData;
    }

    void freemem(Samples*& s) {
        delete[] s->m_title;
        delete[] s->m_data;
        delete s;
        s = nullptr;
    }
}
