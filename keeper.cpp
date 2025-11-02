#include "keeper.h"
#include <stdexcept>

Keeper::Keeper() : head(nullptr), tail(nullptr), count(0) {
    cout << "Вызван конструктор без параметров для Keeper\n";
}

Keeper::Keeper(El* head, El* tail, int count) : head(head), tail(tail), count(count) {
    cout << "Вызван конструктор с параметрами для Keeper\n";
}

Keeper::Keeper(Keeper& other) : head(other.head), tail(other.tail), count(other.count) {
    cout << "Вызван конструктор копирования для Keeper\n";
}

Keeper::~Keeper() {
    cout << "Вызван деструктор для Keeper класса\n";
    clear();
}

void Keeper::delete_head() {
    if (!head) throw std::runtime_error("Попытка удалить элемент из пустого контейнера");
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
        cout << "Данных нет" << endl;
        return;
    }
    int i = 0;
    while (temp != nullptr) {
        cout << i + 1 <<" - ";
        if (temp->value) {
            temp->value->display_obj();
        } else {
            cout << "Данных нет";
        }
        cout << " " << endl;
        temp = temp->next;
        i++;
    }
}

Keeper& Keeper::delete_el(int n) {
    if (n < 0 || n >= count) {
        throw std::out_of_range("Неправильный индекс элемента");
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
        throw std::out_of_range("Неверный индекс для добавления элемента");
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
    cout << "Объект добавлен.\n";
}

Keeper& Keeper::edit_el(int n) {
    if (n < 1 || n > count) {
        throw std::out_of_range("Неправильный индекс элемента");
    }
    El* temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }
    if (temp->value) {
        temp->value->change_info();
    } else {
        throw std::runtime_error("Нет данных для редактирования");
    }
    return *this;
}

Keeper& Keeper::operator!() {
    int index = this->get_count();
    if (index > 0) {
        this->delete_el(index - 1);
    } else {
        cout << "Нечего удалять. Список пуст." << endl;
    }
    return *this;
}

Keeper& operator++(Keeper& other, int) {
    if (other.tail && other.tail->value) {
        other.tail->value->change_info();
    } else {
        throw std::runtime_error("Нет элементов для изменения.");
    }
    return other;
}

void Keeper::save_to_file(const string& filename) {
    ofstream out(filename);
    if (!out) {
        throw std::runtime_error("Ошибка открытия файла для записи");
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
        throw std::runtime_error("Ошибка открытия файла для загрузки");
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
                throw std::runtime_error("Неизвестный тип объекта: " + tag);
            }
            object->load_from_file(in);
            this->add(object, this->get_count());
        } catch (const std::exception& e) {
            cerr << "Ошибка при добавлении объекта: " << e.what() << endl;
            delete object;
        }
    }
    in.close();
}
