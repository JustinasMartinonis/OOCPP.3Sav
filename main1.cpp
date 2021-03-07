#include "FootballPlayer1.h"

using namespace std;

int main() {
    try {
        FootballPlayer player1;
        cin >> player1;
        cout << endl;

        FootballPlayer player2;
        cin >> player2;
        cout << endl;

        bool comparison = (player1 == player2);
        cout << std::boolalpha << comparison << endl;

        cout << player1 << endl;
        cout << player2 << endl;

        //Post-Incrementation
        cout << "Post-incrementation" << endl;
        cout << "Footballer++: " << endl;
        cout << "Contract Before: " << player1.getContractLength() << endl;
        cout << player1++ << endl;
        cout << "Contract After: " << player1.getContractLength() << endl;

        //Pre-Incrementation
        cout << "Pre-incrementation" << endl;
        cout << "++Footballer: " << endl;
        cout << "Contract Before: " << player1.getContractLength() << endl;
        cout << ++player1 << endl;
        cout << "Contract After: " << player1.getContractLength() << endl;

        //Post-decrementation
        cout << "Post-decrementation" << endl;
        cout << "Footballer++: " << endl;
        cout << "Contract Before: " << player1.getContractLength() << endl;
        cout << player1-- << endl;
        cout << "Contract After: " << player1.getContractLength() << endl;

        //Pre-decrementation
        cout << "Pre-decrementation" << endl;
        cout << "Footballer++: " << endl;
        cout << "Contract Before: " << player1.getContractLength() << endl;
        cout << --player1 << endl;
        cout << "Contract After: " << player1.getContractLength() << endl;

        } catch (invalid_argument& e) {
            cerr << e.what() << endl;
        } catch (...) {
            cerr << "Unknown exception occurred." << endl;
        }

	return 0;
}
