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

int sideOf(P s, P e, P p) { return sgn(s.cross(e, p)); }

double polygonArea2(vector<P>& v) {
	double a = v.back().cross(v[0]);
	for (int i = 0; i < v.size() - 1; i++) a += v[i].cross(v[i+1]);
	return a;
}

P lineProj(P a, P b, P p, bool refl=false) {
	P v = b - a;
	return p - v.perp()*(1+refl)*v.cross(p-a)/v.dist2();
}

int main() {
    int t;
    cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        P a, b, c;
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

        set<P> ps = {a, b, c};

        pair<double, pair<P, P>> l1 = {(b - a).dist2(), {a, b}};
        pair<double, pair<P, P>> l2 = {(c - b).dist2(), {b, c}};
        pair<double, pair<P, P>> l3 = {(a - c).dist2(), {a, c}};
        
        pair<double, pair<P, P>> longest = max(l1, max(l2, l3));
        pair<P, P> longestLine = longest.second;

        ps.erase(longestLine.first);
        ps.erase(longestLine.second);

        P opp = *ps.begin();

        P l = longestLine.first, r = longestLine.second, m;

        for (int i = 0; i < 300; i++) {
            m = (l + r) / 2;
            vector<P> a1 = {longestLine.first, m}, a2 = {m, longestLine.second};

            P auxS = (opp - (m + m.perp())).dist2() < (opp - (m - m.perp())).dist2() ? m + m.perp() : m - m.perp();
            pair<P, P> aux = {m, auxS};
        
            P inter;

            if (sideOf(aux.first, aux.second, opp) == 1) {
                inter = lineInter(aux.first, aux.second, longestLine.second, opp).second;
                a1.push_back(inter);
                a1.push_back(opp);
                a2.push_back(inter);
            } else {
                inter = lineInter(aux.first, aux.second, longestLine.first, opp).second;
                a1.push_back(inter);
                a2.push_back(opp);
                a2.push_back(inter);
            }

            double area1 = polygonArea2(a1);
            double area2 = polygonArea2(a2);

            if (area1 < area2) l = m;
            else r = m;
        }

        printf("Triangle #%d Balance Point: (%.2lf,%.2lf)\n", cs, m.x, m.y);
    }
}