#include "base_container.h"

const size_t reserved_mem = 4;

template <typename T>
class Sequence_Container : public Base_Container <T>{
public:
    Sequence_Container() : memSz(0), elNum(0)  {}

    //конструктор копирования
    Sequence_Container( const  Sequence_Container &cnt) {
        elNum = cnt.elNum;
        for (size_t i = 0; i< cnt.elNum; ++i) {
            mem[i] = cnt.mem[i];
        }
    }

    ~Sequence_Container() { delete []mem; }

    void show() const override {
       if (elNum == 0)
           std::cout << "Container is empty" << std::endl;
       else {
           for (size_t i = 0; i < elNum; ++i)
               std::cout << mem[i] << " ";
       }
       std::cout << std::endl;
    }

    void push_back( const T & val ) override {
        size_t i = 0;
        if(elNum >= memSz ) {
            memSz += reserved_mem;
            T *newMem = new T [memSz];
            for (i = 0; i < elNum; ++i) {
                newMem[i] = mem[i];
            }
            if (memSz != reserved_mem)
                delete[]mem;
            mem = newMem;
        }
        mem[elNum] = val;
        elNum++;
    }

    size_t size() const override {
        return elNum;
    }

    void erase( const size_t ind ) override {
        if ( elNum == 0 ) {
            throw std::out_of_range("out of range");
        }
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("out of range");
        }
        size_t i=0, j=0;
         T *newMem = new T [memSz];
         for (i = 0, j=0; i < elNum; ++i, ++j) {
            if (ind != 0) {
                if ( j == (ind-1) ) {
                    ++i;
                }
            }
            else if (i==0){
                ++i;
            }
            newMem[j] = mem[i];
         }
         delete[]mem;
         mem = newMem;
         elNum--;
    }

    void insert( const size_t ind, const T & val ) override {
        if ((ind >= memSz) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        size_t i=0, j=0;
        elNum++;
        T *newMem = new T [memSz];
        for (i=0, j=0; i < elNum; ++i, ++j) {
            if (i == ind) {
                newMem[i] = val;
                if (i != (elNum-1))
                    newMem[i+1] = mem[j];
                --j;
            }
            else
                newMem[i] = mem[j];
         }
        delete[]mem;
        mem = newMem;
    }

    T & operator[](const size_t ind) {
        if ((ind >= elNum) || ( ind < 0)) {
            throw std::out_of_range("index out of range");
        }
        return mem[ind];
    }

    //оператор перемещения
    Sequence_Container & operator = ( Sequence_Container && other) noexcept {
        if (this != &other) {
            std::swap(*this, other);
        }
        return *this;

    }

    //конструктор сдвига
    Sequence_Container ( Sequence_Container && other ) noexcept {
        mem = other.mem;
        other.mem = nullptr;
        memSz = other.memSz;
        other.memSz = 0;
        elNum = other.elNum;
        other.elNum = 0;
    }

    void createCont( const int &sz ) {
        if (sz <= 0)
            throw std::range_error("out of range");
        for(int ii=0; ii<sz; ++ii) {
            this->push_back(static_cast<T>(ii));
        }

    }

private:
    T *mem;
    size_t memSz, elNum;
};





