#include <iostream>
#include <vector>
#include <string>
#include <functional>

class Youtuber
{
public:
	using OnUploadDelegate  = std::function<void(Youtuber*)>;

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
		std::cout << "동영상 품질을 1080p로 올렸습니다!!" << std::endl;
		std::cout << "동영상을 프리미엄으로 등록합니다!!" << std::endl;
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

public:
	std::string GetName() { return name; }

protected:
	virtual Youtuber::OnUploadDelegate GetNotify()
	{
		return [](Youtuber* youtuber) {
			std::cout << youtuber->GetName() << "님꼐서 새 동영상을 업로드하였습니다!" << std::endl;
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
			std::cout << youtuber->GetName() << "님께서 새 동영상을 업로드하였습니다" << std::endl;
			std::cout << "동영상을 보지 않습니다!" << std::endl;
		};
	}
};

class Publisher2 : public Publisher
{
public:
	using Publisher::Publisher;

protected:
	virtual Youtuber::OnUploadDelegate GetNotify() override
	{
		return std::bind(&Publisher2::Notify_Internal, this, std::placeholders::_1);
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
	Publisher* publisher1 = new Publisher("publisher1");
	Publisher* publisher2 = new Publisher1("publisher2");
	Publisher* publisher3 = new Publisher2("publisher3");

	publisher1->SubScribe(big_youtuber);
	publisher2->SubScribe(big_youtuber);
	publisher3->SubScribe(big_youtuber);

	big_youtuber->Upload();

	delete publisher3;
	delete publisher2;
	delete publisher1;
	delete big_youtuber;

	return 0;
}