// COMSC-210 | Lab 12 | Gillian Rhett
/*Write a program that will exercise STD::array functions. 
Code a real-world simulation of something that could be simulated by an array. 
The requirements are:
    Use an STD::array
    Have an external data file with at least 30 elements in it
    Read the data into an STD::array 
    Use a large variety of the <array> member functions from this module 
        to demonstrate your understanding of the STD::array.*/

#include <iostream>
#include <fstream>
#include <array>
#include <string>
using namespace std;

const string filename = "infile.txt";

int main() {
    fstream inFile; // file object to get the items from
    try {
        inFile.open(filename, ios::in);
        if(inFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    int numItems = 0;
    // loop through the file once to find out the number of items
    int tempInt;
    while(inFile >> tempInt){
        ++numItems;
    }  

    int* arr = new int[numItems]; // array to store items from file
    inFile.seekg(ios::beg); // back to the beginning so we can store the items in the array
    int i = 0;
    while(inFile >> tempInt){
        *(arr + i) = tempInt; // TODO fix this
        ++i;
    }
    // now the ints from the file are in the array

    // TESTING
    for (int i = 0; i < numItems; ++i)
        cout << *(arr + i) << endl;

    // TODO demonstration of array functions

    return 0;
}