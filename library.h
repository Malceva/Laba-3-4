//
// Created by Daria on 13.10.2022.
//

#ifndef MATRIXX_LIBRARY_H
#define MATRIXX_LIBRARY_H

#endif //MATRIXX_LIBRARY_H
#ifndef UNTITLED7_LIBRARY_H
#define UNTITLED7_LIBRARY_H

#include <iostream>
#include "Array.h"
using namespace std;

class Matrix {
public:
    Matrix(); //конструктор
    Matrix(int ranked); //конструктор с параметрами
    Matrix(const Matrix &Copy); //конструктор копирования
    ~Matrix(); //деструктор
    float getMatrix (int i, int j); //получение матрицы
    void setMatrix (int i, int j, float v); //значение матрицы
    char *toString() const; //матрица в строковом представлении
    void transpose(); //транспонирование
    Matrix operator+(const Matrix &Copy); //сложение
    Matrix operator=(const Matrix &Copy); //присваивание
    Matrix operator-(const Matrix &Copy);
    Matrix operator*(const Matrix &Copy);
    Matrix operator*(int val);
    Matrix operator+(int val);
    Matrix operator-(int val);
    long &operator()();
    int opr(Matrix *mat, int order);
    void GetMatr(Matrix *mat, Matrix *p, int i, int j, int order);
    virtual void solve(Array *b){};

private:
    int rank; //порядок матрицы
    //int **matrix; //набор элементов
    Array* matrix;
    static int strSave(char *buf, int len, char e); //статистическй метод сохранения символов
    static int dCount(Array *mat, int r); //статистическй метод подсчёта цифр
};

class Kramer : public Matrix{
public:
    Kramer(); //конструктор
    Kramer(int ranked); //конструктор с параметрами
    ~Kramer(); //деструктор
    float get (int i, int j); //получение матрицы
    void set (int i, int j, float v); //значение матрицы
    char *toString() const; //матрица в строковом представлении

    int opr(Kramer *mat, int order); // рекурсивный метод нахождения определителя
    void GetMatr(Kramer *mat, Kramer *p, int i, int j, int order);// перестановка элементов матрицы по диагонали
    int column(Kramer *mat, int h, Array *b);// перестановка колонок

    void solve(Array *b);

private:
    int rank; //порядок матрицы
    Array* matrix;
    static int strSave(char *buf, int len, char e); //статистическй метод сохранения символов
    static int dCount(Array *mat, int r); //статистическй метод подсчёта цифр
};
class Gauss : public  Matrix{
public:
    Gauss(); //конструктор
    Gauss(int ranked); //конструктор с параметрами
    ~Gauss(); //деструктор
    float get (int i, int j); //получение матрицы
    void set (int i, int j, float v); //значение матрицы
    char *toString() const; //матрица в строковом представлении
    float Gause(Gauss *mat, Array*b, int position, int position2);
    void solve(Array *b);

private:
    int rank; //порядок матрицы
    Array* matrix;
    static int strSave(char *buf, int len, char e); //статистическй метод сохранения символов
    static int dCount(Array *mat, int r); //статистическй метод подсчёта цифр

};
#endif //UNTITLED7_LIBRARY_H
