
//to check if two given line segments intersect
#include <iostream>
using namespace std;

struct Point
{
	int x;
	int y;
};

bool onSegment(Point p, Point q, Point r)
{
	if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
		q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
	return true;

	return false;
}


int direction(Point p, Point q, Point r)
{

	// for details of below formula.
	int val = ((q.y - p.y) * (r.x - q.x) )-
			((q.x - p.x) * (r.y - q.y));

            return val;

	
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
	// Find the four orientations needed for general and
	// special cases
	int d1 = direction(p1, q1, p2);
	int d2 = direction(p1, q1, q2);
	int d3 = direction(p2, q2, p1);
	int d4 = direction(p2, q2, q1);

	// General case
	if (((d1 >0 && d2<0) || (d1 <0 && d2>0)) && ((d3 >0 && d4<0) || (d3 <0 && d4>0) ))
		return true;

	// Special Cases
	// p1, q1 and p2 are collinear and p2 lies on segment p1q1
	if (d1 == 0 && onSegment(p1, p2, q1)) return true;

	// p1, q1 and q2 are collinear and q2 lies on segment p1q1
	if (d2 == 0 && onSegment(p1, q2, q1)) return true;

	// p2, q2 and p1 are collinear and p1 lies on segment p2q2
	if (d3 == 0 && onSegment(p2, p1, q2)) return true;

	// p2, q2 and q1 are collinear and q1 lies on segment p2q2
	if (d4 == 0 && onSegment(p2, q1, q2)) return true;

	return false; // Doesn't fall in any of the above cases
}

int main()
{
	struct Point p1 = {1, 1}, q1 = {10, 1};
	struct Point p2 = {1, 2}, q2 = {10, 2};

	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {10, 0}, q1 = {0, 10};
	p2 = {0, 0}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	p1 = {-5, -5}, q1 = {0, 0};
	p2 = {1, 1}, q2 = {10, 10};
	doIntersect(p1, q1, p2, q2)? cout << "Yes\n": cout << "No\n";

	return 0;
}
