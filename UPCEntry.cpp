//UPCEntry.cpp
//Amrit Pandher
//12/4/2020
//UPCEntry implementation file

#include "UPCEntry.h"
#include <iostream>
using namespace std;

UPCEntry::UPCEntry(){} //default constructor

UPCEntry::UPCEntry(string entry){ //cuts off entry at comma and saves first half as upc and saves second half after comma as desc
    string delimiter = ",";
    this->upc = stoll(entry.substr(0,entry.find(delimiter)));
    entry.erase(0,entry.find(delimiter));
    entry.erase(0,1);
    this->desc = entry;
}