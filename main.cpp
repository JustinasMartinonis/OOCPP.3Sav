#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <assert.h>

using namespace std;

namespace football {
    class FootballPlayer {
      private:
        static int countFootballerID;
        int footballerID;
        int yearSigned;
        int contractLength;
        int shirtNumber;
        int playtime;
        int goals;
        int assists;
        int careerGoals;
        int careerAssists;
        float salary;
        std::string name;
        std::string surname;

      public:
        FootballPlayer();
        ~FootballPlayer();
        int getID();
        void setName(const std::string &name);
        std::string getName();
        void setSurname(const std::string &surname);
        std::string getSurname();
        void setYearSigned(int yearS);
        int getYearSigned();
        void setContractLength(int contract);
        int getContractLength();
        void setShirtNumber(int shirtN);
        int getShirtNumber();
        void setSalary(float s);
        float getSalary();
        void addGoals(int goal);
        void addAssists(int assist);
        void minutesPlayed(int minutes);
        void endSeason();
        std::string toString() const;
        bool operator==(const FootballPlayer &player) const;
        bool operator!=(const FootballPlayer &player) const;
        bool operator<(const FootballPlayer &player) const;
        bool operator<=(const FootballPlayer &player) const;
        bool operator>(const FootballPlayer &player) const;
        bool operator>=(const FootballPlayer &player) const;
        FootballPlayer& operator++();
        FootballPlayer operator++(int);
        FootballPlayer& operator--();
        FootballPlayer operator--(int);
        friend std::ostream &operator<<(std::ostream &os, const FootballPlayer &player);
        friend std::istream &operator>>(std::istream &is, FootballPlayer &player);
    };
}

using namespace football;

int football::FootballPlayer::countFootballerID = 1;

