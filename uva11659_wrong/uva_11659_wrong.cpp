#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> split(const string &s, const string &seperator){
    vector<string> result;
    typedef string::size_type string_size;
    string_size i = 0;

    while(i != s.size()){
        int flag = 0;
        while(i != s.size() && flag == 0){
            flag = 1;
            for(string_size x = 0; x < seperator.size(); ++x) {
                if (s[i] == seperator[x]) {
                    ++i;
                    flag = 0;
                    break;
                }
            }
        }
        flag = 0;
        string_size j = i;
        while(j != s.size() && flag == 0){
            for(string_size x = 0; x < seperator.size(); ++x) {
                if (s[j] == seperator[x]) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) {
                ++j;
            }
        }
        if(i != j){
            result.push_back(s.substr(i, j-i));
            i = j;
        }
    }
    return result;
}


int informants(const int i, const int a, const vector<vector<int> > query){

}


int main(){
    //vector<int> results(11,20);
    vector<vector<int> > query(800, vector<int>(2,0));
    vector<int> result;
    int i = 0;
    int a = 0;
    int cont = 0;
    string line;
    vector<string> splited_line;
    while (getline(cin, line)) {
        splited_line = split(line," ");
        i = stoi(splited_line[0]);
        a = stoi(splited_line[0]);
        if (i == 0 && a == 0){
            break;
        }
        for (int j = 0; j != a; ++j){
            getline(cin,line);
            splited_line = split(line," ");
            query[j][0]=stoi(splited_line[0]);
            query[j][1]=stoi(splited_line[1]);
        }
        result[cont] = informants(i, a, query);
        ++cont;
    }
    for (int j=0;j!=cont;++j){
        cout<<result[j]<<endl;
    }

}
