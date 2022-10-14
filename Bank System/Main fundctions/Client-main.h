#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "People headers/Admin.h"
#include "People headers/Client.h"
#include "People headers/Employee.h"
#include "Main fundctions/Welcome.h"
#include "Main fundctions/Login.h"

void login();

//================================================
// Client method
//================================================
void client(int& n) {
	int c{};
	string d;
	string p;
	string user_pass_val;
	//login page
	if (n == 1) {
		Client a;
		a.set_ID(c);
		a.set_Password(p);
		d = to_string(a.get_ID());
		p = a.get_Password();
		user_pass_val = c + " " + p;
		//Return back
		cout << "\nBack to menu enter B \n";
		cout << "To continue enter any key...\n";
		char i{};
		cin >> i;
		system("cls");
		switch (i)
		{
		case 'b':
		case 'B': login();
			break;
		}

	}

	//================================================
	// Client.text
	//===============================================
		fstream ClientData;
		ClientData.open("ClientData.txt", ios::in); //open a file to perform read operation using file object
		if (ClientData.is_open()) { //checking whether the file is open
			string tp;
			vector <string> ClientLogin;
			int i{};
			bool y = false;
			while (getline(ClientData, tp, ';')) { //read data from file object and put it into string.
				ClientLogin.push_back(tp);
				
				if (ClientLogin[i].substr(0, 4) == "ID: " && d == ClientLogin[i].substr(4)) {
						cout << ClientLogin[i - 1] << endl;
						cout << ClientLogin[i] << endl;
						y = true;
				}
				i++;
				//getline(ClientData, tp); //read data from file object and put it into string.
				//	if (user_pass_val == tp) {
				//		cout << "Yes" << endl;
				//	}
				//	else {
				//		system("cls");
				//		cout << "Incorrect username or password! Please try again\n\n";
				//		client(n);
				//	}
				//close the file object.
				
			}
		}
}


