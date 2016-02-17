/* UVa problem: 11331
 *
 * Topic: Bipartite Graphs
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *  Farmer John owns b bulls and c cows. He also owns b + c
 *  fields where each  eld can hold either one cow or one bull.
 *  The fields are located in an area with many hills,
 *  so for some pairs of  elds the animals in those
 *  fields cannot see each other. Unfortunately,
 *  his bulls really do not like each other, and neither do his cows.
 *
 * Solution Summary:
 *
 *   use two coloring graph algorithm and DFS method to check field validation.
 *   use dynamic programming to find if the number of field match the number of bull and cow.
 *   vector "field" stores the graph of fields.
 *   int array "tag" represent the color of fields.
 *   "color_total" represent the total number of two colors in each sub tree (if the graph is divided into sevel parts)
 *   "tree" stores all the number of colors for each sub tree.
 *   "tree_num" represent the number of sub tree.
 *   "pack" is used to represent the total number of colors when I enumerate and add one sub tree each time.
 *
 *
 * Used Resources:
 *
 * https://en.wikipedia.org/wiki/Graph_coloring
 * http://blog.csdn.net/woshi250hua/article/details/7636866
 * http://love-oriented.com/pack/pack2alpha1.pdf
 * http://blog.csdn.net/linraise/article/details/18627895
 * http://www.cnblogs.com/yspworld/p/4306593.html
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
const int maxn = 2002;
vector<int> field[maxn];
int tag[maxn];
int color_total[2];
int tree[maxn][2];
int tree_num;
int n, b, c, a;

int dfs(int p, int color ){
    int dfs_check=1;
    tag[p] = color;
    ++color_total[color];
    for( int i=0; i != field[p].size(); i++ ) {
        int v = field[p][i];
        if( tag[v] == color ) {
            return 0;
        }else if( tag[v] == 2 ) {
            dfs_check = dfs( v, 1-color );
        }
    }
    return dfs_check;
}

int check_sum(){
    vector<int> pack(maxn, -1);
    pack[0] = 0;
    for (int i = 0; i != tree_num; ++i) {
        for (int j = b+c;j >= 0; --j) {
            if (pack[j] == i) {
                pack[j + tree[i][0]] = i + 1;
                pack[j + tree[i][1]] = i + 1;
            }
        }
    }
    if(pack[b] == tree_num || pack[c] == tree_num) {
        return 1;
    } else {
        return 0;
    }
}

int main(){
    cin >> n;
    while(n--){
        tree_num = 0;
        int dfs_result = 1;
        cin >> b >> c >> a ;
        int total = b + c;
        for (int i=1; i <= total; ++i){
            field[i].clear();
            tag[i]=2;
            tree[i][0]=0;
            tree[i][1]=0;
        }
        while (a--){
            int u, v;
            cin >> u >> v;
            field[u].push_back(v);
            field[v].push_back(u);
        }
        for (int i = 1; i <= total; ++i){
            if (tag[i] == 2) {
                color_total[0] = 0;
                color_total[1] = 0;
                dfs_result = dfs(i, 0);
                if (dfs_result==0){
                    cout << "no" << endl;
                    break;
                }
                tree[tree_num][0] = color_total[0];
                tree[tree_num][1] = color_total[1];
                ++tree_num;
            }
        }
        //cout << "dfs check" << dfs_result << endl;
        if (dfs_result) {
            int check = check_sum();
            if (check){
                cout << "yes" << endl;
            }else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}