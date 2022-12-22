//
// Created by Daria on 09.11.2022.
//
#include "Array.h"


LinkedList ::LinkedList() {
    count = 0;
    head = nullptr;


}

LinkedList::LinkedList(int val) {
    count = 0;
    head = nullptr;
    for (int i = 0; i<val+1; i++)
    {
        add(i);
    }
}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::add(float data) {
    if (head == nullptr){
        head = new Node(data);
    }
    else
    {
        Node *current = this->head;
        while(current->pNext != nullptr){
            current = current->pNext;
        }
        current->pNext = new Node(data);
    }
    count++;
}

void LinkedList::remove(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node *previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }
        Node *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        delete toDelete;
        count--;
    }
}

void LinkedList::insert(int index, float val) {

    if(index == 0)
    {
        push_front(val);
    }
    else{
        Node *previous = this->head;
        for(int i = 0;i < index-1; i++ )
        {
            previous = previous->pNext;
        }
        Node *newNode = new Node(val, previous->pNext);
        previous->pNext = newNode;
        count++;
    }
}

void LinkedList::clear() {
    while (count)
    {
        delFirst();
    }
}

void LinkedList::contains(float val) {
    int size = 0;
    Node *current = this->head;
    while(current!= nullptr)
    {
        if (current->data == val){
            cout<< "Yes"<<endl;
        }

        else{
            size++;
        }
        if (size == count){
            cout<<"NO"<<endl;
        }

        current = current->pNext;

    }
}

float LinkedList::get(int val) {
    int size = 0;
    Node *current = this->head;
    while(current!= 0)
    {
        if (size == val){
            return current->data;
        }
        size++;
        current = current->pNext;

    }
}

void LinkedList::set(int index, float val) {

    if(index == 0)
    {
        Node *previous = this->head;
        previous->data = val;
    }
    else{
        Node *previous = this->head;
        for(int i = 0;i < index; i++ )
        {
            previous = previous->pNext;
        }
        previous->data = val;

    }
}

void LinkedList::isEmpty() {
    int size = 0;
    Node *current = this->head;

    if (head == nullptr) {
        cout << "Empty" << endl;
    } else {
        while (current != nullptr) {
            if (current->data == 0) {
                size++;
            }
            current = current->pNext;
        }
        if (size == count) {
            cout << "Empty" << endl;
        }
        else{
            cout << "Not Empty" << endl;
        }
    }
}

void LinkedList::subList(int index, int index2) {
    int size = 0;
    Node *current = this->head;

    while(current != 0)
    {
        if (size == index){
            for (int i = index; i < index2+1; i++)
            {
                cout<<current->data<<endl;
                current = current->pNext;
            }
        }
        size++;
        current = current->pNext;
    }
}

void LinkedList::delFirst() {
    Node *temp = head;
    head = head->pNext;
    delete temp;
    count --;
}

void  LinkedList::print() {

    for (int i =0; i< getCount(); i++)
    {
        cout<< get(i)<<endl;
    }

}

void LinkedList::push_front(int val) {
    head = new Node(val, head);
    count++;
}

void LinkedList::pop_front()
{
    Node *temp = head;
    head = head->pNext;
    delete temp;
    count--;
}

