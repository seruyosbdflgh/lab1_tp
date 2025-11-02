#include "romanist.h"
#include <iostream>
#include <fstream>

using namespace std;

Romanist::Romanist() : name(""), years(""), books(""), bio("") {cout << "Вызван конструктор без параметров для Romanist\n";}

Romanist::Romanist(const string& n, const string& y, const string& b, const string& bio)
    : name(n), years(y), books(b), bio(bio) {cout << "Вызван конструктор с параметрами для Romanist\n";}

Romanist::Romanist(const Romanist& other)
    : name(other.name), years(other.years), books(other.books), bio(other.bio) {cout << "Вызван конструктор копирования для Romanist\n";}

Romanist::~Romanist() {cout << "Вызван деструктор для Romanist\n";}

void Romanist::set_name(string n) {
    name = n;
}

string Romanist::get_name() {
    return name;
}

void Romanist::set_years(string y) {
    years = y;
}

string Romanist::get_years() {
    return years;
}

void Romanist::set_books(string b) {
    books = b;
}

string Romanist::get_books() {
    return books;
}

void Romanist::set_bio(string b) {
    bio = b;
}

string Romanist::get_bio() {
    return bio;
}

void Romanist::display_obj() {
    cout << "Romanist Name: " << name << endl;
    cout << "Years: " << years << endl;
    cout << "Books: " << books << endl;
    cout << "Bio: " << bio << endl;
}

void Romanist::change_info() {
    cin.ignore();
    cout << "Enter new name: \n";
    getline(cin, name);
    cout << "Enter new years: \n";
    getline(cin, years);
    cout << "Enter new books: \n";
    getline(cin, books);
    cout << "Enter new bio: \n";
    getline(cin, bio);
}

void Romanist::save_in_file(ostream& out) {
    out << "Romanist" << endl;
    out << name << endl;
    out << years << endl;
    out << books << endl;
    out << bio << endl;
}

void Romanist::load_from_file(istream& in) {
    getline(in, name);
    getline(in, years);
    getline(in, books);
    getline(in, bio);
}
