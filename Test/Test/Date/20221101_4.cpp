#include<iostream>

/*
	과제
	Won class에 연산자 추가하기
	* / %
	+= -= *= /= %=
*/

class Won
{
public:
	Won(int value) : value(value) { }

	int getValue() const { return value; }

	friend std::ostream& operator<<(std::ostream& os , const Won& rhs) 
	{
		os << rhs.value;
		return os;
	}

	//l + r -> l.operator(r)
	Won operator+(const Won& rhs) const { return value + rhs.value; }
	Won operator-(const Won& rhs) const { return value - rhs.value; }
	Won operator*(const Won& rhs) const { return value * rhs.value; }
	Won operator/(const Won& rhs) const { return value / rhs.value; }
	Won operator%(const Won& rhs) const { return value % rhs.value; }
	Won operator+=(const Won& rhs) { value += rhs.value; return (*this); }
	Won operator-=(const Won& rhs) { value -= rhs.value; return (*this); }
	Won operator*=(const Won& rhs) { value *= rhs.value; return (*this); }
	Won operator/=(const Won& rhs) { value /= rhs.value; return (*this); }
	Won operator%=(const Won& rhs) { value %= rhs.value; return (*this); }
	

private:
	int value;
};

int main()
{
	using namespace std;

	Won w1(10), w2(20);

	cout << w1 + w2 << endl;
	cout << w1 - w2 << endl;
	cout << w1 * w2 << endl;
	cout << w1 / w2 << endl;
	cout << w1 % w2 << endl;

	w1 += w2;			// 10 + 20
	cout << w1 << endl;	// w1 = 30
	w1 -= w2;			// 30 - 20
	cout << w1 << endl;	// w1 = 10
	w1 *= w2;			// 10 * 20
	cout << w1 << endl;	// w1 = 200
	w1 /= w2;			// 200 / 20
	cout << w1 << endl;	// w1 = 10
	w1 %= w2;			// 10 % 20
	cout << w1 << endl;	// w1 = 10

	return 0;
}