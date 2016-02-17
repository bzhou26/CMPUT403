/* UVa problem: 11330
 *
 * Topic: Combinatorics
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 * However, he has not learned about putting pairs of shoes
 * with the same color together. Papa’s job is to pair up the
 * shoes. Since Papa is tired from work at the algorithm factory,
 * he wants to do this in the minimal number of steps.
 * One step means to swap two shoes. Your job is to help Papa.
 *
 * Solution Summary:
 *
 *   store data into a vector, left shoe is the index of the vector, and right shoe is the value.
 *   So if the index = value, it means shoes are paired.
 *   Algorithm: In the vector from left to right, take out each value(right shoe), at the same time,
 *   set it to 0.
 *   Go to the index which its value equals to the "right shoe" you took out, it means you find one pair of shoes.
 *   Then take out the value (right shoe) again, and find next.
 *
 * Used Resources:
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <vector>

using namespace std;

const int maxn = 10020;
vector<int> shoes(maxn,0);

int main(){
    int n, k, ls, rs, result;
    int carry, xchang;
    cin >> k;
    while (k--){
        cin >> n;
        for (int i = 0; i <= maxn - 1 ; ++i){
            shoes[i] = 0;
        }
        for (int i = 0; i != n; ++i){
            cin >> ls >> rs;
            shoes[ls] = rs;
        }
        result = 0;
        for (int j = 1; j <= maxn - 1; ++j) {
            carry = shoes[j];
            shoes[j] = 0;
            while (shoes[carry]){
                xchang = shoes[carry];
                shoes[carry] = 0;
                carry = xchang;
                ++result;
            }
        }
        cout << result << endl;
    }
    return 0;
}

