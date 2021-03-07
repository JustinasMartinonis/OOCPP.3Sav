#ifndef FOOTBALLPLAYER1_HPP_INCLUDED
#define FOOTBALLPLAYER1_HPP_INCLUDED

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

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
    void setID();
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
    int getGoals();
    void addAssists(int assist);
    int getAssists();
    void minutesPlayed(int minutes);
    int getMinutesPlayed();
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


#endif // FOOTBALLPLAYER1_HPP_INCLUDED
