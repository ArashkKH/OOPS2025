/* Citation and Sources...
-----------------------------------------------------------
Workshop 02
Module: Header file for DMA module
Filename: dma.h
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

// dma.h
#ifndef SENECA_DMA_H
#define SENECA_DMA_H
#include "cstr.h"


namespace seneca {
    struct Samples {
        char* m_title;   // Dynamically allocated title
        int* m_data;     // Dynamically allocated array of integers
        int m_size;   // Number of elements in m_data
    };

    // Functions
    Samples* CreateSamples(const char* title);
    void add(Samples& S, const int data[], int size);
    void append(int*& data, int size, const int appendedData[], int dataSize);
    void freemem(Samples*& s);
}

#endif // !SENECA_DMA_H 
