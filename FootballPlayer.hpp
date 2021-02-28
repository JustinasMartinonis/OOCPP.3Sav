#ifndef FOOTBALL_PLAYER
#define FOOTBALL_PLAYER
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdexcept>

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
        void setName(std::string n);
        std::string getName();
        void setSurname(std::string sn);
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
        std::string toString();
    };
}

#endif
