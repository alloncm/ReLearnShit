#pragma once
#include<vector>
#include"Vec2.h"
#include"Drawable.h"
#include"Mat3.h"

class Entity
{
public:
	Entity(std::vector<Vec2> model, Color c,Vec2 pos = { 0.0f,0.0f })
		:
		_model(std::move(model)),
		_position(pos),
		_scale(1.0f),
		_color(c),
		_rotation(0.0f)
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

	float GetScale()const
	{
		return _scale;
	}

	void SetScale(float scale)
	{
		_scale = scale;
	}

	void SetRotation(float rot)
	{
		_rotation = rot;
	}

	float GetRotation()const 
	{
		return _rotation;
	}

	Drawable GetDrawable()const
	{
		Drawable d(_model, _color);
		d.ApplyTransforamtion(
			Mat3::Translation(_position.x, _position.y)*
			Mat3::Scale(_scale)*
			Mat3::Rotation(_rotation)
		);
		return d;
	}

protected:
	void SetModel(std::vector<Vec2> polylines)
	{
		_model = polylines;
	}

private:
	Color _color;
	float _scale;
	float _rotation;
	Vec2 _position;
	std::vector<Vec2> _model;
};