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
#include <algorithm> // for sort and find
#include <numeric> // for accumilate
using namespace std;

const string FILENAME = "infile.txt";
const int SIZE = 32;

int main() {
/* Get items from a file that stores 1 integer per line,
*  and store them in an array for the program to work with.
*  This simulates a situation where we keep track of the
*  visitors a web page recieves each day.
*/
    ifstream inFile; // file object to get the items from
    // try to open the file
    try {
        inFile.open(FILENAME, ios::in);
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
    array <int, SIZE> visitors; // array to store items from file
    // go back to the beginning so we can store the items in the array
    inFile.clear();
    inFile.seekg(ios::beg);
    int i = 0;
    // read each int from the file and store it in the array in the same order
    while(inFile >> tempInt){ // TODO add validation in case an item is not an int
        visitors.at(i) = tempInt;
        ++i;
    }
    // now the ints from the file are in the array

    // demonstration of array functions
    cout << "Visitors per day" << endl;
    cout << "1. size function:" << endl;
    cout << "   days of data collected = " << size(visitors) << endl;
    cout << "2. at function to show 4th item: " << visitors.at(3) << endl;
    cout << "3. [] to show 4th item: " << visitors[3] << endl;
    cout << "4. range-based for loop shows original array contents:\n   ";
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "5. sort function:\n   ";
    sort(visitors.begin(), visitors.end());
    for (int item : visitors) cout << item << " ";
    cout << endl;
    cout << "6. find function:\n   ";
    cout << "searching for value 23 (appears 3 times in the array)... ";
    array<int, SIZE>::iterator it; // iterator for pointing to elements in the array
    it = find(visitors.begin(), visitors.end(), 23);
    if (it != visitors.end())
        cout << "found at position " << it - visitors.begin() << endl;
    else
        cout << "value not found" << endl;
    
        cout << "   searching for value 100 (is not in the array)... ";
    it = find(visitors.begin(), visitors.end(), 100);
    if (it != visitors.end())
        cout << "found at position " << it - visitors.begin() << endl;
    else
        cout << "value not found" << endl;
    cout << "7. begin:" << endl;

    cout << "8. end " << endl;

    cout << "9. " << endl;
    return 0;
}