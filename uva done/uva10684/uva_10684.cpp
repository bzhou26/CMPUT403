/* UVa problem: 10684
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   As Manuel wants to get rich fast and without too much work, he decided to make a career in gambling.
 *   Initially, he plans to study the gains and losses of players, so that, he can identify patterns of
 *   consecutive wins and elaborate a win-win strategy. But Manuel, as smart as he thinks he is, does not know how to
 *   program computers. So he hired you to write programs that will assist him in elaborating his strategy.
 *   Your first task is to write a program that identifies the maximum possible gain out of a sequence of bets.
 *   A bet is an amount of money and is either winning (and this is recorded as a positive value), or losing
 *   (and this is recorded as a negative value).
 *
 * Solution Summary:
 *
 *   scan once, find max sub set
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
    int n, bet;
    while (cin >> n, n){
        int sum = 0, maxwin = 0;
        for (int i = 0; i != n; i++){
            cin >> bet;
            if(sum < 0){
                sum = bet;
            }else{
                sum += bet;
            }
            if (sum > maxwin){
                maxwin = sum;
            }
        }
        if (maxwin > 0){
            cout << "The maximum winning streak is " << maxwin << "." << endl;
        } else {
            cout << "Losing streak." << endl;
        }
    }

    return 0;

}