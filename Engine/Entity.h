#pragma once
#include<vector>
#include"Vec2.h"
#include"Drawable.h"

class Entity
{
public:
	Entity(std::vector<Vec2> model, Color c,Vec2 pos = { 0.0f,0.0f })
		:
		_model(std::move(model)),
		_position(pos),
		_scale(1.0f),
		_color(c)
	{}
	const Vec2& GetPos()const
	{
		return _position;
	}

	void SetPos(const Vec2& newPos)
	{
		_position = newPos;
	}

	void TranslateBy(const Vec2& offset)
	{
		_position += offset;
	}

	float GetScale()
	{
		return _scale;
	}

	void SetScale(float scale)
	{
		_scale = scale;
	}

	Drawable GetDrawable()const
	{
		Drawable d(_model, _color);
		d.Scale(_scale);
		d.Traslate(_position);
		return d;
	}

private:
	Color _color;
	float _scale;
	Vec2 _position;
	std::vector<Vec2> _model;
};