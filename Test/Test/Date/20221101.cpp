#include <iostream>

double hmean(double a, double b);
double gmean(double a, double b);

class bad_hmean
{
private:
	double v1;
	double v2;
public:
	bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	void mesg();
};

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char* mesg();
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean(" << v1 << ", " << v2 << "): "
		<< "잘못된 매개변수 : a = -b\n";
}

const char* bad_gmean::mesg()
{
	return "gmean() 매개 변수들은 >= 0이어야 합니다.\n";
}


int main()
{
	double x, y, z;

	std::cout << "두 수를 입력하십시오 : ";

	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			std::cout << x << ", " << y << "의 조화평균은"
				<< z << "입니다\n";
			std::cout << x << ", " << y << "의 기하평균은"
				<< gmean(x, y) << "입니다\n";
		}
		catch (bad_hmean bg)
		{
			bg.mesg();
			std::cout << "다시 하십시오\n";
			continue;
		}
		catch (bad_gmean hg)
		{
			std::cout << hg.mesg();
			std::cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << std::endl;
			std::cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
			break;
		}
	}
	std::cout << "프로그램을 종료합니다\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}