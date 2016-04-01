/* UVa problem: 11837
 *
 * Topic: String
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   A melody can be represented by a sequence of notes. For example,
 *   A A D C# C# D E E E F# A D G# A
 *   is a well known melody. Note however that as the distances between the semitones are always equal, the same melody
 *   can be written starting with another note (we say that the melody is in another key):
 *   B B E D# D# E Gb Gb Gb G# B E A# B
 *   Your neighbor is a famous composer who suspects someone has plagiarized one of her songs.
 *   She asked your help to write a program that, given the sequence of notes of the melody in her song,
 *   and the sequence of notes of a suspicious snippet of melody, determines if the suspicious snippet occurs,
 *   in some key, in her song.
 *
 * Solution Summary:
 *
 *   find the gap between each two tone, use KMP to find whether the second string is in the first string.
 *
 * Used Resources:
 *
 *   http://blog.csdn.net/v_july_v/article/details/7041827
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include <iostream>
#include <map>
#include <string>
#include <string.h>

using namespace std;
map<string, char> piano;
const int maxn = 100026;
int nt[maxn];
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

void GetNextval(int *t, int tLen) {
    int i =0;
    int j =-1;
    nt[0] =-1;
    while(i<tLen) {
        if(j==-1 || t[i]==t[j]) {
            j++;i++;nt[i] =j;
        } else {
            j=nt[j];
        }
    }
}

int KmpSearch(const int* src, const int* t, int slen, int tlen) {
    int i =0, j=0;
    while(i<slen && j<tlen) {
        if(j==-1 || src[i] ==t[j])
            i++,j++;
        else
            j = nt[j];
    }
    if(j>=tlen) {
        return (i - j);
    } else {
        return -1;
    }
}

int main(){
    init_piano();
    int m, t;
    string read;
    while (cin >> m >> t, m || t){
        int prev=0, ans;
        memset(original, 0, sizeof(original));
        memset(suspect, 0, sizeof(suspect));
        memset(nt, 0, sizeof(nt));
        for(int i = 0; i != m; i++){
            cin >> read;
            auto r = piano.find(read);
            if (i){
                original[i - 1] = (r -> second - prev + 12)%12;
            }
            prev = r -> second;
        }
        for(int i = 0; i != t; i++){
            cin >> read;
            auto r = piano.find(read);
            if (i){
                suspect[i - 1] = (r -> second - prev + 12)%12;
            }
            prev = r -> second;
        }
        GetNextval(original, m - 1);
        ans = KmpSearch(original, suspect, m - 1, t - 1);
        if (ans == -1){
            cout << "N" << endl;
        }else{
            cout << "S" << endl;
        }
    }
    return 0;
}