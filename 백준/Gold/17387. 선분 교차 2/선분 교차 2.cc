#include <iostream>

using namespace std;

struct Point {
    long long x;
    long long y;
};

Point p1, p2, p3, p4;

int ccw(Point a, Point b, Point c)
{
    long long cal = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (cal < 0)
        return -1;
    else if (cal > 0)
        return 1;
    else
        return 0;
}

bool isLine(int a, int b, int c, int d)
{
    if (a > b)
    {
        swap(a, b);
    }
    if (c > d)
    {
        swap(c, d);
    }
    return (a <= d && b >= c);
}

bool isCross()
{
    int a1 = ccw(p1, p2, p3);
    int a2 = ccw(p1, p2, p4);
    int a3 = ccw(p3, p4, p1);
    int a4 = ccw(p3, p4, p2);

    if (a1 * a2 == 0 && a3 * a4 == 0)
    {
        return isLine(p1.x, p2.x, p3.x, p4.x) && isLine(p1.y, p2.y, p3.y, p4.y);
    }

    return a1 * a2 <= 0 && a3 * a4 <= 0;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;

    cout << isCross();

	return 0;
}