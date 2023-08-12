#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a = -1;
        int b = -1;
        int c = 1;
        for(int i = 2; i*i <= n; ++i){
            if(n%i == 0){
                a = i;
                break;
            }
        }
        n = n/a;
        for(int i = a+1; i*i <= n; ++i){
            if(n%i == 0){
                if(n/i != i )b = i;
                break;
            }
        }
        c = n/b;
        if(a == -1 || b == -1){
            cout<<"NO\n";
            continue;    
        }
        cout<<"YES\n";
        cout<<a<<" "<<b<<" "<<c<<"\n";
    }
    return 0;
}