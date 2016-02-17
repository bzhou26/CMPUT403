#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define INITIAL_VALUE -100
vector<int> queens(20, -100);
vector<vector<int> > bad_position(20, vector<int>(20, 0));

int valid(int row, int col){
    if (bad_position[row][col] == -1){
        return 0;
    }
    for (int i=0; i!=queens.size(); ++i){
        if (queens[i] == col || abs(i - row) == abs(queens[i] - col)){
            return 0;
        }
    }
    return 1;
}

int queenTest(int queen_size){
    int n = 0;
    int i = 0;
    int j = 0;
    while (i < queen_size){
        while (j < queen_size){
            if (valid(i, j)) {
                queens[i] = j;
                j = 0;
                break;
            }else{
                ++j;
            }
        }
        if(queens[i] == INITIAL_VALUE){
            if (i==0){
                break;
            }else{
                j = queens[--i] + 1;
                queens[i]= INITIAL_VALUE;
                continue;
            }
        }
        if (i == queen_size - 1){
            ++n;
            //print(queens);
            j = queens[i] + 1;
            queens[i] = INITIAL_VALUE;
            continue;
        }
        ++i;
    }
    return n;
}

int main(){
    int queen_size = 0;
    int count=0;
    string line;
    while (getline(cin, line)) {
        queen_size = stoi(line);
        for (int i = 0; i != queen_size; ++i){
            queens[i]=INITIAL_VALUE;
            getline(cin,line);
            for (int j = 0; j != line.size(); ++j){
                if (line[j]=='*'){
                    bad_position[i][j]=-1;
                }else{
                    bad_position[i][j]=0;
                }
            }
        }
        int result;
        ++count;
        result = queenTest(queen_size);
        printf("case %d: %d\n", count, result);
    }
    return 0;
}
