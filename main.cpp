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
    return (duration_cast<milliseconds>(end - start)).count();
}

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
    return (duration_cast<milliseconds>(end - start)).count();
}

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
    return (duration_cast<milliseconds>(end - start)).count();
}

long long sortVector(vector<string>& myVector) {
    auto start = high_resolution_clock::now();
    sort(myVector.begin(), myVector.end()); // <from algorithm>
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}
long long sortList(list<string>& myList) {
    auto start = high_resolution_clock::now();
    myList.sort();      // member function
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

long long sortSet(set<string>& mySet) {
    return -1;  // sets already sorted
}

long long insertVector(vector<string>& myVector) {
    auto middleIt = myVector.begin() + (myVector.size() / 2);
    auto start = high_resolution_clock::now();
    myVector.insert(middleIt, INSERT_VALUE);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

long long insertList(list<string>& myList) {
    auto middleIt = myList.begin();
    advance(middleIt, (myList.size() / 2)); // Use advance because list is not contiguous
    auto start = high_resolution_clock::now();
    myList.insert(middleIt, INSERT_VALUE);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}
long long insertSet(set<string>& mySet) {
    auto start = high_resolution_clock::now();
    mySet.insert(INSERT_VALUE); // not sequenced
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

long long deleteVector(vector<string>& myVector) {
    auto middleIt = myVector.begin() + (myVector.size() / 2);
    auto start = high_resolution_clock::now();
    myVector.erase(middleIt);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

long long deleteList(list<string>& myList) {
    auto middleIt = myList.begin();
    advance(middleIt, (myList.size() / 2)); // Use advance because list is not contiguous
    auto start = high_resolution_clock::now();
    myList.erase(middleIt);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

long long deleteSet(set<string>& mySet) {
    auto middleIt = mySet.begin();
    advance(middleIt, (mySet.size() / 2)); // Use advance because list is not contiguous
    auto start = high_resolution_clock::now();
    mySet.erase(middleIt);
    auto end = high_resolution_clock::now();
    return (duration_cast<milliseconds>(end - start)).count();
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/