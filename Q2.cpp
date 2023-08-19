#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1000000007;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(int i = 0; i < n; i++)  {
        cin >> v[i];
        sum += v[i];
    }
    int mid = (sum + 1) / 2;
    for(int i = 0; i < n; i++) {
        if(v[i] < mid) {
            mid -= v[i];
        } else {
            cout << i + 1 <<" " << mid << endl;
            break;
        }
    }
    
}
