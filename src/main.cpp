#include "BezierCurve.h"

#include <print>
int main() {
    constexpr int w_ratio = 16;
    constexpr int h_ratio = 9;
    constexpr int p_factor = 80;

    constexpr int frame_count = 60;

    constexpr Point b1{ 50.0f, 80.0f };
    constexpr Point b2{ 500.0f, 546.0f };
    constexpr Point b3{ 800.0f, 250.0f };

    constexpr Point e1{ 60.0f, 120.0f };
    constexpr Point e2{ 450.0f, 300.0f };
    constexpr Point e3{ 900.0f, 220.0f };

    ColorDefinition color_def;
    color_def.background = { 80, 80, 80 };
    color_def.ctrl_point = { 255, 100, 100 };
    color_def.curve = { 100, 255, 100 };

    CurveDefinition curve_def;
    curve_def.picture_width = w_ratio * p_factor;
    curve_def.picture_height = h_ratio * p_factor;
    curve_def.scan_count = 300;
    curve_def.radius = 10;

    for (int t = 0; t < frame_count; ++t)
    {
        std::println("Generating frame {}...\n", t + 1);
        DrawToPPM(std::format("bezier-{:0>2}.ppm", t + 1),
            LerpPoint(b1, e1, 1.0f / frame_count * (t + 1)),
            LerpPoint(b2, e2, 1.0f / frame_count * (t + 1)),
            LerpPoint(b3, e3, 1.0f / frame_count * (t + 1)),
            color_def, curve_def
        );
    }

    std::println("Finished.");
}