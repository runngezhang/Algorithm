#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <ctime>

using namespace std;



#define clr(x) memset(x, 0, sizeof(x))


class LISNumber
{
        public:
        int count(vector <int> cardsnum, int K);
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 4; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {36, 36, 36, 36, 36}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; int Arg2 = 1; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {3, 2, 11, 5, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 20; int Arg2 = 474640725; verify_case(3, Arg2, count(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {31, 4, 15, 9, 26, 5, 35, 8, 9, 7, 9, 32, 3, 8, 4, 6, 26}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; int Arg2 = 12133719; verify_case(4, Arg2, count(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {27, 18, 28, 18, 28, 4, 5, 9, 4, 5, 23, 5,
 36, 28, 7, 4, 7, 13, 5, 26, 6, 24, 9, 7,
 7, 5, 7, 24, 7, 9, 36, 9, 9, 9, 5, 9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 116; int Arg2 = 516440918; verify_case(5, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

};

const int N = 40;
const long long md = 1000000007;

long long d[N][N*N][N];
long long fac[N];


long long fexp (long long x, long long y) {
	long long ans = 1, t = x;
	while (y) {
		if (y&1)
			ans = ans * t % md;
		t = t * t % md;
		y /= 2;
	}
	return ans;
}

long long pinv (long long x) {
	return fexp(x, md - 2);
}

int sum[N];

int LISNumber::count(vector <int> a, int K)
{
	int n = a.size();
	int i, j;

	clr (d);
	sum[0] = 0;
	for (i = 1; i <= n; ++i)
		sum[i] = sum[i-1] + a[i - 1];

	fac[0] = 1;
	for (i = 1; i < N; ++i)
		fac[i] = fac[i-1] * i % md;

	d[1][0][0] = 1;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= K; ++j) {
			d[i][j][0] = (i == 1) ? 0 : d[i-1][j][a[i-2]] * pinv(fac[a[i-2]]) % md;
			for (int p = 1; p <= j; ++p)
				d[i][j][p] = (d[i][j][p-1] * (j - p + 1) % md + d[i][j-1][p-1] * (sum[i-1] + p - (j - p)) % md) % md;
		}
	return (int) (d[n][K][a[n - 1]] * pinv(fac[a[n-1]]) % md);
}

// BEGIN CUT HERE
int main()
{
        LISNumber ___test;
        ___test.run_test(-1);
        return 0;
}
// END CUT HERE
