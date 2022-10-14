#pragma once
#include <iostream>
#include <string>
#include "Person.h"
#include <fstream>
#include "Client.h"
using namespace std ;

class Employee : public Person {
protected :
    
    double balance;
    vector<Client> clients;
    vector <string> clientlist;
    vector<string> clientSearch;

public :
    //con
    Employee () {
    this ->balance = 0 ;
    }
    Employee (double bala ,string pass,int id, string name ) :Person (pass , id , name) {
        this ->balance = bala ;
        this -> password=pass;
        this ->id = id ;
        this ->name = name ;
    }

    //setter
    void set_Balance (double bala) {
    this ->balance = bala ;
    }
    //geter
    double get_Balance () {
    return balance ;
    }

    //method
    void display () {
        cout << "Name : " << name << endl;
        pass_protect();
        cout << "ID : " << id << endl;
        cout << "Balance : " << balance << endl;
    }

/*a. void addClient(Client& client).*/
    void addClient(Client& newClient) {
        clients.push_back(newClient);
        fstream ClientData;
        ClientData.open("ClientData.txt", ios::out | ios::app);  // open a file to perform write operation using file object 
                                                                // ios::app to no delete existing data
        if (ClientData.is_open()) {
            for (int i = 0; i < clients.size(); i++) { //inserting data to ClientData

                ClientData << "Name: " << clients[i].get_Name() << ';';
                ClientData << "ID: " << clients[i].get_ID() << ';';
                ClientData << "Password: " << clients[i].get_Password() << ';';
                ClientData << "Balance: " << clients[i].get_balance() << ';';

            }
            clients.clear(); //clear vector to save memory after adding to data base

        }
    }


    /*Client* searchClient(id)*/
    void searchClient(string id) {
        fstream ClientData;
        ClientData.open("ClientData.txt", ios::in); //open a file to perform read operation using file object
        if (ClientData.is_open()) { //checking whether the file is open
            string tp;
            int i{};
            bool y = false;
            while (getline(ClientData, tp, ';')) { //read data from file object and put it into string.
                clientSearch.push_back(tp);

                if (clientSearch[i].substr(0, 4) == "ID: " && id == clientSearch[i].substr(4)) {
                    cout << clientSearch[i - 1] << endl;
                    cout << clientSearch[i] << endl;
                    y = true;
                }
                i++;
            }
            if (y == false) {

                cout << "404: Not found!" << endl;

            }
        }
    }
    /*CLient List.*/
    void listClient() {
        fstream ClientData;
        ClientData.open("ClientData.txt", ios::in); //open a file to perform read operation using file object
        if (ClientData.is_open()) { //checking whether the file is open
            string tp;
            bool i = false;

            while (getline(ClientData, tp, ';')) { //read data from file object and put it into string.
                clientlist.push_back(tp);
            }
            for (int i = 0; i < clientlist.size(); i++) {
                cout << clientlist[i] << endl;
            }
        }
    }
};
