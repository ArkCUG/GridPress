#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct UnitGrid{
    int x;
    int y;
    int len;
    int val;
};
//稀疏矩阵处理办法、分块压缩等方法
class Matrix{
    /*
        Base structure of something like 2d matrix
    */
private:
    vector<vector<int>> matrix;
    int row=0;
    int col=0;
    vector<UnitGrid> looseMatrix;
    map<int,vector<pair<int,int>>>hash;
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
    vector<vector<int>>getMatrixOrigin(){
        return matrix;
    }
};

void Matrix::blockEncode(){
    vector<vector<bool>>signs(matrix.size(),vector<bool>(matrix[0].size(),false));
    for(int i=0;i<signs.size();i++){
        for(int j=0;j<signs.size();j++){
            if(hash.find(matrix[i][j])==hash.end()){
                pair<int,vector<pair<int,int>>>in;
                in.first=matrix[i][j];
                pair<int,int>coord(i,j);
                in.second.push_back(coord);
                hash.insert(in);
            }else{
                pair<int,int>coord(i,j);
                hash[matrix[i][j]].push_back(coord);
            }
        }
    }
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
