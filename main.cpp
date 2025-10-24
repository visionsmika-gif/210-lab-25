#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>    // For sort()

using namespace std;
using namespace std::chrono;

const string FILE_NAME = "codes.txt";

long long readVector(vector<string>& myVector);
long long readList(list<string>& myList);
long long readSet(set<string>& mySet);

long long sortVector(vector<string>& myVector);
long long sortList(list<string>& myList);
long long sortSet(set<string>& mySet);

int main() {

    // Data structures to compete in the race
    vector<string> myVector;
    list<string> myList;
    set<string> mySet;

    // TODO: fix formatting output
    cout << "Reading race:\n";
    cout << readVector(myVector) << "\n";
    cout << readList(myList) << "\n";
    cout << readSet(mySet) << "\n";

    cout << "Sorting race:\n";
    cout << sortVector(myVector) << "\n";
    cout << sortList(myList) << "\n";
    cout << sortSet(mySet) << "\n";






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

}
long long sortList(list<string>& myList);
long long sortSet(set<string>& mySet);


/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/