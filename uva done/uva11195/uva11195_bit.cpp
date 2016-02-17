/* UVa problem: <11195>
 *
 * Topic: (Backtracking)
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   In this problem you should count
 *   the number of placement of
 *   n
 *   queens on an
 *   n*n board so
 *   that no two queens attack each other.  To make the prob-
 *   lem a little bit harder (easier?), there are some bad squares
 *   where queens cannot be placed. Please keep in mind that bad
 *   squares cannot be used to block queens' attack.
 *
 * Solution Summary:
 *
 *   use bit number to represent the board and the queens. Store bad
 *   positions in a vector. I also use bit number to represent bad positions.
 *   bad positions are stored in an vector.
 *
 * Used Resources:
 *
 *   http://wenku.baidu.com/view/bdb700a5b14e852458fb57d3.html?re=view
 *   http://www.cnblogs.com/zichi/p/4792734.html
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */


#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int result = 0;
int n = 0;
long queen_size = 1;
vector<long> bad_position(16,0);

void queenCheck(long row, long left_diagonal, long right_diagonal, int depth) {
    if (row != queen_size) {
        long valid_position = queen_size & ~(row | left_diagonal | right_diagonal | bad_position[depth]);
        while (valid_position)
        {
            long queen_pos = valid_position & -valid_position;
            valid_position -= queen_pos;
            queenCheck(row + queen_pos, (left_diagonal + queen_pos) << 1, (right_diagonal + queen_pos) >> 1, depth+1);
        }
    } else {
        result++;
    }
}

int main() {
    vector<int> results(11,0);
    int cont = 0;
    string line;
    while (getline(cin, line)) {
        result = 0;
        n = stoi(line);
        if (n == 0){
          break;
        }
        queen_size = (1 << n) - 1;
        for (int i = 0; i != n; ++i){
            bad_position[i]=0;
            getline(cin,line);
            for (int j = 1; j <= n; ++j){
                if (line[j-1] == '*'){
                    bad_position[i] += (long) pow(2,(n-j));
                }
            }
        }
        queenCheck(0, 0, 0, 0);
        results[cont] = result;
        ++cont;
    }
    for (int i = 0; i != cont; ++i){
        printf("Case %d: %d\n", (i+1),results[i]);
    }
    return 0;
}
