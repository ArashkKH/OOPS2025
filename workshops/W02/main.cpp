/* -------------------------------------------------------------------------- */
/*                     Provided Code BY SENECA POLYTECHNIC                    */
/* -------------------------------------------------------------------------- */
/***********************************************************************
// OOP244 Workshop #2: main module
//
// File        main.cpp
// Version     1.0
// Date        2025-05-20
// Author      Fardad Soleimanloo
// Description:
// A Sensor analysis program using dma module
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
***********************************************************************/
// #define DEBUG


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>        // For FILE, fopen, fscanf
#include "dma.h"
#include "sensorAnalysis.h"
#include "cstr.h"         // For strlen, strcpy

using namespace seneca;
using namespace std;
const int CHUNK_SIZE = 50;

/// <summary>
/// Reads a sensor data file and loads readings into a dynamically allocated Samples structure.
/// The first line of the file is treated as the title (prefixed by #).
/// The readings are added in chunks of 50 using the add() function.
/// </summary>
/// <param name="filename">The path to the data file.</param>
/// <returns>A dynamically allocated Samples pointer, or nullptr if the file can't be opened.</returns>
Samples* loadStats(const char* filename) {
   FILE* file = fopen(filename, "r");
   Samples* samples = nullptr;
   if (file) {

      char title[256];

      // Read the first line: title of the readings
      if (fscanf(file, "%[^\n]\n", title) != 1) {
         fclose(file);
         return nullptr;
      }

      samples = CreateSamples(title);

      int buffer[CHUNK_SIZE];
      int value;
      int count = 0;

      // Read integers in chunks of 50
      while (fscanf(file, "%d", &value) == 1) {
         buffer[count++] = value;

         if (count == CHUNK_SIZE) {
            add(*samples, buffer, count);
            count = 0;
         }
      }

      // Add the remaining integers if any
      if (count > 0) {
         add(*samples, buffer, count);
      }

      fclose(file);
   }
   return samples;
}

#ifdef DEBUG
void testCreateSamples() {
    std::cout << "Test: CreateSamples()... ";

    const char title[] = "Test Data Set";
    Samples* s = CreateSamples(title);

    bool ok = s && s->m_title && strcmp(s->m_title, title) == 0
              && s->m_data == nullptr && s->m_size == 0;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s->m_title;
    delete s;
}

void testAppend() {
    std::cout << "Test: append()... ";

    int original[] = {1, 2, 3};
    int toAppend[] = {4, 5};
    int* data = new int[3];
    for (int i = 0; i < 3; ++i) data[i] = original[i];

    append(data, 3, toAppend, 2);

    bool ok = data[0] == 1 && data[1] == 2 && data[2] == 3 &&
              data[3] == 4 && data[4] == 5;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] data;
}

void testAdd() {
    std::cout << "Test: add()... ";

    Samples s;
    s.m_title = nullptr;
    s.m_data = nullptr;
    s.m_size = 0;

    int values1[] = {10, 20};
    int values2[] = {30};

    add(s, values1, 2); // Adds [10, 20]
    add(s, values2, 1); // Appends [30]

    bool ok = s.m_size == 3 &&
              s.m_data[0] == 10 &&
              s.m_data[1] == 20 &&
              s.m_data[2] == 30;

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;

    delete[] s.m_data;
}

void testFreemem() {
    std::cout << "Test: freemem()... ";

    Samples* s = new Samples;
    s->m_title = new char[6];
    strcpy(s->m_title, "Hello");

    s->m_data = new int[3]{1, 2, 3};
    s->m_size = 3;

    freemem(s);

    bool ok = (s == nullptr);

    std::cout << (ok ? "PASS" : "FAIL") << std::endl;
}


#endif // DEBUG






int main() {
   
   #ifndef DEBUG
   const char* filename = "sensor_readings.txt";

   Samples* sample = loadStats(filename);

   if (sample) {
      cout << "--- Sensor Analysis Report ---\n";
      cout << "Title: " << sample->m_title << "\n";
      cout << "Number of Readings: " << sample->m_size << "\n";

      double avg = averageReading(sample->m_data, sample->m_size);
      cout << "Average Temperature: " << avg << " C\n";

      int spikes = countSpikes(sample->m_data, sample->m_size);
      cout << "Spikes Detected: " << spikes << "\n";

      int drop = maxDrop(sample->m_data, sample->m_size);
      cout << "Maximum Drop Between Readings: " << drop << " C\n";

      int inRange = countInRange(sample->m_data, sample->m_size, 90, 110);
      double percent = (double)inRange / sample->m_size * 100;
      cout << "Readings in Optimal Range (90-110C): "
         << inRange << " (" << percent << "%)\n";

      cout << "--------------------------------\n";

      freemem(sample);
   }
   else {
      cerr << "Failed to load data from file: " << filename << "\n";
   }

   #endif // DEBUG

   #ifdef DEBUG
   testCreateSamples() ;
   testAppend() ;
   testAdd() ;
   testFreemem() ;
   #endif // DEBUG

   return 0;
}
