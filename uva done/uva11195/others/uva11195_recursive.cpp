//
// Created by Bo Zhou on 2016-01-19.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using std::vector;

int result = 0;    

int valid(int row, int col, vector<int> queens, vector<vector<int> > bad_position){
    if (bad_position[row][col] == -30){
        return 0;
    }
    for (int i=0; i!=queens.size(); ++i){
        if (queens[i] == col || abs(i - row) == abs(queens[i] - col)){
            return 0;
        }
    }
    return 1;
}

void queenTest(vector<int> queens, vector<vector<int> > bad_position, int k, int n) {
    if(k>n){
        ++result;
    }
    else {
        for(int j=0;j<=n;j++){
            if (valid(k,j,queens,bad_position)) {
                queens[k] = j;
                queenTest(queens, bad_position, k+1,n); 
            }
        }
    }
}

int main() {
    int queen_size = 0;
    string line;
    int count = 0;
    while (getline(cin, line)) {
        result = 0;
        queen_size = stoi(line);
        vector<int> queens(queen_size, -100);
        vector<vector<int> > bad_position(queen_size, vector<int>(queen_size, 0));
        for (int i = 0; i != queen_size; ++i){
            getline(cin,line);
            for (int j = 0; j != line.size(); ++j){
                if (line[j]=='*'){
                    bad_position[i][j]=-30;
                }
            }
        }
        ++count;
        queenTest(queens,bad_position,0,queen_size-1);
        printf("case %d: %d\n", count, result);
    }
    return 0;
}
