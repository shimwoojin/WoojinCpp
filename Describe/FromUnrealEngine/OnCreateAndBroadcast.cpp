#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Youtuber
{
public:
	using OnUploadDelegate  = std::function<void(Youtuber*)>;

	Youtuber(std::string name) : name(name) {}

public:
	void Upload()
	{
		//���ε忡 ���� �������� ó��, ������ ǰ�� �� ���� �ý��� ���� ��
		//���� UploadDelegate(Broadcast)�鿡 ���� ȣ��(Notify)�ϱ� ���� ������ �� ������ �Ϸ�� �� �ְԲ� ������ �����ϱ⵵ ��
		OnUpload();

		for (auto& Upload : UploadDelegate)
		{
			Upload(this);
		}
	}

protected:
	virtual void OnUpload() {}

public:
	void AddSubscriber(OnUploadDelegate fn)
	{
		UploadDelegate.push_back(fn);
	}

public:
	std::string GetName() { return name; }

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

class Subscriber
{
public:
	Subscriber(std::string name) : name(name) {}

	void SubScribe(Youtuber* youtuber)
	{
		youtuber->AddSubscriber(GetNotify());
	}

protected:
	virtual Youtuber::OnUploadDelegate GetNotify()
	{
		return [](Youtuber* youtuber) {
			std::cout << youtuber->GetName() << "�Բ��� �� �������� ���ε��Ͽ����ϴ�!" << std::endl;
		};
	}

public:
	std::string GetName() { return name; }

private:
	std::string name;
};

class Subscriber1 : public Subscriber
{
public:
	using Subscriber::Subscriber;

protected:
	virtual Youtuber::OnUploadDelegate GetNotify() override
	{
		return [](Youtuber* youtuber) {
			std::cout << youtuber->GetName() << "�Բ��� �� �������� ���ε��Ͽ����ϴ�" << std::endl;
			std::cout << "�������� ���� �ʽ��ϴ�!" << std::endl;
		};
	}
};

class Subscriber2 : public Subscriber
{
public:
	using Subscriber::Subscriber;

protected:
	virtual Youtuber::OnUploadDelegate GetNotify() override
	{
		return std::bind(&Subscriber2::Notify_Internal, this, std::placeholders::_1);
	}

private:
	void Notify_Internal(Youtuber* youtuber)
	{
		std::cout << youtuber->GetName() << "�Բ��� �� �������� ���ε��Ͽ����ϴ�" << std::endl;
		std::cout << GetName() << "���� �޽����� �����߽��ϴ�!" << std::endl;
	}
};

int main()
{
	Youtuber* big_youtuber = new Youtuber_Woojin("woojin");
	Subscriber* subscriber1 = new Subscriber("subscriber1");
	Subscriber* subscriber2 = new Subscriber1("subscriber2");
	Subscriber* subscriber3 = new Subscriber2("subscriber3");

	subscriber1->SubScribe(big_youtuber);
	subscriber2->SubScribe(big_youtuber);
	subscriber3->SubScribe(big_youtuber);

	big_youtuber->Upload();

	delete subscriber3;
	delete subscriber2;
	delete subscriber1;
	delete big_youtuber;

	return 0;
}