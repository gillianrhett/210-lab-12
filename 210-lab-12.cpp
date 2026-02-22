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
            throw("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    
    int numItems = 0; // get the number of items the file contains
    

    int* arr = new int[numItems]; // array to store items from file

    return 0;
}