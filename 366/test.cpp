#include <bits/stdc++.h>
#define pop pop_back
#define front back
#define push push_back
 
using namespace std;
 
const int N = 1<<19;
 
int n,q;
int it[N];
vector < int > qu[N];
int cnt,prefix;
 
void update(int pos, int val) {
    for(;pos<=300000;pos+=pos&(-pos)) it[pos]+=val;
}
 
int query(int pos) {
    int ans=0;
    for(;pos>=1;pos-=pos&(-pos)) ans+=it[pos];
    return ans;
}
 
int main() {
    int i,type,x;
 
    scanf("%d %d", &n, &q);
    for(i=1;i<=q;i++) {
        scanf("%d", &type);
        if(type==1) {

            scanf("%d", &x);
            qu[x].push(++cnt);
            update(cnt,1);

            cout << ">> " << prefix << '\n';
            printf("%d\n", query(300000)-query(prefix));
        }
        else if(type==2) {
            scanf("%d", &x);
            while(!qu[x].empty()) update(qu[x].front(),-1),qu[x].pop();
            printf("%d\n", query(300000)-query(prefix));
        }
        else {
            scanf("%d", &x);
            prefix=max(prefix,x);
            printf("%d\n", query(300000)-query(prefix));
        }
    }
 
    return 0;
}