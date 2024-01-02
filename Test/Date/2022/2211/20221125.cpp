class IntArray

{

public:

	int operator [] (const int& index)

	{

		if (index < 0 || index >= 10)

			return -1;


		return values[index];

	}


private:

	int values[10];

};