#ifndef PP_BEZIERPOINT_H_
#define PP_BEZIERPOINT_H_

#include <vector>

struct Point
{
    float x;
    float y;
};
inline bool WithinRadius(const Point& p, int x, int y, int radius = 10)
{
    double px = p.x;
    double py = p.y;
    double ix = x;
    double iy = y;
    double r = radius;
    return ((ix - px) * (ix - px) + (iy - py) * (iy - py)) < (r * r);
}

struct CurvePointStorage
{
    std::vector<bool> storage;
    int width;

    bool operator[](std::size_t i, std::size_t j) const
    {
        return storage[j * width + i];
    }
};

constexpr Point LerpPoint(const Point& p1, const Point& p2, float factor)
{
    return Point{ p1.x + (p2.x - p1.x) * factor, p1.y + (p2.y - p1.y) * factor };
}

struct CurveDefinition
{
    int picture_width;
    int picture_height;
    int scan_count;
    int radius;
};

CurvePointStorage CalculateCurve3P(const Point& p1, const Point& p2, const Point& p3, CurveDefinition def);

#endif // PP_BEZIERPOINT_H_