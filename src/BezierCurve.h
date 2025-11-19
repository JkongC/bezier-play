#ifndef PP_BEZIERCURVE_H_
#define PP_BEZIERCURVE_H_

#include "BezierPoint.h"
#include "picformat/ppm.h"

void DrawToPPM(const char* file_name, Point p1, Point p2, Point p3, const ColorDefinition& color_def, const CurveDefinition& curve_def);

#endif