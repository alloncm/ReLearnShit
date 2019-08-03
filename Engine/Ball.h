#pragma once
#include"Entity.h"


class Ball : public Entity
{
public:
	static std::vector<Vec2> GetPoly(float radius)
	{
		std::vector<Vec2> poly;
		poly.reserve(8 * 2);
		const float dTheta = 2.0f * 3.14159f / float(8 * 2);
		for (int i = 0; i < 8 * 2; i++)
		{
			poly.emplace_back(
				radius * cos(float(i) * dTheta),
				radius * sin(float(i) * dTheta)
			);
		}
		return poly;
	}
	Ball(Vec2 pos, float radius, Vec2 vel, Color c = Colors::Red)
		:
		Entity(GetPoly(radius), c),
		_radius(radius),
		_velocity(vel)
	{}

	float GetRadius()const
	{
		return _radius;
	}

	const Vec2& GetVel()const
	{
		return _velocity;
	}

	void SetVel(const Vec2& vel)
	{
		_velocity = vel;
	}

	void Update(float dt)
	{
		TranslateBy(_velocity*dt);
	}
	
private:
	float _radius;
	Vec2 _velocity;
};