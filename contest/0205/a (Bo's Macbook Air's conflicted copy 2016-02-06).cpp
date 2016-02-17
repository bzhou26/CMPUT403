#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;




int main(){
    int kase;
    cin >> kase;
    while(kase--){
        int n,m;
        cin >> n >> m;
        int s;
        int max1 = -1;
        int max2 = -1;
        for (int i=1; i <= n; i++){
            cin >> s;
            max1 = max(max1,s);
        }
        for (int i=1; i <= m; i++){
            cin >> s;
            max2 = max(max2,s);
        }
        //if (max1== -1 || max2 == -1){
          // cout << "uncertain";
          // }else
          if (max1<max2) {
            cout << "MechaGodzilla";
        }else if (max1>=max2){
          cout << "Godzilla";
        }else{
          cout << "uncertain";
        }
        if (!kase){
          cout << endl;
        }
    }
    return 0;
}
