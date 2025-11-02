#pragma once
#include "base.h"
#include <cstdlib>

class Romanist: public Base {
    private:
        string name;
        string years;
        string books;
        string bio;
    public:
        Romanist();
        Romanist(const string& n, const string& y, const string&b, const string& bio);
        Romanist(const Romanist& other);
        ~Romanist();

        void set_name(string n);
        string get_name();
        void set_years(string y);
        string get_years();
        void set_books(string b);
        string get_books();
        void set_bio(string bio);
        string get_bio();

        void display_obj() override;
        void change_info() override;
        void save_in_file(ostream&) override;
        void load_from_file(istream&) override;

};   
