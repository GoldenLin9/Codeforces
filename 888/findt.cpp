#include <bits/stdc++.h>
using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

typedef Point<double> P;

pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

int main() {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;

        vector<P> ps(n);
        for (int i = 0; i < n; i++) cin >> ps[i].x >> ps[i].y;

        int ans = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
				if (i == j) continue;
                P a = ps[i], b = ps[j];
                P m = (a + b) / 2;
                bool midFound = false;
                for (int k = 0; k < n; k++) {
					if ((ps[k] - m).dist() >= 1e-6) continue;
                    midFound = true;
					break;
                }
                if (!midFound) continue;
				P newP = m + (b - a).perp();
                for (int k = 0; k < n; k++) {
					if ((ps[k] - newP).dist() >= 1e-6) continue;
					ans++;
					break;
                }
            }
        
        printf("Set #%d: %d\n", cs, ans);
    }
}