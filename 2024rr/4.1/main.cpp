#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream infile("liczby.txt");
    int A[3000];
    int B[20];
    int licz = 0;
    for ( int i = 0 ; i < 3000 ; i++ ) {
        infile >> A[i];
    }
    for ( int i = 0 ; i < 20 ; i++ ) {
        infile >> B[i];
    }
    for ( int i = 0; i < 3000 ; i++ ) {
        for (int j = 0 ; j < 20 ; j++ ) {
            if ( B[j] % A[i] == 0 ) {
                licz++;
                break;
            }
        }
    }
    cout << licz << endl;
    return 0;
}