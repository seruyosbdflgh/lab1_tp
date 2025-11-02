#pragma once
#include "base.h"
#include <cstdlib>

class Fantast: public Base {
    private:
        string name;
        string years;
        string books;
        string movies_by_books;
    public:
        Fantast();
        Fantast(const string& n, const string& y, const string&b, const string& m);
        Fantast(const Fantast& other);
        ~Fantast();

        void set_name(string n);
        string get_name();
        void set_years(string y);
        string get_years();
        void set_books(string p);
        string get_books();
        void set_movies(string b);
        string get_movies();

        void display_obj() override;
        void change_info() override;
        void save_in_file(ostream&) override;
        void load_from_file(istream&) override;

}; 
