#include "PatientRecord.h"

// Add Patients
void addPatient(vector<Patient> &patients, Patient &p)
{
    patients.push_back(p);
    ofstream fout("PatientRecord.txt", ios ::app);
    if (!fout)
    {
        cerr << "Error opening file.\n";
        exit(EXIT_FAILURE);
    }
    p.writeToFile(fout);
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
            ofstream fout("PatientRecord.txt", ios ::out);
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
    ifstream fin("PatientRecord.txt", ios ::in);
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