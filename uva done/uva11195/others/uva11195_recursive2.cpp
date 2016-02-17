//
// Created by Bo Zhou on 2016-01-19.
//
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INITIAL_VALUE -1000

vector<int> queens(16, -100);
vector<vector<int> > bad_position(16, vector<int> (16, 0));
int result = 0;
int queen_size = 0;
string line;
int cont = 0;

void printtest(){
    for (int i=0;i!=queen_size;++i){
        printf("%d ",queens[i]);
    }
    printf("\n");
    for (int i=0; i!=queen_size;++i){
        for (int j=0;j!=queen_size;++j){
            printf("%d ",bad_position[i][j]);
        }
        printf("\n");
    }
}

int valid(int row, int col){
  //printtest();
    if (bad_position[row][col] == -30){
        return 0;
    }
    for (int i=0; i!=row; ++i){
        if (queens[i] == col || abs(i - row) == abs(queens[i] - col)){
            return 0;
        }
    }
    return 1;
}




void queenTest(int k, int n) {
    if(k>n){
        ++result;
    }
    else {
        for(int j=0;j<=n;++j){
            if (valid(k,j)) {
                queens[k] = j;
                queenTest(k+1, n);
            }
        }
    }
}

int main() {
    while (getline(cin, line)) {
        result = 0;
        queen_size = stoi(line);
        for (int i = 0; i != queen_size; ++i){
            queens[i]=INITIAL_VALUE;
            getline(cin,line);
            for (int j = 0; j != queen_size; ++j){
                if (line[j]=='*'){
                    bad_position[i][j]=-30;
                }else{
                    bad_position[i][j]=0;
                }
            }
        }
        ++cont;
        //    printtest();
        queenTest(0, queen_size-1);
        //printtest();
        printf("case %d: %d\n", cont, result);
        //fflush(stdout);
    }
    return 0;
}
