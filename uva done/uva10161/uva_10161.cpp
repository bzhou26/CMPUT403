/* UVa problem: 10161
 *
 * Topic: Arithmetic
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   One day, an ant called Alice came to an M*M chessboard. She wanted to go around all the grids.
 *   So she began to walk along the chessboard according to this way: (you can assume that her speed is one grid per second)
 *   At the first second, Alice was standing at (1,1). Firstly she went up for a grid, then a grid to the right,
 *   a grid downward. After that, she went a grid to the right, then two grids upward, and then two grids to the
 *   leftin a word, the path was like a snake.
 *   For example, her first 25 seconds went like this:
 *
 * Solution Summary:
 *
 *   find the number on the diagonal
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
#include <cmath>

using namespace std;

int main(){
    int n, a, b;
    while (cin >> n, n){
        a = 1;
        b = 2;
        while (n >= a && abs(n - a) >= (b / 2)){
            a += b;
            b += 2;
        }
        b /= 2;
        if (b & 1){
            if (a >= n){
                cout << b << " " << b - (a - n) << endl;
            } else {
                cout << b - (n - a) << " " << b << endl;
            }
        } else {
            if (a >= n){
                cout << b - (a - n) << " " << b << endl;
            } else {
                cout << b << " " << b - (n - a) << endl;
            }
        }
    }
    return 0;
}