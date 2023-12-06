#include <iostream>
#include <vector>
#include <string>

class Youtuber
{
public:
	using OnUploadDelegate  = void(*)(Youtuber*);

	Youtuber(std::string name) : name(name) {}

	void Upload()
	{
		OnUpload();

		for (auto& Upload : UploadDelegate)
		{
			Upload(this);
		}
	}

public:
	void AddPublisher(OnUploadDelegate fn)
	{
		UploadDelegate.push_back(fn);
	}

public:
	std::string GetName() { return name; }

protected:
	virtual void OnUpload() {}

private:
	std::vector<OnUploadDelegate > UploadDelegate;
	std::string name;
};

class Youtuber_Woojin : public Youtuber
{
public:
	Youtuber_Woojin(std::string name) : Youtuber(name) {}

protected:
	virtual void OnUpload() override
	{
		std::cout << "������ ǰ���� 1080p�� �÷Ƚ��ϴ�!!" << std::endl;
		std::cout << "�������� �����̾����� ����մϴ�!!" << std::endl;
	}
};

class Publisher
{
public:
	Publisher(std::string name) : name(name) {}

	void SubScribe(Youtuber* youtuber)
	{
		youtuber->AddPublisher(GetNotify());
	}

protected:
	virtual Youtuber::OnUploadDelegate GetNotify()
	{
		return [](Youtuber* youtuber) {
			std::cout << youtuber->GetName() << "�Բ��� �� �������� ���ε��Ͽ����ϴ�!" << std::endl;
		};
	}

private:
	std::string name;
};

class Publisher1 : public Publisher
{
public:
	using Publisher::Publisher;

protected:
	virtual Youtuber::OnUploadDelegate GetNotify() override
	{
		return [](Youtuber* youtuber) {
			std::cout << youtuber->GetName() << "�Բ��� �� �������� ���ε��Ͽ����ϴ�" << std::endl;
			std::cout << "�������� ���� �ʽ��ϴ�!" << std::endl;
		};
	}
};

int main()
{
	Youtuber_Woojin* big_youtuber = new Youtuber_Woojin("woojin");
	Publisher1* publisher1 = new Publisher1("publisher1");
	Publisher* publisher2 = new Publisher("publisher2");

	publisher1->SubScribe(big_youtuber);
	publisher2->SubScribe(big_youtuber);

	big_youtuber->Upload();

	delete publisher1;
	delete big_youtuber;

	return 0;
}