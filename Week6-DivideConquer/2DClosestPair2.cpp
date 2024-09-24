#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>

struct Point {
    int x, y;
};

class ClosestPairFinder {
private:
    static constexpr double INF = std::numeric_limits<double>::infinity();

    static double distance(const Point& p1, const Point& p2) {
        return std::hypot(p1.x - p2.x, p1.y - p2.y);
    }

    static double bruteForce(const std::vector<Point>& points, int start, int end) {
        double minDist = INF;
        for (int i = start; i < end; ++i)
            for (int j = i + 1; j < end; ++j)
                minDist = std::min(minDist, distance(points[i], points[j]));
        return minDist;
    }

    static double stripClosest(std::vector<Point>& strip, double d) {
        std::sort(strip.begin(), strip.end(), [](const Point& a, const Point& b) {
            return a.y < b.y;
        });

        for (size_t i = 0; i < strip.size(); ++i)
            for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; ++j)
                d = std::min(d, distance(strip[i], strip[j]));

        return d;
    }

    static double closestUtil(std::vector<Point>& points, int start, int end) {
        if (end - start <= 3)
            return bruteForce(points, start, end);

        int mid = (start + end) / 2;
        Point midPoint = points[mid];

        double dl = closestUtil(points, start, mid);
        double dr = closestUtil(points, mid, end);
        double d = std::min(dl, dr);

        std::vector<Point> strip;
        for (int i = start; i < end; i++)
            if (std::abs(points[i].x - midPoint.x) < d)
                strip.push_back(points[i]);

        return std::min(d, stripClosest(strip, d));
    }

public:
    static double findClosestPair(std::vector<Point>& points) {
        std::sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
            return a.x < b.x;
        });

        return closestUtil(points, 0, points.size());
    }
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Point> points(n);
    for (auto& point : points) {
        std::cin >> point.x >> point.y;
    }

    std::cout << std::fixed << std::setprecision(3)
              << ClosestPairFinder::findClosestPair(points) << std::endl;

    return 0;
}