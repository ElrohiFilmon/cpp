#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct employee {
    string name;
    int age;
    char gender;
    string employmentYear;
    string paystatus;
};

void write(int& n) {
    cout << "How many records do you want to enter?" << endl;
    cin >> n;

    employee* e = new employee[n];
    fstream ifile("employee_data.dat", ios::binary | ios::out); // Open for writing (creates if not exists)

    if (ifile) {
        cout << "----Enter your records----" << endl << "Notice: Fill them respectively!" << endl;
       
        for (int i = 0; i < n; ++i) {
            cout << "Record " << i + 1 << endl;
            cout << "Name: ";
            cin >> e[i].name;
            cout << "Age: ";
            cin >> e[i].age;
            cout << "Gender (M/F): ";
            cin >> e[i].gender;
            cout << "Year Employement: ";
            cin >> e[i].employmentYear;
            cout << "Pay Status: ";
            cin >> e[i].paystatus;
            ifile.write((char*)&e[i], sizeof(employee));
        }
    } else {
        cerr << "Error opening file for writing!" << endl;
    }

    ifile.close();
    delete[] e; // Deallocate memory after use
}

void display(const int n) {
    cout << " 1: Name" << "  2: Age" << " 3: Gender (M/F)" << "  4: Employment Year  " << "5: Pay Status" << endl;

    fstream ofile("employee_data.dat", ios::binary | ios::in); // Open file for reading

    if (ofile) {
        employee* e = new employee[n];
        for (int i = 0; i < n; ++i) {
            ofile.read((char*)&e[i], sizeof(employee));
            cout << " " << e[i].name << "   " << e[i].age << "   " << e[i].gender << "       " << e[i].employmentYear << "  " << e[i].paystatus << endl;
        }
        delete[] e; // Deallocate memory after use
    } else {
        cerr << "Error opening file for reading!" << endl;
    }

    ofile.close();
}

void update(const string& name, int n) {
    fstream file("employee_data.dat", ios::in | ios::out | ios::binary);

    if (file) {
        bool found = false;
        employee e;

        for (int i = 0; i < n; ++i) {
            int offset = i * sizeof(employee);
            file.seekg(offset, ios::beg);
            file.read((char*)&e, sizeof(employee));

            if (e.name == name) {
                found = true;
                cout << "Enter the updated information for the record:" << endl;
                            cout << "Enter new details for the employee: " << endl;
                cout << "Name: ";
                cin >> e.name;
                cout << "Age: ";
                cin >> e.age;
                cout << "Gender (M/F): ";
                cin >> e.gender;
                cout << "Year Employement: ";
                cin >> e.employmentYear;
                cout << "Pay Status: ";
            
                
                file.seekp(offset, ios::beg);
                file.write((char*)&e, sizeof(employee));
                cout << "Record updated successfully!" << endl;
                break;
            }
        }

        if (!found) {
            cout << "Employee with name '" << name << "' not found." << endl;
        }
    } else {
        cerr << "Error opening file for update!" << endl;
    }

    file.close();
}

void remove(const string& name, int& n) {
    fstream file("employee_data.dat", ios::in | ios::out | ios::binary);

    if (file) {
        bool found = false;
        employee* e = new employee[n];
        int count = 0;

        for (int i = 0; i < n; ++i) {
            file.read((char*)&e[i], sizeof(employee));
            if (e[i].name != name) {
                e[count++] = e[i];
            } else {
                found = true;
            }
        }

        file.close();

        if (found) {
            fstream ofile("employee_data.dat", ios::binary | ios::out | ios::trunc);
            for (int i = 0; i < count; ++i) {
                ofile.write((char*)&e[i], sizeof(employee));
            }
            ofile.close();
            n = count; // Update the number of records
            cout << "Record removed successfully!" << endl;
        } else {
            cout << "Employee with name '" << name << "' not found." << endl;
        }

        delete[] e; // Deallocate memory after use
    } else {
        cerr << "Error opening file for update!" << endl;
    }
}

void searchByName(const string& name, const int n) {
    fstream file("employee_data.dat", ios::binary | ios::in);

    if (file) {
        bool found = false;
        employee* e = new employee[n];
        ofstream unpaidFile("unpaid_employees.txt", ios::app); // Open file in append mode

        for (int i = 0; i < n; ++i) {
            file.read((char*)&e[i], sizeof(employee));
            if (e[i].name == name) {
                cout << " Name: " << e[i].name << " Age: " << e[i].age << " Gender: " << e[i].gender << " Employment Year: " << e[i].employmentYear << " Pay Status: " << e[i].paystatus << endl;
                found = true;
                if (e[i].paystatus == "unpaid") {
                    unpaidFile << " Name: " << e[i].name << " Age: " << e[i].age << " Gender: " << e[i].gender << " Employment Year: " << e[i].employmentYear << endl;
                }
            }
        }

        if (!found) {
            cout << "Employee with name '" << name << "' not found." << endl;
        }

        unpaidFile.close();
        delete[] e;
    } else {
        cerr << "Error opening file for reading!" << endl;
    }

    file.close();
}

int main() {
    int choice, n = 0;

    do {
        cout << "Menu:" << endl;
        cout << "1. Add Records" << endl;
        cout << "2. Display Records" << endl;
        cout << "3. Update Record by Name" << endl;
        cout << "4. Remove Record by Name" << endl;
        cout << "5. Search by Name" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                write(n);
                break;
            case 2:
                display(n);
                break;
            case 3: {
                string name;
                cout << "Enter the name of the employee to update: ";
                cin >> name;
                update(name, n);
                break;
            } 
            case 4: {
                string name;
                cout << "Enter the name of the employee to remove: ";
                cin >> name;
                remove(name, n);
                break;
            }
            case 5: {
                string name;
                cout << "Enter the name to search: ";
                cin >> name;
                searchByName(name, n);
                break;
            }
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
