#include <iostream>
#include <string>
#include "GymMember.h"
#include "Kind.h"
using namespace std;

GymMember::GymMember(string name, std::string accountnumber, Kind kind) { //constructor
	mName = name; 
	mAccountNumber = accountnumber;
	mKind = kind;
	mWorkoutCount = 0;
}

int GymMember::workoutsThisMonth() { //returns workouts
	return mWorkoutCount;
}

void GymMember::startNewMonth() { //sets workouts to 0
	mWorkoutCount = 0;
}

void GymMember::newWorkout() { //increments workouts
	mWorkoutCount++;
}

//getter methods
Kind GymMember::getKind() { 
	return mKind;
}

string GymMember::getKindAsString() {
	switch (mKind) { //switch method that returns string for each Kind
	case OTHER:
		return "OTHER";
	case REGULAR:
		return "REGULAR";
	case PREMIER:
		return "PREMIER";
	case EXECUTIVE:
		return "EXECUTIVE";
	}
	return "";
}

string GymMember::getName() {
	return mName;
}

string GymMember::getAccountNumber() {
	return mAccountNumber;
}