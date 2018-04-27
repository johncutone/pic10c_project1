#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "cards.h"
using namespace std;



// This main function plays the game
int main() {
	cout << "Enter starting integer amount: ";
	int start_amount;
	cin >> start_amount;
	cout << endl;

	Player my_player(start_amount);

	while (my_player.current_balance() > 0) {
		cout << "You have " << my_player.current_balance() << " dollars" << endl;
		Hand my_h = Hand();
		bool keep_playing = true;
		while (keep_playing == true) {
			cout << "Your cards:" < , endl;

		}
	}
}