//
// Created by Daria on 03.12.2022.
//
#include "library.h"
#include <iostream>
#include "Array.h"


Kramer::Kramer(){
    rank = 0;
    matrix = nullptr;

}

Kramer::Kramer(int ranked) {
    rank = ranked;

    Array b(rank);
    //cout<<b.get(1)<<endl;

    matrix = new Array [rank];
    for (int i = 0; i < rank; i++)
        for (int j = 0; j < rank; j++)
            matrix[i].set(j, b.get(j));
}

Kramer::~Kramer()  {
    delete [] matrix;
}
float Kramer::get(int i, int j) {
    return matrix[i].get(j);
}
void Kramer::set(int i, int j, float v) {
    matrix[i].set(j,v);
}

int Kramer::strSave(char *buf, int len, char e) {
    return std::sprintf(buf + len * sizeof(char), "%c", e);
}

char* Kramer::toString() const {
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
            len += Kramer::strSave(buf, len, ('\n'));

        } else {
            len += Kramer::strSave(buf, len, ('\0'));
        }
    }
    return buf;
}

int Kramer::dCount(Array* mat, int r) {
    Kramer dif(r);
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


void Kramer:: solve(Array *b) {

    Kramer p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j ,matrix[i].get(j));
            //p.set(i, j, mat->getMatrix(i, j));
        }
    }

    Kramer mat(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            mat.set(i, j ,matrix[i].get(j));
            //p.set(i, j, mat->getMatrix(i, j));
        }
    }


    int l;;
    int k = p.opr(&mat, this->rank);
    for (int i = 0; i < this->rank; i++)
    {
        l = mat.column(&mat, i , b)/k;
        //l = mat->column(mat, i, b)/k;
        cout<<l<<endl;
    }

}


int Kramer::column(Kramer *mat, int h, Array *b) {
    Kramer p(this->rank);
    for (int i =0; i < this->rank; i++)
    {
        for(int j = 0; j < this->rank; j++)
        {
            p.set(i, j, mat->get(i, j));
        }
    }
    int d;
    for(int j = 0; j < this->rank; j ++)
    {
        p.set(j, h , b->get(j));
        //p.setMatrix(j, h, b->get(j));

    }
    return d = p.opr(&p, this->rank);
}


int  Kramer::opr(Kramer *mat, int order) {
    int i, j, d, k, n;
    Kramer p(order);
    j = 0; d = 0;
    k = 1;
    n = order - 1;
    if (order<1) cout << "NO!";
    if (order == 1) {
        d = mat->get(0,0);
        //d = mat->getMatrix(0, 0);
        return d;
    }
    if (order == 2) {
        d = mat->get(0,0) *mat->get(1,1) - (mat->get(1,0)*mat->get(0,1));
        return d;
    }
    if (order>2) {
        for (i = 0; i<order; i++) {
            GetMatr(mat, &p, i, 0, order);
            d = d + k * mat->get(i, 0)* opr(&p, n);

            k = -k;
        }
    }
    return d;


}
void Kramer::GetMatr(Kramer *mat, Kramer *p, int i, int j, int order) {

    int ki, kj, di, dj;
    di = 0;
    for (ki = 0; ki<order - 1; ki++) {
        if (ki == i) {di = 1;
            dj = 0;
        }
        for (kj = 0; kj<order - 1; kj++) {
            if (kj == j) {
                dj = 1;
            }
            p->set(ki, kj, mat->get(ki+di, kj+dj));
        }
    }
}
