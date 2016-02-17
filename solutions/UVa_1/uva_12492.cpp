/* UVa problem: 12492
 *
 * Topic: Combinatorics
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   Probably everyone in this competition knows the Rubik’s Cube,
 *   a challenging 3-D puzzle. Each of it six sides is covered with nine labels,
 *   each label of a color (blue, yellow, orange, white, green and red).
 *   You must write a program that, given a sequence of movements,
 *   determines the minimum number of complete applications of that
 *   sequence to make the cube return to its original state.
 *
 * Solution Summary:
 *
 *   lable each small block:
 *                              back
 *                              00 01 02
 *                              03 04 05
 *                              06 07 08
 *                              --------
 *                    left    |  top     | right
 *                   36 37 38 | 09 10 11 | 45 46 47
 *                   39 40 41 | 12 13 14 | 48 49 50
 *                   42 43 44 | 15 16 17 | 51 52 53
 *                              --------
 *                              front
 *                              18 19 20
 *                              21 22 23
 *                              24 25 26
 *                              --------
 *                              down
 *                              27 28 29
 *                              30 31 32
 *                              33 34 35
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


#include <iostream>
#include <string.h>

using namespace std;
int rubic[54];
int dif = 1;

void face_clockwise(int s){
    int temp1 = rubic[s+1];
    int temp2 = rubic[s+2];
    rubic[s+2] = rubic[s];
    rubic[s+1] = rubic[s+3];
    rubic[s] = rubic[s+6];
    rubic[s+3] = rubic[s+7];
    rubic[s+6] = rubic[s+8];
    rubic[s+7] = rubic[s+5];
    rubic[s+8] = temp2;
    rubic[s+5] = temp1;
}

void face_countclockwise(int s){
    int temp1 = rubic[s];
    int temp2 = rubic[s+1];
    rubic[s] = rubic[s+2];
    rubic[s+1] = rubic[s+5];
    rubic[s+2] = rubic[s+8];
    rubic[s+5] = rubic[s+7];
    rubic[s+8] = rubic[s+6];
    rubic[s+7] = rubic[s+3];
    rubic[s+6] = temp1;
    rubic[s+3] = temp2;
}

void U_rotate(){
    face_clockwise(9);
    int temp1 = rubic[6];
    int temp2 = rubic[7];
    int temp3 = rubic[8];
    rubic[6] = rubic[44];
    rubic[7] = rubic[41];
    rubic[8] = rubic[38];
    rubic[44] = rubic[20];
    rubic[41] = rubic[19];
    rubic[38] = rubic[18];
    rubic[20] = rubic[45];
    rubic[19] = rubic[48];
    rubic[18] = rubic[51];
    rubic[45] = temp1;
    rubic[48] = temp2;
    rubic[51] = temp3;
}

void u_rotate(){
    face_countclockwise(9);
    int temp1 = rubic[6];
    int temp2 = rubic[7];
    int temp3 = rubic[8];
    rubic[6] = rubic[45];
    rubic[7] = rubic[48];
    rubic[8] = rubic[51];
    rubic[45] = rubic[20];
    rubic[48] = rubic[19];
    rubic[51] = rubic[18];
    rubic[20] = rubic[44];
    rubic[19] = rubic[41];
    rubic[18] = rubic[38];
    rubic[44] = temp1;
    rubic[41] = temp2;
    rubic[38] = temp3;
}

void D_rotate(){
    face_clockwise(27);
    int temp1 = rubic[0];
    int temp2 = rubic[1];
    int temp3 = rubic[2];
    rubic[0] = rubic[47];
    rubic[1] = rubic[50];
    rubic[2] = rubic[53];
    rubic[47] = rubic[26];
    rubic[50] = rubic[25];
    rubic[53] = rubic[24];
    rubic[26] = rubic[42];
    rubic[25] = rubic[39];
    rubic[24] = rubic[36];
    rubic[42] = temp1;
    rubic[39] = temp2;
    rubic[36] = temp3;
}

void d_rotate(){
    face_countclockwise(27);
    int temp1 = rubic[0];
    int temp2 = rubic[1];
    int temp3 = rubic[2];
    rubic[0] = rubic[42];
    rubic[1] = rubic[39];
    rubic[2] = rubic[36];
    rubic[42] = rubic[26];
    rubic[39] = rubic[25];
    rubic[36] = rubic[24];
    rubic[26] = rubic[47];
    rubic[25] = rubic[50];
    rubic[24] = rubic[53];
    rubic[47] = temp1;
    rubic[50] = temp2;
    rubic[53] = temp3;
}

void F_rotate(){
    face_clockwise(18);
    int temp1 = rubic[15];
    int temp2 = rubic[16];
    int temp3 = rubic[17];
    rubic[15] = rubic[42];
    rubic[16] = rubic[43];
    rubic[17] = rubic[44];
    rubic[42] = rubic[29];
    rubic[43] = rubic[28];
    rubic[44] = rubic[27];
    rubic[29] = rubic[51];
    rubic[28] = rubic[52];
    rubic[27] = rubic[53];
    rubic[51] = temp1;
    rubic[52] = temp2;
    rubic[53] = temp3;
}

void f_rotate(){
    face_countclockwise(18);
    int temp1 = rubic[15];
    int temp2 = rubic[16];
    int temp3 = rubic[17];
    rubic[15] = rubic[51];
    rubic[16] = rubic[52];
    rubic[17] = rubic[53];
    rubic[51] = rubic[29];
    rubic[52] = rubic[28];
    rubic[53] = rubic[27];
    rubic[29] = rubic[42];
    rubic[28] = rubic[43];
    rubic[27] = rubic[44];
    rubic[42] = temp1;
    rubic[43] = temp2;
    rubic[44] = temp3;
}

void B_rotate(){
    face_clockwise(0);
    int temp1 = rubic[33];
    int temp2 = rubic[34];
    int temp3 = rubic[35];
    rubic[33] = rubic[38];
    rubic[34] = rubic[37];
    rubic[35] = rubic[36];
    rubic[38] = rubic[11];
    rubic[37] = rubic[10];
    rubic[36] = rubic[9];
    rubic[11] = rubic[47];
    rubic[10] = rubic[46];
    rubic[9] = rubic[45];
    rubic[47] = temp1;
    rubic[46] = temp2;
    rubic[45] = temp3;
}

void b_rotate(){
    face_countclockwise(0);
    int temp1 = rubic[33];
    int temp2 = rubic[34];
    int temp3 = rubic[35];
    rubic[33] = rubic[47];
    rubic[34] = rubic[46];
    rubic[35] = rubic[45];
    rubic[47] = rubic[11];
    rubic[46] = rubic[10];
    rubic[45] = rubic[9];
    rubic[11] = rubic[38];
    rubic[10] = rubic[37];
    rubic[9] = rubic[36];
    rubic[38] = temp1;
    rubic[37] = temp2;
    rubic[36] = temp3;
}

void L_rotate(){
    face_clockwise(36);
    int temp1 = rubic[0];
    int temp2 = rubic[3];
    int temp3 = rubic[6];
    rubic[0] = rubic[27];
    rubic[3] = rubic[30];
    rubic[6] = rubic[33];
    rubic[27] = rubic[18];
    rubic[30] = rubic[21];
    rubic[33] = rubic[24];
    rubic[18] = rubic[9];
    rubic[21] = rubic[12];
    rubic[24] = rubic[15];
    rubic[9] = temp1;
    rubic[12] = temp2;
    rubic[15] = temp3;
}

void l_rotate(){
    face_countclockwise(36);
    int temp1 = rubic[0];
    int temp2 = rubic[3];
    int temp3 = rubic[6];
    rubic[0] = rubic[9];
    rubic[3] = rubic[12];
    rubic[6] = rubic[15];
    rubic[9] = rubic[18];
    rubic[12] = rubic[21];
    rubic[15] = rubic[24];
    rubic[18] = rubic[27];
    rubic[21] = rubic[30];
    rubic[24] = rubic[33];
    rubic[27] = temp1;
    rubic[30] = temp2;
    rubic[33] = temp3;
}

void R_rotate(){
    face_clockwise(45);
    int temp1 = rubic[8];
    int temp2 = rubic[5];
    int temp3 = rubic[2];
    rubic[8] = rubic[17];
    rubic[5] = rubic[14];
    rubic[2] = rubic[11];
    rubic[17] = rubic[26];
    rubic[14] = rubic[23];
    rubic[11] = rubic[20];
    rubic[26] = rubic[35];
    rubic[23] = rubic[32];
    rubic[20] = rubic[29];
    rubic[35] = temp1;
    rubic[32] = temp2;
    rubic[29] = temp3;
}

void r_rotate(){
    face_countclockwise(45);
    int temp1 = rubic[8];
    int temp2 = rubic[5];
    int temp3 = rubic[2];
    rubic[8] = rubic[35];
    rubic[5] = rubic[32];
    rubic[2] = rubic[29];
    rubic[35] = rubic[26];
    rubic[32] = rubic[23];
    rubic[29] = rubic[20];
    rubic[26] = rubic[17];
    rubic[23] = rubic[14];
    rubic[20] = rubic[11];
    rubic[17] = temp1;
    rubic[14] = temp2;
    rubic[11] = temp3;
}

void init_rubic(){
    for (int i = 0; i != 54; i++){
        rubic[i] = i;
    }
}

int check_rubic(){
    for (int i = 0; i != 54; i++){
        if (rubic[i] != i){
            return 1;
        }
    }
    return 0;
}

void do_command(char i){
    switch(i){
        case 'R':{
            R_rotate();
            break;
        }
        case 'r':{
            r_rotate();
            break;
        }
        case 'F':{
            F_rotate();
            break;
        }
        case 'f':{
            f_rotate();
            break;
        }
        case 'L':{
            L_rotate();
            break;
        }
        case 'l':{
            l_rotate();
            break;
        }
        case 'B':{
            B_rotate();
            break;
        }
        case 'b':{
            b_rotate();
            break;
        }
        case 'U':{
            U_rotate();
            break;
        }
        case 'u':{
            u_rotate();
            break;
        }
        case 'D':{
            D_rotate();
            break;
        }
        case 'd':{
            d_rotate();
            break;
        }
    }
}

int main(){
    string ins;
    while (getline(cin,ins)){
        int cont = 0;
        init_rubic();
        do{
            for (int i = 0; i != ins.size(); i++){
                do_command(ins[i]);
            }
            dif = check_rubic();
            cont++;
        }while(dif);
        cout << cont << endl;
    }
    return 0;
}
