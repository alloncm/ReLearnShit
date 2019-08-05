#pragma once
#include"CoordinateTransformer.h"

class Camera
{
public:
	Camera(CoordinateTransformer& transformer)
		:
		_tranformer(transformer),
		_position(Vec2_<float>(0.0f,0.0f)),
		_scale(1.0f)
	{}

	const Vec2& GetPos()
	{
		return _position;
	}

	void SetPos(const Vec2& pos)
	{
		_position = pos;
	}

	void MoveBy(const Vec2& offset)
	{
		_position += offset;
	}
	float GetScale()
	{
		return _scale;
	}
	void SetScale(float s)
	{
		_scale = s;
	}
	void Draw(Drawable& drawable)
	{
		drawable.ApplyTransforamtion(Mat3::Scale(_scale)*Mat3::Translation(-_position));
		_tranformer.Draw(drawable);
	}	

private:
	float _scale;
	Vec2 _position;
	CoordinateTransformer& _tranformer;
};