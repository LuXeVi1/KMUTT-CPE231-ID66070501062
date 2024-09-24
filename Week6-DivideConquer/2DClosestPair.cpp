#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

float distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) +
                (p1.y - p2.y) * (p1.y - p2.y));
}

float bruteForce(Point P[], int n) {
    float minDist = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (distance(P[i], P[j]) < minDist)
                minDist = distance(P[i], P[j]);
    return minDist;
}

float stripClosest(Point strip[], int size, float d) {
    float minDist = d;

    for (int i = 0; i < size; ++i)
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j)
            if (distance(strip[i], strip[j]) < minDist)
                minDist = distance(strip[i], strip[j]);

    return minDist;
}

float closestUtil(Point P[], int n) {
    if (n <= 3)
        return bruteForce(P, n);

    int mid = n / 2;
    Point midPoint = P[mid];

    float dl = closestUtil(P, mid);
    float dr = closestUtil(P + mid, n - mid);

    float d = min(dl, dr);

    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(P[i].x - midPoint.x) < d)
            strip[j] = P[i], j++;

    return min(d, stripClosest(strip, j, d));
}

float closest(Point P[], int n) {
    sort(P, P + n, [](Point a, Point b) {
        return a.x < b.x;
    });

    return closestUtil(P, n);
}

int main() {
    int n;
    cin >> n;

    Point P[n];
    for (int i = 0; i < n; i++) {
        cin >> P[i].x >> P[i].y;
    }

    cout << fixed << setprecision(3) << closest(P, n) << endl;

    return 0;
}
