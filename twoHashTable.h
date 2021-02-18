//twoHashTable.h
//Amrit Pandher
//12/4/2020
//twoHashTable header file

#ifndef TWO_HASH_TABLE
#define TWO_HASH_TABLE
#include "position.h"
#include "UPCEntry.h"
#include <cmath>
#include "list.h"
using namespace std;

class TwoHashTable
{
public:
    int size = 0; 
    List<UPCEntry> *arr; //dynamic array of UPCEntry linked lists
    int *lengths; //dynamic array of integers

    TwoHashTable(string filename, int tableSize); //constructor
    bool insert(UPCEntry &item);     // returns true if successful, false otherwise.
    Position search(UPCEntry &item); // if not found, return the default position with both indices set as -1
    float getStdDev(); //returns standard deviation

private:
    float stddev(int *binLengths, int tableSize)
    {
        float sum = 0;
        for (int i = 0; i < tableSize; i++)
            sum += binLengths[i];

        float avarage = sum / tableSize;

        float dev_sum = 0;
        for (int i = 0; i < tableSize; i++)
        {
            dev_sum = dev_sum + (binLengths[i] - avarage) * (binLengths[i] - avarage);
        }

        float variance = dev_sum / tableSize;
        return sqrt(variance);
    }
};
#endif