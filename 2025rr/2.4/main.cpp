#include <iostream>
#include <fstream>
#include <string>

long long trojkowy(const std::string &s) {
    long long wartosc = 0;
    for (char c : s) {
        int liczba;
        if (c == 'o') liczba = 0;
        else if (c == '+') liczba = 1;
        else liczba = 2;
        wartosc = wartosc * 3 + liczba;
    }
    return wartosc;
}

std::string dot(long long n) {
    if (n == 0) return "o";
    std::string s = "";
    while (n > 0) {
        int liczba = n % 3;
        char c;
        if (liczba == 0) c = 'o';
        else if (liczba == 1) c = '+';
        else c = '*';
        s += c;
        n /= 3;
    }
    return s;
}

int main() {
    std::ifstream infile("symbole.txt");
    std::string s;
    int suma = 0;
    while (infile >> s) {
        suma += trojkowy(s);
    }
    std::string napis = dot(suma);
    std::cout << suma << std::endl;
    std::cout << napis << std::endl;
    return 0;
}