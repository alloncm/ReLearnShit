#pragma once
#include"Entity.h"
#include<algorithm>

class Plank :public Entity 
{
public:
	Plank(Vec2 anchor, float freeX, float minFreeY, float maxFreeY,float fatness = 8.0f, Color c = Colors::Gray)
		:
		Entity({}, c, anchor),
		_minFreeYModel(minFreeY-anchor.y),
		_maxFreeYModel(maxFreeY - anchor.y),
		_freePtModel(freeX - anchor.x, _minFreeYModel),
		_fatness(fatness)
	{}

	Drawable GetDrawable()
	{
		std::vector<Vec2> model;
		model.reserve(4);
		model.emplace_back(0.0f, 0.0f);
		model.push_back(_freePtModel);
		model.push_back(_freePtModel + Vec2(0.0f, _fatness));
		model.emplace_back(0.0f, _fatness);
		SetModel(std::move(model));
		return Entity::GetDrawable();
	}

	Vec2 GetFreePt()const
	{
		return _freePtModel + GetPos();
	}

	void SetFreeY(float freeY)
	{
		float v = freeY - GetPos().y;
		float result = v;
		if (v <  _minFreeYModel)
		{
			result = _minFreeYModel;
		}
		else if (_maxFreeYModel < v)
		{
			result = _maxFreeYModel;
		}
		_freePtModel.y = result;
	}
	void MoveFreeY(float deltaY)
	{
		SetFreeY(GetFreePt().y + deltaY);
	}

	Vec2 GetPlankSurfaceVector()const 
	{
		return -_freePtModel;
	}

private:
	float _fatness;
	float _minFreeYModel;
	float _maxFreeYModel;
	Vec2 _freePtModel;
};