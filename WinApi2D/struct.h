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

	fVec2& normalize(fVec2 other)
	{
		float length = (float)sqrt(other.x * other.x + other.y + other.y);
		this->x = other.x / length;
		this->y = other.y / length;
	}
};