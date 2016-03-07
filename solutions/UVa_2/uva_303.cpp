/* UVa problem: 303
 *
 * Topic: Geometry
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Each pipe component consists of many straight pipes connected tightly together. For the
 *   programming purposes, the company developed the description of each component as a sequence of
 *   points[x1, y1], [x2, y2].......[xn, yn], where x1 < x2 < ... < xn. The light is emitted
 *   by a segment source with endpoints [x1, y1 - 1] and [x1, y1]. Assume that the light is not
 *   bent at the pipe bent points and the bent points do not stop the light beam.
 *
 * Solution Summary:
 *
 *   enumerate the line from up points and down points.
 *   than find the longest distance for these lines.
 *
 * Used Resources:
 *
 *   https://segmentfault.com/a/1190000004070478
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <iomanip>

using namespace std;

int N;
double m1, m2;
typedef struct Point{
    double x;
    double y;
};
Point u_points[100];
Point d_points[100];
const double esp = 1e-8;
double touch = 0.0;

Point operator-(const Point &P1, const Point &P2){
    Point r;
    r.x = P1.x - P2.x;
    r.y = P1.y - P2.y;
    return r;
}

Point operator+(const Point &P1, const Point &P2){
    Point r;
    r.x = P1.x + P2.x;
    r.y = P1.y + P2.y;
    return r;
}

double operator*(const Point &P1, const Point &P2){
    return (P1.x * P2.y - P2.x * P1.y);
}

double sign(double x, const double base = 0.0){
    if (x > base + esp) return 1;
    if (x < base - esp) return -1;
    else return 0;
}

bool isLineSegmentCross(const Point P1, const Point P2, const Point Q1, const Point Q2){
    m1 = (P2 - P1) * (Q1 - P1);
    m2 = (P2 - P1) * (Q2 - P1);
    if (sign(m1) * sign(m2) > 0){
        return false;
    } else {
        touch = (Q1.x * m2 - Q2.x * m1) / (m2 - m1);
        return true;
    }
}

double find_distance(Point a, Point b){
    touch = 0.0;
    double dis1, dis2;
    for (int i = 0; i != N; i++){
        if (!isLineSegmentCross(a, b, u_points[i], d_points[i])){
            if (i == 0){
                return d_points[0].x;
            }
            isLineSegmentCross(a, b, u_points[i], u_points[i - 1]);
            dis1 = touch;
            isLineSegmentCross(a, b, d_points[i], d_points[i - 1]);
            dis2 = touch;
            return max(dis1, dis2);
        }
    }
    return d_points[N-1].x;
}

int main(){
    double dis = 0;
    while (cin >> N, N){
        for (int i = 0; i != N; i++){
            cin >> u_points[i].x >> u_points[i].y;
            d_points[i].x = u_points[i].x;
            d_points[i].y = u_points[i].y - 1;
        }
        dis = u_points[0].x;
        for (int i = 0; i != N; i++) {
            for (int j = 0; j != N; j++) {
                dis = max(dis, find_distance(u_points[i], d_points[j]));
            }
        }
        if (! sign(dis, d_points[N-1].x) ){
            cout << "Through all the pipe." << endl;
        }else{
            cout << setiosflags(ios::fixed) << setprecision(2) << dis << endl;
        }
    }
    return 0;
}