/* UVa problem: 10327
 *
 * Topic: Sorting
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Sorting in computer science is an important part. Almost every
 *   problem can be solved effeciently if sorted data are found. There
 *   are some excellent sorting algorithm which has already acheived
 *   the lower bound n · lg n. In this problem we will also discuss
 *   about a new sorting approach. In this approach only one operation
 *   (Flip) is available and that is you can exchange two adjacent terms.
 *   If you think a while, you will see that it is always possible to sort
 *   a set of numbers in this way.
 *
 * Solution Summary:
 *
 *   use bubble sort
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
#include <string.h>

using namespace std;

const int maxn = 1010;
int number[maxn];
int cont;
int N;

void bubble_sort(){
    int tmp;
    for (int i = 0; i != N; i++){
        for (int j = 0; j < N-i-1; j++){
            if (number[j] > number[j+1]){
                cont++;
                tmp = number[j];
                number [j] = number[j+1];
                number [j+1] = tmp;
            }
        }
    }
}

int main(){
    while(scanf("%d", &N) != EOF){
        int a;
        memset(number,0,sizeof(number));
        for (int i = 0; i != N; i++){
            cin >> a;
            number[i] = a;
        }
        // sort
        cont = 0;
        bubble_sort();
        cout << "Minimum exchange operations : " << cont << endl;
    }
}