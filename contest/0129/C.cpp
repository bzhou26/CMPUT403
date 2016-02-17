//
// Created by Bo Zhou on 2016-01-29.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int n = 0;
    string line;
    while(scanf("%s", &line) != EOF){
        int power = 0;
        int level = 0;
        level = line.length();
        power = pow(2,line.length());


        int y = 0;
        int x = 0;
        long long reminder = 0;
        long long table_size = power * power;
        int quo = table_size;
//        while(quo>0){
        y = n/power;
        x = n%power;
//        }
        printf("%d %d %d\n", level, x, y);
    }


    return 0;
}
