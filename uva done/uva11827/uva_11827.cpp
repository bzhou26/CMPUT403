/* UVa problem: 11827
 *
 * Topic: Number Theory
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Given the N integers, you have to find the maximum GCD (greatest common divisor) of every possible pair
 *   of these integers.
 *
 * Solution Summary:
 *
 *   use Euclid gcd
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
#include <sstream>

using namespace std;
const int maxn = 200;
int number[maxn];
int kase, n;

int gcd(int a, int b){
    while(b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}


int cal(){
    int mx = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i+1; j <= n - 1; j++){
            mx = max(mx, gcd(number[i], number[j]));
        }
    }
    return mx;
}

int main(){
    string line;
    cin >> kase;
    cin.ignore();
    int ans;
    while(kase--){
        getline(cin, line);
        if (!line.length()){
            break;
        }
        istringstream iss(line);
        n = 0;
        while (iss >> number[n]){
            n++;
        }
        ans = cal();
        cout << ans << endl;
    }
    return 0;
}
