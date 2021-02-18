//UPCEntry.h
//Amrit Pandher
//12/4/2020
//UPCEntry header file

#ifndef UPC_ENTRY
#define UPC_ENTRY
#include <string>
#include <iostream>
using namespace std;

struct UPCEntry
{
    long long upc = -1;
    string desc = "";

    UPCEntry(); //default constructor
    UPCEntry(string entry); //constructor with string parameter (data)

    int hash1(int tableSize) //first hash function
    {
        return upc % tableSize;
    }

    int hash2(int tableSize) //second hash function
    {
        return abs(desc[0] + 27 * desc[1] + 729 * desc[2]) % tableSize;
    }

        //all operator overloads
    void operator=(const UPCEntry other){
        this->desc = other.desc;
        this->upc = other.upc;
    }

    bool operator>(const UPCEntry other){
        return this->upc > other.upc;
    }
    bool operator<(const UPCEntry other){
        return this->upc < other.upc;
    }
    bool operator==(const UPCEntry other){
        return this->upc == other.upc;
    }
    bool operator!=(const UPCEntry other){
        return this->upc != other.upc;
    }
    bool operator>=(const UPCEntry other){
        return ((this->upc = other.upc)||(this->upc > other.upc));
    }
    friend ostream& operator<<(ostream& os, const UPCEntry& item){
        os << "Description: " << item.desc;
        return os;
    }
};
#endif
