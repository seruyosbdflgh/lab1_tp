#include "base.h"

Base::Base() {cout << "Вызван конструктор без параметров для Base класса\n";}

Base::Base(const string& n) {cout << "Вызван конструктор с параметрами для Base класса\n";}

Base::Base(const Base& other) {cout << "Вызван конструктор копирования для Base класса\n";}

Base::~Base() {cout << "Вызван виртуальный деструктор для Base класса\n";}