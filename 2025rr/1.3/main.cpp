#include <iostream>
using namespace std;

int przestaw2(int n) {
    int wynik = 0;
    int m = 1;

    while (n > 0) {
        int r = n % 100;
        int a = r / 10;
        int b = r % 10;
        n = n / 100;

        int w;
        if (n > 0) {
            w = a + 10 * b;
        } else {
            if (a > 0)
                w = a + 10 * b;
            else
                w = b;
        }

        wynik += w * m;
        m *= 100;
    }

    return wynik;
}

int main() {
    cout << przestaw2(43657688);
    return 0;
}
