#ifndef PP_PICFORMAT_H_
#define PP_PICFORMAT_H_

#include <cstdio>
#include <vector>

struct Color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};

struct ColorDefinition
{
    Color background;
    Color curve;
    Color ctrl_point;
};

class PPMFile
{
public:
    PPMFile(const char* path, int width, int height);
    ~PPMFile();

    void WritePixel(const Color& color);

    inline bool IsValid() const
    {
        return m_FileStream != nullptr;
    }

    inline int GetWidth() const
    {
        return m_Width;
    }
    inline int GetHeight() const
    {
        return m_Height;
    }
    inline int GetCurrentX() const
    {
        return m_CurrentX;
    }

    inline int GetCurrentY() const
    {
        return m_CurrentY;
    }

    inline int GetCurrentPos() const
    {
        return GetCurrentY() * m_Width + GetCurrentX();
    }

private:
    const char* m_Path;
    std::FILE* m_FileStream;
    static inline std::vector<Color> s_Buffer;

    int m_Width;
    int m_Height;

    int m_CurrentX;
    int m_CurrentY;
};

#endif // PP_PICFORMAT_H_