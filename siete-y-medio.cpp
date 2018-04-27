#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;

// Global constants (if any)


// Non member functions declarations (if any)


// Non member functions implementations (if any)


// Stub for main
int main() {
	Hand h = Hand();
	while (h.get_total() < 7.5) {
		cout << h.get_total() << endl;
		h.add_card();
	}
	int x;
	cin >> x;
}