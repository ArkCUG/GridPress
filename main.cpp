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
    while(getline(ifs,s)){
        cout<<s<<endl;
    }
    return 0;
}