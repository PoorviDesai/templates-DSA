#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
#define MOD 1000000007
 
void update(ll BIT[], ll n, ll i, ll val) {
    for(;i<=n;i += (i & -i)) {
        BIT[i] += val;
    }
}
 
ll query(ll BIT[], ll i) {
    ll sum = 0;
    
    for(;i;i-=(i & -i)) {
        sum += BIT[i];
    }
    
    return sum;
}
 
// for decomposition
void convert(ll arr[], ll n) {
    ll tmp[n];
    for(ll i=0;i<n;i++) {
        tmp[i] = arr[i];
    }
    
    sort(tmp, tmp + n);
    
    for(ll i=0;i<n;i++) {
        arr[i] = lower_bound(tmp, tmp + n, arr[i]) - tmp + 1;
    }
}
 
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    // ll t;
    // cin>>t;
    
    // while(t--) {
        
    // }
    ll n;
    cin>>n;
    
    ll a[n];
    for(ll i=0;i<n;i++) {
        cin>>a[i];
    }
    
    convert(a, n);
    
    ll BIT[n + 1];
    ll greaterLeft[n + 1];
    ll smallerRight[n + 1];
    
    memset(BIT, 0, sizeof(BIT));
    memset(greaterLeft, 0, sizeof(greaterLeft));
    memset(smallerRight, 0, sizeof(smallerRight));
    
    // finding all elements to right which are smaller than current element
    for(ll i=n-1;i>=0;i--) {
        smallerRight[i] = query(BIT, a[i] - 1);
        update(BIT, n, a[i], 1);
    }
    
    for(ll i=0;i<=n;i++) {
        BIT[i] = 0;
    }
    
    // finding all the elements to the left which are greater than the current element
    for(ll i=0;i<n;i++) {
        greaterLeft[i] = i - query(BIT, a[i]);
        update(BIT, n, a[i], 1);
    }
    
    // final ans
    ll ans=0;
    for(ll i=0;i<n;i++) {
        ans += (greaterLeft[i] * smallerRight[i]);
    }
    
    cout<<ans<<endl;
    
    return 0;
}
