//BuilderPattern
#include <iostream>
#include <string>
using namespace std;

class Item
{
public:
	Item(string Name, int Count, int Size, float SpawnInterval)
	{
		Init();

		this->Name = Name;
		this->Count = Count;
		this->Size = Size;
		this->SpawnInterval = SpawnInterval;
	}

	void Init()
	{
		Name = string("NoNamedItem");
		Count = 0;
		Size = 0;
		SpawnInterval = 10.f;
	}

	void PrintProperty()
	{
		cout << "Name : " << Name << endl;
		cout << "Count : " << Count << endl;
		cout << "Size : " << Size << endl;
		cout << "SpawnInterval : " << SpawnInterval << endl;
	}

private:
	string Name;
	int Count;
	int Size;
	float SpawnInterval;
};

class ItemBuilder
{
public:
	ItemBuilder& SetName(string Name)
	{
		this->Name = Name;
		return (*this);
	}

	ItemBuilder& SetCount(int Count)
	{
		this->Count = Count;
		return (*this);
	}

	ItemBuilder& SetSize(int Size)
	{
		this->Size = Size;
		return (*this);
	}

	ItemBuilder& SetSpawnInterval(float SpawnInterval)
	{
		this->SpawnInterval = SpawnInterval;
		return (*this);
	}

	Item* Build()
	{
		return new Item(Name, Count, Size, SpawnInterval);
	}

private:
	string Name;
	int Count;
	int Size;
	float SpawnInterval;
};

int main()
{
	Item* Apple = ItemBuilder()
		.SetName("Apple")
		.SetCount(3)
		.SetSize(5)
		.SetSpawnInterval(10)
		.Build();

	Apple->PrintProperty();

	Item* Banana = ItemBuilder()
		.SetName("Banana")
		.SetSize(10)
		.Build();

	Banana->PrintProperty();

	delete Apple;
	delete Banana;

	return 0;
}