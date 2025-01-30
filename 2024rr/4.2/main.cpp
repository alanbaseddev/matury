#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    vector<int> liczba;
    int n;
    ifstream infile("liczby.txt");
    string line;
    if (getline(infile, line)) {
        istringstream iss(line);
        while (iss >> n) {
            liczba.push_back(n);
        }
    }
    sort(liczba.begin(), liczba.end(), greater<int>());
    cout << liczba[100];
    return 0;
}