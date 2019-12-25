// #define OLC_PGE_APPLICATION
#include "PixelEngine.h"
#include "MandelCreator.h"
#include <random>
// Override base class with your custom functionality
class Example : public PixelEngine
{
public:
	Example()
	{
		AppName = "Mandelapp";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}
	bool OnUserUpdate(float fElapsedTime) override
	{
		// called once per frame, draws random coloured pixels
		MandelCreator mandel(GetDrawTarget(),700,700);
		std::pair<int32_t, int32_t> mousepos = GetMousePos();
		mandel.DrawJuliaRGB(mousepos.first, mousepos.second);
		return true;
	}
};
int main()
{
    Example demo;
	if (demo.Build(700, 700, 1, 1))
		demo.Start();
	return 0;
}