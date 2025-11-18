#include "BezierPoint.h"

CurvePointStorage CalculateCurve3P(const Point& p1, const Point& p2, const Point& p3, CurveDefinition def)
{
    int &X = def.picture_width, &Y = def.picture_height, &scanCount = def.scan_count, &radius = def.radius;
    
    CurvePointStorage ret;
    ret.width = X;
    ret.storage.resize(X * Y, false);

    std::vector<std::pair<int, int>> circle_points;

    for (int j = -radius; j <= radius; ++j)
    {
        for (int i = -radius; i <= radius; ++i)
        {
            if (WithinRadius(Point{0.0f, 0.0f}, i, j, radius))
            {
                circle_points.emplace_back(i, j);
            }
        }
    }

    for (int i = 0; i < scanCount; ++i)
    {
        float factor = 1.0f / scanCount * i;
        
        Point lp1 = LerpPoint(p1, p2, factor);
        Point lp2 = LerpPoint(p2, p3, factor);
        Point p = LerpPoint(lp1, lp2, factor);
        
        int cx = static_cast<int>(p.x);
        int cy = static_cast<int>(p.y);

        for (auto& [dx, dy] : circle_points)
        {
            int wx = cx + dx;
            int wy = cy + dy;
            if (wx >= 0 && wx < X && wy >= 0 && wy < Y)
            {
                ret.storage[wy * X + wx] = true;
            }
        }

    }

    return ret;
}