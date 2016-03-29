/* UVa problem: 10125
 *
 * Topic: Arithmetic
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   Given S, a set of integers, find the largest d such that a+b+c = d
 *   where a, b, c, and d are distinct elements of S.
 *
 * Solution Summary:
 *   old:
 *   create a table of a+b, O(n^2) by using map.
 *   test d-c with table
 *   uva time: 0.342
 *
 *   new:
 *   use struct to store a+b including a and b; O(n^2)
 *   sort the array.
 *   check d-c by binary search for the array which stores a+b (nlogn);
 *   uva time: 0.043
 *
 * Used Resources:
 *
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int number[2026];
typedef struct tup{
    int total, a, b;
} Tup;
const int maxn = 2026*2026;
Tup sum[maxn];

bool test(int a, int b, int size){
    int l = 0, r = size;
    int mid;
    int pivot = number[a] - number[b];
    /* if there is one or more result, find the most left side pair */
    while(l<r){
        mid = (l + r) / 2;
        if (pivot < sum[mid].total){
            r = mid - 1;
        }else if(pivot > sum[mid].total){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    if (sum[r].total == pivot){
        /* if there are more than one result */
        while(sum[r].total == pivot){
            if (sum[r].a != number[a] && sum[r].a != number[b] && sum[r].b != number[a] && sum[r].b != number[b]){
                return true;
            }else{
                r++;
            }
        }
        return false;
    }else{
        return false;
    }
}

bool cmp(Tup a, Tup b){
    return a.total < b.total;
}


int main(){
    int N;
    while (cin >> N, N) {
        /* read all numbers */
        for (int i = 0; i != N; i++){
            cin >> number[i];
        }
        /* sort numbers from small to lage */
        sort(number,number + N);
        /* create table of a+b */
        int cont = 0;
        for (int i = 0; i != N - 1; i++){
            for (int j = i + 1; j != N; j++){
                sum[cont].a = number[i];
                sum[cont].b = number[j];
                sum[cont].total = number[i] + number[j];
                cont++;
            }
        }
        sort(sum,sum+cont,cmp);
        int result = -536870912;
        /* test d-c */
        for (int i = N-1; i != 0; i--){
            for (int j = 0; j != i; j++){
                if (test(i, j, cont)){
                    result = number[i];
                    break;
                }
            }
            if (result != -536870912){
                break;
            }
        }
        if (result == -536870912){
            cout << "no solution" << endl;
        }else{
            cout << result << endl;
        }
    }
    return 0;
}
