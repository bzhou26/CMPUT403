/* UVa problem: 10077
 *
 * Topic: Arithmetic
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   The Stern-Brocot tree is a beautiful way for constructing the set of all nonnegative fractions m where m
 *   (0 1) and n are relatively prime. The idea is to start with two fractions 1 , 0
 *   operations as many times as desired:
 *
 * Solution Summary:
 *
 *
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

using namespace std;

int main(){
    int a, b, la, lb, ra, rb = 0;
    while (cin >> a >> b, a != 1 || b != 1){
        la = 0;
        lb = 1;
        ra = 1;
        rb = 0;
        while (((la + ra) != a) || ((lb + rb) != b)){
            if ((la + ra) * b < (lb + rb) * a){
                cout << "R";
                la += ra;
                lb += rb;
            } else {
                cout << "L";
                ra += la;
                rb += lb;
            }
        }
        cout << endl;
    }
    return 0;
}