#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll> g[100001];
ll inOut[100001][2], counter;
ll a[100001], z;
ll segTree[400004];
ll spf[1000001];
// void dfsOrdering(ll root, ll parent){
//     inOut[root][0] = counter++;
//     a[z++] = root;
//     for(auto it: g[root])
//         if(it != parent)
//             dfsOrdering(it, root);
//     inOut[root][1] = counter++;
//     a[z++] = root;
// }
void construct(ll low, ll high, ll ind){
    if(low >= high){
        segTree[ind] = a[low];
        return;
    }
    ll mid = (low + high) / 2;
    construct(low, mid, 2*ind+1);
    construct(mid+1, high, 2*ind+2);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}
ll query(ll low, ll high, ll l, ll r, ll ind){
    if(low >= l && high <= r)
        return segTree[ind];
    if(low > r || high < l)
        return 0;
    ll mid = (low + high) / 2;
    ll ans1 = query(low, mid, l, r, 2*ind+1);
    ll ans2 = query(mid+1, high, l, r, 2*ind+2);
    return ans1 + ans2;
}
void update(ll low, ll high, ll ind, ll x, ll val){
    if(low == high && low == x){
        segTree[ind] = val;
        return;
    }
    ll mid = (low + high) / 2;
    if(low <= x && x <= mid)
        update(low, mid, 2*ind+1, x, val);
    else
        update(mid+1, high, 2*ind+2, x, val);
    segTree[ind] = segTree[2*ind+1] + segTree[2*ind+2];
}
ll getSum(ll n){
    if(n == 0)
        return 0;
    map<ll, ll> primes;
    while(n != 1){
        primes[spf[n]]++;
        n /= spf[n];
    }
    ll summ = 1;
    for(auto it: primes)
        summ *= (pow(it.first, it.second+1) - 1) / (it.first - 1);
    return summ;
}
int main(){
    counter = 0;
    int n, i, j, x, y, type;
    for(i = 0; i < 1000001; i++)
        spf[i] = i;
    for(i = 2; i < 1000001; i++)
        if(spf[i] == i)
            for(j = 2*i; j < 1000001; j+=i)
                spf[j] = min(spf[j], (ll)i);
    scanf("%lld %lld", &n, &q);
    for(i = 0; i < n-1; i++){
        scanf("%lld %lld", &x, &y);
        g[x].pb(y);
        g[y].pb(x);
    }
    dfsOrdering(1, -1);
    while(q--){
        cin>>type>>x;
        if(type == 1){
            cout<<query(0, 2*n-1, inOut[x][0], inOut[x][1], 0)<<endl;
        }
        else{
            update(0, 2*n-1, 0, x, val);
            update(0, 2*n-1, 0, x, val);
        }
    }
return 0;
}