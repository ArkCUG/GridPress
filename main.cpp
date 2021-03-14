#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

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