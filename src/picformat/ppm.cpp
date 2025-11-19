#include <format>
#include <print>

#include "ppm.h"
PPMFile::PPMFile(const char *path, int width, int height)
    : m_Path(path), m_FileStream(std::fopen(path, "w")), m_Width(width), m_Height(height)
{
    std::print(m_FileStream, "P6\n");
    std::print(m_FileStream, "{} {}\n", m_Width, m_Height);
    std::print(m_FileStream, "255\n");

    std::freopen(m_Path, "ab", m_FileStream);

    s_Buffer.reserve(m_Width * m_Height);
}

PPMFile::~PPMFile()
{
    std::fwrite(s_Buffer.data(), sizeof(unsigned char), s_Buffer.size() * 3, m_FileStream);
    std::fclose(m_FileStream);
    s_Buffer.clear();
}

void PPMFile::WritePixel(const Color &color)
{
    s_Buffer.push_back(color);
}
