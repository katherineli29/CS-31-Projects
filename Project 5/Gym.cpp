#include <iostream>
#include <string>
#include "Gym.h"
#include "GymMember.h"
#include "Kind.h"
using namespace std;

Gym::Gym(string name, string location, Kind kind) { //constructor
	mName = name;
	mLocation = location;
	mKind = kind;

	hasCardio = false; //I just set these to false as default
	hasWeights = false;
	hasPool = false;
	hasTrack = false;
}

void Gym::setFeatures(bool cardio, bool weights, bool pool, bool track) { //setter method for features
	hasCardio = cardio;
	hasWeights = weights;
	hasPool = pool;
	hasTrack = track;
}

bool Gym::canWorkoutHere(GymMember m) { //check if Kind is high enough
	Kind memberKind = m.getKind(); //member's Kind

	switch (memberKind) { //switch method based on member's Kind
	case OTHER:
		if (mKind == OTHER) { //check that Gym's Kind is OTHER for OTHER member
			return true;
		}
		else {
			return false;
		}
		break;
	case REGULAR:
		if (mKind == REGULAR) { //REGULAR goes to REGULAR
			return true;
		}
		else {
			return false;
		}
		break;
	case PREMIER:
		if (mKind == REGULAR || mKind == PREMIER) { //PREMIER goes to REGULAR or PREMIER
			return true;
		}
		else {
			return false;
		}
		break;
	case EXECUTIVE:
		if (mKind == REGULAR || mKind == PREMIER || mKind == EXECUTIVE) { //EXECUTIVE can go anywhere except OTHER
			return true;
		}
		else {
			return false;
		}
		break;
	}

	return false;
}

bool Gym::checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack) {
	if (!canWorkoutHere(m)) { //if the member can't workout, then they can't check in
		return false;
	}

	if (wantsCardio && !hasCardio) { //if m wants cardio but Gym doesn't have it, return false
		return false;
	}
	if (wantsWeights && !hasWeights) { //rinse and repeat earlier logic
		return false;
	}
	if (wantsPool && !hasPool) {
		return false;
	}
	if (wantsTrack && !hasTrack) {
		return false;
	}

	m.newWorkout();
	return true;
}

//getter methods
bool Gym::hasCardioFeatures() {
	return hasCardio;
}

bool Gym::hasWeightsFeatures() {
	return hasWeights;
}

bool Gym::hasPoolFeatures() {
	return hasPool;
}

bool Gym::hasTrackFeatures() {
	return hasTrack;
}

Kind Gym::getKind() {
	return mKind;
}

string Gym::getKindAsString() {
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

string Gym::getLocation() {
	return mLocation;
}

string Gym::getName() {
	return mName;
}