#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

const int N = 100010;

struct point{double x,y;};

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int main ()
{
	int i, j, k, n, m;
	bool flag = true;
	point cv[N];
	for (scanf ("%d", &n), i = 0; i < n; i++)
		scanf ("%lf%lf", &cv[i].x, &cv[i].y);
	for (scanf ("%d", &m); m; m--) {
		point t; scanf ("%lf%lf", &t.x, &t.y);
		int up = n - 1, low = 1;
		while (up > low) {
			int mid = (up + low + 1) >> 1;
			if (xmult (cv[mid], t, cv[0]) <= 0)  low = mid;
			else up = mid - 1;
		}
		if (low == n - 1 || xmult (cv[1], t, cv[0]) >= 0) flag = false;
		else if (xmult (t, cv[low + 1], cv[low]) <= 0) flag = false;
	}
	if (!flag) puts ("NO");
	else puts ("YES");
	return 0;
}



