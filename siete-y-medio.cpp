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
		int bet;
		cout << "Enter bet: ";
		cin >> bet;
		while (!my_player.make_bet(bet)) {
			cout << "Can't bet that much...you broke" << endl;
			cout << "Enter bet: ";
			cin >> bet;
		}
		Hand my_h = Hand();
		bool keep_hitting = true;
		// players turn:
		while (keep_hitting == true) {
			cout << "Your cards:" << endl;
			my_h.print_hand();
			cout << "Your total is: " << my_h.get_total() << ". take a hit? (y/n)? ";
			string yes_no;
			cin >> yes_no;
			cout << endl;

			if (yes_no == "y") {
				my_h.add_card();
				cout << "New Card: ";
				my_h.print_last_card();
				cout << endl;
				if (my_h.get_total() > 7.5) {
					cout << "BUSTED!!" << endl;
					keep_hitting = false;
				}
			}
			else
				keep_hitting = false;
		}

		Hand d_h = Hand();
		if (my_h.get_total() <= 7.5) {
			//dealers turn
			cout << "Dealer's cards: " << endl;
			d_h.print_hand();
			cout << "The dealer's total is: " << d_h.get_total() << "." << endl;
			while (d_h.get_total() < 5.5) {
				d_h.add_card();
				cout << "New Card: ";
				d_h.print_last_card();
				cout << endl;
				cout << "Dealer's cards: ";
				d_h.print_hand();
				cout << "The dealer's total is: " << d_h.get_total() << "." << endl;
			}
		}
		
		// case for player wins
		if (my_h.get_total() > d_h.get_total() && my_h.get_total() <= 7.5) {
			my_player.win_bet(bet);
			cout << "Way to go champ, you won " << bet << endl << endl;
		} // case for dealer wins because has higher total
		else if (d_h.get_total() > 7.5) {
			my_player.win_bet(bet);
			cout << "Way to go champ, you won " << bet << endl << endl;
		}
		else { // dealer wins
			my_player.lose_bet(bet);
			cout << "Dang you lost " << bet << endl;
		}


	}
	cout << "You allll out of $$$...Peace!";
	int x;
	cin >> x;
}