#pragma once
#include <iostream>
#include <string>
#include "../Validation/Validation.h"
using namespace std ;

class Person : public Validation {
protected:
string password;
int id;
string name;

public:
//Constructors
Person (){
  
}
Person (string pass,int id, string name){
this->password = pass_val(pass);
this->id=id;
this->name = name_val(name);
}
//Setters
void set_Password(string pass){
    do {
        cout << "Enter your Pass: ";
        cin >> pass;
        this->password = pass_val(pass);
    } while (pass_vall < 1);
}

void set_ID(int id){
        cout << "Enter your ID: ";
        cin >> id;
        this->id = id;
}

void set_Name(string name){
    
    do {
        cout << "Enter your name: ";
        cin >> name;
        this->name = name_val(name);
    } while (name_vall != 2 );
    
}
//Getters
string get_Password(){
    
    return password + '@';
}
int get_ID(){
return id;
}
string get_Name(){
 return name;
}
//Methods
void pass_protect() {
    cout << "Password : ";
    for (int i = 0; i < password.length(); i++) {

        cout << "*";
    }
    cout << endl;
}

//Abstract
virtual void display () = 0;
};
