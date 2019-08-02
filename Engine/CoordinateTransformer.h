#pragma once
#include"Drawable.h"

class CoordinateTransformer
{
public:
	CoordinateTransformer(Graphics& gragics)
		:
		gfx(gragics)
	{}

	void Draw(Drawable& drawable) const
	{
		const Vec2_<float> offset(Graphics::ScreenWidth / 2, Graphics::ScreenHeight / 2);
		drawable.ScaleY(-1.0f);
		drawable.Traslate(offset);
		drawable.Render(gfx);
	}

private:
	Graphics& gfx;
};