/* UVa problem: 11327
 *
 * Topic: Number Theory
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Consider the following method of enumerating all rational numbers between 0 and 1 (inclusively).
 *   for d = 1 to infinity do
 *      for n = 0 to d do
 *          if gcd(n,d) = 1 then print n/d
 *   where gcd(n, d) is the greatest common divisor of n and d. For example, the start of the sequence looks like:
 *   0/1, 1/1, 1/2, 1/3, 2/3, 1/4, 3/4, 1/5, 2/5, 3/5, 4/5, 1/6, 5/6, 1/7, . . .
 *
 * Solution Summary:
 *
 *   calculate the result of euler into a table oh[manx] before test.
 *   Based on the input k, do binary search to find the position in the table, the index is the denumerator
 *   than enumerate gcd for number 1 to the denumerator - 1 to find the numerator.
 *
 * Used Resources:
 *
 *  http://baike.baidu.com/view/107769.htm
 *   Euler's totient function:
 *   φ(x)=x(1-1/p1)(1-1/p2)(1-1/p3)(1-1/p4)...(1-1/pn)   p1, p2……pn are prime factors of x.
 *   if Ｅ（x ＊ｐ）＝Ｅ（x）＊ｐ      n = 0 mod p
 *      else Ｅ（x＊ｐ）＝Ｅ（x）＊Ｅ（ｐ）＝Ｅ（x）＊（ｐ－１）
 *   Ｅ（ａｂ）＝Ｅ（ａ）＊Ｅ（ｂ）
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <math.h>

using namespace std;

long long k;
const int maxn = 200020;
long long oh[maxn];

long long euler(long long x) {
    long long res = x;
    long long range = (long long) sqrt(x*1)+1;
    for (long long i=2; i < range; i++){
        if (x % i ==0){
            res = res / i * (i - 1);
            while (x % i == 0){
                x = x / i;
            }
        }
    }
    if (x>1) {
        res = res / x * (x - 1);
    }
    return res;
}

void init_oh(){
    oh[0] = 1;
    oh[1] = 2;
    oh[2] = 3;
    oh[3] = 5;
    for (long long i = 4; i != maxn; i++){
        oh[i] = euler(i) + oh[i-1];
    }
}

int binary_search(long long x){
    int start = 0;
    int end = maxn - 1;
    int mid;
    while (start + 1 < end) {
        mid = (start + end) / 2;
        if (oh[mid] == x) {
            return mid;
        } else if (oh[mid] < x) {
            start = mid;
        } else if (oh[mid] > x) {
            end = mid;
        }
    }
    return end;
}

int gcd (int a, int b){
    int r;
    while (b){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int pos, numerator;
    long long n, index;
    init_oh();
    while (cin >> k, k) {
        int cont = 0;
        if (k == 1){
            cout << "0/1" << endl;
            continue;
        } else if (k == 2){
            cout << "1/1" << endl;
            continue;
        }
        pos = binary_search(k);
        index = k - oh[pos - 1];
        for (int i = 1; i < pos; i++) {
            if (gcd(i , pos) == 1) {
                cont++;
            }
            if (cont == index) {
                numerator = i;
                break;
            }
        }
        cout << numerator << '/' << pos << endl;
    }
    return 0;
}
