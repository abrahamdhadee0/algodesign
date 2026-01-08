// /c:/Users/perha/OneDrive/Desktop/DSA/linked list/dll/1.cpp
// Doubly linked list (template) with basic operations and a short demo.

#include <iostream>
#include <stdexcept>

template<typename T>
class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(const T& v) : value(v), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t sz;

    Node* node_at(size_t index) const {
        if (index >= sz) return nullptr;
        Node* cur;
        if (index < sz / 2) {
            cur = head;
            for (size_t i = 0; i < index; ++i) cur = cur->next;
        } else {
            cur = tail;
            for (size_t i = sz - 1; i > index; --i) cur = cur->prev;
        }
        return cur;
    }

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), sz(0) {}
    ~DoublyLinkedList() { clear(); }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

    bool empty() const { return sz == 0; }
    size_t size() const { return sz; }

    void push_front(const T& value) {
        Node* n = new Node(value);
        n->next = head;
        if (head) head->prev = n;
        head = n;
        if (!tail) tail = n;
        ++sz;
    }

    void push_back(const T& value) {
        Node* n = new Node(value);
        n->prev = tail;
        if (tail) tail->next = n;
        tail = n;
        if (!head) head = n;
        ++sz;
    }

    void pop_front() {
        if (!head) throw std::out_of_range("pop_front on empty list");
        Node* old = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete old;
        --sz;
    }

    void pop_back() {
        if (!tail) throw std::out_of_range("pop_back on empty list");
        Node* old = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete old;
        --sz;
    }

    // insert at index (0..size). index == size -> push_back
    void insert_at(size_t index, const T& value) {
        if (index > sz) throw std::out_of_range("insert_at index out of range");
        if (index == 0) { push_front(value); return; }
        if (index == sz) { push_back(value); return; }
        Node* succ = node_at(index);
        Node* pred = succ->prev;
        Node* n = new Node(value);
        n->prev = pred;
        n->next = succ;
        pred->next = n;
        succ->prev = n;
        ++sz;
    }

    // erase at index (0..size-1)
    void erase_at(size_t index) {
        if (index >= sz) throw std::out_of_range("erase_at index out of range");
        Node* cur = node_at(index);
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        else tail = cur->prev;
        delete cur;
        --sz;
    }

    // returns first index of value or -1 if not found
    int find(const T& value) const {
        Node* cur = head;
        size_t idx = 0;
        while (cur) {
            if (cur->value == value) return static_cast<int>(idx);
            cur = cur->next;
            ++idx;
        }
        return -1;
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nxt = cur->next;
            delete cur;
            cur = nxt;
        }
        head = tail = nullptr;
        sz = 0;
    }

    void print_forward(std::ostream& os = std::cout) const {
        os << "[";
        Node* cur = head;
        bool first = true;
        while (cur) {
            if (!first) os << " <-> ";
            os << cur->value;
            first = false;
            cur = cur->next;
        }
        os << "]";
    }

    void print_backward(std::ostream& os = std::cout) const {
        os << "[";
        Node* cur = tail;
        bool first = true;
        while (cur) {
            if (!first) os << " <-> ";
            os << cur->value;
            first = false;
            cur = cur->prev;
        }
        os << "]";
    }
};

int main() {
    DoublyLinkedList<int> dll;
    dll.push_back(10);
    dll.push_back(20);
    dll.push_front(5);
    dll.insert_at(1, 7); // [5 <-> 7 <-> 10 <-> 20]

    std::cout << "Forward: ";
    dll.print_forward();
    std::cout << "\nBackward: ";
    dll.print_backward();
    std::cout << "\nSize: " << dll.size() << "\n";

    int idx = dll.find(10);
    std::cout << "Index of 10: " << idx << "\n";

    dll.erase_at(1); // remove 7
    std::cout << "After erase_at(1): ";
    dll.print_forward();
    std::cout << "\n";

    dll.pop_front();
    dll.pop_back();
    std::cout << "After pop_front & pop_back: ";
    dll.print_forward();
    std::cout << "\n";

    dll.clear();
    std::cout << "After clear, empty: " << std::boolalpha << dll.empty() << "\n";
    return 0;
}