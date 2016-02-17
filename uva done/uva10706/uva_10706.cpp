/* UVa problem: <10706>
 *
 * Topic: Binary Search
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   A single positive integer i is given. Write a program to find the digit located in the position
 *   i in the sequence of number groups S1S2 . . . Sk.
 *   Each group Sk consists of a sequence of positive integer numbers ranging from 1 to k,
 *   written one after another. For example, the first 80 digits of the sequence are as follows:
 *   11212312341234512345612345671234567812345678912345678910123456789101112345678910
 *
 * Solution Summary:
 *
 *   1, initial a table by vector for binary search.
 *   2, in the table, each value represent the total number of numbers in the sequence.
 *   3, use (position - sequence) to calculate the length in Sn (drop S1S2...Sn-1) from 1 to exact answer.
 *   4, find exact number and print.
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
#include <cmath>

using namespace std;

vector<long long> all_table(1, 0);

void initTable(){
    int i = 0;
    long long j, total;
    long long prev = 0;
    for (i = 1; i!= 6; ++i){
        for (j = pow(10, i-1); j != pow(10, i); ++j){
            total = prev + i + all_table[j-1];
            prev += i;
            all_table.push_back(total);
        }
    }
}

int findNumber(long long length, int pos){
    long long sum = 0;
    int ans;
    int power , denominator, cur_num;
    for(int j = 1 ; j <= pos ; j++){
        cur_num = j;
        power = 0;
        for(int i = cur_num; i != 0 ; i/=10) {
            power++;
        }
        for(int k = power - 1; k >= 0 ; --k){
          ans = cur_num/(pow(10,k));
            ++sum;
            if(sum == length){
                return ans;
            }
            denominator = pow(10,k) ;
            cur_num %= denominator;
        }
    }
}

int search(long long query){
    int l = 0;
    int r = (int)all_table.size();
    int pivot = 0;
    while (l < r-1){
        pivot = (l + r)/2;
        if (all_table[pivot]>=query){
            r = pivot;
        }else{
            l = pivot;
        }
    }
    long long length = query - all_table[l];
    int ans = 0;
    ans = findNumber(length,r);
    return ans;
}

int main(){
    int n = 0;
    scanf("%d",&n);
    initTable();
    for (int i=0;i!=n;++i){
        long long query = 0;
        scanf("%lld", &query);
        int result;
        result = search(query);
        printf("%d\n",result);
    }
    return 0;
}
