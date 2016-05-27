/*  BOJ 1110 - 더하기 사이클
    2016.05. */
#include <cstdio>
using namespace std;
int N,t,c;
int main() {
    scanf("%d",&N);
    t=N;
    do {
        c++;
        t=t%10*10+(t/10+t%10)%10;
    } while(t!=N);
    printf("%d",c);
    return 0;
}