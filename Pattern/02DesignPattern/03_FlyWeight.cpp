//03_FlyWeight.cpp

/*
	����(�����) ������ ���� ������ ��ü�� ǥ���ϱ⿡ ���� ����

	- ����� ������ ���� Ŭ����ȭ �� �� ǥ���ϰ��� �ϴ� ��ü����
	������ ��������� ������ ��
	- �׷���ī�忡�� ���� ������ �� ���� ����
*/

class TreeModel
{
private:
	//Mesh mesh_;
	//Texture bark_;
	//Texture leaves_;
};

class Tree
{
private:
	TreeModel* model_;	//���� ������ ���� Ŭ����

	//Vector position_;
	//double height_;
	//double thickness_;
	//Color brakTint_;
	//Color leafTint_;
};

//===========================================

class Terrain
{
public:
	Terrain(int movementCost, bool isWater/*, Texture texture*/)
		: movementCost_(movementCost),
		isWater_(isWater)
		//texture_(texture)
	{}

//getter
//...

private:
	int movementCost_;
	bool isWater_;
	//Texture texture_;
};

#define WIDTH 30
#define HEIGHT 40

class World
{
public:
	World() 
	: grassTerrain_(1, false/*, GRASS_TEXTURE*/),
		hillTerrain_(3, false/*, HILL_TEXTURE*/)
	{}

	void generateTerrain();

	const Terrain& getTile(int x, int y) const
	{
		return *tiles_[x][y];
	}

private:
	Terrain grassTerrain_;
	Terrain hillTerrain_;
	//Terrain riverTerrain_;

	Terrain* tiles_[WIDTH][HEIGHT];

};

void World::generateTerrain()
{
	for (int x = 0; x < WIDTH; x++)
	{
		for (int y = 0; y < HEIGHT; y++)
		{
			tiles_[x][y] = &grassTerrain_;
		}
	}
}
