#pragma once
#include"Vec2.h"

template<typename T>
class Vec3_ : public Vec2_<T>
{
public:
	T w = (T)1;
public:
	Vec3_<T>() = default;

	Vec3_<T>(T x, T y)
		:
		Vec2_(x, y)
	{}
	Vec3_(const Vec2_<T>& v2)
		:
		Vec2_(v2.x, v2.y)
	{}

	explicit operator Vec2_<T>()const
	{
		return Vec2_<T>(x, y);
	}
};