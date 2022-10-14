#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
#include "People headers/Admin.h"
#include "People headers/Client.h"
#include "People headers/Employee.h"
#include "Main fundctions/Login.h"
#include "Main fundctions/Client-main.h"



//================================================
// Welcome method
//================================================
void welcome()
{
	cout << "======================================================================================================================\n\n";
	cout << "         *       *   ******     *      ******  *****   *     *    *****     \n";
	cout << "         *       *   *          *      *       *   *   *  *  *    *         \n";
	cout << "          *  *  *    ******     *      *       *   *   *  *  *    *****     \n";
	cout << "           * * *     *          *      *       *   *   *     *    *         \n";
	cout << "            * *      ******     ****   ******  *****   *     *    *****     \n\n";

	cout << "                                    *******   *****    \n";
	cout << "                                       *      *   *    \n";
	cout << "                                       *      *   *    \n";
	cout << "                                       *      *   *    \n";
	cout << "                                       *      *****    \n\n";

	cout << "                             *     *     *******   *    *  *****   *     *    *  * * *     ******       \n";
	cout << "                          * *  *  * *       *      *    *  *       *     *    *  *     *   *              \n";
	cout << "                           *     *          *      * *  *  *       *     *    *  *      *  ******         \n";
	cout << "                        * *  *  * *         *      *  * *  *       *     *    *  *     *   *               \n";
	cout << "                         *    *           ******   *    *  *****   ****    * *   * * *     ******         \n\n";
	cout << "========================================================================================================================\n";

}

//the delay of welcome massage
void sleep(float seconds) {
	clock_t startClock = clock();
	float secondsAhead = seconds * CLOCKS_PER_SEC;
	// do nothing until the elapsed time has passed.
	while (clock() < startClock + secondsAhead);
	return;
}