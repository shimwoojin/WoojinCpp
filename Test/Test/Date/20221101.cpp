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
		<< "�߸��� �Ű����� : a = -b\n";
}

const char* bad_gmean::mesg()
{
	return "gmean() �Ű� �������� >= 0�̾�� �մϴ�.\n";
}


int main()
{
	double x, y, z;

	std::cout << "�� ���� �Է��Ͻʽÿ� : ";

	while (std::cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			std::cout << x << ", " << y << "�� ��ȭ�����"
				<< z << "�Դϴ�\n";
			std::cout << x << ", " << y << "�� ���������"
				<< gmean(x, y) << "�Դϴ�\n";
		}
		catch (bad_hmean bg)
		{
			bg.mesg();
			std::cout << "�ٽ� �Ͻʽÿ�\n";
			continue;
		}
		catch (bad_gmean hg)
		{
			std::cout << hg.mesg();
			std::cout << "Values used: " << hg.v1 << ", "
				<< hg.v2 << std::endl;
			std::cout << "�˼��մϴ�. �� �̻� ������ �� �����ϴ�.\n";
			break;
		}
	}
	std::cout << "���α׷��� �����մϴ�\n";

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