football::FootballPlayer::FootballPlayer() {
    footballerID = countFootballerID;
    ++countFootballerID;
    setName("N/A");
    setSurname("N/A");
    setYearSigned(2021);
    setContractLength(5);
    setShirtNumber(99);
    minutesPlayed(0);
    addGoals(0);
    addAssists(0);
    setSalary(1);
    careerGoals = 0;
    careerAssists = 0;
}
football::FootballPlayer::~FootballPlayer() {
}
int football::FootballPlayer::getID(){
    return footballerID;
}
void football::FootballPlayer::setName(const std::string &name) {
    this->name = name;
}
std::string football::FootballPlayer::getName() {
    return name;
}
void football::FootballPlayer::setSurname(const std::string &surname) {
    this->surname = surname;
}
std::string football::FootballPlayer::getSurname() {
    return surname;
}
void football::FootballPlayer::setYearSigned(int yearS) {
    if(yearS <= 2021 && yearS >= 2000) {
        yearSigned = yearS;
    } else {
        throw std::invalid_argument("Invalid year of signing.");
    }
}
int football::FootballPlayer::getYearSigned() {
    return yearSigned;
}
void football::FootballPlayer::setContractLength(int contract) {
    if(contract <= 20 && contract >= 1){
        contractLength = contract;
    } else {
        throw std::invalid_argument("Invalid contract length.");
    }
}
int football::FootballPlayer::getContractLength() {
    return contractLength;
}
void football::FootballPlayer::setShirtNumber(int shirtN) {
    if(shirtN <= 99 && shirtN >=1){
        shirtNumber = shirtN;
    } else {
        throw std::invalid_argument("Invalid shirt number.");
    }
}
int football::FootballPlayer::getShirtNumber() {
    return shirtNumber;
}
void football::FootballPlayer::setSalary(float s) {
    if(s > 0){
        salary = s;
    } else {
        throw std::invalid_argument("Invalid salary.");
    }
}
float football::FootballPlayer::getSalary() {
    return salary;
}
void football::FootballPlayer::addGoals(int goal) {
    if(goal >= 0){
        goals += goal;
    } else {
        throw std::invalid_argument("Invalid amount of goals.");
    }
    careerGoals += goal;
}
void football::FootballPlayer::addAssists(int assist) {
    if(assist >= 0){
        assists += assist;
    } else {
        throw std::invalid_argument("Invalid amount of assists.");
    }
    careerAssists += assist;
}
void football::FootballPlayer::minutesPlayed(int minutes) {
    if(minutes >= 0){
        playtime += minutes;
    } else {
        throw std::invalid_argument("Invalid amount of minutes played.");
    }
}
void football::FootballPlayer::endSeason() {
    --contractLength;
    std::cout << toString() << std::endl;
    goals = 0;
    assists = 0;
    playtime = 0;
}
std::string football::FootballPlayer::toString() const {
    std::ostringstream ss;
    ss << "\nFootballer (ID " << footballerID << ") End of the Season stats\n" << std::endl;
    ss << "Name: " << name << std::endl;
    ss << "Surname: " << surname << std::endl;
    ss << "Shirt no.: " << shirtNumber << std::endl;
    ss << "Season Goals: " << goals << std::endl;
    ss << "Season Assists: " << assists << std::endl;
    ss << "Minutes played: " << playtime << std::endl;
    ss << "\nContract signed in: " << yearSigned << std::endl;
    ss << "Years left in contract: " << contractLength << std::endl;
    ss << "Current salary (millions EUR): " << salary << std::endl;
    ss << "\nCurrent Career Goals: " << careerGoals << std::endl;
    ss << "Current Career Assists: " << careerAssists << std::endl;
        if(contractLength <= 0) {
            ss << "\nThe player may now sign for a new club" <<
            " for free or extend his contract!" << std::endl;
        }
    return ss.str();
}
bool football::FootballPlayer::operator==(const FootballPlayer &player) const {
    return (goals == player.goals && assists == player.assists);
}
bool football::FootballPlayer::operator!=(const FootballPlayer &player) const {
    return !(*this == player);
}
bool football::FootballPlayer::operator<(const FootballPlayer &player) const {
    return (goals < player.goals && assists < player.assists && name == player.name);
}
bool football::FootballPlayer::operator<=(const FootballPlayer &player) const {
    return (*this == player || *this < player);
}
bool football::FootballPlayer::operator>(const FootballPlayer &player) const {
    return !(*this < player);
}
bool football::FootballPlayer::operator>=(const FootballPlayer &player) const {
    return (*this == player || *this > player);
}
FootballPlayer &FootballPlayer::operator++() {
    ++this->footballerID;
    return *this;
}
FootballPlayer FootballPlayer::operator++(int) {
    FootballPlayer temp = *this;
    ++this->footballerID;
    return temp;
}
FootballPlayer &FootballPlayer::operator--() {
    --this->footballerID;
    return *this;
}
FootballPlayer FootballPlayer::operator--(int) {
    FootballPlayer temp = *this;
    --this->footballerID;
    return temp;
}
std::ostream &operator<<(std::ostream &os, const FootballPlayer &player) {
    os << player.toString();
    return os;
}
std::istream &operator>>(std::istream &is, FootballPlayer &player) {

    FootballPlayer temp;
    //is >> temp.name >> temp.surname >> temp.yearSigned >> temp.contractLength;
    //is >> temp.shirtNumber >> temp.salary;
    //is >> temp.playtime >> temp.goals >> temp.assists;

    FootballPlayer newObject;
    newObject.setName(temp.name);
    newObject.setSurname(temp.surname);
    newObject.setYearSigned(temp.yearSigned);
    newObject.setContractLength(temp.contractLength);
    newObject.setShirtNumber(temp.shirtNumber);
    newObject.setSalary(temp.salary);
    newObject.minutesPlayed(temp.playtime);
    newObject.addGoals(temp.goals);
    newObject.addAssists(temp.assists);
    player = newObject;

    return is;
}
*/
int main() {
    try { /*
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
        cout << endl;
        cout << footballers[1].getName() << endl;
        cout << footballers[1].getSurname() << endl;
        cout << footballers[1].getYearSigned() << endl;
        cout << footballers[1].getShirtNumber() << endl;
        cout << footballers[1].getSalary() << endl;
        cout << footballers[1].getContractLength() << endl;
        cout << endl;
        */
        FootballPlayer player;
        cin >> player;
        cout << player << endl;
        FootballPlayer player2;
        player2.setSalary(4);
        bool comparison = player > player2;
        cout << comparison;

        ++player;
        cout << player << endl;
        //Testing comparison methods
        //assert(footballers[1].getSalary() == footballers[1].getSalary());
        //assert(footballers[0].getSalary() != footballers[1].getSalary());
        //assert(footballers[0].getSalary() < footballers[1].getSalary());
        //assert(footballers[0].getSalary() <= footballers[1].getSalary());
        //assert(footballers[1].getSalary() > footballers[0].getSalary());
        //assert(footballers[1].getSalary() >= footballers[0].getSalary());

        //Post-Incrementation and Pre-Incrementation
        cout << "Post-incrementation" << endl;
        cout << "Footballer++: " << player++ << endl;
        cout << "Pre-incrementation" << endl;
        cout << "++Footballer: " << ++player << endl;

        //Exception thrown
        //footballers[2].setSalary(-1);

        //delete[] footballers;

        //Exception caught
        } catch (invalid_argument& e) {
            cerr << e.what() << endl;
        } catch (...) {
            cerr << "Unknown exception occurred." << endl;
        }

	return 0;
}
