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

P c;

pair<double, double> aAndP(P p1, P p2) {
    double area = fabs((p1 - c).cross(p2 - c)) / 2;
    double perimeter = (p1 - c).dist() + (p2 - c).dist() + (p2 - p1).dist();
    return {area, perimeter};
}

int main() {
    P p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    while (p1.x || p1.y || p2.x || p2.y || p3.x || p3.y || p4.x || p4.y) {
        
        pair<P, P> comb1, comb2;
        comb1.first = p1;

        vector<vector<P>> ps = {{p2, p3, p4}, {p2, p4, p3}, {p3, p2, p4}};

        for (int i = 0; i < ps.size(); i++) {
            if (sideOf(p1, ps[i][1], ps[i][0]) != sideOf(p1, ps[i][1], ps[i][2])) {
                comb1.second = ps[i][1];
                comb2.first = ps[i][0];
                comb2.second = ps[i][2];
            }
        }

        c = lineInter(comb1.first, comb1.second, comb2.first, comb2.second).second;

        vector<pair<double, double>> areaAndPerimeter;

        areaAndPerimeter.emplace_back(aAndP(comb1.first, comb2.first));
        areaAndPerimeter.emplace_back(aAndP(comb1.first, comb2.second));
        areaAndPerimeter.emplace_back(aAndP(comb1.second, comb2.first));
        areaAndPerimeter.emplace_back(aAndP(comb1.second, comb2.second));
        
        sort(areaAndPerimeter.rbegin(), areaAndPerimeter.rend());

        for (pair<double, double> q : areaAndPerimeter)
            printf("%.3lf %.3lf ", q.first, q.second);
        cout << endl;

        cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
    }
}