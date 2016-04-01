#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;
map<string, int> piano;
const int maxn = 100026;
int original[maxn], suspect[maxn];

void init_piano(){
    piano["C"]=1;
    piano["B#"]=1;
    piano["C#"]=2;
    piano["Db"]=2;
    piano["D"]=3;
    piano["Eb"]=4;
    piano["D#"]=4;
    piano["E"]=5;
    piano["Fb"]=5;
    piano["F"]=6;
    piano["E#"]=6;
    piano["Gb"]=7;
    piano["F#"]=7;
    piano["G"]=8;
    piano["Ab"]=9;
    piano["G#"]=9;
    piano["A"]=10;
    piano["Bb"]=11;
    piano["A#"]=11;
    piano["B"]=12;
    piano["Cb"]=12;
}

int main(){
    init_piano();
    int m, t;
    string read;
    while (cin >> m >> t, m || t){
        memset(original, 0, sizeof(original));
        memset(suspect, 0, sizeof(suspect));
//        auto r = piano.find("E#");
//        cout << r->second << endl;
        for(int i = 0; i != m; i++){
            cin >> read;
//            cout << read << endl;
            auto r = piano.find(read);
            original[i] = r -> second;
        }
        for(int i = 0; i != t; i++){
            cin >> read;
            auto r = piano.find(read);
            suspect[i] = r -> second;
        }
        int same = 0;
        int gap = -13;
        for (int i = 0; i <= (m - t); i++){
            gap = suspect[0] - original[i];
            int l = 1;
            for (int j = 1; j < t; j++){
                if ((suspect[j]- original[i + l]) == gap){
                    same = 1;
                    l++;
                    continue;
                }else{
                    same = 0;
                    break;
                }
            }
            if (same == 1){
                break;
            }
        }
        if (same == 1){
            cout << 'S' << endl;
        }else{
            cout << 'N' << endl;
        }
    }
    return 0;
}
