#include <iostream>
#include <fstream>
using namespace std;

string odwroc(string slowo) {
	string odw = "";
	for ( int i = 0; i < slowo.size(); i++ ) {
		odw = slowo[i] + odw;
	}
	return odw;
}


int main(int argc, char** argv) {
	ifstream infile1;
	ifstream infile2("nowe.txt");
	string slowo;
	string nowe;
	int licz;
	int licz1;
	for ( int i = 0; i < 25; i++ ) {
		infile2 >> nowe;
		string odwrotna = odwroc(nowe);
		licz = 0;
		licz1 = 0;
		infile1.open("slowa.txt");
		for ( int j = 0; j < 1000; j++ ) {
			infile1 >> slowo;
			if ( nowe == slowo ) {
				licz++;
			}
			if ( odwrotna == slowo ) {
				licz1++;
			}
		}
		infile1.close();
		cout << nowe << " " << licz << " " << licz1 << endl;
	}

	return 0;
}