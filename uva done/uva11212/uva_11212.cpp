/* UVa problem: 11212
 *
 * Topic: Backtracking
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   You have n equal-length paragraphs numbered 1 to n. Now you want to arrange them in the order of
 *   1, 2, . . . , n. With the help of a clipboard, you can easily do this: Ctrl-X (cut) and Ctrl-V (paste)
 *   several times. You cannot cut twice before pasting, but you can cut several contiguous paragraphs at the
 *   same time - they’ll be pasted in order.
 *   For example, in order to make {2, 4, 1, 5, 3, 6}, you can cut 1 and paste before 2,
 *   then cut 3 and paste before 4. As another example, one copy and paste is enough for {3, 4, 5, 1, 2}.
 *   There are two ways to do so: cut {3, 4, 5} and paste after {1, 2}, or cut {1, 2} and paste before {3, 4, 5}.
 *
 * Solution Summary:
 *
 *   ida* search (dfs search) add search depth one by one.
 *
 * Used Resources:
 *
 *   http://blog.csdn.net/urecvbnkuhbh_54245df/article/details/5856756
 *   http://www.asciitable.com/
 *   http://baike.baidu.com/link?url=AZWuZBTxmXjmeizmgHj81QOgcQ3MsPTMLuN9Lyofz_oZ4FLPfzly4Cjnro3l3oa2ylAqiE4GWIWUaJROf-bAjq
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */


#include <iostream>

using namespace std;

string sorted, original, x;
int n;

int ida_dfs (int currDepth, int depth, string currString){
    if (currDepth == depth){
        if (currString == sorted){
            return 1;
        } else {
            return 0;
        }
    }
    int height = 0;
    for (int i = 0; i != n - 1; i++){
        if (currString[i+1] - currString[i] != 1){
            height++;
        }
    }
    if (3 * currDepth + height > 3 * depth){
        return 0;
    }
    for (int i = 0; i != n; i++){
        for (int j = i; j != n; j++){
            for (int k = 0; k != i; k++){
                string t = currString.substr(0, k);
                string u = currString.substr(i, j-i+1);
                string v = currString.substr(k, i-k);
                string w = currString.substr(j+1, n-j);
                if (ida_dfs(currDepth+1, depth, t+u+v+w)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    int cont = 0;
    while (cin >> n, n){
        original = "";
        sorted = "";
        for (int i = 1; i <= n; i++){
            cin >> x;
            original += x;
            sorted += '0' + i;
        }
        int depth = 0;
        while (++depth){
            if (ida_dfs(0, depth-1, original)){
                cout << "Case " << ++cont << ": " << depth - 1 << endl;
                break;
            }
        }
    }
    return 0;
}