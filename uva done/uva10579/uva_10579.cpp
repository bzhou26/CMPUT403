/* UVa problem: 10579
 *
 * Topic: Combinatorics
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   A Fibonacci sequence is calculated by adding the previous two
 *   members of the sequence, with the first two members being both 1.
 *   Note: No generated fibonacci number in excess of 1000 digits will be in the test data,
 *   i.e. f(20) = 6765 has 4 digits.
 *
 * Solution Summary:
 *
 *   use array to simulate plus opertation
 *
 * Used Resources:
 *
 *
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <string.h>

using namespace std;
const int maxn = 6000;
const int maxlen = 1026;
int table[maxn][maxlen];

void initTable(){
    memset(table, 0, sizeof(table));
    table[1][0] = table[2][0] = 1;
    for ( int i = 3 ; i != maxn ; i++ ) {
        for ( int j = 0 ; j != maxlen ; j++ ) {
            table[i][j] = table[i - 2][j] + table[i - 1][j];
        }
        for ( int j = 0 ; j <= maxlen ; ++ j ) {
            if (table[i][j] > 9) {
                table[i][j + 1] += table[i][j] / 10;
                table[i][j] %= 10;
            }
        }
    }
}

int main(){
    int n;
    initTable();
    while (cin >> n){
        int pos = 0;
        for(int i = 1025; i != 0; i--){
            if (table[n][i] != 0 ){
                pos = i;
                break;
            }
        }
        for(int i = pos; i >= 0; i--){
            cout << table[n][i];
        }
        cout << endl;
    }
    return 0;
}

