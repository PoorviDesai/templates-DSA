// https://codeforces.com/contest/276/problem/C
// qs which can be seen as an application of fenwick tree

// maximum freq wle index ko max number assign krna hh
// assign krna can cause TLE if done by brute force or naive way
// so this can be done using Fenwick Tree
// update(l,1) & update(r+1, -1)
// r k baad -1 !!

#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long int
 
ll ans=0, n, q;
 
#define MAX_N 300001
 
ll cum[MAX_N];
ll newcum[MAX_N];
 
ll tree[MAX_N];
 
void update(int x, ll val)
{
    while(x<=n)
    {
        tree[x] += val;
        x += (x & -x);
    }
}
ll read(int x)
{
    int sum=0;
    while(x>0)
    {
        sum += tree[x];
        x -= (x & -x);
    }
    return sum;
}
 
int main()
{
    // ll t;
    // cin>>t;
    // while(t--)
    // {
 
 
    // }
    ios_base::sync_with_stdio(0), cin.tie(0);
    
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        cin>>cum[i];
    }
    sort(cum, cum + n, greater<int>());
    ll l,r;
    while(q--)
    {
        cin>>l>>r;
        update(l, 1);
        update(r+1, -1);
    }
    for(int i=1;i<=n;i++)
    {
        newcum[i-1] = read(i);
    }
    sort(newcum, newcum + n, greater<int>());
    for(int i=0;i<n;i++)
    {
        ans += (newcum[i] * cum[i]);
    }
    cout<<ans<<endl;
    return 0;
}
 
