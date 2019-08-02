#pragma once
#include<vector>
#include"Vec2.h"
#include"Graphics.h"

class Drawable
{
public:
	Drawable(std::vector<Vec2> model, Color c)
		:
		_model(std::move(model)),
		_scaleX(1.0f),
		_scaleY(1.0f),
		_translation({0.0f,0.0f}),
		_color(c)
	{}
	void Traslate(const Vec2& translation)
	{
		_translation += translation;
	}

	void Scale(float scale)
	{
		_scaleX *= scale;
		_scaleY *= scale;
		_translation *= scale;
	}

	void ScaleX(float x)
	{
		_scaleX *= x;
		_translation.x *= x;
	}

	void ScaleY(float y)
	{
		_scaleY *= y;
		_translation.y *= y;
	}

	void Render(Graphics& gfx)
	{
		auto poly = _model;
		for (auto& v : poly)
		{
			v.x *= _scaleX;
			v.y *= _scaleY;
			v += _translation;
		}

		gfx.DrawClosePolyline(poly, _color);
	}
private:
	Color _color;
	Vec2 _translation;
	float _scaleX;
	float _scaleY;
	std::vector<Vec2> _model;
};