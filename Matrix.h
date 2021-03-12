#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct UnitGrid{
    int x;
    int y;
    int val;
};
class Matrix{
    /*
        Base structure of something like 2d matrix
    */
private:
    vector<vector<int>> matrix;
    int row=0;
    int col=0;
    vector<UnitGrid> looseMatrix;
public:
    Matrix(vector<vector<int>> datasrc){
        matrix=datasrc;
        if(datasrc.size()!=0){
            row=matrix.size();
            if(datasrc[0].size()!=0)
                col=matrix[0].size();
        }
    }
};
#endif