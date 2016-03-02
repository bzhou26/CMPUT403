/* UVa problem: 10065
 *
 * Topic: Geometry
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Yes, as you have apprehended the Useless Tile Packers (UTP) pack tiles.
 *   The tiles are of uniform thickness and have simple polygonal shape.
 *   For each tile a container is custom-built. The floor of the container
 *   is a convex polygon and under this constraint it has the minimum possible
 *   space inside to hold the tile it is built for. But this strategy leads to
 *   wasted space inside the container.
 *
 * Solution Summary:
 *
 *   Calculate the original ploygon area as S1.
 *   Using Graham Sacn algorithm to find the convex hull then calculate the area as S2.
 *   You can get the percentage of waste by (S2-S1)/S2
 *
 * Used Resources:
 *
 *   https://zh.wikipedia.org/wiki/%E5%A4%9A%E8%BE%B9%E5%BD%A2
 *   http://www.cnblogs.com/jbelial/archive/2011/08/05/2128625.html
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef struct Point{
    int x;
    int y;
};
const int maxn = 200;
Point points[maxn], stack[maxn];
int N;
int top = 1;

double multiply(const Point p0, const Point p1, const Point p2){
    return ((p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}

double distance(Point p1, Point p2){
    double dx,dy;
    dx = p1.x - p2.x;
    dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

void find_min_point(){
    int min = 0 ;
    Point min_p;
    min_p = points[0];
    for (int i = 0; i != N; i++){
        if (min_p.y > points[i].y || (min_p.y == points[i].y && min_p.x > points[i].x)){
            min = i;
            min_p = points[i];
        }
    }
    points[min] = points[0];
    points[0] = min_p;
}

void sort_points(){
    Point tmp;
    double m;
    double dis1, dis2;
    for (int i = 1; i != N - 1; i++){
        for (int j = 1; j < N - i; j++){
            m = multiply(points[0], points[j], points[j+1]);
            dis1 = distance(points[0], points[j]);
            dis2 = distance(points[0], points[j+1]);
            if (m < 0 || (m == 0 && dis1 > dis2)){
                tmp = points[j];
                points[j] = points[j+1];
                points[j+1] = tmp;
            }
        }
    }
}

void Graham(){
    find_min_point();
    sort_points();
    stack[0] = points[0];
    stack[1] = points[1];
    for (int i = 2; i != N; i++){
        while(top > 0 && multiply(stack[top-1], points[i], stack[top]) >= 0){
            top--;
        }
        stack[++top] = points[i];
    }
    top++;
}

double ploygon_area(const int max, const char k){
    double s = 0.0;
    for (int i = 0; i != max - 1; i++) {
        switch (k) {
            case 'o':{
                s += multiply(points[0],points[i],points[i+1]);
                break;
            }
            case 'c':{
                s += multiply(stack[0],stack[i],stack[i+1]);
                break;
            }
        }
    }
    return (0.5 * s);
}

double convex_hull(){
    double c_area;
    Graham();
    c_area = ploygon_area(top, 'c');
    return c_area;
}

int main(){
    double o_area, c_area, p;
    int kase = 0;
    while (cin >> N, N){
        for (int i = 0; i != N; i++){
            cin >> points[i].x >> points[i].y ;
        }
        top = 1;
        o_area = fabs(ploygon_area(N, 'o'));
        c_area = fabs(convex_hull());
        p = (c_area - o_area) / c_area;
        cout << "Tile #" << ++kase << endl;
        cout << "Wasted Space = " << setiosflags(ios::fixed) << setprecision(2) << p*100 << " %" << endl << endl;
    }
    return 0;
}