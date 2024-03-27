#define toStr(a) #a
#define io(a) cin >> a
#define minimum(a, b) a = a < b ? a : b
#define maximum(a, b) a = a > b ? a : b
#define FUNCTION(min_max, signal) void calc_##min_max(int& a, int b) {a = a signal b ? a : b;}
#define foreach(a, b) for(int b = 0; b < a.size(); b++)
#define INF 10000000
#include <iostream>
#include <vector>
using namespace std;

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif 

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int main(){
	int n; cin >> n;
	vector<int> v(n);
	foreach(v, i) {
		io(v)[i];
	}
	int mn = INF;
	int mx = -INF;
	foreach(v, i) {
		minimum(mn, v[i]);
		maximum(mx, v[i]);
	}
	int ans = mx - mn;
	cout << toStr(Result =) <<' '<< ans;
	return 0;

}