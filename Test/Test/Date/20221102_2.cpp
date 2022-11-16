/*
	����
	����ȯ �����ε��� �Ͽ�
	Hour, Milli_Second Ŭ������
	�ٸ� Ŭ�������� ����ȯ�� ����������
	ó���ǵ���(�ð� ������ �°�) �ϱ�
*/
#include <iostream>

class Minute;
class Second;
class Milli_Second;

class Hour
{
public:
	Hour() : hour(0) {}
	Hour(int hour) : hour(hour) {}

	friend std::ostream& operator<<(std::ostream& os, const Hour ho)
	{
		os << ho.hour;
		return os;
	}

	operator Minute();
	operator Second();
	operator Milli_Second();

private:
	int hour;
};

class Minute
{
public:
	Minute() : minute(0) { }
	Minute(int minute) : minute(minute) { }

	friend std::ostream& operator<<(std::ostream& os, const Minute mi)
	{
		os << mi.minute;
		return os;
	}

private:
	int minute;
};

class Second
{
public:
	Second() : second(0) {}
	Second(int second) : second(second) {}

	friend std::ostream& operator<<(std::ostream& os, const Second se)
	{
		os << se.second;
		return os;
	}

private:
	int second;
};

class Milli_Second
{
public:
	Milli_Second() : milli_second(0) {}
	Milli_Second(int milli_second) : milli_second(milli_second) {}

	friend std::ostream& operator<<(std::ostream& os, const Milli_Second ms)
	{
		os << ms.milli_second;
		return os;
	}

	operator Hour();
	operator Minute();
	operator Second();

private:
	int milli_second;
};

Hour::operator Minute()
{
	return hour * 60;
}

Hour::operator Second()
{
	return hour * 3600;
}

Hour::operator Milli_Second()
{
	return hour * 60 * 60 * 1000;
}

Milli_Second::operator Hour()
{
	return (milli_second / 3600000);
}

Milli_Second::operator Minute()
{
	return (milli_second / 60000);
}

Milli_Second::operator Second()
{
	return (milli_second / 1000);
}

int main()
{
	using namespace std;

	int hour = 5;
	Hour h(hour);
	cout << hour << "�ð��� ������ �ٲٸ� "<< static_cast<Minute>(h) <<"�� �Դϴ�." << endl;
	cout << hour << "�ð��� �ʷ� �ٲٸ� " << static_cast<Second>(h) <<"�� �Դϴ�." << endl;
	cout << hour << "�ð��� ms�ʷ� �ٲٸ� " << static_cast<Milli_Second>(h) << "ms�� �Դϴ�." << endl;

	int millisecond = 7200000;
	Milli_Second m(millisecond);
	cout << millisecond << "ms�ʸ� �ð����� �ٲٸ� " << static_cast<Hour>(m) << "�ð� �Դϴ�." << endl;
	cout << millisecond << "ms�ʸ� �ð����� �ٲٸ� " << static_cast<Minute>(m) << "�� �Դϴ�." << endl;
	cout << millisecond << "ms�ʸ� �ð����� �ٲٸ� " << static_cast<Second>(m) << "�� �Դϴ�." << endl;
	return 0;
}