#ifndef PATIENTRECORD_H
#define PATIENTRECORD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>
using namespace std;
class Patient
{
    int id;
    static int newId;
    string name;
    string cnic;
    string phoneNumber;
    string disease;
    string status; // admitted/discharged

public:
    // default constructor.
    Patient();
    // parameterized constructor.
    Patient(string n, string c, string number, string d, string s);
    // getters/setters.
    void setName(string name);
    void setcnic(string cnic);
    void setPhoneNumber(string phoneNumber);
    void setDisease(string disease);
    void setStatus(string status);
    int getid() const;
    string getName() const;
    string getCnic() const;
    string getPhoneNo() const;
    string getStatus() const;
    string getDisease() const;
    // display function.
    void display();
    // destructor.
    ~Patient();
    void readfromfile(ifstream &fin);
    void writeToFile(ofstream &fout);
};
#endif