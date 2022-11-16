#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H
#include "Kind.h"
#include <string>

class GymMember {
private:
	std::string mName; //variables
	std::string mAccountNumber;
	Kind mKind;
	int mWorkoutCount;

public: 
	GymMember(std::string name, std::string accountnumber, Kind kind); //constructor

	int workoutsThisMonth(); //functions
	void startNewMonth(); 
	void newWorkout();

	Kind getKind(); //getter methods
	std::string getKindAsString();
	std::string getName();
	std::string getAccountNumber();

};

#endif 