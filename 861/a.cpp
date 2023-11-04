#include <bits/stdc++.h>
using namespace std;


#define all(a) a.begin(), a.end()

void ahcorz(){
    int l,r; cin >> l >> r;
    int maxx=-1,res;
    for(int i=l; i<=r; ++i){

        string s=to_string(i);

        int val=(*max_element(all(s)))-(*min_element(all(s)));

        if(val>maxx) maxx=val,res=i;
        
        if(maxx==9) break;
    }
    cout << res << "\n";
}
 
signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    int t; cin >> t;
    while(t--) ahcorz();
}