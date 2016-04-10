/* UVa problem: 10927
 *
 * Topic: Geometry
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   The famous contempory art designer Momo is preparing its new open-air exhibit.
 *   It will consist of randomly placed poles emitting lasers in horizontal direction.
 *   All the lasers shall reach the so-called laser totem T. However, as the poles are placed randomly at
 *   different heights, a laser light L might be hidden behind a taller pole P, if P, T and L are aligned
 *   and if the height of P is larger or equal to the pole where L is attached.
 *   Your job is, given a configuration of poles, determine which are the visible poles.
 *
 * Solution Summary:
 *
 *   sort by Polar coordinate
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
#include <cmath>
#include <algorithm>

using namespace std;

typedef struct _pole{
    int x;
    int y;
    int height;
    double theta;
} pole;
const int maxn = 100026;
pole totem[maxn], miss[maxn];
int cont, maxh;

bool cmp(pole a, pole b){
    if (a.theta == b.theta){
        return fabs(a.x) < fabs(b.x);
    }
    return a.theta < b.theta;
}

bool cmp2(pole a, pole b){
    if (a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main (){
    int N, kase = 0;
    while (cin >> N, N){
        for (int i = 0; i != N; i++){
            cin >> totem[i].x >> totem[i].y >> totem[i].height;
            totem[i].theta = atan2(totem[i].y, totem[i].x);
        }
        sort (totem, totem+N, cmp);
        cont = 0;
        maxh = totem[0].height;
        for (int i = 1; i != N; i++){
            if (totem[i].theta == totem[i-1].theta){
                if (totem[i].height <= maxh){
                    miss[cont++] = totem[i];
                }
                maxh = max(maxh, totem[i].height);
            } else {
                maxh = totem[i].height;
            }
        }
        cout << "Data set " << ++kase << ":" << endl;
        if (cont != 0){
            sort(miss, miss + cont, cmp2);
            cout << "Some lights are not visible:" << endl;
            for (int i = 0; i != cont - 1; i++){
                cout << "x = " << miss[i].x << ", y = " << miss[i].y << ";" << endl;
            }
            cout << "x = " << miss[cont-1].x << ", y = " << miss[cont-1].y << "." << endl;
        }else{
            cout << "All the lights are visible." << endl;
        }
    }
    return 0;
}