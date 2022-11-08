#include <iostream>
using namespace std;
#include <string>
#include <cctype>

bool isValidCDPlayerString(string cdstring)
{
	bool isOpenVariable = false;  //all the parameters to check
	bool containsCD = false;  //note to self: i'll eat my foot before trying global variables again
	bool isPlaying = false;
	bool isPlaying2 = false;  //track numbers can't go right after C (stopped), but S can (playing)
	int lastTrack = 0;

	if (cdstring[0] != 'O') {  //check that first char is O
		return false;
	}

	for (size_t i = 0; i < cdstring.size(); i++) {  //checking each character
		char check = cdstring[i];

		if (isdigit(check)) {  //checking tracks
			if (isPlaying == false || isOpenVariable == true || isPlaying2 == false) {  //has to be playing and closed
				return false;
			}

			int currentTrack = check - '0';

			if (currentTrack != lastTrack + 1) {  //checks sequential order
				return false;
			}
			lastTrack = currentTrack;  //playing new track
		}
		else if (check == 'O') {  //open
			if (isOpenVariable == true) {  //player has to be closed
				return false;
			}
			isOpenVariable = true;
		}

		else if (check == 'I') {  //insert
			if (isOpenVariable == false || containsCD == true) {  //player has to be open and w/out CD
				return false;
			}
			containsCD = true;
			lastTrack = 0;  //can start playing from 1st track again
		}

		else if (check == 'R') {  //remove
			if (isOpenVariable == false || containsCD == false) {  //player has to be open and w/ CD
				return false;
			}
			containsCD = false;
		}

		else if (check == 'C') {  //close
			if (isOpenVariable == false) {  //player has to be open
				return false;
			}
			isOpenVariable = false;
			isPlaying2 = false;
		}

		else if (check == 'P') {  //play
			if (isOpenVariable == true || containsCD == false) {  //player has to be closed and w/ CD
				return false;
			}
			isPlaying = true;  //only affected by S and P
			isPlaying2 = true;  //only affected by P and C
		}

		else if (check == 'S') {  //stop
			if (isPlaying == false) {  //player has to be playing
				return false;
			}
			isPlaying = false;
		}

		else {  //any other characters
			return false;
		}
	}

	return true;  //returns true after passing all checks
}

bool isOpen(string cdstring) {  //check if player is open
	if (!isValidCDPlayerString(cdstring)) {
		return false;
	}

	bool isOpenVariable = false;

	for (size_t i = 0; i < cdstring.size(); i++) {  //dumbass. should have made a for loop searching string backwards.
		if (cdstring[i] == 'O') {  //opened
			isOpenVariable = true;
		}
		else if (cdstring[i] == 'C') {  //closed
			isOpenVariable = false;
		}
	}
	return isOpenVariable;
}

bool hasCD(string cdstring) {   //check if player has CD
	if (!isValidCDPlayerString(cdstring)) {
		return false;
	}

	bool withCD = false;

	for (size_t i = 0; i < cdstring.size(); i++) {
		if (cdstring[i] == 'I') {  //insert
			withCD = true;
		}
		else if (cdstring[i] == 'R') {  //remove
			withCD = false;
		}
	}

	return withCD;  //do people even read our comments
}

int totalTracksPlayed(string cdstring) {  //check tracks played
	if (!isValidCDPlayerString(cdstring)) {
		return -1;
	}

	int tracksPlayed = 0;

	for (size_t i = 0; i < cdstring.size(); i++) {
		if (isdigit(cdstring[i])) {  //adds 1 for every number uwu
			tracksPlayed++;
		}
	}

	return tracksPlayed;
}

int currentTrack(string cdstring) {  //check next track to be played (which is not current but whatever)
	if (!isValidCDPlayerString(cdstring)) {
		return -1;
	}

	int track = 1;   //start with 1
	bool containsCD = false;

	for (size_t i = 0; i < cdstring.size(); i++) {
		if (isdigit(cdstring[i])) {
			track = cdstring[i] - '0' + 1;  //changes to track after each number
		}
		else if (cdstring[i] == 'I') {
			containsCD = true;
			track = 1;
		}
		else if (cdstring[i] == 'R') {
			containsCD = false;
		}
	}

	if (containsCD == false) {  //returns -1 if empty
		return -1;
	}

	return track;
}

int main()
{
	string s;
	cout.setf(ios::boolalpha); // prints bool values as "true" or "false"
	for (;;)
	{
		cout << "Enter a possible result string: ";
		getline(cin, s); if (s == "quit") break;
		cout << "isValidCDPlayerString returns ";
		cout << isValidCDPlayerString(s) << endl;
		cout << "isOpen(s) returns ";
		cout << isOpen(s) << endl;
		cout << "hasCD(s) returns ";
		cout << hasCD(s) << endl;
		cout << "totalTracksPlayed(s) returns ";
		cout << totalTracksPlayed(s) << endl;
		cout << "currentTrack(s) returns ";
		cout << currentTrack(s) << endl;
		cout << endl;
	}

	return(0);
}