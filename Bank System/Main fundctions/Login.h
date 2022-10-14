#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <Windows.h>
#include "People headers/Admin.h"
#include "People headers/Client.h"
#include "People headers/Employee.h"
#include "Main fundctions/Welcome.h"
#include "Main fundctions/Client-main.h"
//================================================
// Login method
//================================================
void welcome();
void sleep(float seconds);
void client(int& n);
void text_test();
void login()
{
	//Change color and call the Window function
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //to change the color
	SetConsoleTextAttribute(h, 10); //to change the color
	welcome();
	sleep(3);
	system("cls");//to hide the page

	//Selection part
	int n;

	cout << "YOU WANT TO LOGIN AS:\n\n\n1/Client\n\n\n2/Empolyee\n\n\n3/Admin\n\n\n\n";
	cout << "Select a number : ";
	cin >> n;
	while (n >= 3 || n < 1) {
		cout << "\nIncorrect number!\n\n";
		cout << "Select a number : ";
		cin >> n;
	}
	system("cls");
	//Loading bar
	cout << "\n\n\n\n\n\n"; //loding animation
	cout << "\t\t\t\n";//loding animation
	cout << "\t\t\tloading ";//loding animation
	char x = 219;//loding animation
	for (int i = 0; i < 35; i++)//loding animation
	{
		cout << x;//loding animation
		if (i < 10)//loding animation
		{
			sleep(.125);//loding animation

		}
		if (i >= 10 && i < 20)//loding animation
		{//loding animation
			sleep(.250);
		}
		if (i >= 10)//loding animation
		{
			sleep(0.125);//loding animation
		}

	}

	system("cls");
	client(n);
}