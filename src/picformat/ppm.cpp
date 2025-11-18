#include <format>

#include "ppm.h"
PPMFile::PPMFile(std::filesystem::path path, int width, int height)
    : m_Path(path), m_FileStream(m_Path, std::ios::out | std::ios::trunc)
    , m_Width(width), m_Height(height)
{
    m_FileStream << "P6\n" << std::format("{} {}\n", m_Width, m_Height) << "255\n";
    m_FileStream = std::fstream(m_Path, std::ios::app | std::ios::out | std::ios::binary);
}
void PPMFile::WritePixel(const Color& color)
{
    m_FileStream << color.r << color.g << color.b;
}
