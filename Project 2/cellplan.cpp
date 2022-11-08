#include <iostream>
#include <string>
using namespace std;

int main()
{
	string plan, autopay, paperless;
	int base, lines, gigabytes;
	double total = 0;
	
	cout << "What type of cell plan do you have? ";   //check plan 
	getline(cin, plan);

	if (plan == "Unlimited Elite") {
		base = 85;
	}
	else if (plan == "Unlimited Extra") {
		base = 75;
	}
	else if (plan == "Unlimited Starter") {
		base = 65;
	}
	else if (plan == "Prepaid") {
		base = 50;
	}
	else {
		cout << "Your cell plan is not valid!";
		return(0);
	}

	cout << "Are you on autopay? ";    //check autopay
	cin >> autopay;

	if (autopay == "Yes") {
		total -= 2;
	}
	else if (autopay != "No") {
		cout << "Your autopay is not valid!";
		return(0);
	}

	cout << "Are you on paperless billing? ";    //check paperless
	cin >> paperless;

	if (paperless == "Yes") {
		total -= 3;
	}
	else if (paperless != "No") {
		cout << "Your paperless billing is not valid!";
		return(0);
	}

	cout << "How many lines will be on your plan? ";  //check lines
	cin >> lines;

	if (lines == 1 || lines == 2 || lines == 3) {
		total *= lines;
		total += base * lines;
		if (lines > 1) {
			total -= lines * 10;
		}
	}
	else {
		cout << "Your lines are not valid!";
		return(0);
	}

	cout << "How many gigabytes did you consume this month? ";  //check gigabytes
	cin >> gigabytes;

	if (gigabytes >= 0 && gigabytes <= 30) {
		if (plan == "Prepaid" && gigabytes > 4) {
			total += ((gigabytes - 4) / 2) * 10;
		}
	}
	else {
		cout << "Your gigabytes are not valid!";
		return(0);
	}

	cout.setf(ios::fixed);  //to print out two deci
	cout.precision(2);

	cout << "Your " << plan << " cell plan costs $" << total << ".";

	return(0);
}