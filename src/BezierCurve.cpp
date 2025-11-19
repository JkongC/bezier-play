#include "BezierCurve.h"

void DrawToPPM(const char* file_name, Point p1, Point p2, Point p3, const ColorDefinition& color_def, const CurveDefinition& curve_def)
{
    auto curve = CalculateCurve3P(p1, p2, p3, curve_def);

    PPMFile f{file_name, curve_def.picture_width, curve_def.picture_height};
    for (int j = 0; j < f.GetHeight(); ++j)
    {
        for (int i = 0; i < f.GetWidth(); ++i)
        {
            if (WithinRadius(p1, i, j) || WithinRadius(p2, i, j) || WithinRadius(p3, i, j))
            {
                f.WritePixel(color_def.ctrl_point);
            }
            else if (curve[i, j])
            {
                f.WritePixel(color_def.curve);
            }
            else
            {
                f.WritePixel(color_def.background);
            }
        }
    }
}