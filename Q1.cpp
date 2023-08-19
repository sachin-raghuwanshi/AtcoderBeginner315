#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int mod = 1000000007;
int main() 
{
    string s;
    cin >> s;
    string ans = "";
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u') {
            continue;
        }
        ans.push_back(s[i]);
    }
    cout << ans;
}
