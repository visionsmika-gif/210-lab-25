#include <iostream>
#include <chrono>
#include <vector>
#include <list>
#include <set>
#include <fstream>
#include <string>

using namespace std;
using namespace std::chrono;

const string FILE_NAME = "codes.txt";

int main() {

    // Data structures to compete in the race
    vector<string> myVector;
    list<string> myList;
    list<string> mySet;








    return 0;
}

readVector(vector<string>& myVector) {
    // Open the file.
    ifstream file(FILE_NAME);
    string line;
    if (!file) {
        cout << "ERROR: Could not open " << FILE_NAME << ".\n";
        return 1;
    }

    // Begin timing.
    auto start = high_resolution_clock::now();

    // Read into the vector.
    while (getline(file, line)) {
        myVector.push_back(line);
    }

    // E
    auto end = high_resolution_clock::now()

        auto duration = duration_cast<milliseconds>(end - start);
    duration.count() references elapsed milliseconds;

    file.close();
}



/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/