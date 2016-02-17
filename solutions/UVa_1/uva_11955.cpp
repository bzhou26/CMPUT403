/* UVa problem: <11955>
 *
 * Topic: (Arithmetic)
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 * John likes mathematics a lot. His main passion is the binomial theorem.
 * However it is rather hard to calculate binomial coe cients,
 * so he decided to write a computer program that can expand any power of a sum into a sum of powers.
 * Mathematically it can be written like this:
 * (a + b)k = x1ak + x2ak−1b + x3ak−2b2 + ... + xk+1bk where x1...k+1 are binomial coe cients xi = Cki .
 *
 * Solution Summary:
 *
 *   read line into string
 *   split line into 3 parts, number 1, number 2, power,
 *   base on the polynominal, calculate coefficients for each terms,
 *   then combine these two numbers and power to terms from left to right.
 *
 *
 * Used Resources:
 *
 *   https://en.wikipedia.org/wiki/Binomial_theorem
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

vector<string> expressions;

long findCoefficient(int n, int k){
    double coefficient = 1;
    if ( k > n - k ) {
        k = n - k;
    }
    for (int i = 0; i != k; ++i) {
        coefficient *= (n - i);
        coefficient /= (i + 1);
    }
    return (long) coefficient;
}

string extendExpress(string a_num, string b_num, int n){
    string result, a, b, a_power, b_power, front;
    long coef = 0;
    for (int i=0; i<=n; ++i){
        coef = findCoefficient(n, i);
        if (coef > 1){
            front = to_string(coef)+"*";
        }else{
            front = "";
        }
        if ((n-i) >= 2){
            a_power = "^" + to_string(n-i);
        }else{
            a_power = "";
        }
        if (i >= 2){
            b_power = "^" + to_string(i);
        }else{
            b_power = "";
        }
        if ((n - i) == 0){
            a = "";
        }else{
            a = a_num;
        }
        if (i == 0){
            b = "";
        }else{
            b = b_num;
        }
        if (b != "" && a != ""){
            b = "*" + b;
        }
        result += front + a + a_power+ b + b_power;
        if (i != n){
            result += "+";
        }
    }
    return result;
}

void express(string line){
    string a;
    string b;
    string power;
    string expression;
    int n = 0;
    int i = 1;
    for (i = 1; i != line.size(); ++i){
        if (line[i] == '+'){
            break;
        }else{
            a+=line[i];
        }
    }
    for (++i; i != line.size(); ++i){
        if (line[i] == ')'){
            break;
        }else{
            b+=line[i];
        }
    }
    for (i += 2; i != line.size(); ++i){
        power += line[i];
    }
    n = stoi(power);
    expression = extendExpress(a,b,n);
    expressions.push_back(expression);
}

int main(){
    int n;
    string line;
    getline(cin, line);
    n = stoi(line);
    for (int i = 0; i != n; ++i){
        getline(cin,line);
        express(line);
    }
    for (int i = 0; i != n; ++i){
        cout << "Case "<< to_string(i+1)+": " << expressions[i] << endl;
    }

}
