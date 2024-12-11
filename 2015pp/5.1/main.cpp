#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
	ifstream infile("slowa.txt");
	string slowo;
	int licz[13] = {0};
	for ( int i = 0; i < 1000; i++ ) {
		infile >> slowo;
		licz[slowo.size()]++;
	}
	for ( int i = 1; i <= 12; i++ ) {
		cout << "Slow dlugosci " << i << " jest " << licz[i] << endl;
	}

	return 0;
}