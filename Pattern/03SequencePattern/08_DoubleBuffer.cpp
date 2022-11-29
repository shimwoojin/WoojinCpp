//08_DoubleBuffer.cpp

/*
	�ε巯�� Render�� �����ϰ� ���ִ� ����

	- ���� �������� �����ϴ� ���� ���
	-> ������ ���� ���� '����' ����, ������ �� ���� '����'����
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