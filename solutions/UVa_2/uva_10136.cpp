/* UVa problem: <10136>
 *
 * Topic: Geometry
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Making chocolate chip cookies involves mixing flour, salt, oil,
 *   baking soda and chocolate chips to form dough which is rolled
 *   into a plane about 50 cm square.
 *   Circles are cut from the plane, placed on a cookie sheet, and
 *   baked in an oven for about twenty minutes. When the cookies are done,
 *   they are removed from the oven and allowed to cool before being eaten.
 *   We are concerned here with the process of cutting the first cookie
 *   after the dough has been rolled. Each chip is visible in the planar
 *   dough, so we need simply to place the cutter so as to maximize the
 *   number of chocolate chips contained in its perimeter.
 *
 * Solution Summary:
 *
 *   1. For each 2 points, find two centres of the circle which has the two points on
 *   this circle.
 *   2. Calculate the number of chocolates within this circle with the centre point you got in
 *   step 1 and radius 2.5 cm.
 *
 * Used Resources:
 *
 *   http://www.cplusplus.com/reference/sstream/istringstream/str/
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */


#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

struct Point{
    double x;
    double y;
};
const int maxn = 200;
Point point1 = {0.0, 0.0};
vector<Point> centre(2);
vector<Point> chocolate(maxn, point1);
int chips_number;

double distance(const Point a, const Point b){
    double dx, dy;
    dx = a.x - b.x;
    dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

void find_cycle_centre(const Point p1, const Point p2){
    Point mid_point, centre1, centre2;
    double k, mdis, slope, arcdis, alpha;
    mid_point.x = (p1.x + p2.x)/2;
    mid_point.y = (p1.y + p2.y)/2;
    mdis = distance(mid_point,p1);

    if (p1.x == p2.x) {
        centre1.x = mid_point.x + sqrt(2.5 * 2.5 - mdis * mdis);
        centre1.y = mid_point.y;
        centre2.x = mid_point.x - sqrt(2.5 * 2.5 - mdis * mdis);
        centre2.y = mid_point.y;
    }else if (p1.y == p2.y){
        centre1.y = mid_point.y + sqrt(2.5 * 2.5 - mdis * mdis);
        centre1.x = mid_point.x;
        centre2.y = mid_point.y - sqrt(2.5 * 2.5 - mdis * mdis);
        centre2.x = mid_point.x;
    }else{
        slope = - (p1.x - p2.x) / (p1.y - p2.y);
        alpha = atan(slope);
        arcdis = sqrt(2.5 * 2.5 - mdis * mdis);
        centre1.x = mid_point.x + arcdis * cos(alpha);
        centre1.y = mid_point.y + arcdis * sin(alpha);
        centre2.x = mid_point.x - arcdis * cos(alpha);
        centre2.y = mid_point.y - arcdis * sin(alpha);
    }
    centre[0] = centre1;
    centre[1] = centre2;
}

int find_chips(const int a, const int b){
    int total_chips1 = 0;
    int total_chips2 = 0;
    if (distance(chocolate[a], chocolate[b]) > 5){
        return 1;
    }else{
        find_cycle_centre(chocolate[a], chocolate[b]);
        for (int i = 0; i != chips_number; i++ ){
            if (distance(centre[0], chocolate[i]) <= 2.5){
                total_chips1++;
            }
            if (distance(centre[1], chocolate[i]) <= 2.5){
                total_chips2++;
            }
        }
        return max(total_chips1, total_chips2);
    }
}

int main(){
    string line;
    int kase;
    istringstream iss;
    cin >> kase;
    cin.ignore();
    getline(cin,line);
    while(kase--) {
        chips_number = 0;
        int max_chips = 1;
        while (getline(cin, line), line.length()) {
            iss.clear();
            iss.str(line);
            iss >> chocolate[chips_number].x >> chocolate[chips_number].y;
            chips_number++;
        }
        for (int i = 0; i < chips_number - 1; i++){
            for (int j = i + 1; j != chips_number; j++){
                max_chips = max(max_chips, find_chips(i,j));
            }
        }
        cout << max_chips << endl;
        if (kase){
            cout << endl;
        }
    }
    return 0;
}
