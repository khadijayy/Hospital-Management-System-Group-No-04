#include "PatientRecord.h"
// default constructor.
Patient::Patient() : id(newId++), name(""), cnic(""), phoneNumber(""), disease(""), status("") {}
// parameterized constructor.
Patient::Patient(string n, string c, string number, string d, string s) : id(newId++), disease(d), status(s)
{
    setName(n);
    setcnic(c);
    setPhoneNumber(number);
}
void Patient::setName(string name)
{
    if (name.empty())
    {
        cout << "Name cant be empty" << endl;
        return;
    }
    this->name = name;
}
void Patient::setcnic(string cnic)
{
    string cleaned_cnic;
    for (char ch : cnic)
    {
        if (isdigit(ch))
        {
            cleaned_cnic += ch;
        }
    }

    if (cleaned_cnic.length() != 13)
    {
        cout << "Incorrect CNIC" << endl;
        return;
    }

    this->cnic = cleaned_cnic;
}
void Patient::setPhoneNumber(string phoneNumber)
{
    string cleaned_phone;
    for (char ch : phoneNumber)
    {
        if (isdigit(ch))
        {
            cleaned_phone += ch;
        }
    }

    if (cleaned_phone.length() != 11)
    {
        cout << "Incorrect Phone Number" << endl;
        return;
    }
    this->phoneNumber = phoneNumber;
}
void Patient::setDisease(string disease)
{
    this->disease = disease;
}
void Patient::setStatus(string status)
{
    this->status = status;
}
int Patient::getid() const { return id; }
string Patient::getName() const { return name; }
string Patient::getCnic() const { return cnic; }
string Patient::getPhoneNo() const { return phoneNumber; }
string Patient::getStatus() const { return status; }
string Patient::getDisease() const { return disease; }
