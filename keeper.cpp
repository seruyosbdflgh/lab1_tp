#include "keeper.h"
#include <stdexcept>

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {
    cout << "Default constructor called for Keeper\n";
}

Keeper::Keeper(El* head, El* tail, int count) : head(head), tail(tail), count(count) {
    cout << "Parameterized constructor called for Keeper\n";
}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Copy constructor called for Keeper\n";
}

Keeper::~Keeper() {
    cout << "Destructor called for Keeper class\n";
    clear();
}

void Keeper::delete_head() {
    if (!head) throw std::runtime_error("Attempt to delete element from empty container");
    El* temp = head;
    head = head->next;
    delete temp->value;
    delete temp;
    count--;
    if (count == 0) {
        tail = nullptr;
    }
}

void Keeper::clear() {
    while (head != nullptr)
        delete_head();
}

int Keeper::get_count() {
    return count;
}

void Keeper::print_keeper() {
    El* temp = head;

    if (count == 0) {
        cout << "No data available" << endl;
        return;
    }
    int i = 0;
    while (temp != nullptr) {
        cout << i + 1 <<" - ";
        if (temp->value) {
            temp->value->display_obj();
        } else {
            cout << "No data available";
        }
        cout << " " << endl;
        temp = temp->next;
        i++;
    }
}

Keeper& Keeper::delete_el(int n) {
    if (n < 0 || n >= count) {
        throw std::out_of_range("Invalid element index");
    }

    El* temp = head;
    if (n == 0) {
        head = head->next;
        delete temp->value;
        delete temp;
        count--;
        if (count == 0) {
            tail = nullptr;
        }
        return *this;
    }
    for (int i = 0; i < n - 1; i++) {
        temp = temp->next;
    }
    El* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == tail) {
        tail = temp;
    }
    delete toDelete->value;
    delete toDelete;
    count--;

    return *this;
}

void Keeper::add(Base* obj, int index) {
    if (index < 0 || index > count) {
        throw std::out_of_range("Invalid index for adding element");
    }

    El* newElement = new El;
    newElement->value = obj;
    newElement->next = nullptr;

    if (index == 0) {
        newElement->next = head;
        head = newElement;
        if (count == 0) {
            tail = head;
        }
    } else {
        El* temp = head;
        for (int i = 1; i < index; i++) {
            temp = temp->next;
        }
        newElement->next = temp->next;
        temp->next = newElement;
        if (newElement->next == nullptr) {
            tail = newElement;
        }
    }
    count++;
    cout << "Object added.\n";
}

Keeper& Keeper::edit_el(int n) {
    if (n < 1 || n > count) {
        throw std::out_of_range("Invalid element index");
    }
    El* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }
    if (temp->value) {
        temp->value->change_info();
    } else {
        throw std::runtime_error("No data available for editing");
    }
    return *this;
}

Keeper& Keeper::operator!() {
    int index = this->get_count();
    if (index > 0) {
        this->delete_el(index - 1);
    } else {
        cout << "Nothing to delete. The list is empty." << endl;
    }
    return *this;
}

Keeper& operator++(Keeper& other, int) {
    if (other.tail && other.tail->value) {
        other.tail->value->change_info();
    } else {
        throw std::runtime_error("No elements available for modification.");
    }
    return other;
}

void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Error opening file for writing");
    }
    El* current = head;
    while (current != nullptr) {
        current->value->save_in_file(out);
        current = current->next;
    }
    out.close();
}

void Keeper::load_from_file(const string& filename) {
    ifstream in(filename);
    if (!in) {
        throw std::runtime_error("Error opening file for loading");
    }
    string tag;
    while (getline(in, tag)) {
        if (!tag.empty() && tag.back() == '\r') {
            tag.pop_back();
        }
        Base* object = nullptr;
        try {
            if (tag == "Romanist") {
                object = new Romanist();
            } else if (tag == "Poet") {
                object = new Poet();
            } else if (tag == "Fantast") {
                object = new Fantast();
            } else {
                throw std::runtime_error("Unknown object type: " + tag);
            }
            object->load_from_file(in);
            this->add(object, this->get_count());
        } catch (const std::exception& e) {
            cerr << "Error adding object: " << e.what() << endl;
            delete object;
        }
    }
    in.close();
}