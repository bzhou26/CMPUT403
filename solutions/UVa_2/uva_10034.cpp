/* UVa problem: 10034
 *
 * Topic: Graphs
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Consider Dick’s back to be a plane with freckles at various (x, y) locations.
 *   Your job is to tell Richie how to connect the dots so as to minimize the
 *   amount of ink used. Richie connects the dots by drawing straight lines
 *   between pairs, possibly lifting the pen between lines. When Richie is
 *   done there must be a sequence of connected lines from any freckle to any other freckle.
 *
 * Solution Summary:
 *
 *   Use Kruskal find the minimum-spanning-tree
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Kruskal's_algorithm
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int n = 0;
int n_edge = 0;
typedef struct point{
    double x,y;
    int group;
} Node;
typedef struct line{
    int start, end;
    double weight;
} Edge;
Node freckle[110];
Edge edge[7000];

double calculate_dis(const point a, const point b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return (sqrt(dx * dx + dy * dy));
}

bool cmp_edge(Edge a, Edge b){
    return a.weight < b.weight;
}

int find_end(int node_pos){
    if (node_pos == freckle[node_pos].group){
        return node_pos;
    } else {
        return freckle[node_pos].group = find_end(freckle[node_pos].group);
    }
}

int main(){
    int kase;
    cin >> kase;
    int g1, g2;
    while(kase--) {
        cin >> n;
        for (int i = 0; i != n; i++) {
            cin >> freckle[i].x >> freckle[i].y;
            freckle[i].group = i;
        }
        n_edge = 0;
        for (int i = 0; i != n; i++){
            for (int j = i + 1; j != n; j++){
                edge[n_edge].start = i;
                edge[n_edge].end = j;
                edge[n_edge].weight = calculate_dis(freckle[i], freckle[j]);
                n_edge ++;
            }
        }
        sort(edge, edge + n_edge, cmp_edge);
        double edge_count = 0;
        for (int i = 0; i != n_edge; i++){
            g1 = find_end(edge[i].start);
            g2 = find_end(edge[i].end);
            if (g1 != g2){
                edge_count += edge[i].weight;
                freckle[g1].group = g2;
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(2) << edge_count << endl;
        if (kase){
            cout << endl;
        }
    }
    return 0;
}