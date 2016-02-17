//
// Created by Bo Zhou on 2016-02-12.
//

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int kase;
    cin >> kase;
    while (kase--){
        vector<string> result;
        int num;
        cin >> num;
        while (num--){
            string info;
            cin >> info;
            int check = 0;
            for (int i = 0; i< result.size(); i++){
                if (result[i] == info){
                    check = 1;
                    break;
                }
            }
            if (check == 0){
                result.push_back(info);
            }

        }
        cout << result.size() << endl;
    }
    return 0;
}