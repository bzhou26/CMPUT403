#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INT 3000

int isvalueinarray(int val, int *arr, int size){
  int i;
  for (i=0; i < size; i++) {
    if (arr[i] == val){
      return i;
    }
  }
  return -1;
}

int main(int argc, char *argv[]) {
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
  
  if (argc == 3 ){
    numerator = atoi(argv[1]);
    original_num = numerator;
    denominator = atoi(argv[2]);
  }
  else {
    printf("please enter 2 number\n");
    return -1;
  }
  // caculate quotient and reminder.
  for (int i=0;i<MAX_INT;i++){
    quo=numerator/denominator;
    reminder = numerator % denominator;
    quo_exist[i] = quo;
    reminder_exist[i]=reminder;
    numerator = reminder*10;
    if (( pos = isvalueinarray(reminder,reminder_exist,i)) != -1){
      end_pos = i;
      break;
    }
  }
  cycle_count = end_pos - pos;
  // print result
  quo = original_num/denominator;
  printf("%d/%d = %d.",original_num,denominator,quo);
  for (int i = 1;i<pos+1;i++){
    printf("%d",quo_exist[i]);
  }
  printf("(");
  for (int i = pos+1;i<=end_pos;i++){
    printf("%d",quo_exist[i]);
  }
  printf(")\n");
  printf("%d = number of digits in repeating cycle\n", cycle_count);
}
