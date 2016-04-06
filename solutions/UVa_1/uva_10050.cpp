/* UVa problem: 10050
 *
 * Topic: Data Structures
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   A social research organization has determined a simple set of parameters to simulate the behavior of the
 *   political parties of our country. One of the parameters is a positive integer h (called the hartal parameter)
 *   that denotes the average number of days between two successive hartals (strikes) called by the corresponding party.
 *   Though the parameter is far too simple to be flawless, it can still be used to forecast the damages caused by
 *   hartals. The following example will give you a clear idea:
 *   Consider three political parties. Assume h1 = 3, h2 = 4 and h3 = 8 where hi is the hartal parameter for
 *   party i (i = 1,2,3). Now, we will simulate the behavior of these three parties for N = 14 days. One must always
 *   start the simulation on a Sunday and assume that there will be no hartals on weekly holidays
 *   (on Fridays and Saturdays).
 *
 * Solution Summary:
 *
 *   1 is the day, 2 is weekend.
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
int day[3660], sum;

void mark_day(int total, int gap){
    for (int i = 0; i <= total; i += gap){
        if (day[i] != 2 && day[i] != 1){
            sum++;
            day[i] = 1;
        }
    }
}

void mark_weekend(int total){
    day[0] = 2;
    for (int i = 6; i <= total; i+=6){
        day[i] = 2;
        day[++i] = 2;
    }
}

int main(){
    int kase, n, p, d;
    cin >> kase;
    while (kase--){
        memset(day, 0, sizeof(day));
        cin >> n >> p;
        mark_weekend(n);
        sum = 0;
        for (int i = 0; i != p; i++){
            cin >> d;
            mark_day(n, d);
        }
        cout << sum << endl;
    }
    return 0;
}