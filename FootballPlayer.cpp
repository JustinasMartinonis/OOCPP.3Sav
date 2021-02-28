#include "FootballPlayer.hpp"

    	int football::FootballPlayer::countFootballerID = 1;

		football::FootballPlayer::FootballPlayer() {
			footballerID = countFootballerID;
			++countFootballerID;
			yearSigned = 0;
			contractLength = 0;
			shirtNumber = 0;
			playtime = 0;
			goals = 0;
			assists = 0;
			salary = 0;
			careerGoals = 0;
			careerAssists = 0;
        }
        football::FootballPlayer::~FootballPlayer() {
        }
        void football::FootballPlayer::setName(std::string n) {
            name = n;
        }
	std::string football::FootballPlayer::getName() {
		return name;
	}
	void football::FootballPlayer::setSurname(std::string sn) {
		surname = sn;
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
	std::string football::FootballPlayer::toString() {
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
