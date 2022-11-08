#include <iostream>
#include <string>
using namespace std;

int locateMinimum(const  string  array[], int  n);
int countCommonElements(const string array1[], int  n1, const string array2[], int n2);
int countVowels(const string array[], int n);
bool hasThreeOfX(const string array[], int n, string x);
string majorityElement(const string array[], int  n);
bool shiftRight(string array[], int n, int amount, string placeholder);
bool rotateLeft(string array[], int n, int amount);
int replaceAll(string array[], int n, char letterToReplace, char letterToFill);

int main() {
	string folks[8] = { "samwell", "jon", "margaery", "daenerys",
						  "tyrion", "sansa", "magdalena", "jon" };
	string data[5] = { "mama", "mama", "12,", "sansa", "mama" };

	cout << "Should return 3: " << locateMinimum(folks, 8) << endl;
	for (int i = 0; i < 8; i++) {
		cout << folks[i] << " ";
	}
	cout << endl;

	cout << "Should return 1: " << countCommonElements(folks, 8, data, 5) << endl;
	cout << "Should return 0: " << countCommonElements(folks, 3, data, 3) << endl;
	cout << endl;

	cout << "8: " << countVowels(data, 5) << endl;
	cout << "21: " << countVowels(folks, 8) << endl;
	cout << endl;

	cout << "Should return true: " << boolalpha << hasThreeOfX(data, 5, "mama") << endl;
	cout << "Should return false: " << boolalpha << hasThreeOfX(folks, 8, "jon") << endl;
	cout << endl;

	cout << "Empty: " << majorityElement(folks, 8) << endl;
	cout << "mama: " << majorityElement(data, 5) << endl;
	cout << endl;

	cout << "True: " << boolalpha << shiftRight(data, 5, 2, "foo") << endl;
	for (int i = 0; i < 5; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	string data2[5] = { "mama", "mama", "12,", "sansa", "mama" };
	cout << "True: " << boolalpha << shiftRight(data2, 5, 10, "bar") << endl;
	for (int i = 0; i < 5; i++) {
		cout << data2[i] << " ";
	}
	cout << endl;
	cout << "False: " << boolalpha << shiftRight(data, -5, 10, "foobar") << endl;
	cout << endl;

	cout << "True: " << boolalpha << rotateLeft(folks, 8, 1) << endl;
	for (int i = 0; i < 8; i++) {
		cout << folks[i] << " ";
	}
	cout << endl;
	cout << "False: " << boolalpha << rotateLeft(folks, 2, 12) << endl;
	cout << endl;

	cout << "0: " << replaceAll(folks, 8, 'A', 'Z') << endl;
	cout << "-1: " << replaceAll(folks, -10, 'A', 'Z') << endl;
	cout << "9: " << replaceAll(folks, 8, 'a', 'Z') << endl;
	for (int i = 0; i < 8; i++) {
		cout << folks[i] << " ";
	}

	return(0);
}

int locateMinimum(const  string  array[], int  n) {
	if (n <= 0) {
		return -1;
	}

	string min = array[0];
	int finValue = 0;

	for (int i = 1; i < n; i++) {
		if (array[i] < min) {
			min = array[i];
			finValue = i;
		}
	}

	return finValue;
}

int countCommonElements(const string array1[], int  n1, const string array2[], int n2) {
	if (n1 <= 0 || n2 <= 0) {
		return -1;
	}

	int finValue = 0;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n2; j++) {
			if (array1[i] == array2[j]) {
				finValue++;
			}
		}
	}

	return finValue;
}

int countVowels(const string array[], int n) {
	if (n <= 0) {
		return -1;
	}

	int numVowels = 0;

	for (int i = 0; i < n; i++) {
		for (size_t j = 0; j < array[i].size(); j++) {
			switch (array[i][j]) {
			case 'A':
			case 'a':
			case 'E':
			case 'e':
			case 'I':
			case 'i':
			case 'O':
			case 'o':
			case 'U':
			case 'u':
			case 'Y':
			case 'y':
				numVowels++;
				break;
			}
		}
	}

	return numVowels;
}

bool hasThreeOfX(const string array[], int n, string x) {
	if (n <= 0) {
		return false;
	}

	int three = 0;

	for (int i = 0; i < n; i++) {
		if (array[i] == x) {
			three++;
		}
	}

	if (three == 3) {
		return true;
	}
	return false;
}

string majorityElement(const string array[], int  n) {
	if (n <= 0) {
		return "";
	}

	int half = n / 2 + 1;

	for (int i = 0; i < half; i++) {
		int overHalf = 0;
		for (int j = 0; j < n; j++) {
			if (array[i] == array[j]) {
				overHalf++;
				if (overHalf >= half) {
					return array[i];
				}
			}
		}
	}

	return "";
}

bool shiftRight(string array[], int n, int amount, string placeholder) {
	if (n <= 0 || amount <= 0) {
		return false;
	}

	for (int i = n - amount; i >= 0; i--) {
		if (i + amount < n) {
			array[i + amount] = array[i];
		}
	}

	for (int i = 0; i < amount && i < n; i++) {
		array[i] = placeholder;
	}

	return true;
}

bool rotateLeft(string array[], int n, int amount) {
	if (n <= 1 || (amount > 1 && (amount % n) == 0)) {
		return false;
	}

	for (int i = 0; i < amount; i++) {
		string save = array[0];
		array[0] = array[1];
		for (int j = 2; j < n; j++) {
			array[j - 1] = array[j];
		}
		array[n - 1] = save;
	}

	return true;
}

int replaceAll(string array[], int n, char letterToReplace, char letterToFill) {
	if (n <= 0) {
		return -1;
	}

	int replaced = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < array[i].size(); j++) {
			if (array[i][j] == letterToReplace) {
				array[i][j] = letterToFill;
				replaced++;
			}
		}
	}

	return replaced;
}
