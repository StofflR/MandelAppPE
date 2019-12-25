#pragma once
#include "Sprite.h"
#include <cstdint>
#include <complex>

class MandelCreator
{
private:
    Sprite *_drawTarget;
    int32_t _size_x;
    int32_t _size_y;
    float _scale;
    std::complex<float> _center;
    std::complex<float> _exponent;
    int32_t _maxItt;

public:
    MandelCreator() = default;
    MandelCreator(Sprite *drawTarget, int32_t size_x, int32_t size_y, float scale = 2, std::complex<float> center = std::complex<float>(0,0), std::complex<float> exponent=std::complex<float>(2,0), int32_t maxItt = 512);
    ~MandelCreator();
    void DrawMandelBrot();
    void DrawJulia(int32_t x, int32_t y);
    void DrawJuliaRGB(int32_t x, int32_t y);
    float mapNumber(int l_min, int l_max, int x, int r_min, int r_max);
};
