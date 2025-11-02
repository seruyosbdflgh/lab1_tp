#pragma once
#include "base.h"
#include <cstdlib>

class Poet: public Base {
    private:
        string name;
        string years;
        string poems;
    public:
        Poet();
        Poet(const string& n, const string& y, const string&p);
        Poet(const Poet& other);
        ~Poet();

        void set_name(string n);
        string get_name();
        void set_years(string y);
        string get_years();
        void set_poems(string p);
        string get_poems();

        void display_obj() override;
        void change_info() override;
        void save_in_file(ostream&) override;
        void load_from_file(istream&) override;

};
