/*  BOJ 2579 - 계단 오르기
    2016.05. by junodeveloper */
#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
int n,a[301],d1[301],d2[301];
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    d1[1]=a[1], d1[2]=a[1]+a[2], d1[3]=a[2]+a[3];
    d2[1]=0, d2[2]=a[2], d2[3]=a[1]+a[3];
    for(int i=4;i<=n;i++) {
        d1[i]=d2[i-1]+a[i];
        d2[i]=MAX(d1[i-2]+a[i],d2[i-2]+a[i]);
    }
    printf("%d",MAX(d1[n],d2[n]));
    return 0;
}