/* UVa problem: <714>
 *
 * Topic: Binary Search
 *
 * Level: 2 points
 * 
 * Brief problem description: 
 * 
 * Imagine you have m books (numbered 1,2,...,m) that
 * may have di erent number of pages (p1,p2,...,pm) and you want to
 * make one copy of each of them.
 * Your task is to divide these books among k scribes, k ≤ m. Each book
 * can be assigned to a single scriber only, and every scriber must get a continuous sequence of books.
 *
 * Solution Summary:
 *
 *   1, input all books into an vector, at the same time find the largest number and the total sum.
 *   2, set largest number as minimum number and the total sum as maximum number to find a threshold of
 *    each scriber's most pages.
 *   3, implement greedy algorithm, assign books from back to front based on the threshold.
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Binary_search_algorithm
 *
 * I hereby certify that I have produced the following solution myself 
 * using the resources listed above in accordance with the CMPUT 403 
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <vector>

using namespace std;

int m = 0;
int k = 0;
long long books[600];
long long l = 0;
long long r = 0;

long long findPivot(){
    long long pivot = 0;
    while( l < r ) {
        long long sum = 0;
        int scriber = 0;
        pivot = (l + r)/2;
        for (int i = 0; i != m; ++i){
            if(sum + books[i] > pivot){
                ++scriber;
                sum = 0;
            }
            sum += books[i];
        }
        if (sum > pivot){
            ++scriber;
        }
        if (scriber > k-1){
            l = pivot + 1;
        }else{
            r = pivot;
        }
    }
    // printf("pivot is %d\n",r);
    return r;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int pp = 0; pp < n; pp++){
        l = 0;
        r = 0;
        scanf("%d%d",&m,&k);
        for (int i = 0; i< m;i++){
            scanf("%lld",&books[i]);
            l = max(l, books[i]);
            r += books[i];
        }
        int group = k - 1;
        long long pivot = 0;
        pivot = findPivot();
        vector<long long> results[600];
        int per_sum = 0;
        for (int i = m - 1; i >= 0 ; --i) {
            if (per_sum + books[i] > pivot) {
                --group;
                per_sum = 0;
            }
            if(i == group) {
                for(int j = 0; j <= i; j ++) {
                    results[j].push_back(books[j]);
                }
                break;
            }
            per_sum += books[i];
            results[group].push_back(books[i]);
        }
        for (int i = 0; i != k; ++i) {
            for (int q = results[i].size()-1; q >=0; -- q){
                printf("%lld",results[i][q]);
                if (q != 0 || i != k-1){
                    printf(" ");
                }
            }
            if (i < k-1){
                printf("/ ");
            }
        }
        printf("\n");
    }
    return 0;
}

