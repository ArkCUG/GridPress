#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct UnitGrid{
    int x;
    int y;
    int len;
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
    void blockEncode();
    void blockDecode();
};

void Matrix::blockEncode(){
    vector<vector<bool>>signs(matrix.size(),vector<bool>(matrix[0].size(),false));
}
void Matrix::blockDecode(){
    int length=0;
    for(vector<UnitGrid>::iterator it=looseMatrix.begin();it!=looseMatrix.end();it++){
        length=max(length,(*it).len+(*it).x);
        length=max(length,(*it).len+(*it).y);
    }
    vector<vector<int>>origin(length,vector<int>(length,0));
    matrix=origin;
    for(vector<UnitGrid>::iterator it=looseMatrix.begin();it!=looseMatrix.end();it++){
        for(int i=(*it).x;i<(*it).len+(*it).x;i++){
            for(int j=(*it).y;j<(*it).y+(*it).len;j++){
                matrix[i][j]=(*it).val;
            }
        }
    }
}
#endif