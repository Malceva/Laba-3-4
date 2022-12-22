//
// Created by Daria on 05.12.2022.
//

#include "library.h"
#include <iostream>
#include "Array.h"


Gauss::Gauss(){
    rank = 0;
    matrix = nullptr;

}

Gauss::Gauss(int ranked) {
    rank = ranked;

    Array b(rank);
    //cout<<b.get(1)<<endl;

    matrix = new Array [rank];
    for (int i = 0; i < rank; i++)
        for (int j = 0; j < rank; j++)
            matrix[i].set(j, b.get(j));
}

Gauss::~Gauss()  {
    delete [] matrix;
}
float Gauss::get(int i, int j) {
    return matrix[i].get(j);
}
void Gauss::set(int i, int j, float v) {
    matrix[i].set(j,v);
}

int Gauss::strSave(char *buf, int len, char e) {
    return std::sprintf(buf + len * sizeof(char), "%c", e);
}

char* Gauss::toString() const {
    int l, len;
    if (matrix == nullptr) return nullptr;
    l = dCount(matrix, rank);
    char *buf = new char[l + rank * rank];
    len = 0;
    for (int i = 0; i < rank; i++) {
        for (int j = 0; j < rank; j++) {
            len += std::sprintf(buf + len * sizeof(char), "%f", matrix[i].get(j));
            if (j != rank - 1) {
                len += strSave(buf, len, (' '));
            }
        }
        if (i != rank - 1) {
            len += Gauss::strSave(buf, len, ('\n'));

        } else {
            len += Gauss::strSave(buf, len, ('\0'));
        }
    }
    return buf;
}

int Gauss::dCount(Array* mat, int r) {
    Gauss dif(r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            dif.matrix[i].set(j, mat[i].get(j));

        }
    }
    int len;
    len = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            while (dif.matrix[i].get(j) > 0) {
                len++;
                dif.matrix[i].set(j, dif.matrix[i].get(j)/10);
            }
        }
    }
    return len;
}

void Gauss::solve(Array *b) {
    Gauss p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j ,matrix[i].get(j));
        }
    }
    p.Gause(&p,b,0,0);
}

//рекурсивный метод Гаусса. Принимает саму матрицу, массив 4 столбец матрицы,
float Gauss::Gause(Gauss* mat, Array *b, int position, int position2) {
    Array x(3);
    for(int i = 0; i < rank; i++)
    {
        x.set(i, b->get(i));

    }

    Gauss p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j, mat->get(i, j));
        }
    }
    //если дошли до крайнего нижнего элемента в матрице, подставляем и вычисляем значения из уравнения
    if(position == rank -1){
        x.set(position, x.get(position)/ p.get(position,position2));
        p.set(position, position2, p.get(position,position2)/p.get(position,position2));
        cout<<"-------"<<endl;
        cout<<p.toString()<<endl;
        cout<<x.cStr()<<endl;
        int d;
        for (int i = rank-1; i != -1; i--){
            if(i == rank-1){
                cout<<x.get(rank-1)<<endl;
            }
            else{
                d = x.get(i);
                for(int j = rank-1; j >i; j--)
                {
                    d = d -x.get(j) * p.get(i,j);
                }
                cout<<d<<endl;
            }
        }
    }

    else{
        //значение k - строка и столбец от которой идут преобразования матрицы
        float k = mat->get(position, position2);
        //находит наибольший элемент в столбце
        for (int i = position+1; i< this->rank; i++)
        {
            if (k <mat->get(i, position2))
            {
                k = mat->get(i, position2);
            }
        }
        //меняет строчки местами
        for(int i = position; i < rank; i ++)
        {
            if(k == mat->get(i, position2))
            {
                for(int l=position; l <rank; l++)
                {
                    p.set(position,l,mat->get(i, l));
                    p.set(i,l,mat->get(position, l));
                }
                x.set(position, b->get(i));
                x.set(i, b->get(position));
            }
        }
        //делит всю строку на первый элемент из этой же строки
        for (int i =position; i< rank; i++)
        {
            float u = p.get(i,position2);
            for (int j = position2; j< rank; j ++){


                p.set(i, j, p.get(i,j)/u);

            }
            x.set(i, x.get(i)/u);

        }
        //вычитает строки
        for (int i = position + 1; i < rank; i ++)
        {
            for (int j = position2; j<rank; j++)
            {
                float y = p.get(position, j);
                p.set(i, j, p.get(i, j)-y);
            }
            x.set(i, x.get(i)-x.get(position));


        }
        // увеличиваем position и position2, т.к переходим на новую строчку и новый столбец
        position ++;
        position2 ++;
        p.Gause(&p, &x, position, position2);

    }

}