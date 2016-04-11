/* UVa problem: 10057
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   find an integer number A (This A is the combination lock code) such that (|X1 − A| + |X2 − A| + . . . + |Xn − A|)
 *   is minimum.
 *
 * Solution Summary:
 *
 *   find the median
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
#include <algorithm>
#include <string.h>

using namespace std;
const int maxn = 1000026;
int number[maxn];

int main(){
    int n, l, r, mid, A, sumA, nA;
    while (cin >> n){
        memset(number, 0, sizeof(number));
        for (int i = 0; i != n; i++){
            cin >> number[i];
        }
        sort(number, number + n);
        sumA = 0;
        nA = 0;
        if (n%2){
            mid = (n - 1) / 2;
            A = number[mid];
            for (int i = mid; i != n; i++){
                if (number[i] == A){
                    sumA++;
                }else{
                    break;
                }
            }
            for (int i = mid - 1; i >= 0; i--){
                if (number[i] == A){
                    sumA++;
                } else {
                    break;
                }
            }
            nA = 1;
        } else {
            l = (n - 2) / 2;
            r = n / 2;
            A = number[l];
            for (int i = l; i >=0; i--){
                if (number[i] == A){
                    sumA++;
                } else {
                    break;
                }
            }
            for (int i = r; i != n; i++){
                if (number[i] == number[r]){
                    sumA++;
                } else {
                    break;
                }
            }
            nA = number[r] - number[l] + 1;
        }
        cout << A << " " << sumA << " " << nA << endl;
    }
    return 0;
}