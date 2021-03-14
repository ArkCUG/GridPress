#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

bool checkRect(vector<vector<int>>& src,int i,int j,int l){
    int r=i+l;
    int c=j+l;
    if(src[r][c]!=src[i][j])return false;
    
}

int detectLength(vector<vector<int>>& src,int i,int j){
    int val=src[i][j];
    for(int l=1;l<src.size()-i&&l<src.size()-j;l++){

        l++;
    }
}

int main(){
    ifstream ifs("source.txt");
    if(!ifs){
        cout<<"No such file named source.txt"<<endl;
        return -1;
    }
    string s;
    vector<vector<int>> dataset;
    while(getline(ifs,s)){
        int i;
        cout<<s<<endl;
        istringstream iss(s);
        vector<int>tmp;
        while(iss>>i){
            cout<<i<<endl;
            tmp.push_back(i);
        }
        dataset.push_back(tmp);
    }
    cout<<dataset.size()<<dataset[0].size()<<endl;
    return 0;
}