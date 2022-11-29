//08_DoubleBuffer.cpp

/*
	부드러운 Render를 가능하게 해주는 패턴

	- 이전 프레임을 저장하는 버퍼 사용
	-> 정보를 읽을 때는 '현재' 버퍼, 정보를 쓸 때는 '다음'버퍼
*/

class Framebuffer
{
public:
	Framebuffer() { clear(); }
	void clear()
	{
		for (int i = 0; i < WIDTH * HEIGHT; i++)
		{
			pixels_[i] = 0;	//WHITE
		}
	}
	void draw(int x, int y)
	{
		pixels_[(WIDTH * y) + x] = 1;	//BLACK
	}
	const char* getPixels() { return pixels_; }

private:
	static const int WIDTH = 160;
	static const int HEIGHT = 120;

	char pixels_[WIDTH * HEIGHT];
};

class Scene
{
public:
	Scene() : current_(&buffers_[0]), next_(&buffers_[1]) {}
	void draw()
	{
		next_->clear();
		next_->draw(1, 1);
		next_->draw(12, 12);
		next_->draw(13, 13);
		//...
		swap();
	}
	Framebuffer& getBuffer() { return *current_; }

private:
	void swap()
	{
		Framebuffer* temp = current_;
		current_ = next_;
		next_ = temp;
	}
	Framebuffer buffers_[2];
	Framebuffer* current_;
	Framebuffer* next_;
};