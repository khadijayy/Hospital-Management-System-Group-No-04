#include "PatientRecord.h"

Patient::Patient() : id(newId++), name(""), cnic(""), phoneNumber(""), disease(""), status("") {}
Patient::~Patient() {}
Patient::Patient(string n, string c, string number, string d, string s) : id(newId++), disease(d), status(s), name(n)
{
    setcnic(c);
    setPhoneNumber(number);
}
void Patient::setName(string name)
{

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
        throw invalid_argument("Incorrect CNIC");
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
        throw invalid_argument("Incorrect Phone Number");
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

void Patient::readfromfile(ifstream &fin)
{
    fin >> id;
    fin.ignore();
    getline(fin, name);
    getline(fin, cnic);
    getline(fin, phoneNumber);
    getline(fin, disease);
    getline(fin, status);
}
void Patient::writeToFile(ofstream &fout)
{
    fout << id << endl;
    fout << name << endl;
    fout << cnic << endl;
    fout << phoneNumber << endl;
    fout << disease << endl;
    fout << status << endl;
}

void Patient::display()
{
    cout << "Patient Id: " << id << endl;
    cout << "Patient Name: " << name << endl;
    cout << "CNIC: " << cnic << endl;
    cout << "Phone Number: " << phoneNumber << endl;
    cout << "Disease: " << disease << endl;
    cout << "Status: " << status << endl;
}

int Patient ::newId = 1;
