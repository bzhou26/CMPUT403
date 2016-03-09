/* UVa problem: 374
 *
 * Topic: Number Theory
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *    Calculate R = B^P MOD M
 *    for large values of B, P, and M using an efficient algorithm.
 *    (That's right, this problem has a time dependency !!!.)
 *
 * Solution Summary:
 *
 *   quick power method:
 *   R = A^13 = A* (A^2)^6
 *   for (A^2)^6 = ((A^2)^2)^3
 *   for ((A^2)^2)^3 = A * ((A^2)^2)^2
 *   ...
 *
 *    a≡x (mod d),b≡m (mod d)
 *    a*b≡x*m (mod d )
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Modular_arithmetic
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>

using namespace std;

int main(){
    long long b, p, m, r;
    while (cin >> b >> p >> m){
        if (p == 0){
            r = 1;
        }else{
            r = 1;
            while (p){
                if (p & 1){
                    r *= b;
                    r %= m;
                }
                b *= b;
                b %= m;
                p >>= 1;
            }
        }
        cout << r << endl;
    }
    return 0;
}