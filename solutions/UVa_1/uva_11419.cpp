/* UVa problem: 11419
 *
 * Topic: Bipartite Graphs
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *  All of a sudden he realizes that he can kill the enemies without en-tering
 *  the temple using the great cannon ball which spits out a gigantic
 *  ball bigger than him killing anything it runs into and keeps on rolling until it
 *  finally explodes. But the cannonball can only shoot horizontally or vertically
 *  and all the enemies along the path of that cannon ball will be killed.
 *  Now he wants to save as many cannon balls as possible for
 *  fighting with Mental. So, he wants to know the minimum number of cannon
 *  balls and the positions from which he can shoot the cannonballs to eliminate all enemies from outside that temple.
 *
 * Solution Summary:
 *
 *   Based on the resource https://www.byvoid.com/blog/hungary
 *   Use hungary algorithm to find the largest number of independent edge set.
 *   Then based on the method on http://www.hardbird.net/uva-11419-sam-i-am%E4%BA%8C%E5%88%86%E5%9B%BE%E6%9C%80%E5%B0%8F%E7%82%B9%E8%A6%86%E7%9B%96/
 *   In the X set, if the point is not covered, it is the row point we can choose, and in Y set, the point which is covered
 *   is the point we can choose.
 *
 * Used Resources:
 *
 *   https://www.renfei.org/blog/bipartite-matching.html
 *   https://www.byvoid.com/blog/hungary
 *   http://www.hardbird.net/uva-11419-sam-i-am%E4%BA%8C%E5%88%86%E5%9B%BE%E6%9C%80%E5%B0%8F%E7%82%B9%E8%A6%86%E7%9B%96/
 *
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

const int maxn = 2000;
int r, c, n;
vector<int> x(maxn,0);
vector<int> y(maxn,0);
vector<int> S(maxn,0);
vector<int> T(maxn,0);
vector<int> board[maxn];

int dfs(int u) {
    S[u] = 1;
    for (int i = 0; i < board[u].size(); i++) {
        int v = board[u][i];
        if (!T[v]) {
            T[v] = 1;
            if (!x[v] || dfs(x[v])) {
                x[v] = u;
                y[u] = v;
                return 1;
            }
        }
    }
    return 0;
}


int hungary(){
    int result = 0;
    for (int i = 0; i <= maxn; ++i){
        x[i] = 0;
        y[i] = 0;
    }
    for (int i = 1; i <= r; ++i){
        for (int j = 0; j <= maxn; ++j){
            S[j]=0;
            T[j]=0;
        }
        if (dfs(i)){
            ++result;
        }
    }
    return result;
}

int main(){
    cin >> r >> c >> n;
    while (r || c || n){
        int r_pos, c_pos;
        for (int i = 0; i <= r; ++i){
            board[i].clear();
        }
        for (int k = 0; k != n; ++k){
            cin >> r_pos >> c_pos;
            board[r_pos].push_back(c_pos);
        }
        int total = 0;
        total = hungary();
        for (int j = 0; j != maxn; ++j){
            S[j]=0;
            T[j]=0;
        }
        for (int i = 1; i <= r; ++i){
            if (!y[i]){
                dfs(i);
            }
        }
        //print result
        cout << total;
        for (int i = 1; i <= r; ++i){
            if (!S[i]) {
                cout << " r" << i;
            }
        }
        for (int i = 1; i <= c; ++i){
            if (T[i]) {
                cout << " c" << i;
            }
        }
        cout << endl;
        //re-input
        cin >> r >> c >> n;
    }
    return 0;
}
