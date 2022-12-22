//
// Created by Daria on 13.10.2022.
//

#include "Array.h"


Array::Array()
{
    this-> size = 50;
    this-> length = 0;
    this->array = new float[this->size];
}


Array::Array(int size)
{
    this->size = size;
    this->length = 0;
    this->size2 = size;
    this->array = new float[this->size];
    for(int i=0; i<size;i++){
        add(i);
    }

}

Array::Array(const Array &other){
    this->size= other.size;
    this->array = new float[other.size];
    for(int i=0;i <other.size; i++)
    {
        this->array[i] = other.array[i];
    }
};

Array::~Array(){
    delete[] array;
};

void Array::add(float  val)
{
    this-> array [this-> length] = val;
    this-> length ++;
}

void Array::remove(int index) {
    if(index>size){
        throw out_of_range("The index is not found");
    }
    int k = this->size;
    for(int i = index;i< this->size-1; i++)
    {
        this->array[i] = this->array[i+1];
    }
    this->array[this->size-1] = 0;
}

void  Array::insert(int index, float val) {
    if (index > size){
        cout<<"There are\t"<< this->size<<"\telements"<<endl;
        throw out_of_range("The array contains less elements");
    }
    int size2 = this->size +1;
    float * newArr = new float [size2];

    memcpy( newArr, array, size * sizeof(int) );

    this->size = size2;
    delete [] array;
    array = newArr;
    for (int i = size; i > index; i--)
    {
        this->array[i] = this->array[i-1];

    }
    this->array[index] = val;
}

void Array::clear() {
    for(int i = 0; i< this->size; i++)
    {
        this->array[i] = 0;
    }

}
void  Array::contains(float val) {
    int value = 0;
    for (int i = 0; i < this->size; i ++)
    {
        if (this->array[i] == val)
        {
            cout<<"Exist"<<endl;

        }
        else{
            value ++;
        }
        if (value== this->size)
        {
            cout<< "Not Found"<<endl;

        }
    }
}

float Array::get(int index)
{
    if(index > size){
        throw out_of_range("Not Found");
    }
    else{

        return this->array[index];
    }

}

void Array::set(int index, float val){
    if (index > size){
        throw out_of_range("Not Excist");
    }
    this-> array [index] = val;
}

void Array::isEmpty() {
    int val = 0;
    for(int i =0; i< this->size; i++)
    {
        if (this->array[i] == 0)
        {
            val ++;
        }

    }
    if (val == size){
        cout<<"Empty"<<endl;
    }
    else{
        cout<<"Not Empty"<<endl;
    }
}
void Array::subList(int index, int index2) {

    for(int i = index; i < index2; i ++)
    {
        cout<< array[i]<<endl;

    }
}


char* Array::cStr() const{
    int len;
    int l;
    if (array == nullptr) return nullptr;
    l = digitCount(array, size);
    char *buf = new char[l + size * size];
    len = 0;
    for (int i = 0; i < size; i++) {
        len += std::sprintf(buf + len * sizeof(char), "%f", array[i]);
        if (i != size - 1) {
            len += strCat(buf, len, (' '));
        }
        else {
            len += strCat(buf, len, ('\0'));
        }
    }
    return buf;

}
int Array::digitCount(float *array, float order2) {
    Array other(order2);

    for (int i = 0; i < order2; i++) {
        other.array[i] = array[i];
    }
    int len;
    len = 0;
    for (int i = 0; i < order2; i++) {
        while (other.array[i] > 0) {
            len++;
            other.array[i] = other.array[i] / 10;
        }
    }
    return len;
}

int Array::strCat(char *buf, int len, char elem) {
    return std::sprintf(buf + len * sizeof(char), "%c", elem);
}
float &Array::operator()(int index) {
    cout<<array[index]<<endl;
    return this->array[index];
}
Array Array::operator*(int val) {

    for (int j = 0; j < size; j ++){
        array[j] = array[j] * val;

    }
    Array temp(size);
    for (int i = 0; i <size; i ++){
        temp.array[i] = array[i];
    }
    return temp;

}
Array Array::operator--() {
    int size2 = this->size -1;
    float * newArr = new float [size2];

    memcpy( newArr, array, size * sizeof(int) );

    this->size = size2;
    delete [] array;
    array = newArr;

    Array temp(size);
    for (int i = 0; i <size; i ++){
        temp.array[i] = array[i];
    }
    return temp;


}
Array Array::operator+(int val) {

    int size2 = this->size +1;
    float * newArr = new float [size2];

    memcpy( newArr, array, size * sizeof(int) );

    this->size = size2;
    delete [] array;
    array = newArr;
    array[size-1] = val;
    Array temp(size);
    for (int i = 0; i <size; i ++){
        temp.array[i] = array[i];
    }
    return temp;


}

Array Array::operator=(const Array &other) {
    if (this != &other) {
        delete[] array;
        size = other.size;
        array = new float [other.size];

        for (int i = 0; i < other.size; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

Array Array::operator+(const Array &other) {
    int order;
    int max = size;
    int min = other.size;
    if(max > min ){
        order = min;
    }
    else{
        order = max;
    }
    Array temp(order);
    for (int i =0; i <order; i++)
    {
        temp.array[i] = array[i] + other.array[i];
        //cout<<temp.get(i)<<endl;
        //temp.set(i, array[i] +other.array[i]);
    }
    return temp;
}