#ifndef POLY_H
#define POLY_H

#include<iostream>
#include<cmath>
#include"poly.h"
using namespace std ;
class polynomial
{
    //protected:
    public:
    int* coeff;
    int size;
    int capacity;
    
    polynomial(int ); //1 constructor
    polynomial(const polynomial& rhs); //6
    polynomial &operator=(polynomial& rhs);//6
    ~polynomial();//6

    polynomial& operator+=(const polynomial& rhs);
    polynomial operator+(const polynomial& rhs) const;//7
    polynomial operator*(polynomial& rhs);//13
    polynomial& operator-=(const polynomial& rhs) ;
    polynomial operator-(const polynomial& rhs) const ;//13
    friend ostream& operator<<(ostream& out, const polynomial& p);//14

    int getCoefficient(int power); //4
    void setCoefficient(int,int );//12

    void resize(int pow);
    void addTerm(int co,int pw); //2 adTerm
    int degree (); //3
    int operator()(int value); //5

    void clear();//11
    void derivative();//8
    void Antiderivative();//9
    void addtoCoefficient(int c,int p );//10
};

#endif