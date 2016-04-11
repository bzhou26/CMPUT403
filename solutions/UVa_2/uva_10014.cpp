/* UVa problem: 10014
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   There is a sequence of n+2 elements a0,a1,...,an+1 (n ≤ 3000;−1000 ≤ ai ≤ 1000). It is known that ai = ai−1 +ai+1 −ci
 *   2
 *   for each i = 1,2,...,n. You are given a0,an+1,c1,...,cn. Write a program which calculates a1.
 *
 * Solution Summary:
 *
 *   ai = (a[i-1] + a[i+1])/2 - c[i]
 *   a[i] - a[i-1] = a[i+1] - a[i] - 2 * c[i]
 *   a[i] - a[i-1] = a[i+2] - a[i+1] - 2(c[i+1] + c[i])
 *   .
 *   .
 *   .
 *   (n + 1) * (a[1] - a[0]) = a[n+1] - a[0] - 2 * (n * c[1] + (n - 1) * c[2] + ... + 2 * c[n-1] + 1 * c[n])
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
#include <iomanip>

using namespace std;
const int maxn = 3026;
double allc[maxn];

int main(){
    int kase, n;
    double a0, aend, ans, sum;
    cin >> kase;
    while (kase--){
        sum = 0;
        cin >> n >> a0 >> aend;
        for (int i = 1; i <= n; i++){
            cin >> allc[i];
        }
        for (int i = 1; i <= n; i++){
            sum += (n + 1 - i) * allc[i];
        }
        ans = (aend + n * a0 - 2 * sum) / (n + 1);
        cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
        if (kase){
            cout << endl;
        }
    }
    return 0;
}