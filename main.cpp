#include "PatientRecord.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <stdexcept>
#include <limits>
#include <algorithm>
#include <iomanip>
using namespace std;

// Menu
void menu()
{
    cout << "Main Menu.\n";
    cout << "1. Add a Patient.\n";
    cout << "2. Delete a Patient.\n";
    cout << "3. Update a Patient.\n";
    cout << "4. Search a Patient.\n";
    cout << "5. Display All Patients.\n";
    cout << "6. Press 0 to Exit.\n";
}
// Add Patients
void addPatient(vector<Patient> &patients, Patient &p)
{
    patients.push_back(p);
    ofstream fout("PatientRecord.txt", ios ::app | ios::binary);
    if (!fout)
    {
        cerr << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }
    p.writeToFile(fout);
    cout << "A new Patient Added Successfully! " << endl;
    fout.close();
}
// Delete Patients
void deletePatient(vector<Patient> &patients, int id)
{
    bool found = false;
    for (auto iter = patients.begin(); iter != patients.end(); iter++)
    {
        if (iter->getid() == id)
        {
            found = true;
            patients.erase(iter);
            ofstream fout("PatientRecord.txt", ios ::binary);
            if (!fout)
            {
                cerr << "Error opening file.\n";
                exit(EXIT_FAILURE);
            }
            for (auto &p : patients)
            {
                p.writeToFile(fout);
            }
            fout.close();
            cout << "Patient with id " << id << " removed successfully.\n";
            break;
        }
    }
    if (!found)
    {
        cout << "No record found.\n";
    }
}
// Display Patients.
void displayPatients()
{
    ifstream fin("PatientRecord.txt", ios ::binary);
    if (!fin)
    {
        cerr << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }
    while (!fin.eof())
    {
        Patient p;
        p.readfromfile(fin);
        if (fin.eof())
            break;
        p.display();
        cout << "=========================.\n";
    }
    fin.close();
}

// Update Patient
void update_patient(vector<Patient> &p, int id)
{

    bool find = false;

    for (int i = 0; i < p.size(); i++)
    {
        if (p[i].getid() == id)
        {
            find = true;
            string name;
            cout << "Enter name: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, name);
            p[i].setName(name);
            cout << "Enter cnic: ";
            string cnic;
            cin >> cnic;
            try
            {

                p[i].setcnic(cnic);
            }
            catch (const invalid_argument &in)
            {
                cout << in.what() << endl;
            }
            cout << "Enter Phone no: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            string no;
            getline(cin, no);
            try
            {

                p[i].setPhoneNumber(no);
            }
            catch (const invalid_argument &in)
            {
                cout << in.what() << endl;
            }
            cout << "Enter Disease: ";
            string disease;
            getline(cin, disease);
            p[i].setDisease(disease);
            break;
        }
    }

    if (find)
    {
        ofstream fout;
        fout.open("PatientRecord.txt", ios::binary | ios::trunc);
        if (!fout)
        {
            cout << "ERROR OPENING FILE" << endl;
            return;
        }

        for (auto &i : p)
        {
            i.writeToFile(fout);
        }
        fout.close();
        cout << "Patient with ID " << id << " updated successfully." << endl;
    }
    else
    {
        cout << "Patient with ID " << id << " not found." << endl;
    }
}

// search patient
void search_patient(int id)
{

    bool find = false;
    ifstream fin;
    fin.open("PatientRecord.txt", ios::binary);
    if (!fin)
    {
        cout << "ERROR OPENING FILE" << endl;
        return;
    }

    Patient patient;
    while (!fin.eof())
    {
        patient.readfromfile(fin);
        if (patient.getid() == id)
        {
            find = true;
            cout << "Patient with id: " << id << " succesfully found! " << endl;
            cout << endl;
            patient.display();
            break;
        }
    }
    if (!find)
    {
        cout << "No record of patient with id: " << id << " found! " << endl;
    }

    fin.close();
}

int main()
{
    int choice;
    vector<Patient> patients;
    cout << setw(60) << right << "===========================================" << endl;
    cout << setw(60) << right << "WELCOME TO THE HOSPITAL MANAGEMENT SYSTEM " << endl;
    cout << setw(60) << right << "===========================================" << endl;
    do
    {
        menu();
        cout << "Enter Your Choice: ";
        cin >> choice;
        if (!cin || choice < 0 || choice > 5)
        {
            cout << "Invalid Choice " << endl;
            cout << "Enter Again! " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else
        {
            if (choice == 0)
            {
                cout << "Exiting Patient Management System.\n";
                exit(0);
            }
            else if (choice == 1)
            {
                int id;
                string name, cnic, phone, disease;
                string status;

                cout << "Enter Name: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, name);
                cout << "Enter CNIC: ";
                getline(cin, cnic);

                cout << "Enter Phone Number: ";
                getline(cin, phone);
                cout << "Enter Disease: ";
                getline(cin, disease);
                cout << "Is Admitted (1 for yes(admitted), 0 for no(discharged)): ";
                cin >> status;
                try
                {
                    Patient new_patient(name, cnic, phone, disease, status);
                    addPatient(patients, new_patient);
                }
                catch (invalid_argument &in)
                {
                    cout << in.what() << endl;
                }
                catch (exception &e)
                {
                    cout << e.what() << endl;
                }
            }
            else if (choice == 2)
            {
                int id;
                cout << "Enter id of the patient to delete : ";
                cin >> id;
                deletePatient(patients, id);
            }
            else if (choice == 3)
            {
                int id;
                cout << "Enter id of the patient to update : ";
                cin >> id;
                update_patient(patients, id);
            }
            else if (choice == 4)
            {
                int id;
                cout << "Enter id of the patient to search for: ";
                cin >> id;
                search_patient(id);
            }
            else if (choice == 5)
            {
                displayPatients();
            }
        }

    } while (choice != 0);
    return 0;
}