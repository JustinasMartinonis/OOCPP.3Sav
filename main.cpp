#include "FootballPlayer.hpp"

using namespace std;
using namespace football;

int main() {
    try {
    FootballPlayer *footballers = new FootballPlayer[2];
    footballers[0].setName("Ansu");
    footballers[0].setSurname("Fati");
    footballers[0].setYearSigned(2021);
    footballers[0].setContractLength(5);
    footballers[0].setShirtNumber(30);
    footballers[0].setSalary(1.1);
    footballers[0].addGoals(5);
    footballers[0].addAssists(1);
    footballers[0].minutesPlayed(958);
    footballers[0].endSeason();
    cout << "\n------------------------------------------" << endl;
    footballers[1].setName("Frenkie");
    footballers[1].setSurname("de Jong");
    footballers[1].setYearSigned(2018);
    footballers[1].setContractLength(2);
    footballers[1].setShirtNumber(21);
    footballers[1].setSalary(9);
    footballers[1].addGoals(7);
    footballers[1].addAssists(16);
    footballers[1].minutesPlayed(2650);
    footballers[1].endSeason();
    cout << "\n------------------------------------------" << endl;

    //Testing get methods
    cout << footballers[1].getName() << endl;
    cout << footballers[1].getSurname() << endl;
    cout << footballers[1].getYearSigned() << endl;
    cout << footballers[1].getShirtNumber() << endl;
    cout << footballers[1].getSalary() << endl;
    cout << footballers[1].getContractLength() << endl;

    //Exception thrown
    footballers[2].setSalary(-1);

    delete[] footballers;

    //Exception caught
    } catch (invalid_argument& e) {
        cout << e.what() << endl;
    } catch (...) {
        cout << "Unknown exception occured." << endl;
    }
	return 0;
}
