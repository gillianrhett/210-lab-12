// COMSC-210 | Lab 12 | Gillian Rhett
/*Write a program that will exercise STD::array functions. 
Code a real-world simulation of something that could be simulated by an array. 
The requirements are:
    X Use an STD::array
    X Have an external data file with at least 30 elements in it
    X Read the data into an STD::array 
    _ Use a large variety of the <array> member functions from this module 
        to demonstrate your understanding of the STD::array.*/

#include <iostream>
#include <fstream>
#include <array>
#include <string> // for the filename
using namespace std;

const string filename = "infile.txt";
const int numItems = 32;

int main() {
/* Get items from a file that stores 1 integer per line,
*  and store them in an array for the program to work with.
*  This simulates a list of inventory counts we can initially
*  get from a file then read, add, and remove items from the array.
*/
    ifstream inFile; // file object to get the items from
    // try to open the file
    try {
        inFile.open(filename, ios::in);
        if(inFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    int tempInt = 0;
    /*
    this part won't work with the array class, which needs a const
    // loop through the file once to find out the number of items
    int numItems = 0;
    while(inFile >> tempInt){
        ++numItems;
    }  
    */
    array <int, numItems> arr; // array to store items from file
    // go back to the beginning so we can store the items in the array
    inFile.clear();
    inFile.seekg(ios::beg);
    int i = 0;
    // read each int from the file and store it in the array in the same order
    while(inFile >> tempInt){ // TODO add validation in case an item is not an int
        arr.at(i) = tempInt;
        ++i;
    }
    // now the ints from the file are in the array

    // TESTING
    for (int i = 0; i < numItems; ++i)
        cout << arr.at(i) << endl;

    // TODO demonstration of array functions

    return 0;
}