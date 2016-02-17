//
// Created by Bo Zhou on 2016-01-29.
//
#include <iostream>

int main(){
    long long numerator, denominator;

    while(scanf("%lld%lld", &numerator, &denominator) != EOF && (numerator || denominator)){
        int quo = 0;
        int reminder = 0;
        while(true){
            quo += numerator/denominator;
            reminder = numerator % denominator;
            numerator = reminder;
            if (numerator/denominator == 0){
                break;
            }
        }
        printf("%d %d / %lld\n", quo, reminder, denominator);
    }
    return 0;

}
