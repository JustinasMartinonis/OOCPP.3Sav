e#include "FootballPlayer1.hpp"

using namespace std;

int FootballPlayer::countFootballerID = 0;

FootballPlayer::FootballPlayer() {
    footballerID = 0;
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
FootballPlayer::~FootballPlayer() {
}
void FootballPlayer::setID() {
    ++countFootballerID;
    footballerID = countFootballerID;
}
int FootballPlayer::getID(){
    return footballerID;
}
void FootballPlayer::setName(const std::string &name) {
    this->name = name;
}
std::string FootballPlayer::getName() {
    return name;
}
void FootballPlayer::setSurname(const std::string &surname) {
    this->surname = surname;
}
std::string FootballPlayer::getSurname() {
    return surname;
}
void FootballPlayer::setYearSigned(int yearS) {
    if(yearS <= 2021 && yearS >= 2000) {
        yearSigned = yearS;
    } else {
        throw std::invalid_argument("Invalid year of signing.");
    }
}
int FootballPlayer::getYearSigned() {
    return yearSigned;
}
void FootballPlayer::setContractLength(int contract) {
    if(contract <= 20 && contract >= 1){
        contractLength = contract;
    } else {
        throw std::invalid_argument("Invalid contract length.");
    }
}
int FootballPlayer::getContractLength() {
    return contractLength;
}
void FootballPlayer::setShirtNumber(int shirtN) {
    if(shirtN <= 99 && shirtN >=1){
        shirtNumber = shirtN;
    } else {
        throw std::invalid_argument("Invalid shirt number.");
    }
}
int FootballPlayer::getShirtNumber() {
    return shirtNumber;
}
void FootballPlayer::setSalary(float s) {
    if(s > 0){
        salary = s;
    } else {
        throw std::invalid_argument("Invalid salary.");
    }
}
float FootballPlayer::getSalary() {
    return salary;
}
void FootballPlayer::addGoals(int goal) {
    goals = goal;
    if(goal < 0) {
        throw std::invalid_argument("Invalid amount of goals.");
    }
    careerGoals += goal;
}
int FootballPlayer::getGoals() {
    return goals;
}
void FootballPlayer::addAssists(int assist) {
    assists = assist;
    if(assist < 0) {
        throw std::invalid_argument("Invalid amount of assists.");
    }
    careerAssists += assist;
}
int FootballPlayer::getAssists() {
    return assists;
}
void FootballPlayer::minutesPlayed(int minutes) {
    playtime = minutes;
    if(minutes < 0) {
        throw std::invalid_argument("Invalid amount of minutes played.");
    }
}
int FootballPlayer::getMinutesPlayed() {
    return playtime;
}
void FootballPlayer::endSeason() {
    --contractLength;
    std::cout << toString() << std::endl;
    goals = 0;
    assists = 0;
    playtime = 0;
}
std::string FootballPlayer::toString() const {
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
bool FootballPlayer::operator==(const FootballPlayer &player) const {
    if(goals == player.goals) {
        return true;
    } else {
        return false;
    }
}
bool FootballPlayer::operator!=(const FootballPlayer &player) const {
    bool temp = *this == player;
    return !temp;
}
bool FootballPlayer::operator<(const FootballPlayer &player) const {
    return player > *this;
}
bool FootballPlayer::operator<=(const FootballPlayer &player) const {
    if(*this == player) {
        return true;
    } else {
        return *this < player;
    }
}
bool FootballPlayer::operator>(const FootballPlayer &player) const {
    if(goals > player.goals) {
        return true;
    } else {
        return false;
    }
}
bool FootballPlayer::operator>=(const FootballPlayer &player) const {
    if(*this == player) {
        return true;
    } else {
        return *this > player;
    }
}
FootballPlayer &FootballPlayer::operator++() {
    ++this->contractLength;
    return *this;
}
FootballPlayer FootballPlayer::operator++(int) {
    FootballPlayer temp = *this;
    ++this->contractLength;
    return temp;
}
FootballPlayer &FootballPlayer::operator--() {
    --this->contractLength;
    return *this;
}
FootballPlayer FootballPlayer::operator--(int) {
    FootballPlayer temp = *this;
    --this->contractLength;
    return temp;
}
std::ostream &operator<<(std::ostream &os, const FootballPlayer &player) {
    os << player.toString();
    return os;
}
std::istream &operator>>(std::istream &is, FootballPlayer &player) {

    FootballPlayer temp;
    cout << "Name: ";
    is >> temp.name;
    cout << "Surname: ";
    is >> temp.surname;
    cout << "Year Signed: ";
    is >> temp.yearSigned;
    cout << "Contract Length: ";
    is >> temp.contractLength;
    cout << "Assigned Shirt Number: ";
    is >> temp.shirtNumber;
    cout << "Salary (millions EUR): ";
    is >> temp.salary;
    cout << "Minutes played: ";
    is >> temp.playtime;
    cout << "Goals Scored: ";
    is >> temp.goals;
    cout << "Assists given: ";
    is >> temp.assists;

    FootballPlayer newObject;
    newObject.setID();
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
