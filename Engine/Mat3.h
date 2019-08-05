#pragma once
#include"Vec3.h"

template<typename T>
class Mat3_
{
public:
	Vec3_<T> operator*(const Vec3_<T>& v)const
	{
		Vec3_<T> vout;
		vout.x = v.x*cells[0][0] + v.y*cells[0][1] + v.w*cells[0][2];
		vout.y = v.x*cells[1][0] + v.y*cells[1][1] + v.w*cells[1][2];
		vout.w = v.x*cells[2][0] + v.y*cells[2][1] + v.w*cells[2][2];
		return vout;
	}

	Mat3_<T> operator* (const Mat3_<T>& m)const
	{
		Mat3_<T> out;
		for (int col_left = 0; col_left < 3; col_left++)
		{
			for (int row_right = 0; row_right < 3; row_right++)
			{
				out.cells[col_left][row_right] = (T)0;
				for (int i = 0; i < 3; i++)
				{
					out.cells[col_left][row_right] += cells[col_left][i] * m.cells[i][row_right];
				}
			}
		}

		return out;
	}

	static Mat3_<T> ScaleIndependent(T x, T y)
	{
		return{
			(T)x, (T)0, (T)0,
			(T)0, (T)y, (T)0,
			(T)0, (T)0, (T)1
		};
	}

	static Mat3_<T> Scale(T factor)
	{
		return ScaleIndependent(factor, factor);
	}

	static Mat3_<T> Identity()
	{
		return Scale((T)1);
	}

	static Mat3_<T> Rotation(T theta)
	{
		const T sint = std::sin(theta);
		const T cost = std::cos(theta);

		return{
			cost, -sint, (T)0,
			sint, cost, (T)0,
			(T)0, (T)0, (T)1
		};
	}

	static Mat3_<T> Translation(T x, T y)
	{
		return{
			(T)1, (T)0, x,
			(T)0, (T)1, y,
			(T)0, (T)0, (T)1
		};
	}
	static Mat3_<T> Translation(const Vec2_<T>& v)
	{
		return Translation(v.x, v.y);
	}
public:
	T cells[3][3];
};

typedef Mat3_<float> Mat3;