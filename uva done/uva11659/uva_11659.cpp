/* UVa problem: 11659
 *
 * Topic: Backtracking
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   The problem’s input has several cases. Each test case begins with a line with two nonnegative integer numbers,
 *   i (0 < i ≤ 20) and a (0 ≤ a ≤ 800), separated by blanks. i is the number of informants and a is the number of
 *   answers in the confidence survey. Then, a lines follow, each one with two integer numbers x and y (1 ≤ x ≤ i,
 *   1 ≤ |y| ≤ i), separated by blanks. If y is positive, the input line means that “informant x says informant y is
 *   reliable”. If y is negative, the then the line means that “informant x says informant y is not reliable”.
 *   The end of the input is indicated by a line with two 0 values (an artificial case that should be ignored).
 *
 * Solution Summary:
 *
 *   ignore x, if y is negative, if y is reliable before, mark it as unreliable.
 *
 * Used Resources:
 *
 *   ...
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
int people[30];

int main(){
    int n, a, x, y;
    while (cin >> n >> a, n || a){
        memset(people, 1, sizeof(people));
        for (int i = 0; i != a; i++){
            cin >> x >> y;
            if (y < 0){
                if (people[-y]){
                    n--;
                    people[-y] = 0;
                }
            }
        }
        cout << n << endl;
    }
    return 0;
}