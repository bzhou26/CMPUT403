/* UVa problem: <202>
 *
 * Topic: (Arithmetic)
 *
 * Level: 2 points
 *
 * Brief problem description:
 *
 *   The decimal expansion of the fraction 1/33 is 0.03, where the 03 is used
 *   to indicate that the cycle 03 repeats inde nitely with no intervening digits.
 *   In fact, the decimal expansion of every rational number (fraction) has a
 *   repeating cycle as opposed to decimal expansions of irrational numbers,
 *   which have no such repeating cycles.
 *
 * Solution Summary:
 *
 *   Keep calculating quotient and reminder, and save them into two arrays, each time do:
 *                           numerator/denominator = quotient, reminder
 *                           original = reminder*10
 *   if same reminder occurs, repeat cycle has been found.
 *   In quotient array, from the second value, all the rest of values represent the number behind dot.
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

#include <stdio.h>
#include <string.h>

#define MAX_INT 3000

int checkInArray(int val, int *arr, int size){
    int i;
    for (i=0; i < size; i++) {
        if (arr[i] == val){
            return i;
        }
    }
    return -1;
}

int main() {
    int reminder_exist[MAX_INT+1];
    int quo_exist[MAX_INT+1];
    memset(quo_exist,0,sizeof(quo_exist));
    memset(reminder_exist, 0, sizeof(reminder_exist));
    int numerator;
    int original_num;
    int quo;
    int denominator;
    int reminder;
    int pos = 0;
    int end_pos = 0;
    int cycle_count = 0;
  
    while(scanf("%d%d", &numerator, &denominator) != EOF && denominator){
        original_num = numerator;
        /* caculate quotient and reminder.*/
        for (int i=0;i<MAX_INT;i++){
            quo=numerator/denominator;
            reminder = numerator % denominator;
            quo_exist[i] = quo;
            reminder_exist[i]=reminder;
            numerator = reminder*10;
            if (( pos = checkInArray(reminder,reminder_exist,i)) != -1){
                end_pos = i;
                break;
            }
        }
        cycle_count = end_pos - pos;
        /* print result */
        int count = 0;
        quo = original_num/denominator;
        printf("%d/%d = %d.",original_num,denominator,quo);
        for (int i = 1;i<pos+1;i++){
            count++;
            printf("%d",quo_exist[i]);
        }
        printf("(");
        for (int i = pos+1;i<=end_pos;i++){
            count++;
            printf("%d",quo_exist[i]);
            if (count==50){
                printf("...");
                break;
            }
        }
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n\n", cycle_count);
    }
    return 0;
}
