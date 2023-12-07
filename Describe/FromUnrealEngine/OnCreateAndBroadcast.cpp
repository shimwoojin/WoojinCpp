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
		//업로드에 대한 전반적인 처리, 동영상 품질 및 유료 시스템 결제 등
		//또한 UploadDelegate(Broadcast)들에 대해 호출(Notify)하기 전에 본인의 값 세팅이 완료될 수 있게끔 순서를 보장하기도 함
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
		std::cout << "동영상 품질을 1080p로 올렸습니다!!" << std::endl;
		std::cout << "동영상을 프리미엄으로 등록합니다!!" << std::endl;
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
			std::cout << youtuber->GetName() << "님꼐서 새 동영상을 업로드하였습니다!" << std::endl;
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
			std::cout << youtuber->GetName() << "님께서 새 동영상을 업로드하였습니다" << std::endl;
			std::cout << "동영상을 보지 않습니다!" << std::endl;
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
		std::cout << youtuber->GetName() << "님께서 새 동영상을 업로드하였습니다" << std::endl;
		std::cout << GetName() << "님은 메시지를 무시했습니다!" << std::endl;
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