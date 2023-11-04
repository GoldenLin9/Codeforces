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

vector<pair<P, P>> roads;

struct intersection {
    P p;
    int i, j;
    double t1, t2;
    double time;
    intersection(P p, int i, int j) {
        this->p = p;
        this->i = i;
        this->j = j;
        t1 = (p - roads[i].first).dist2();
        t2 = (p - roads[j].first).dist2();
        time = max(t1, t2);
    }
    bool operator<(intersection other) {
        return time < other.time;
    }
};

const double PI = 3.1415926535898;

int main() {
    int n;
    cin >> n;

    while (n) {
        roads = vector<pair<P, P>>(n);

        for (int i = 0; i < n; i++)
            cin >> roads[i].first.x;
        
        for (int i = 0; i < n; i++) {
            double deg;
            cin >> deg;
            double rad = deg * PI / 180;
            roads[i].second = P(roads[i].first.x + cos(rad), sin(rad));
        }
        
        vector<intersection> intersections;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                pair<int, P> res = lineInter(roads[i].first, roads[i].second, roads[j].first, roads[j].second);
                if (res.first == 0) continue;
                if (res.second.y <= 0) continue;
                intersections.emplace_back(res.second, i, j);
            }
        
        sort(intersections.begin(), intersections.end());

        int numCross = n;
        vector<bool> canCross(n, true);

        for (int i = 0; i < intersections.size(); i++) {
            intersection inter = intersections[i];
            if (!canCross[inter.i] || !canCross[inter.j]) continue;
            if (inter.t1 <= inter.t2) canCross[inter.j] = false;
            else canCross[inter.i] = false;
            numCross--;
        }
        
        cout << numCross << endl;
        for (int i = 0; i < n; i++)
            if (canCross[i]) cout << i << " ";
        cout << endl;

        cin >> n;
    }
}