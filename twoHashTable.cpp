//twoHashTable.cpp
//Amrit Pandher
//12/4/2020
//twoHashTable implementation file

#include "twoHashTable.h"
#include "UPCEntry.h"
#include "list.h"
#include <fstream>   
#include <iostream>
using namespace std;

TwoHashTable::TwoHashTable(string filename, int size){ //creates a dynamic array of lists and integers, reads data from file and updates arrays
    this->size = size;
    arr = new List<UPCEntry>[size];
   
    lengths = new int[size];

    string line; ifstream file; UPCEntry entry;
    file.open(filename); getline(file,line);
    
    while(getline(file, line)){
        entry = UPCEntry(line);
        insert(entry);
    }
    for(int i = 0; i<size; i++){
        lengths[i] = arr[i].size;
    }
}

bool TwoHashTable::insert(UPCEntry &item){ //checks hash values with each other and appends to smaller value placement. If both are the same it appends to h1
    int h1 = item.hash1(size);
    int h2 = item.hash2(size);

    if(arr[h1].size <= arr[h2].size){
        arr[h1].InsertNode(0,item);
        return true;
    }
    if(arr[h1].size > arr[h2].size){
        arr[h2].InsertNode(0,item);
        return true;
    }
    return false;
}

Position TwoHashTable::search(UPCEntry &item){ //checks hash1 location, then hash2 location and returns the position of the item
    int h1 = item.hash1(size);
    int h2 = item.hash2(size);
    Position place;

    if(arr[h1].FindNode(item) != -1){
        place.indexInTable = h1;
        place.indexInBin = arr[h1].FindNode(item);
        return place;
    }
    else if(arr[h2].FindNode(item) != -1){
        place.indexInTable = h2;
        place.indexInBin = arr[h2].FindNode(item);
    }
    return place;
}

float TwoHashTable::getStdDev(){ //returns standard deviation
    return stddev(lengths, size);
}