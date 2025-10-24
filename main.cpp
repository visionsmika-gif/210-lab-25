#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>    // For sort() and advance()

using namespace std;
using namespace std::chrono;

const string FILE_NAME = "codes.txt";
const string INSERT_VALUE = "TESTCODE";

long long readVector(vector<string>& myVector);
long long readList(list<string>& myList);
long long readSet(set<string>& mySet);

long long sortVector(vector<string>& myVector);
long long sortList(list<string>& myList);
long long sortSet(set<string>& mySet);

long long insertVector(vector<string>& myVector);
long long insertList(list<string>& myList);
long long insertSet(set<string>& mySet);

long long deleteVector(vector<string>& myVector);
long long deleteList(list<string>& myList);
long long deleteSet(set<string>& mySet);

int main() {
    // Data structures to compete in the race
    vector<string> myVector;
    list<string> myList;
    set<string> mySet;

    cout << "Reading race:\n";
    cout << readVector(myVector) << "\n";
    cout << readList(myList) << "\n";
    cout << readSet(mySet) << "\n";

    cout << "Sorting race:\n";
    cout << sortVector(myVector) << "\n";
    cout << sortList(myList) << "\n";
    cout << sortSet(mySet) << "\n";

    cout << "Inserting race:\n";
    cout << insertVector(myVector) << "\n";
    cout << insertList(myList) << "\n";
    cout << insertSet(mySet) << "\n";

    cout << "Deleting race:\n";
    cout << deleteVector(myVector) << "\n";
    cout << deleteList(myList) << "\n";
    cout << deleteSet(mySet) << "\n";

    return 0;
}


// Function to return the time it takes to read elements from a file into a vector.
// Args:    a vector
// Returns: time in microseconds
long long readVector(vector<string>& myVector) {
    // Open the file
    ifstream file(FILE_NAME);
    string line;
    if (!file) {
        cout << "ERROR: Could not open " << FILE_NAME << ".\n";
        return 1;
    }

    // Begin timing
    auto start = high_resolution_clock::now();

    // Read file
    while (getline(file, line)) {
        myVector.push_back(line);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Close the file
    file.close();

    // Return time result
    return (duration_cast<microseconds>(end - start)).count();
}

// Function to return the time it takes to read elements from a file into a list.
// Args:    a list
// Returns: time in microseconds
long long readList(list<string>& myList) {
    // Open the file
    ifstream file(FILE_NAME);
    string line;
    if (!file) {
        cout << "ERROR: Could not open " << FILE_NAME << ".\n";
        return 1;
    }

    // Begin timing
    auto start = high_resolution_clock::now();

    // Read file
    while (getline(file, line)) {
        myList.push_back(line);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Close the file
    file.close();

    // Return time result
    return (duration_cast<microseconds>(end - start)).count();
}

// Function to return the time it takes to read elements from a file into a set.
// Args:    a set
// Returns: time in microseconds
long long readSet(set<string>& mySet) {
    // Open the file
    ifstream file(FILE_NAME);
    string line;
    if (!file) {
        cout << "ERROR: Could not open " << FILE_NAME << ".\n";
        return 1;
    }

    // Begin timing
    auto start = high_resolution_clock::now();

    // Read file
    while (getline(file, line)) {
        mySet.insert(line);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Close the file
    file.close();

    // Return time result
    return (duration_cast<microseconds>(end - start)).count();
}

// Function to return the time it takes to sort a vector.
// Args:    a vector
// Returns: time in microseconds
long long sortVector(vector<string>& myVector) {
    auto start = high_resolution_clock::now();                  // Begin timing
    sort(myVector.begin(), myVector.end());                     // Sort vector
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes to sort a list.
// Args:    a list
// Returns: time in microseconds
long long sortList(list<string>& myList) {
    auto start = high_resolution_clock::now();                  // Begin timing
    myList.sort();                                              // Sort list
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes to sort a set.
// Args:    a set
// Returns: -1 (because a set is already sorted)
long long sortSet(set<string>& mySet) {
    return -1;
}

// Function to return the time it takes insert an element in the middle of a vector.
// Args:    a vector
// Returns: time in microseconds
long long insertVector(vector<string>& myVector) {
    auto start = high_resolution_clock::now();                  // Begin timing
    auto middleIt = myVector.begin() + (myVector.size() / 2);   // Create an iterator in the middle
    myVector.insert(middleIt, INSERT_VALUE);                    // Insert a value in the middle
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes insert an element in the middle of a list.
// Args:    a list
// Returns: time in microseconds
long long insertList(list<string>& myList) {
    auto start = high_resolution_clock::now();                  // Begin timing
    auto middleIt = myList.begin();                             // Create an iterator
    advance(middleIt, (myList.size() / 2));                     // Advance the iterator to the middle
    myList.insert(middleIt, INSERT_VALUE);                      // Insert a value in the middle
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes insert an element in a set.
// Args:    a set
// Returns: time in microseconds
long long insertSet(set<string>& mySet) {
    auto start = high_resolution_clock::now();                  // Begin timing
    mySet.insert(INSERT_VALUE);                                 // Insert a value
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes delete an element in the middle of a vector.
// Args:    a vector
// Returns: time in microseconds
long long deleteVector(vector<string>& myVector) {
    auto start = high_resolution_clock::now();                  // Begin timing
    auto middleIt = myVector.begin() + (myVector.size() / 2);   // Create an iterator in the middle
    myVector.erase(middleIt);                                   // Delete a value in the middle
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes delete an element in the middle of a list.
// Args:    a list
// Returns: time in microseconds
long long deleteList(list<string>& myList) {
    auto start = high_resolution_clock::now();                  // Begin timing
    auto middleIt = myList.begin();                             // Create an iterator
    advance(middleIt, (myList.size() / 2));                     // Advance the iterator to the middle
    myList.erase(middleIt);                                     // Delete a value in the middle
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

// Function to return the time it takes delete an element in the middle of a set.
// Args:    a set
// Returns: time in microseconds
long long deleteSet(set<string>& mySet) {
    auto start = high_resolution_clock::now();                  // Begin timing
    auto middleIt = mySet.begin();                              // Create an iterator
    advance(middleIt, (mySet.size() / 2));                      // Advance the iterator to the middle
    mySet.erase(middleIt);                                      // Delete a value in the middle
    auto end = high_resolution_clock::now();                    // End timing
    return (duration_cast<microseconds>(end - start)).count();  // Return time result
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/