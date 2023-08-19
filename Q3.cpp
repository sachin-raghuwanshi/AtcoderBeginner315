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
    vector<int>f(n), s(n);
    int index = -1;
    int highest = -1;
    for(int i = 0; i < n; i++) {
        cin >> f[i] >> s[i];
        if(s[i] > highest) {
            highest = s[i];
            index = i;
        }
    }
    int secondSameFlav = 0;
    for(int i = 0; i < n; i++) {
        if(f[i] == f[index] && i != index) {
            if(secondSameFlav < s[i]) {
                secondSameFlav = s[i];
            }
        }
    }
    int secondDiffFlav = 0; 
    for(int i = 0; i < n; i++) {
        if(f[i] != f[index]) {
            if(secondDiffFlav < s[i]) {
                secondDiffFlav = s[i];
            }
        }
    }
    int ans = max(highest + secondSameFlav /2, highest + secondDiffFlav);
    cout << ans << endl;
 
}
