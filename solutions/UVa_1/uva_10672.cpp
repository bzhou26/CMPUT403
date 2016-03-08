/* UVa problem: 10672
 *
 * Topic: Graphs
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   n boxes are placed on the vertices of a rooted tree, which are
 *   numbered from 1 ton,1≤n≤10000. Eachboxiseither empty or contains a
 *   number of marbles; the total number of marbles is n. The task is to
 *   move the marbles such that each box contains exactly one mar- ble.
 *   This is to be accomplished be a se- quence of moves; each move consists
 *   of moving one marble to a box at an adjacent vertex. What is the
 *   minimum number of moves required to achieve the goal?
 *
 * Solution Summary:
 *
 *   father[] to store one vetex's father vetex.
 *   v[] to store the number of marbles in one vetex.
 *   degree[] to store the number of children for one vetex.
 *
 *   find the vertices which have no child. push them into queue.
 *   move the marbles between the vetex in the queue and its parent.
 *   if one vetex finish moving marbles among its children, it becomes a leaf vetex, and push it into queue.
 *   keep doing this until only root vetex left on the top (no need to move).
 *
 * Used Resources:
 *
 *   http://www.cplusplus.com/reference/queue/queue/
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int n_node;
int father[10100];
int v[10100];
int degree[10100];

int main(){
    int d, m, vetex, ch, a, pa;
    while(cin >> n_node, n_node){
        //input
        memset(v, 0, sizeof(int));
        memset(father, 0, sizeof(int));
        memset(degree, 0, sizeof(int));

        for (int i = 0; i != n_node; i++){
            cin >> vetex >> m >> d;
            v[vetex] = m;
            degree[vetex] = d;
            for (int j = 0; j != d; j++){
                cin >> ch;
                father[ch] = vetex;
            }
        }
        queue<int> q;
        int cont = 0;
        for (int i = 1; i <= n_node; i++){
            if (degree[i] == 0){
                q.push(i);
            }
        }
        while (!q.empty()){
            a = q.front();
            q.pop();
            pa = father[a];
            if (pa == 0){
                break;
            } else {
                if (v[a] != 1){
                    v[pa] += v[a] - 1;
                    cont += abs(v[a] - 1);
                    v[a] = 1;
                }
                degree[pa]--;
                if (degree[pa] == 0){
                    q.push(pa);
                }
            }
        }
        cout << cont << endl;
    }
    return 0;
}