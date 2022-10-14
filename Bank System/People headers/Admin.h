#pragma once
#include <iostream>
#include <fstream>
#include "Employee.h"
#include "../Validation/Validation.h"
#include "Client.h"

using namespace std;

//======================================
// Admin class inherted from Employee
//======================================

class Admin : public Employee
{
private:
    vector <Employee> employees;
    vector <string> employeelist;
    vector <string> employeeSearch;


public:
   Admin(){}
   Admin(double bala, string pass, int id, string name) :Employee(bala,pass, id, name) {
     
    }

    //methods
    void display() {
        cout << "Name : " << name << endl;
        pass_protect();
        cout << "ID : " << id << endl;
        cout << "Balance : " << balance << endl;
    }


//======================================
// Clients -> Add, search and list
//======================================

    /*a. void addClient(Client& client).*/
    void addClient(Client& newClient) {     
            clients.push_back(newClient);
            fstream ClientData;
            ClientData.open("ClientData.txt", ios::out |ios::app);  // open a file to perform write operation using file object 
                                                                    // ios::app to no delete existing data
            if (ClientData.is_open()){
                for (int i = 0; i < clients.size(); i++) { //inserting data to ClientData
                
                    ClientData << "Name: " << clients[i].get_Name() << ';';
                    ClientData << "ID: " << clients[i].get_ID() << ';';
                    ClientData << "Password: " << clients[i].get_Password() << ';';
                    ClientData << "Balance: " << clients[i].get_balance() << ';' << endl;
                   
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
                        cout << clientSearch[i-1] << endl;
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



//======================================
// Employee -> Add, search and list
//======================================

    /*Addemployee.*/
    void addEmployee(Employee& newEmployee) {
        employees.push_back(newEmployee);
        fstream EmployeeData;
        EmployeeData.open("EmployeeData.txt", ios::out | ios::app);  // open a file to perform write operation using file object 
                                                                // ios::app to no delete existing data
        if (EmployeeData.is_open()) {
            for (int i = 0; i < employees.size(); i++) { //inserting data to employeesData

                EmployeeData << "Name: " << employees[i].get_Name() << ';';
                EmployeeData << "ID: " << employees[i].get_ID() << ';';
                EmployeeData << "Password: " << employees[i].get_Password() << ';';
                EmployeeData << "Balance: " << employees[i].get_Balance() << ';' << endl;

            }
            employees.clear(); //clear vector to save memory after adding to data base

        }
    }


    /*Employee* searchemployee(id)*/
    void searchemployee(string id) {
        fstream EmployeeData;
        EmployeeData.open("EmployeeData.txt", ios::in); //open a file to perform read operation using file object
        if (EmployeeData.is_open()) { //checking whether the file is open
            string tp;
            int i{};
            bool y = false;
            while (getline(EmployeeData, tp, ';')) { //read data from file object and put it into string.
                employeeSearch.push_back(tp);

                if (employeeSearch[i].substr(0, 4) == "ID: " && id == employeeSearch[i].substr(4)) {
                    cout << employeeSearch[i - 1] << endl;
                    cout << employeeSearch[i] << endl;
                    y = true;
                }
                i++;
            }
            if (y == false) {

                cout << "404: Not found!" << endl;

            }
        }
    }
    /*Employee List.*/
    void listEmployee() {
        fstream EmployeeData;
        EmployeeData.open("EmployeeData.txt", ios::in); //open a file to perform read operation using file object
        if (EmployeeData.is_open()) { //checking whether the file is open
            string tp;
            bool i = false;

            while (getline(EmployeeData, tp, ';')) { //read data from file object and put it into string.
                employeelist.push_back(tp);
            }
            for (int i = 0; i < employeelist.size(); i++) {
                cout << employeelist[i] << endl;
            }
        }
    }
};


