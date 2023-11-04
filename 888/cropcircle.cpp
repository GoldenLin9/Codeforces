#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

// DOES NOT ACCOUNT FOR STRAIGHT LINE POINTS
typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
	return (B-A).dist()*(C-B).dist()*(A-C).dist()/
			abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
	P b = C-A, c = B-A;
	return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

const double PI = 3.1415926535898;

int main() {
    int n;
    cin >> n;

    int i = 0;
    while (n) {
        i++;
        vector<P> ps(n);

        for (int i = 0; i < n; i++) cin >> ps[i].x;
        for (int i = 0; i < n; i++) cin >> ps[i].y;

		vector<pair<P, double>> cs;
        
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++) {
                    if (fabs((ps[j] - ps[i]).cross(ps[k] - ps[i])) < 1e-5) continue;
                    double r = ccRadius(ps[i], ps[j], ps[k]);
                    P c = ccCenter(ps[i], ps[j], ps[k]);

					bool contained = false;
					for (int i = 0; i < cs.size(); i++)
						if ((c - cs[i].first).dist() < 1e-5 && fabs(r - cs[i].second) < 1e-5) {
							contained = true;
							break;
						}
					if (contained) continue;
					cs.emplace_back(c, r);
                }

        printf("Circles for boulder set #%d: %d\n", i, cs.size());

        cin >> n;
    }
}