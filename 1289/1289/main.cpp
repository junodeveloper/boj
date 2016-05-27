/*  BOJ 1289 - 트리의 가중치
    2016.05. by junodeveloper */
#include <cstdio>
#include <vector>
#define M 1000000007
using namespace std;
typedef long long int lli;
vector<pair<lli,lli> > adj[100001];
lli N,d[100001],res;
bool chk[100001];
void f(lli v) {
    chk[v]=1;
    lli w=0,sum=0;
    for(auto t : adj[v]) {
        lli u=t.first, e=t.second;
        if(!chk[u]) {
            f(u);
            w=(w+sum*(d[u]*e%M)%M+sum*e)%M;
            sum=(sum+d[u]*e+e)%M;
        }
    }
    d[v]=sum;
    res=(res+w+sum)%M;
}
int main() {
    scanf("%lld",&N);
    for(int i=0;i<N-1;i++) {
        lli a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    f(1);
    printf("%lld",res);
    return 0;
}