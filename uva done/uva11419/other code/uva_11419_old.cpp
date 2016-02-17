#include <iostream>
#include <vector>

using namespace std;

const int maxn = 2000;
vector<int> row(maxn,0);
vector<int> col(maxn,0);
int row_num = 0, col_num = 0;

int main(){
    int r, c, n;
    cin >> r >> c >> n;
    while (r || c || n){
        row_num = 0;
        col_num = 0;
        for (int i = 0; i <= max(r,c); ++i){
            row[i] = 0;
            col[i] = 0;
        }
        int r_pos, c_pos;
        for (int k = 0; k != n; ++k){
            cin >> r_pos >> c_pos;
            if (!row[r_pos] && (r_pos <= r) && (c_pos <= c) && r_pos && c_pos){
                row[r_pos] = 1;
                ++row_num;
            }
            if (!col[c_pos] && (r_pos <= r) && (c_pos <= c) && r_pos && c_pos){
                col[c_pos] = 1;
                ++col_num;
            }
        }
        //finish input
        if (row_num <= col_num){
            cout << row_num;
            for (int i = 1; i <= r; ++i){
                if (row[i]){
                    cout << " r" << i;
                }
            }
            cout << endl;
        }else{
            cout << col_num;
            for (int i = 1; i <= c; ++i){
                if (col[i]){
                    cout << " c" << i;
                }
            }
            cout << endl;
        }
        cin >> r >> c >> n;
    }
    return 0;
}
