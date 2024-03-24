#include <iostream>
using namespace std;

struct Vector3
{
	float x;
	float y;
	float z;
};

Vector3 VectorCross(Vector3 a, Vector3 b)
{
	return Vector3{
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x };
}

int main()
{
	float x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	float answer = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);

	if (answer > 0)
	{
		cout << 1;
	}
	else if (answer < 0)
	{
		cout << -1;
	}
	else
	{
		cout << 0;
	}

	return 0;
}