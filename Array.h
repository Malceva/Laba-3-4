//
// Created by Daria on 13.10.2022.
//

#ifndef MATRIXX_ARRAY_H
#define MATRIXX_ARRAY_H

#endif //MATRIXX_ARRAY_H
#ifndef __CLASSARRAY_H
#define __CLASSARRAY_H

#include <iostream>
#include <exception>

using namespace std;

class List{
public:
    virtual void add(float val) = 0;
    virtual void remove(int index) =0;
    virtual void insert(int index, float val) = 0;
    virtual  void  clear() = 0;
    virtual void contains(float val) =0;
    virtual float get(int  index) = 0 ;
    virtual  void  set(int  index, float val) = 0;
    virtual void isEmpty() = 0;
    virtual  void subList(int index, int index2) = 0;

};
class Array : public  List{

public:
    Array ();// конструктор по умолчанию
    Array(int capacity);// конструктор с параметрами
    Array(const Array &other);// Конструктор копирования
    ~Array();// Деструктор*/

    void add(float val) ;// добавление в конец
    void remove(int index) ;// удаление по индексу
    void insert(int index, float val) ; //замена числа
    void clear(); // удаляет все элементы из списка
    void contains(float val) ;// проверка на включение
    float get(int index);// получение элемента массива
    void set(int index, float val) ;// вставка по индексу
    void isEmpty(); //проверяет на наличие элементов в массиве
    void subList(int index, int index2);// получение среза массива
    char *cStr() const;
    Array operator=(const Array &other);
    Array operator+(const Array&other);
    float &operator()(int index);
    Array operator*(int val);
    Array operator+(int val);
    Array operator--();
private:

    int size  ; // емкость массива
    int length  ; // фактическая длина массива
    float * array; // массив, в котором хранятся данные
    int size2 ; // емкость для 2-го массива
    static int digitCount(float *array, float order2);
    static int strCat(char *buf, int len, char elem);


};


class LinkedList: public List{
public:
    LinkedList();
    LinkedList(int val);
    ~LinkedList();
    void  print();
    int getCount(){ return count;}
    void push_front(int val);
    void pop_front();
    void delFirst();
    void add(float val);
    void remove(int index);
    void insert(int index, float val);
    void clear();
    void contains(float val);
    float get(int index);
    void set(int index, float val);
    void isEmpty();
    void subList(int index, int index2);



private:
    class Node{
    public:
        Node *pNext;
        int data;
        Node(int  data, Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };
    int count;
    Node *head;
};


class Myexception: public  exception{
public:
    Myexception(const char*msg): exception()
    {

    }
private:

};


#endif /*__CLASSARRAY_H*/