#include "base_container.h"

template <typename T>

class List_Container_oneDir : public Base_Container<T> {
public:
    List_Container_oneDir() : elNum(0), first_node(nullptr), tmp_node(nullptr) { }

    List_Container_oneDir( List_Container_oneDir & other ) : elNum(0) {
        for( size_t i=0; i<other.size(); ++i) {
            this->push_back(other[i]);
        }
    }

    ~List_Container_oneDir() {
        Node *p = first_node;
        while(p) {
            tmp_node = p->next;
            delete p;
            p = tmp_node;
        }
    }

    struct Node {
        Node* next;
        T data;
    };

    void createCont( const int &sz ) {
        if (sz <= 0)
            throw std::range_error("out of range");
        for(int ii=0; ii<sz; ++ii) {
            push_back(static_cast<T>(ii));
        }

    }

    void show() const override {
        if (elNum == 0)
            throw std::out_of_range("out of range");

        Node *p = first_node;
        while (p) {
            std::cout << p->data << " ";
            p = p->next;
        }
        std::cout<<std::endl;
    }

    void push_back( const T & val ) override {
        Node* new_node = new Node{};
        if (size() == 0) {
            first_node = new_node;
        }
        else {
            tmp_node->next = new_node;
        }
        new_node->data = val;
        new_node->next = nullptr;
        tmp_node = new_node;
        elNum++;
    }


    void erase( const size_t ind ) override {
        if (elNum == 0) {
            throw std::out_of_range("index out of range");
        }
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        Node *p = first_node;
        tmp_node = nullptr;
        if (ind == 0) {
            tmp_node = first_node->next;
            first_node->next = nullptr;
            first_node = tmp_node;
        }
        else {
            size_t cntr = 0;
            while ( cntr != (ind-1) ) {
                tmp_node = p;
                p = p->next;
                cntr++;
            }
            if (elNum == 2 )
                first_node->next = nullptr;
            else
                tmp_node->next = p->next;
        }
       elNum--;
    }

    void insert( const size_t ind, const T & val) override {
        if ((ind > elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        Node *p = first_node;
        size_t cntr = 0;
        tmp_node = nullptr;
        Node *new_node = new Node{};
        new_node->data = val;
        if (ind == 0) {
            first_node = new_node;
        }
        while ( cntr != ind ) {
            tmp_node = p;
            p = p->next;
            cntr++;
        }
        if (tmp_node) tmp_node->next = new_node;
        new_node->next = p;
        elNum++;
    }

    size_t size() const override {
        return elNum;
    }

    T & operator[](const size_t ind) {
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        Node *p = first_node;
        size_t cntr = 0;
        while ( cntr != ind ) {
            p = p->next;
            cntr++;
        }
        return p->data;
    }


    //оператор перемещения
    List_Container_oneDir & operator = ( List_Container_oneDir && other) noexcept {
        first_node = other.first_node;
        other.first_node = nullptr;
        elNum = other.elNum;
        other.elNum = 0;
        return *this;

    }

    //конструктор сдвига
    List_Container_oneDir ( List_Container_oneDir && other ) noexcept {
        first_node = other.first_node;
        other.first_node = nullptr;
        elNum = other.elNum;
        other.elNum = 0;
    }

private:
    size_t elNum;
    Node *first_node;
    Node *tmp_node;
};







