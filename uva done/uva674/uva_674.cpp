/* UVa problem: 674
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Suppose there are 5 types of coins: 50-cent, 25-cent, 10-cent, 5-cent, and 1-cent.
 *   We want to make changes with these coins for a given amount of money.
 *   For example, if we have 11 cents, then we can make changes with one 10-cent coin and one 1-cent coin,
 *   two 5-cent coins and one 1-cent coin, one 5-cent coin and six 1-cent coins, or eleven 1-cent coins.
 *   So there are four ways of making changes for 11 cents with the above coins. Note that we count that
 *   there is one way of making change for zero cent.
 *   Write a program to  nd the total number of di erent ways of making changes for any
 *   amount of money in cents. Your program should be able to handle up to 7489 cents.
 *
 * Solution Summary:
 *
 *   ways[i, value] = ways[i-1, v] + ways[i, v - money[i]]
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
const int maxn = 7496;
int money[] = {1,5,10,25,50};
int ways[maxn];

void dp(){
    memset(ways,0,sizeof(ways));
    ways[0]=1;
    for (int i = 0; i != 5; i++){
        for (int j = money[i]; j != 7496; j++){
            ways[j] += ways[j - money[i]];
        }
    }
}

int main(){
    dp();
    int m;
    while(cin >> m){
        cout << ways[m] << endl;
    }
    return 0;
}
