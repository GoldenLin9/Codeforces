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
bool circleInter(P a,P b,double r1,double r2,pair<P, P>* out) {
	if (a == b) { assert(r1 != r2); return false; }
	P vec = b - a;
	double d2 = vec.dist2(), sum = r1+r2, dif = r1-r2,
	       p = (d2 + r1*r1 - r2*r2)/(d2*2), h2 = r1*r1 - p*p*d2;
	if (sum*sum < d2 || dif*dif > d2) return false;
	P mid = a + vec*p, per = vec.perp() * sqrt(fmax(0, h2) / d2);
	*out = {mid + per, mid - per};
	return true;
}

const double PI = 3.1415926535898;

int main() {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        int n;
        cin >> n;

        vector<P> ps(n);
        vector<double> r(n), a(n);

        double sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> ps[i].x >> ps[i].y >> r[i];
            a[i] = PI * r[i] * r[i];
            sum += a[i];
        }

        for (int i = 0; i < n - 1; i++) {
            pair<P, P> out;

            if (circleInter(ps[i], ps[i + 1], r[i], r[i + 1], &out)) {
                P u1 = out.first - ps[i], v1 = out.second - ps[i];
                double trapezoidArea = fabs(u1.cross(v1));

                double arc1Angle = acos(u1.dot(v1) / (u1.dist() * v1.dist()));
                double arc1Area = a[i] * arc1Angle / (2 * PI);

                P u2 = out.first - ps[i + 1], v2 = out.second - ps[i + 1];
                double arc2Angle = acos(u2.dot(v2) / (u2.dist() * v2.dist()));
                double arc2Area = a[i + 1] * arc2Angle / (2 * PI);

                double intersectionArea = -trapezoidArea + arc1Area + arc2Area;
                sum -= intersectionArea;
            }
        }

        printf("Set #%d: %.2lf\n", cs, sum);
    }
}