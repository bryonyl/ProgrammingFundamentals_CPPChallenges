#pragma once

class Vector2
{
public:
	float x, y;

	float Magnitude();
	void Normalize();
	Vector2 Normalized();

	Vector2 operator*(float value);
	Vector2 operator+(Vector2& rightHandSide);
	Vector2 operator-(Vector2& rightHandSide);
	Vector2 operator=(Vector2& rightHandSide);
	Vector2 operator-();

	Vector2(Vector2& thingToCopy);

	static float Dot(Vector2 a, Vector2 b);
	static float Distance(Vector2 a, Vector2 b);
};