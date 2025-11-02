#pragma once
#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    Base();
    Base(const string& n);
    Base(const Base& other);
    virtual ~Base();

    virtual void display_obj() = 0;
    virtual void change_info() = 0;
    virtual void save_in_file(ostream&) = 0;
    virtual void load_from_file(istream&) = 0;
};