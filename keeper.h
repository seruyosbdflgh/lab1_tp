#pragma once
#include "base.h"
#include "fantast.h"
#include "poet.h"
#include "romanist.h"
#include <fstream>
using namespace std;

class Keeper
{
private:
    struct El
    {
        El* next;
        Base* value;
    };
    El* head;
    El* tail;
    int count;
    
public:
    Keeper();
    Keeper(El* head, El* tail, int c);
    Keeper(Keeper& other);
    void delete_head();
    void clear();
    void print_keeper();
    int get_count();
    void add(Base* other, int c);
    Keeper& delete_el(int n);
    Keeper& edit_el(int n);
    Keeper& operator!();
    friend Keeper& operator++(Keeper& K, int);
    void save_to_file(const string& filename);
    void load_from_file(const string& filename);
    ~Keeper();
};
