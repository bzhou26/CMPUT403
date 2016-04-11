/* UVa problem: 10300
 *
 * Topic: Arithmetic
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   German farmers are given a premium depending on the conditions at their farmyard. Imagine the following
 *   simplified regulation: you know the size of each farmer’s farmyard in square meters and the number of animals
 *   living at it. We won’t make a difference between different animals, although this is far from reality.
 *   Moreover you have information about the degree the farmer uses environment-friendly equipment and practices,
 *   expressed in a single integer greater than zero. The amount of money a farmer receives can be calculated from
 *   these parameters as follows. First you need the space a single animal occupies at an average. This value (in
 *   square meters) is then multiplied by the parameter that stands for the farmer’s environment-friendliness,
 *   resulting in the premium a farmer is paid per animal he owns. To compute the final premium of a farmer just
 *   multiply this premium per animal with the number of animals the farmer owns.
 *
 * Solution Summary:
 *
 *   square * environment-friendliness
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

using namespace std;

int main(){
    int kase, f, a, b, c, sum;
    cin >> kase;
    while (kase--){
        cin >> f;
        sum = 0;
        for (int i = 0; i != f; i++){
            cin >> a >> b >> c;
            sum += a*c;
        }
        cout << sum << endl;
    }
    return 0;
}