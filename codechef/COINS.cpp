//INCLUDE
#include <bits/stdc++.h>
using namespace std;
//DEFINE
#define gc getchar_unlocked			//char c = gc();
#define fo(i,n) for (i=0;i<n;i++)
#define Fo(i,k,n) for (i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define ll	long long
#define lli	long long int
#define pb	push_back
#define mp	make_pair
#define F 	first
#define S 	second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626	//to pi or not to pi.
#define MOD 1000000007
#define INF 0x3f3f3f3f
//TYPEDEF
typedef pair<int, int>	pi;
typedef pair<lli, lli>	pl;
typedef vector<int>		vi;
typedef vector<lli>		vlli;
typedef vector<ll>		vl;
typedef vector<pi>		vpi;
typedef vector<pl>		vpl;
typedef vector<vi>		vvi;
typedef vector<vl>		vvl;

lli coins(vector<lli> &v,lli n) {
	if (n <= 11) {
		return n;
	}
	if (n < 1000000) {
		if(v[n]) {
			return v[n];
		}
		else {
			lli max = (lli)(coins(v,floor(n>>1)) + coins(v,floor(n/3)) + coins(v,floor(n>>2)));
			v[n] = ((max > n) ? max : n);
			return v[n];
		}
	}
	lli max = (lli)(coins(v,floor(n>>1)) + coins(v,floor(n/3)) + coins(v,floor(n>>2)));
	return ((max > n) ? max : n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vlli v(1000000,0);
	lli num;
	while (cin>>num) {
		cout<<coins(v,num)<<endl;
	}
	return 0;
}

ll mpow(int base, int exp) {
	base %= MOD;
	int result = 1;
	while (exp > 0) {
		if (exp & 1) result = ((ll)result * base) % MOD;
		base = ((ll)base * base) % MOD;
		exp >>= 1;
	}
	return result;
}

