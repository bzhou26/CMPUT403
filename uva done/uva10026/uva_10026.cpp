/* UVa problem: 10026
 *
 * Topic: Sorting
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Shoemaker has N jobs (orders from customers) which he must make.
 *   Shoemaker can work on only one job in each day. For each i-th job,
 *   it is known the integer Ti (1 ≤ Ti ≤ 1000), the time in days it takes
 *   the shoemaker to finish the job. For each day of delay before starting
 *   to work for the i-th job, shoemaker must pay a fine of Si (1 ≤ Si ≤ 10000)
 *   cents. Your task is to help the shoemaker, writing a programm to find the
 *   sequence of jobs with minimal total fine.
 *
 * Solution Summary:
 *
 *   Based on Fine/time, do the decreasing sorting.
 *
 * Used Resources:
 *
 *  http://www.cplusplus.com/reference/algorithm/stable_sort/
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 1020;
int n, t, s;
typedef struct {
    double t;
    double s;
    int pos;
}Work;
Work table[maxn];

bool cmp (const Work a, const Work b){
    double d1 = a.s/a.t;
    double d2 = b.s/b.t;
    return d1 > d2;
}

int main(){
    int kase;
    cin >> kase;
    while(kase--){
        cin >> n;
        memset(table,0,sizeof(table));
        for (int i = 1; i <= n; ++i){
            cin >> t >> s;
            table[i].s = s;
            table[i].t = t;
            table[i].pos = i;
        }
        stable_sort(table+1, table+n+1, cmp);
        for (int i = 1; i <= n; i++){
            cout << table[i].pos;
            if (i != n){
                cout << " ";
            }
        }
        cout << endl;
        if (kase){
            cout << endl;
        }
    }
    return 0;
}
