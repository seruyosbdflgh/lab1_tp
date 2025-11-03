#include "keeper.h"
#include "fantast.h"
#include "romanist.h"
#include "poet.h"
#include "base.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int get_valid_number(const string& prompt) {
    string input;
    int number;
    while (true) {
        cout << prompt;
        cin >> input;
        try {
            number = stoi(input);
            break; 
        } catch (invalid_argument&) {
            cout << "Error: please enter a valid number.\n";
        } catch (out_of_range&) {
            cout << "Error: the entered number is too large.\n";
        }
    }
    return number;
}

int main() {
    Keeper keeper;
    int choice = 0;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Add object\n";
        cout << "2. Delete object\n";
        cout << "3. Edit object\n";
        cout << "4. Operator !\n";
        cout << "5. Operator ++\n";
        cout << "6. Show all objects\n";
        cout << "7. Save data to file\n";
        cout << "8. Load data from file\n";
        cout << "0. Exit\n";
        choice = get_valid_number("Enter operation number: ");

        switch (choice) {
            case 1: {
                int index = get_valid_number("Enter index to add object: ");
                int objType = get_valid_number("Choose object type:\n1. Fantast\n2. Romanist\n3. Poet\nEnter type number: ");

                Base* obj = nullptr;
                if (objType == 1) {
                    string name, years, books, movies_by_books;

                    cout << "Enter fantast name: ";
                    cin >> name;
                    cout << "Enter years of life: ";
                    cin >> years;
                    cout << "Enter books: ";
                    cin >> books;
                    cout << "Enter movies based on books: ";
                    cin >> movies_by_books;

                    obj = new Fantast(name, years, books, movies_by_books);
                } 
                else if (objType == 2) {
                    string name, years, books, bio;

                    cout << "Enter romanist name: ";
                    cin >> name;
                    cout << "Enter years of life: ";
                    cin >> years;
                    cout << "Enter books: ";
                    cin >> books;
                    cout << "Enter biography: ";
                    cin >> bio;

                    obj = new Romanist(name, years, books, bio);
                } 
                else if (objType == 3) {
                    string name, years, poems;

                    cout << "Enter poet name: ";
                    cin >> name;
                    cout << "Enter years of life: ";
                    cin >> years;
                    cout << "Enter poems: ";
                    cin >> poems;

                    obj = new Poet(name, years, poems);
                } 
                else {
                    cout << "Invalid object type\n";
                    continue;
                }

                keeper.add(obj, index - 1);
                break;
            }

            case 2: {
                int index = get_valid_number("Enter index to delete object: ");
                keeper.delete_el(index + 1);
                break;
            }

            case 3: {
                int index = get_valid_number("Enter index to edit object: ");
                keeper.edit_el(index);
                break;
            }

            case 4:
                !keeper;
                break;

            case 5:
                keeper++;
                break;
            
            case 6:
                keeper.print_keeper();
                break;

            case 7: {
                string filename;
                cout << "Enter filename to save: ";
                cin >> filename;
                keeper.save_to_file(filename);
                break;
            }

            case 8: {
                string filename;
                cout << "Enter filename to load: ";
                cin >> filename;
                keeper.load_from_file(filename);
                break;
            }

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}