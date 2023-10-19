#include <iostream>

struct IVoice
{
	virtual void setTone(int tone_) = 0;
	virtual ~IVoice() { std::cout << "Voice destructor" << std::endl; }
};

class ManVoice : public IVoice
{
public:
	ManVoice() : tone(10) { std::cout << "ManVoice" << std::endl; }
	~ManVoice() { std::cout << "ManVoice destructor" << std::endl; }
	virtual void setTone(int tone_) { tone = tone_; }
private:
	int tone;
};

int main()
{
	{
		IVoice* manvoice = new ManVoice;
		delete manvoice;
	}
	std::cout<< "#######" << std::endl;

	return 0;
}