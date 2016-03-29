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
 *
 *   create a table of a+b, O(n^2)
 *   test d-c with table
 *   total cost is O(n^2)
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
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int number[2026];
map<int, vector<int> > sum;

bool test(int a, int b){
    int k = sum[number[a] - number[b]].size();
    int num1, num2;
    if (k){
        for (int i = 0; i != k; i++){
            num1 = sum[number[a]-number[b]][i];
            num2 = sum[number[a]-number[b]][++i];
            if (number[a] != num1 && number[a] != num2 && number[b] != num1 && number[b] != num2){
                return true;
            }
        }
        return false;
    }else{
        return false;
    }
}

int main(){
    int N;
    while (cin >> N, N) {
        sum.clear();
        /* read all numbers */
        for (int i = 0; i != N; i++){
            cin >> number[i];
        }
        /* sort numbers from small to lage */
        sort(number,number + N);
        /* create table of a+b */
        for (int i = 0; i != N - 1; i++){
            for (int j = i + 1; j != N; j++){
                sum[number[i]+number[j]].push_back(number[i]);
                sum[number[i]+number[j]].push_back(number[j]);
            }
        }
        int result = -536870912;
        /* test d-c */
        for (int i = N-1; i != 0; i--){
            for (int j = 0; j != i; j++){
                if (test(i, j)){
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
