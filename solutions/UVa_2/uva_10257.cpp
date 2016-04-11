/* UVa problem: 10257
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Dick is 12 years old. When we say this, we mean that it is at least twelve and not yet thirteen years since
 *   Dick was born.
 *   Dick and Jane have three pets: Spot the dog, Puff the Cat, and Yertle the Turtle.
 *   Spot was s years old when Puff was born; Puff was p years old when Yertle was born; Spot was y years
 *   old when Yertle was born. The sum of Spot’s age, Puff’s age, and Yertle’s age equals the sum of Dick’s
 *   age (d) and Jane’s age (j). How old are Spot, Puff, and Yertle?
 *
 * Solution Summary:
 *
 *   suppose turtle is x:
 *   cat = x + p + [0, 1)
 *   dog = x + p + [0, 1) + s +[0, 1) = x + p + s + {0, 1}
 *   x + cat + dog = d + j + {0, 1}
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

using namespace std;

int main(){
    int s, p, y, j, dog, cat, turtle;
    int A, B, C;
    while (cin >> s >> p >> y >> j){
        j += 12;
        int done = 0;
        for (int da = 0; (da <= 1) && !done; da++){
            for (int db = 0; (db <= 1) && !done; db++){
                for (int dc = 0; (dc <= 1) && !done; dc++){
                    A = s + da;
                    B = p + db;
                    C = y + dc;
                    if ((A + B != C) || ((A + C + j) % 3 != 0)){
                        continue;
                    }
                    dog = (A + C +j) / 3;
                    cat = dog - A;
                    turtle = cat - B;
                    if (dog < cat || cat < turtle || dog + cat + turtle != j){
                        continue;
                    }
                    cout << dog << " " << cat << " " << turtle << endl;
                    done = 1;
                }
            }
        }
    }
    return 0;
}