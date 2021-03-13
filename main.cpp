#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Matrix.h"

using namespace std;

struct CodeUnit{
    int x;
    int y;
    int len;
    int val;
};

void getUnitEncode(vector<vector<int>>&m){
    map<int,vector<pair<int,int>>>mat;
    for(int i=0;i<m.size();i++){
        for(int j=0;j<m.size();j++){
            if(mat.find(m[i][j])==mat.end()){
                pair<int,int>coord(i,j);
                pair<int,vector<pair<int,int>>>in(m[i][j],vector<pair<int,int>>(0));
                in.second.push_back(coord);
                mat.insert(in);
            }
            else{
                pair<int,int>coord(i,j);
                mat[m[i][j]].push_back(coord);
            }
        }
    }
}

int main(){
    ifstream ifs("source.txt");
    if(!ifs){
        cout<<"No such file named source.txt"<<endl;
        return -1;
    }
    string s;
    vector<vector<int>>matrix;
    while(getline(ifs,s)){
        cout<<s<<endl;
        istringstream iss(s);
        vector<int> tmp;
        int a;
        while(iss>>a){
            tmp.push_back(a);
        }
        matrix.push_back(tmp);
    }
    cout<<matrix.size();
    getUnitEncode(matrix);
    return 0;
}