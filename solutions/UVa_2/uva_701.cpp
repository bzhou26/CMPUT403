/* UVa problem: 701
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   An archeologist seeking proof of the presence of extraterrestrials in the Earth’s past, stumbles upon a
 *   partially destroyed wall containing strange chains of numbers. The left-hand part of these lines of digits
 *   is always intact, but unfortunately the right-hand one is often lost by erosion of the stone. However, she
 *   notices that all the numbers with all its digits intact are powers of 2, so that the hypothesis that all of
 *   them are powers of 2 is obvious. To reinforce her belief, she selects a list of numbers on which it is apparent
 *   that the number of legible digits is strictly smaller than the number of lost ones, and asks you to  nd the
 *   smallest power of 2 (if any) whose  rst digits coincide with those of the list.
 *   Thus you must write a program such that given an integer,
 *   it determines (if it exists) the smallest exponent E such that the
 *   rst digits of 2E coincide with the integer (remember that more than half of the digits are missing).
 *
 * Solution Summary:
 *
 *   log2(n) + y * log2(10) < e < log2(n+1) + y * log2(10),  y > floor(lgN) + 1
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
    int n, lamda, l, r;
    double l1, r1, c;
    while (cin >> n){
        lamda = 0;
        l1 = log2(n);
        r1 = log2(n+1);
        c = log2(10.0);
        for (int i = n; i; i /= 10){
            lamda++;
        }
        for (int i = lamda + 1; ; i++){
            l = (int) (l1 + i * c);
            r = (int) (r1 + i * c);
            if (l != r){
                cout << r << endl;
                break;
            }
        }
    }
    return 0;
}