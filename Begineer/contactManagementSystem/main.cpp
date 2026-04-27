#include <iostream>
#include <vector>
#include <fstream> // for file I/O
#include <sstream>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

void saveContacts(const vector<Contact> &contacts) {
    ofstream file("contacts.txt");
    for(const auto& c : contacts) {
        file << c.name << "|" << c.phone << "|" << c.email << endl;
    }
}

void loadContacts(vector<Contact> &contacts) {
    ifstream file("contacts.txt");
    if(!file) return;

    string line;
    while(getline(file, line)) {
        stringstream ss(line);

        string name, phone, email;
        getline(ss, name, '|');
        getline(ss, phone, '|');
        getline(ss, email, '|');

        contacts.push_back({name, phone, email});
    }
}

void addContact(vector<Contact> &contacts) {
    Contact c;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c.name);

    cout << "Enter Phone: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    contacts.push_back(c);
    saveContacts(contacts);

    cout << "Contact added successfully!\n";
}

void viewContact(const vector<Contact> &contacts) {
    if (contacts.empty()) {
        cout << "No contacts found.\n";
        return;
    }
    for(size_t i=0; i<contacts.size(); ++i) {
        cout << "\nContact " << i+1 << ":\n";
        cout << "Name: " << contacts[i].name << endl;
        cout << "Phone: " << contacts[i].phone << endl;
        cout << "Email: " << contacts[i].email << endl;
    }
}

void searchContact(const vector<Contact> &contacts) {
    string name;
    cout << "Enter name to search: ";
    cin.ignore();
    getline(cin, name);
    bool found = false;

    for(const auto& c : contacts) {
        if(c.name.find(name) != string::npos) {
            cout << "\nFound:\n";
            cout << "Name: " << c.name << endl;
            cout << "Phone: " << c.phone << endl;
            cout << "Email: " << c.email << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No matching contact found.\n";
    }
}

void deleteContact(vector<Contact> &contacts) {
    string name;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, name);

    for(auto it = contacts.begin(); it != contacts.end(); ++it) {
        if(it->name == name) {
            contacts.erase(it);
            saveContacts(contacts);
            cout << "Contact deleted.\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

int main() {
    vector<Contact> contacts;
    loadContacts(contacts);
    int choice;
    
    do {
        cout << "\n--- Contact Management System ---\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contact\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addContact(contacts); break;
            case 2: viewContact(contacts); break;
            case 3: searchContact(contacts); break;
            case 4: deleteContact(contacts); break;
            case 5: cout << "Exiting...\n";break;
            default: cout << "Invalid choice.\n";
        }
    } while(choice != 5);

    return 0;
}