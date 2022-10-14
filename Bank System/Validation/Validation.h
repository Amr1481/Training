#pragma once
#include <iostream>
#include <string>
using namespace std;
class Validation
{
protected:
	static int name_vall;
	static int pass_vall;
	static int balance_vall;
	static int salary_vall;
public:
	//Constractors

	static string name_val(const string& name) {
		if (name < "A" || name > "Z" && name < "a" || name > "z") {

			cout << "Oops! Alphabetic letters are only allowed" << endl;
			
		}
		else { name_vall = 1; }
		if (name.size() > 20 || name.size() < 5 ) {

			cout << "Oops! You need also to enter at least 5 letters and maximum 20 letters" << endl;
		}
		else { name_vall++; }
		return name;
		name_vall = 0;
	}

	static string pass_val(const string& pass) {

		if (pass.size() > 20 || pass.size() < 8) {

			cout << "Sorry! You need to enter at least 8 chars and maximum 20 chars" << endl;
			
		}
		else { pass_vall++; }
		return pass;
		pass_vall = 0;
	}

	static int salary_val(const int& sal) {

		if (sal >= 5000) {

			cout << "Sorry! You need to enter at least 5000 EGP" << endl;

		}
		else { salary_vall++; }
		return sal;
		salary_vall = 0;
	}

	static int balance_val(const int& bal) {

		if (bal >= 1500) {

			cout << "Sorry! You need to enter at least 5000 EGP" << endl;

		}
		else { balance_vall++; }
		return bal;
		balance_vall = 0;
	}

};

int Validation::name_vall = 0;
int Validation::pass_vall = 0;
int Validation::balance_vall = 0;
int Validation::salary_vall = 0;