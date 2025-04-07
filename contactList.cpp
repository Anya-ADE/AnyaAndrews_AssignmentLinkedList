#include <iostream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    Contact* next;

    Contact(){
        next = nullptr;
    }
};

void insertAtBeginning(Contact*& head, string name, string phone);
void insertAtEnd(Contact*& head, string name, string phone);
void displayList(Contact* head);
Contact* searchByName(Contact* head, string name);
bool deleteByName(Contact*& head, string name);

int main() {

    Contact* head = nullptr;
    int choice;
    string name, phone;

    do {
        cout << "\nContact List Menu:\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Display Contacts\n";
        cout << "4. Search by Name\n";
        cout << "5. Delete by Name\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtBeginning(head, name, phone);
                break;
            case 2:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone: ";
                getline(cin, phone);
                insertAtEnd(head, name, phone);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                cout << "Enter name to search: ";
                getline(cin, name);
                {
                    Contact* found = searchByName(head, name);
                    if (found) {
                        cout << "Found: " << found->name << " - " << found->phone << endl;
                    } else {
                        cout << "Contact not found.\n";
                    }
                }
                break;
            case 5:
                cout << "Enter name to delete: ";
                getline(cin, name);
                if (deleteByName(head, name)) {
                    cout << "Deleted successfully.\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
        }

    } while (choice != 6);

    return 0;
}

void insertAtBeginning(Contact*& head, string name, string phone) {
    Contact* addContact = new Contact;
    addContact->name = name;
    addContact->phone = phone;
    addContact->next = head;
    head = addContact;
}

void insertAtEnd(Contact*& head, string name, string phone) {
    Contact* addContact = new Contact;
    addContact->name = name;
    addContact->phone = phone;

    if (!head){
        head = addContact;
        return;
    }
    Contact* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = addContact;
}

void displayList(Contact* head) {
     Contact* temp = head;
     if (!temp){
        cout << "Contact list is empty!" << endl;
        return;
     }

     cout << "Contact List: " << endl;
     while (temp){
        cout << temp->name << " " << temp->phone << endl;
        temp = temp->next;
     }
}

Contact* searchByName(Contact* head, string name) {
     Contact* temp = head;
     while (temp) {
        if (temp->name == name) {
            return temp;
        }
        temp = temp->next;
     }
     return nullptr;
}

bool deleteByName(Contact*& head, string name) {
    if (!head) {
        return false;
    }

    if (head->name == name) {
        Contact* tempdel = head;
        head = head->next;
        delete tempdel;
        return true;
    }

    Contact* temp = head;
    Contact* prev = nullptr;
    while (temp) {
        if (temp->name == name) {
            if (prev) {
                prev->next = temp->next;
            }
            delete temp;
            return true;
        }
        prev = temp;
        temp = temp->next;
    }
    return false;
}
