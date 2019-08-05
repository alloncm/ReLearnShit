#pragma once
#include"Drawable.h"
#include"Mat3.h"

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
		drawable.ApplyTransforamtion(
			Mat3::Translation(offset)*
			Mat3::ScaleIndependent(1.0f, -1.0f));
		drawable.Render(gfx);
	}

private:
	Graphics& gfx;
};