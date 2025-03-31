#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    bool operator < (const Point& p) const {
        if (fabs(x - p.x) < EPS) return y < p.y;
        return x < p.x;
    }
    
    bool operator == (const Point& p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }
};

struct Line {
    Point p1, p2;
    double length;
    Line(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {
        length = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

// Vector operations
double cross(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

Point subtract(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

// Check if point p lies on line segment l
bool onSegment(const Point& p, const Line& l) {
    if (p == l.p1 || p == l.p2) return true;
    
    Point v1 = subtract(l.p2, l.p1);
    Point v2 = subtract(p, l.p1);
    
    if (fabs(cross(v1, v2)) > EPS) return false;
    
    double dot = v1.x * v2.x + v1.y * v2.y;
    return dot >= -EPS && dot <= v1.x * v1.x + v1.y * v1.y + EPS;
}

// Find intersection point of two lines
bool findIntersection(const Line& l1, const Line& l2, Point& intersection) {
    Point r = Point(l1.p2.x - l1.p1.x, l1.p2.y - l1.p1.y);
    Point s = Point(l2.p2.x - l2.p1.x, l2.p2.y - l2.p1.y);
    
    double rxs = cross(r, s);
    Point q_p = subtract(l2.p1, l1.p1);
    
    if (fabs(rxs) < EPS) return false;
    
    double t = cross(q_p, s) / rxs;
    double u = cross(q_p, r) / rxs;
    
    if (t < -EPS || t > 1 + EPS || u < -EPS || u > 1 + EPS) 
        return false;
        
    intersection.x = l1.p1.x + t * r.x;
    intersection.y = l1.p1.y + t * r.y;
    return true;
}

// Find all intersection points
vector<Point> findAllIntersections(const vector<Line>& lines) {
    set<pair<double, double>> intersectionSet;
    vector<Point> intersections;
    
    for (const Line& line : lines) {
        intersectionSet.insert({line.p1.x, line.p1.y});
        intersectionSet.insert({line.p2.x, line.p2.y});
    }
    
    for (size_t i = 0; i < lines.size(); i++) {
        for (size_t j = i + 1; j < lines.size(); j++) {
            Point intersection;
            if (findIntersection(lines[i], lines[j], intersection)) {
                intersectionSet.insert({intersection.x, intersection.y});
            }
        }
    }
    
    for (const auto& p : intersectionSet) {
        intersections.push_back(Point(p.first, p.second));
    }
    return intersections;
}

// Build adjacency list for graph
vector<vector<int>> buildGraph(const vector<Point>& points, const vector<Line>& lines) {
    int n = points.size();
    vector<vector<int>> graph(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (const Line& line : lines) {
                if (onSegment(points[i], line) && onSegment(points[j], line)) {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                    break;
                }
            }
        }
    }
    return graph;
}

// Find cycles in graph using DFS
void findCycles(int v, int parent, int start, vector<bool>& visited, 
                vector<int>& path, const vector<vector<int>>& graph,
                vector<vector<int>>& cycles) {
    visited[v] = true;
    path.push_back(v);
    
    for (int u : graph[v]) {
        if (!visited[u]) {
            findCycles(u, v, start, visited, path, graph, cycles);
        }
        else if (u == start && u != parent && path.size() >= 3) {
            cycles.push_back(path);
        }
    }
    
    path.pop_back();
    visited[v] = false;
}

// Calculate area of polygon
double calculateArea(const vector<Point>& points, const vector<int>& cycle) {
    double area = 0;
    for (size_t i = 0; i < cycle.size(); i++) {
        int j = (i + 1) % cycle.size();
        const Point& p1 = points[cycle[i]];
        const Point& p2 = points[cycle[j]];
        area += (p1.x * p2.y - p2.x * p1.y);
    }
    return fabs(area) / 2;
}

// Check if leftover pieces can form same figure
bool canFormSameFigure(const vector<Line>& lines, const vector<bool>& used, double targetArea) {
    double totalLength = 0;
    for (size_t i = 0; i < lines.size(); i++) {
        if (!used[i]) totalLength += lines[i].length;
    }
    
    double minPerimeter = sqrt(targetArea * 16);
    return totalLength >= minPerimeter;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<Line> lines(n);
    for (int i = 0; i < n; i++) {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        lines[i] = Line(Point(x1, y1), Point(x2, y2));
    }
    
    vector<Point> points = findAllIntersections(lines);
    if (points.size() < 3) {
        cout << "No\n";
        return 0;
    }
    
    vector<vector<int>> graph = buildGraph(points, lines);
    vector<vector<int>> cycles;
    vector<bool> visited(points.size());
    vector<int> path;
    
    for (size_t i = 0; i < points.size(); i++) {
        findCycles(i, -1, i, visited, path, graph, cycles);
    }
    
    double maxArea = 0;
    vector<int> bestCycle;
    vector<bool> used(n, false);
    
    for (const auto& cycle : cycles) {
        double area = calculateArea(points, cycle);
        if (area > maxArea) {
            maxArea = area;
            bestCycle = cycle;
        }
    }
    
    if (maxArea < EPS) {
        cout << "No\n";
        return 0;
    }
    
    // Mark used lines
    for (size_t i = 0; i < bestCycle.size(); i++) {
        int j = (i + 1) % bestCycle.size();
        const Point& p1 = points[bestCycle[i]];
        const Point& p2 = points[bestCycle[j]];
        
        for (size_t k = 0; k < lines.size(); k++) {
            if (onSegment(p1, lines[k]) && onSegment(p2, lines[k])) {
                used[k] = true;
            }
        }
    }
    
    cout << "Yes\n";
    cout << (canFormSameFigure(lines, used, maxArea) ? "Yes\n" : "No\n");
    cout << fixed << setprecision(2) << maxArea << "\n";
    
    return 0;
}