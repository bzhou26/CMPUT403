/* UVa problem: 11584
 *
 * Topic: Dynamic Programming
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   We say a sequence of char- acters is a palindrome if it is the same written forwards and backwards. For example,
 *   ‘racecar’ is a palindrome, but ‘fastcar’ is not.
 *
 * Solution Summary:
 *
 *   use matrix p[i][j] to represent if the word from i to j is palindrome, then scan again.
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
const int maxn = 1026;
int p[maxn][maxn];
int dp[maxn];

void init_p(string &str) {
    int n = str.size();
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++) {
        int l = i - 1, r = i;
        while (l >= 0 && r < n && str[l] == str[r]) {
            p[l][r] = 1;
            l--;
            r++;
        }
        l = i - 1, r = i + 1;
        while (l >= 0 && r < n && str[l] == str[r]) {
            p[l][r] = 1;
            l--;
            r++;
        }
    }
}

int main(){
    int kase;
    string word;
    cin >> kase;
    while (kase--){
        memset(dp, 0, sizeof(dp));
        cin >> word;
        init_p(word);
        dp[0] = 1;
        for(int i = 1; i < word.size(); i ++) {
            dp[i] = dp[i-1] + 1;
            for(int j = 0; j < i; j ++) {
                if(p[j][i]) {
                    if(j) {
                        dp[i] = min(dp[i], dp[j-1] + 1);
                    } else{
                        dp[i] = 1;
                    }
                }
            }
        }
        cout << dp[word.size()-1] << endl;
    }
    return 0;
}
