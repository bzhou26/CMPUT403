/* UVa problem: 11136
 *
 * Topic: Data Structures
 *
 * Level: 1 point
 *
 * Brief problem description:
 *   • A client who wants to participate in the promotion (aka a sucker) must write down their phone number on the bill
 *   of their purchase and put the bill into a special urn.
 *   • Two bills are selected from the urn at the end of each day: first the highest bill is selected and then the
 *   lowest bill is selected. The client who paid the largest bill receives a monetary prize equal to the difference
 *   between his bill and the lowest bill of the day.
 *   • Both selected bills are not returned to the urn while all the remaining ones are kept in the urn for the next day.
 *
 * Solution Summary:
 *
 *   use multiset which is a sorted container.
 *
 * Used Resources:
 *
 * http://www.cplusplus.com/reference/set/multiset/end/
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <set>

using namespace std;
long long sum=0;
multiset<long long> bills;

int main(){
    int kase, n;
    long long money;
    while (cin >> kase, kase){
        sum = 0;
        bills.clear();
        for (int i = 0; i != kase; i++){
            cin >> n;
            while (n--){
                cin >> money;
                bills.insert(money);
            }
            sum += ((*(--bills.end())) - (*bills.begin()));
            bills.erase(--bills.end());
            bills.erase(bills.begin());
        }
        cout << sum << endl;
    }
    return 0;
}