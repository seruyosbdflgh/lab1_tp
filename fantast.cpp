#include "fantast.h"
#include <iostream>
#include <fstream>

using namespace std;

Fantast::Fantast() : name(""), years(""), books(""), movies_by_books("") {cout << "Вызван конструктор без параметров для Fantast\n";}

Fantast::Fantast(const string& n, const string& y, const string& b, const string& m)
    : name(n), years(y), books(b), movies_by_books(m) {cout << "Вызван конструктор с параметрами для Fantast\n";}

Fantast::Fantast(const Fantast& other)
    : name(other.name), years(other.years), books(other.books), movies_by_books(other.movies_by_books) {cout << "Вызван конструктор копирования для Fantast\n";}

Fantast::~Fantast() {cout << "Вызван деструктор для Fantast\n";}

void Fantast::set_name(string n) {
    name = n;
}

string Fantast::get_name() {
    return name;
}

void Fantast::set_years(string y) {
    years = y;
}

string Fantast::get_years() {
    return years;
}

void Fantast::set_books(string b) {
    books = b;
}

string Fantast::get_books() {
    return books;
}

void Fantast::set_movies(string m) {
    movies_by_books = m;
}

string Fantast::get_movies() {
    return movies_by_books;
}

void Fantast::display_obj() {
    cout << "Fantast Name: " << name << endl;
    cout << "Years: " << years << endl;
    cout << "Books: " << books << endl;
    cout << "Movies by books: " << movies_by_books << endl;
}

void Fantast::change_info() {
    cin.ignore();
    cout << "Enter new name: \n";
    getline(cin, name);
    cout << "Enter new years: \n";
    getline(cin, years);
    cout << "Enter new books: \n";
    getline(cin, books);
    cout << "Enter new movies by books: \n";
    getline(cin, movies_by_books);
}

void Fantast::save_in_file(ostream& out) {
    out << "Fantast" << endl;
    out << name << endl;
    out << years << endl;
    out << books << endl;
    out << movies_by_books << endl;
}

void Fantast::load_from_file(istream& in) {
    getline(in, name);
    getline(in, years);
    getline(in, books);
    getline(in, movies_by_books);
}
