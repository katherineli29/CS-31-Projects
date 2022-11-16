#ifndef GYM_H
#define GYM_H
#include <string>
#include "Kind.h"
#include "GymMember.h"

class Gym {
private:
	std::string mName; //variables
	std::string mLocation;
	Kind mKind;

	bool hasCardio; //gym features
	bool hasWeights;
	bool hasPool;
	bool hasTrack;

public:
	Gym(std::string name, std::string location, Kind kind); //constructor

	void setFeatures(bool cardio, bool weights, bool pool, bool track); //set features
	
	bool canWorkoutHere(GymMember m); //functions
	bool checkin(GymMember& m, bool wantsCardio, bool wantsWeights, bool wantsPool, bool wantsTrack);

	bool hasCardioFeatures(); //functions to access features
	bool hasWeightsFeatures();
	bool hasPoolFeatures();
	bool hasTrackFeatures();

	Kind getKind();
	std::string getKindAsString();
	std::string getLocation();
	std::string getName();

};

#endif 