#pragma once

struct iPoint
{
	int x;
	int y;
};

struct fPoint
{
	float x;
	float y;

	fPoint()
	{
		x = 0;
		y = 0;
	}

	fPoint(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};

struct iVec2
{
	int x;
	int y;
};

struct fVec2
{
	float x;
	float y;

	fVec2()
	{
		x = 0;
		y = 0;
	}

	fVec2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	fVec2& normalize()
	{
		float length = (float)sqrt(x * x + y * y);

		assert(length != 0.f);

		x = x / length;
		y = y / length;

		return *this;
	}
};