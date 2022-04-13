#include <iostream>

float ApproxSin(float x)
{
	float t = x / (2.0f * 3.141592653f);
	t -= (int)t;

	return (t < 0.5f) ? 
		-16 * t * t + 8 * t :
		16 * t * t - 16 * t - 8 * t + 8;
}

int main()
{
	std::cout << "C++ sin(): " << sin(30.0f * 3.1415926f / 180.0f) << "\n";
	std::cout << "ApproxSin(): " << ApproxSin(30.0f * 3.1415926f / 180.0f) << "\n";
	return 0;
}
