/* UVa problem: 11512
 *
 * Topic: String
 *
 * Level: 1 point
 *
 * Brief problem description:
 *
 *   The scientists of the institute decoded successfully the DNA sequences of numerous bacterias from the same family,
 *   with other method of sequencing (much more expensive than the shotgun process) that avoids the problem of
 *   repetitions. The biologists wonder if it was a waste of money the application of the other method because they
 *   believe there is not any large repeated fragment in the DNA of the bacterias of the family studied.
 *   The biologists contacted you to write a program that, given a DNA strand, finds the largest substring that is
 *   repeated two or more times in the sequence.
 *
 * Solution Summary:
 *
 *   use Suffix array as data struct and the algorithm in the resource paper.
 *
 * Used Resources:
 *
 *   http://wenku.baidu.com/view/228caa45b307e87101f696a8.html###
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Bo Zhou
 */

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN = 1010;
char r[MAXN];
int wa[MAXN], wb[MAXN], wv[MAXN], ws[MAXN];
int sa[MAXN], height[MAXN], rk[MAXN];

//http://wenku.baidu.com/view/228caa45b307e87101f696a8.html###
int cmp(int *r,int a,int b,int l) {
    return r[a]==r[b]&&r[a+l]==r[b+l];
}

//http://wenku.baidu.com/view/228caa45b307e87101f696a8.html###
void SA(int n,int m) {
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++) ws[i]=0;
    for(i=0;i<n;i++) ws[x[i]=r[i]]++;
    for(i=1;i<m;i++) ws[i]+=ws[i-1];
    for(i=n-1;i>=0;i--) sa[--ws[x[i]]]=i;
    for(j=p=1;p<n;j<<=1,m=p) {
        for(p=0,i=n-j;i<n;i++) y[p++]=i;
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        for(i=0;i<n;i++) wv[i]=x[y[i]];
        for(i=0;i<m;i++) ws[i]=0;
        for(i=0;i<n;i++) ws[wv[i]]++;
        for(i=1;i<m;i++) ws[i]+=ws[i-1];
        for(i=n-1;i>=0;i--) sa[--ws[wv[i]]]=y[i];
        for(t=x,x=y,y=t,x[sa[0]]=0,p=i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return;
}
//http://wenku.baidu.com/view/228caa45b307e87101f696a8.html###
void calheight(int n) {
    int i,j,k;
    for(i=1;i<=n;i++) rk[sa[i]]=i;
    for(i=k=0;i<n;height[rk[i++]]=k)
        for(k?k--:0,j=sa[rk[i]-1];r[i+k]==r[j+k];k++);
}

int main() {
    int result, kase, len, i, j, k;
    scanf("%d", &kase);
//    std::cin >> c;
    while(kase--) {
        scanf("%s", r);
        len=strlen(r);
        SA(len + 1, 'U');
        calheight(len);
        result = 0;
        for(i = 1; i <= len; i++){
            result = max(result, height[i]);
        }
        if(result) {
            for(i = k = 1; i <= len; i++) {
                if(height[i] >= result){
                    break;
                }
            }
            for(j = i; j <= len && height[j] >= result; j++){
                k++;
            }
            for(j = sa[i]; j < sa[i] + result; j++){
                putchar(r[j]);
            }
            printf(" %d\n", k);
        }
        else
            puts("No repetitions found!");
    }
    return 0;
}