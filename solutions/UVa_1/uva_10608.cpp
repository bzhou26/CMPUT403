/* UVa problem: 10608
 *
 * Topic: Data Structures
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   There is a town with N citizens. It is known that some pairs of
 *   people are friends. According to the famous saying that “The friends
 *   of my friends are my friends, too” it follows that if A and B are
 *   friends and B and C are friends then A and C are friends, too.
 *   Your task is to count how many people there are in the largest group of friends.
 *
 * Solution Summary:
 *
 *   use an array father[] to represent the node number(index) and its father node(value)
 *   use an array sum[] to calculate the sum(value) for the group the node(index) stays.
 *
 * Used Resources:
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
const int maxn = 30026;
int father[maxn];
int sum[maxn];

int find_father(int x){
    if (father[x] == x){
        return x;
    }else{
        return father[x] = find_father(father[x]);
    }
}

int main(){
    int kase, N, M, c1, c2;
    int p1, p2;
    cin >> kase;
    while(kase--){
        cin >> N >> M;
        for (int i = 0; i <= N; i++){
            father[i] = i;
            sum[i] = 1;
        }
        int ans = 0;
        for (int i = 0; i != M; i++){
            cin >> c1 >> c2;
            p1 = find_father(c1);
            p2 = find_father(c2);
            if (p1 != p2){
                father[p1] = p2;
                sum[p2] += sum[p1];
                ans = max(ans, sum[p2]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}