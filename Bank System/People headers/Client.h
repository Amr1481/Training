#pragma once
#include <iostream>
#include <string>
#include "People headers/Person.h"

class Client :public Person {
protected:
    double balance;
   
public:
    //Constructors
    Client() {
        this->balance = 0.0;
     
    }
    Client(double balance, string pass, int id, string name) :Person(pass, id, name) {
        this->balance = balance;
       // this->amount = amount;
        this->password = pass;
        this->id = id;
        this->name = name;
    }

    //Setters:
    void set_balance(double balance) {
        this->balance = balance;
    }

    //Getters:
    double get_balance() {
        return balance;
    }

    //Method:

    void  deposit(double amount) {
       
        balance += amount;
        cout << "Transaction Confirmed!" << endl;
        cout << "Thanks! your balnce now is: " << balance << endl;
    }

    void withdraw(double amount) {
        if (balance < amount) {

            cout << "Sorry! you don't have enough balance" << endl;
            cout << "Current blance: " << balance << endl;
        }
        else {
            balance -= amount;
            cout << "Transaction Confirmed!" << endl;
            cout << "Thanks! your balnce now is: " << balance << endl;
        }
    }

 /*There is an error here*/
    void  transfer(double amount/*, Client & recipient*/) {
       if (balance < amount) {

            cout << "Sorry! you don't have enough balance" << endl;
            cout << "Current blance: " << balance << endl;
       }
       else {
           balance -= amount;
           cout << "Transaction Confirmed!" << endl;
           cout << "Thanks! your balnce now is: " << balance << endl;
       }
    }

    void checkBalance() {
        cout << "Your balnce now is: " << balance << endl;
    }

    //Method display:
    void display() {
        cout << "Name : " << name << endl;
        pass_protect();
        cout << "ID : " << id << endl;
        cout << "Balance : " << balance << endl;
    }

};
