#include "MandelCreator.h"
#include <cmath>
#include <iostream>

MandelCreator::MandelCreator(Sprite *drawTarget, int32_t size_x, int32_t size_y, float scale, std::complex<float> center, std::complex<float> exponent, int32_t maxItt) :
_drawTarget(drawTarget), _size_x(size_x), _size_y(size_y), _scale(scale), _center(center), _exponent(exponent), _maxItt(maxItt)
{

}


MandelCreator::MandelCreator::~MandelCreator()
{
}

void MandelCreator::DrawMandelBrot()
{
    for (int32_t ind_i = 0; ind_i < _size_x; ind_i++)
    {
        for (int32_t ind_j = 0; ind_j <= (int32_t)_size_y/2; ind_j++)
        {
            std::complex<float> z(0,0);
            float re = mapNumber(0,_size_x,ind_i, -_scale, _scale);
            float im = mapNumber(0,_size_y,ind_j, -_scale, _scale);
            std::complex<float> c(re,im);
            float itt = 0;

            while (abs(z) < 2 && itt < _maxItt)
            {
                z = std::pow(z, 2) + c;
                itt++;
            }
            itt = itt/_maxItt*255;
            _drawTarget->SetPixel(ind_i, ind_j, Pixel((int)itt,(int)itt,(int)itt));
            _drawTarget->SetPixel(ind_i, _size_y-ind_j, Pixel((int)itt,(int)itt,(int)itt));
        }
    }
}


void MandelCreator::DrawJuliaRGB(int32_t x, int32_t y)
{
    float re = mapNumber(0,_size_x,x, -_scale, _scale);
    float im = mapNumber(0,_size_y,y, -_scale, _scale);
    std::complex<float> c(re,im);

    for (int32_t ind_i = 0; ind_i < _size_x; ind_i++)
    {
        for (int32_t ind_j = 0; ind_j <= (int32_t)_size_y/2; ind_j++)
        {
            re = mapNumber(0,_size_x,ind_i, -_scale, _scale);
            im = mapNumber(0,_size_y,ind_j, -_scale, _scale);
            
            std::complex<float> z(re, im);
            float itt_red = 0;
            float itt_green = 0;
            float itt_blue = 0;

            while (abs(z) < 2 && itt_blue < _maxItt)
            {
                z = std::pow(z, 2) + c;
                if (itt_blue < (int)_maxItt/2)
                    itt_red++;
                if (itt_blue < (int)_maxItt/4)
                    itt_green++;
                itt_blue++;

            }
            itt_blue = itt_blue/_maxItt*255;
            itt_red = (itt_red/(_maxItt/2))*255;
            itt_green = (itt_green/(_maxItt/4))*255;
            _drawTarget->SetPixel(ind_i, ind_j, Pixel((uint32_t)itt_red,(uint32_t)itt_green,(uint32_t)itt_blue));
            _drawTarget->SetPixel(_size_x-ind_i, _size_y-ind_j, Pixel((uint32_t)itt_red,(uint32_t)itt_green,(uint32_t)itt_blue));
        }
        
    }
}


void MandelCreator::DrawJulia(int32_t x, int32_t y)
{
    float re = mapNumber(0,_size_x,x, -_scale, _scale);
    float im = mapNumber(0,_size_y,y, -_scale, _scale);
    std::complex<float> c(re,im);

    for (int32_t ind_i = 0; ind_i < _size_x; ind_i++)
    {
        for (int32_t ind_j = 0; ind_j <= (int32_t)_size_y/2; ind_j++)
        {
            re = mapNumber(0,_size_x,ind_i, -_scale, _scale);
            im = mapNumber(0,_size_y,ind_j, -_scale, _scale);
            
            std::complex<float> z(re, im);
            float itt = 0;

            while (abs(z) < 2 && itt < _maxItt)
            {
                z = std::pow(z, 2) + c;
                itt++;
            }
            itt = itt/_maxItt*255;
            _drawTarget->SetPixel(ind_i, ind_j, Pixel((int)itt,(int)itt,(int)itt));
            _drawTarget->SetPixel(_size_x-ind_i, _size_y-ind_j, Pixel((int)itt,(int)itt,(int)itt));
        }
        
    }
}

float MandelCreator::mapNumber(int l_min, int l_max, int x, int r_min, int r_max)
{
    return (float)(x-l_min)/(l_max-l_min)*(r_max-r_min) + r_min;
}