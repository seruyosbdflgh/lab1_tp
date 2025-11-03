#include "base.h"

Base::Base() {cout << "Default constructor called for Base class\n";}

Base::Base(const string& n) {cout << "Parameterized constructor called for Base class\n";}

Base::Base(const Base& other) {cout << "Copy constructor called for Base class\n";}

Base::~Base() {cout << "Virtual destructor called for Base class\n";}