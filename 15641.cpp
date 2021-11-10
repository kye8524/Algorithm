#include <iostream>

using namespace std;
int check(int m) {
    int target=77;
	return m<=target?1:0;
}

int solve() {
	int l = 0;
    int n=100;
	int r = n;
	int res = -1;
	while (l<=r)
	{
		int m = (l + r) / 2;
		if (check(m)) {
			res = m;
			l = m + 1;
		}else {
			r = m - 1;
		}
	}
	cout<<res<<'\n';
	return 0;
}
int main(){
    solve();
}