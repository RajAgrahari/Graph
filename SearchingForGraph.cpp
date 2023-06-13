//https://codeforces.com/contest/402/problem/C
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define NOOB ios_base::sync_with_stdio(false);
#define CODER cin.tie(NULL);
#define SOLUTION cout.tie(NULL);

int main()
{
    NOOB CODER SOLUTION
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,p;
        cin>>n>>p;
        ll cnt=0;
        bool f=false;
        for(ll i=1;i<=n;i++)
        {
           for(ll j=i+1;j<=n;j++)
           {
               cout<<i<<' '<<j<<'\n';
               cnt++;
               if(cnt==(2*n+p))
               {
                  f=true;
                  break;
               }
           }
           if(f)
           break;
        }
    }
    return 0;
}
