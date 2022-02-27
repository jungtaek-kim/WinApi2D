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

	fPoint& operator=(const fPoint& other)
	{
		x = other.x;
		y = other.y;

		return *this;
	}

	fPoint operator+(const fPoint& other)
	{
		return fPoint(x + other.x, y + other.y);
	}

	fPoint operator-(const fPoint& other)
	{
		return fPoint(x - other.x, y - other.y);
	}

	template <typename T>
	fPoint operator*(T num)
	{
		return fPoint(x * num, y * num);
	}

	template <typename T>
	fPoint operator/(T num)
	{
		assert(0 != num);

		return fPoint(x / num, y / num);
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
		float length = (float)sqrt((double)x * x + (double)y * y);

		assert(length != 0.f);

		x = x / length;
		y = y / length;

		return *this;
	}
};