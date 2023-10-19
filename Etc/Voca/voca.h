#pragma once

class Voca
{
public:
	Voca() {}
	Voca(std::string english, std::string korean)
		: english(english), korean(korean) {}
	
	//setter
	void write_english(const std::string english) { this->english = english; }
	void write_korean(const std::string korean) { this->korean = korean; }

	//getter
	const std::string& get_korean() const { return korean; }
	const std::string& get_english() const { return english; }

	friend std::ostream& operator<<(std::ostream& os, const Voca& vo)
	{
		os << vo.english << " " << vo.korean;
		return os;
	}

private:
	std::string english;
	std::string korean;
};

