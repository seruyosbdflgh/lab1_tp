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
            cout << "Ошибка: введите корректное число.\n";
        } catch (out_of_range&) {
            cout << "Ошибка: введенное число слишком большое.\n";
        }
    }
    return number;
}

int main() {
    Keeper keeper;
    int choice = 0;

    do {
        cout << "\n--- Меню ---\n";
        cout << "1. Добавить объект\n";
        cout << "2. Удалить объект\n";
        cout << "3. Изменить объект\n";
        cout << "4. Оператор !\n";
        cout << "5. Оператор ++\n";
        cout << "6. Показать все объекты\n";
        cout << "7. Сохранить данные в файл\n";
        cout << "8. Загрузить данные из файла\n";
        cout << "0. Выйти\n";
        choice = get_valid_number("Введите номер операции: ");

        switch (choice) {
            case 1: {
                int index = get_valid_number("Введите индекс для добавления объекта: ");
                int objType = get_valid_number("Выберите тип объекта:\n1. Фантаст\n2. Романист\n3. Поэт\nВведите номер типа: ");

                Base* obj = nullptr;
                if (objType == 1) {
                    string name, years, books, movies_by_books;

                    cout << "Введите имя фантаста: ";
                    cin >> name;
                    cout << "Введите годы жизни: ";
                    cin >> years;
                    cout << "Введите книги: ";
                    cin >> books;
                    cout << "Введите фильмы по книгам: ";
                    cin >> movies_by_books;

                    obj = new Fantast(name, years, books, movies_by_books);
                } 
                else if (objType == 2) {
                    string name, years, books, bio;

                    cout << "Введите имя романиста: ";
                    cin >> name;
                    cout << "Введите годы жизни: ";
                    cin >> years;
                    cout << "Введите книги: ";
                    cin >> books;
                    cout << "Введите биографию: ";
                    cin >> bio;

                    obj = new Romanist(name, years, books, bio);
                } 
                else if (objType == 3) {
                    string name, years, poems;

                    cout << "Введите имя поэта: ";
                    cin >> name;
                    cout << "Введите годы жизни: ";
                    cin >> years;
                    cout << "Введите поэмы: ";
                    cin >> poems;

                    obj = new Poet(name, years, poems);
                } 
                else {
                    cout << "Неверный тип объекта\n";
                    continue;
                }

                keeper.add(obj, index - 1);
                break;
            }

            case 2: {
                int index = get_valid_number("Введите индекс для удаления объекта: ");
                keeper.delete_el(index + 1);
                break;
            }

            case 3: {
                int index = get_valid_number("Введите индекс для редактирования объекта: ");
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
                cout << "Введите имя файла для сохранения: ";
                cin >> filename;
                keeper.save_to_file(filename);
                break;
            }

            case 8: {
                string filename;
                cout << "Введите имя файла для загрузки: ";
                cin >> filename;
                keeper.load_from_file(filename);
                break;
            }

            case 0:
                cout << "Выход из программы...\n";
                break;

            default:
                cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 0);

    return 0;
}
