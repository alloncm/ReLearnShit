#pragma once
#include<vector>
#include"Mat3.h"
#include"Graphics.h"

class Drawable
{
public:
	Drawable(std::vector<Vec2> model, Color c)
		:
		_model(std::move(model)),
		_mat(Mat3_<float>::Identity()),
		_color(c)
	{}
	
	void ApplyTransforamtion(const Mat3_<float>& mat)
	{
		_mat = _mat*mat;
	}

	void Render(Graphics& gfx)
	{
		auto poly = _model;
		for (auto& v : poly)
		{
			v = _mat*v;
		}

		gfx.DrawClosePolyline(poly, _color);
	}
private:
	Color _color;
	Mat3_<float> _mat;
	std::vector<Vec2> _model;
};