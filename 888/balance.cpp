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


double length(Point<double> p1, Point<double> p2) {
    return sqrt(pow(p1.x - p2.x, 2) - pow(p2.y - p1.x, 2));
}

void solve() {
    Point<double> p1, p2, p3;
    cin >> p1.x >> p2.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << p1 << p2 << p3 << '\n';

    Point<double> m1, m2;
    Point<double> peak;
    if (length(p1, p2) > length(p2, p3)) {
        if (length(p1, p2) > length(p1, p3)) {
            m1.x = p1.x;
            m1.y = p1.y;
            m2.x = p2.x;
            m2.y = p2.y;
            peak.x = p3.x;
            peak.y = p3.y;
        } else {
            m1.x = p1.x;
            m1.y = p1.y;
            m2.x = p3.x;
            m2.y = p3.y;
            peak.x = p2.x;
            peak.y = p2.y;
        }
    } else {
        if (length(p2, p3) > length(p1, p3)) {
            m1.x = p2.x;
            m1.y = p2.y;
            m2.x = p3.x;
            m2.y = p3.y;
            peak.x = p1.x;
            peak.y = p1.y;
        } else {
            m1.x = p1.x;
            m1.y = p1.y;
            m2.x = p3.x;
            m2.y = p3.y;
            peak.x = p2.x;
            peak.y = p2.y;
        }
    }

    


}


int main() {
    int t; cin >> t;
    while (t--) solve();
}