#ifndef MATRIX.H
#define MATRIX.H

#include <iostream>
#include <string>
#include <vector>

template <typename T>
class matrix {
    private:
        int rowNum;
        int colNum;

    public:
        Matrix(int r, int c) : rowNum(r), colNum(c) {}

        virtual void put(int r, int c, T value) = 0;                //insert value into [r,c]
        T get(int r, int c) = 0;                         //get value at [r,c]
        virtual void display() = 0;                                 //display the matrix
        virtual void toString(int loc, string directon) = 0;        //get row/column as a string

        virtual void add(const matrix& inputMatrix) = 0;            //add two matrix
        virtual void subtract(const matrix& inputMatrix) = 0;       //substract two matrix
        virtual void multiply(const matrix& inputMatrix) = 0;       //multiply two matrix
        virtual void divide(const matrix& inputMatrix) = 0;         //divide two matrix

        virtual void rowOp(int r1, int c1, int r2, int c2) = 0;     //row operation: R1 = c1*R1 + c2*R2
        virtual matrix<T> echelonf() = 0;                           //get echelon form
        virtual matrix<T> rref() = 0;                               //get reduceed echelon form
        virtual int determinant() = 0;                              //get determinant
        virtual matrix<T> transpose() = 0;                          //get transpose of matrix
        virtual matrix<T> inverse() = 0;                            //get matrix inverse
        virtual int eigenval() = 0;                                 //get eigen values
        virtual std::vector<T> eigenvec() = 0;                      //get eigen vectors
        virtual bool inSpan(std::vector<T> b) = 0;                  //determine if a vector b is within the span(in column space/ being the linear combination) of matrix
        virtual std::vector<T> solve(std::vector<T> b) = 0;         //determine type of solution(unique, infinite, none) & solve the matrix with the input vector b
        virtual std::vector<matrix> diagonize() = 0;                //diagnoize the matrix
        virtual std::vector<matrix> LUfactor() = 0;                 //Perform LU factorization
        virtual int norm(string normType) = 0;                      //Get the norm(1-norm, infinity norm, euclidean norm) of a matrix

        int rank();                                                 //get rank of matrix
        int nullity();                                              //get nullity of matrix
        int dimension();                                            //get dimension of matrix
};

#endif