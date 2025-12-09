#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>

int NWD(int a, int b) {
    while (b !=0 ) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main() {
    std::ifstream infile("dron.txt");
    int A, B;
    int licznik = 0;
    while (infile >> A >> B) {
        int absA = abs(A);
        int absB = abs(B);
        int wynik_nwd = NWD(absA, absB);
        if (wynik_nwd > 1) {
            licznik++;
        }
    }
    std::cout << licznik << std::endl;
    return 0;
}