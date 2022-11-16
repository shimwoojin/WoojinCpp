#include <iostream>
using namespace std;

template <class T>
class Storage8
{
public:
	void Set(int index, const T& value)
	{
		arr[index] = value;
	}

	const T& Get(int index) { return arr[index]; }

private:
	T arr[8];
};

template<>
class Storage8<bool>
{
public:
	Storage8() : bit8(0) {}
	void BitOnOff(int index, const bool& OnOff)
	{
		if (OnOff == true)
		{
			bit8 |= 1 << (7 - index);
		}
		else
			bit8 &= ~(1 << (7 - index));
	}

	const bool& Get(int index)
	{
		bool isBitOn = true;
		isBitOn = (bit8 & 1 << (7 - index));
		return isBitOn; 
	}

private:
	unsigned char bit8;
};

int main()
{
	Storage8<bool> bitflag;
	bitflag.BitOnOff(0, true);
	bitflag.BitOnOff(1, true);
	bitflag.BitOnOff(2, true);
	bitflag.BitOnOff(3, true);
	bitflag.BitOnOff(5, true);
	bitflag.BitOnOff(7, true);

	bitflag.BitOnOff(2, false);
	bitflag.BitOnOff(3, false);
	bitflag.BitOnOff(4, false);


	for (int i = 0; i < 8; i++)
		cout << i << "번째 비트 : " << bitflag.Get(i) << endl;

	return 0;
}