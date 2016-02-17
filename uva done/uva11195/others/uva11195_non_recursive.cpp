#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
using std::vector;



int valid(int row, int col, vector<int> queens, vector<vector<int> > bad_position){
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

void print(vector<int> queens){
    for (int i=0;i!=queens.size();++i){
        printf("%d ",queens[i]);
    }
    printf("\n");
}

int queenTest(vector<int> queens, vector<vector<int> > bad_position, int initial_value){
    int n = 0;
    int i = 0;
    int j = 0;
    while (i < queens.size()){
        while (j < queens.size()){
            if (valid(i, j, queens, bad_position)) {
                queens[i] = j;
                j = 0;
                break;
            }else{
                ++j;
            }
        }
        if(queens[i] == initial_value){
            if (i==0){
                break;
            }else{
                j = queens[--i] + 1;
                queens[i]= initial_value;
                continue;
            }
        }
        if (i == queens.size() - 1){
            ++n;
            //print(queens);
            j = queens[i] + 1;
            queens[i] = initial_value;
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
        //fflush(stdin);
        int initial_value = 0 - queen_size - 100;
        vector<int> queens(queen_size, initial_value);
        vector<vector<int> > bad_position(queen_size, vector<int>(queen_size, 0));
        for (int i = 0; i != queen_size; ++i){
            getline(cin,line);
            for (int j = 0; j != line.size(); ++j){
                if (line[j]=='*'){
                    bad_position[i][j]=-1;
                }
            }
        }
        int result;
        ++count;
        result = queenTest(queens, bad_position, initial_value);
        printf("case %d: %d\n", count, result);
    }
    return 0;
}
