/* UVa problem: 10209
 *
 * Topic: Geometry
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   In the image below you can see a square ABCD, where AB = BC = CD = DA = a.
 *   Four arcs are drawn taking the four vertexes A, B, C, D as centers and a as the radius.
 *   The arc that is drawn tak- ing A as center, starts at neighboring ver- tex B and ends at neighboring
 *   vertex D. All other arcs are drawn in a similar fash- ion. Regions of three different shapes are created
 *   in this fashion. You will have to determine the total area if these different shaped regions.
 *
 * Solution Summary:
 *
 *   x + 4y + 4z = a^2
 *   x + 3y + 2z = pi/4*a^2
 *   z + pi*a^2/6 + sqrt(3)/4*a^2 = a^2
 *
 * Used Resources:
 *
 *   ...
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
const double PI = acos(-1.0);

int main(){
    double a, x, y, z;
    while (cin >> a){
        x = (1.0 - sqrt(3) + PI / 3.0) * a * a;
        y = (-4.0 + 2.0 * sqrt(3) + PI / 3.0) * a * a;
        z = (4.0 - sqrt(3) - 2.0 / 3.0 * PI) * a * a;
        cout << setiosflags(ios::fixed) << setprecision(3) << x << " " << y << " " << z << endl;
    }
    return 0;
}