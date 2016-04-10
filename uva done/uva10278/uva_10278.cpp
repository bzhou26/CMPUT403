/* UVa problem: 10278
 *
 * Topic: Graphs
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   A city is served by a number of fire stations. Some residents have complained that the distance from their
 *   houses to the nearest station is too far, so a new station is to be built. You are to choose the location of the
 *   fire station so as to reduce the distance to the nearest station from the houses of the disgruntled residents.
 *   The city has up to 500 intersections, connected by road segments of various lengths. No more than 20 road segments
 *   intersect at a given intersection. The location of houses and firestations alike are considered to be at
 *   intersections (the travel distance from the intersection to the actual building can be discounted). Furthermore,
 *   we assume that there is at least one house associated with every intersection. There may be more than one firestation
 *   per intersection.
 *
 * Solution Summary:
 *
 *   use floyd to find all distance between each two intersections, then find the minmum distance to a fire station
 *   for each intersection.
 *   enumerate each intersection as a new fire station, re-compute the distance from each intersection to a fire station.
 *   find the smallest one.
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <sstream>

using namespace std;

const int maxf = 108;
const int maxn = 518;
const int maxnumber = 0x7FFFFF;
int station[maxf];
int road[maxn][maxn];
int distoFire[maxn];
int kase, f, n, sec1, sec2, weight, minDis, maxDis, dis, intersec;

void floyd(){
    maxDis = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                dis = road[j][i] + road[i][k];
                if (dis < road[j][k]){
                    road[j][k] = dis;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++){
        road[i][i] = 0;
    }
}

void find_dis_toFire(){
    for (int i = 1; i <= n; i++){
        dis = maxnumber;
        for (int j = 1; j <= f; j++){
            if (road[i][station[j]] < dis){
                dis = road[i][station[j]];
            }
        }
        distoFire[i] = dis;
        if (maxDis < dis){
            maxDis = dis;
        }
    }
}

void renew_dis_toFire(){
    intersec = 1;
    for (int i = n; i > 0; i--){
        minDis = 0;
        for (int j = 1; j <= n; j++){
            if (road[j][i] < distoFire[j]){
                if (minDis < road[j][i]){
                    minDis = road[j][i];
                }
            }else{
                if (minDis < distoFire[j]){
                    minDis = distoFire[j];
                }
            }
        }
        if (minDis <= maxDis){
            intersec = i;
            maxDis = minDis;
        }
    }
}

int main(){
    istringstream iss;
    cin >> kase;
    while (kase--){
        cin >> f >> n;
        for (int i = 1; i <= f; i++){
            cin >> station[i];
        }
        for (int i = 0; i != maxn; i++){
            for (int j = 0; j != maxn; j++){
                road[i][j] = maxnumber;
            }
        }
        cin.ignore();
        string line;
        while (getline(cin, line), line.length()){
            iss.clear();
            iss.str(line);
            iss >> sec1 >> sec2 >> weight;
            road[sec1][sec2] = road[sec2][sec1] = weight;
        }
        floyd();
        find_dis_toFire();
        renew_dis_toFire();
        cout << intersec << endl;
        if (kase){
            cout << endl;
        }
    }
    return 0;
}