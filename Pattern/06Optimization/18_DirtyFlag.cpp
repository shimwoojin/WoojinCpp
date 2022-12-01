//18_DirtyFlag.cpp

/*
	불필요한 작업을 피하기 위해 실제로 필요할 때까지 그 일을 미룸
*/

/*
	- 계속해서 변경되는 '기본 값'이 있음, '파생 값'은 기본 값에 '비싼 작업'을 해야 얻을 수 있음
	- '더티 플래그'는 '기본 값'이 변경되면 켜짐
	- '파생 값'을 써야할 때 플래그가 켜져 있다면 계산한 뒤 더티 플래그를 꺼줌
*/

//불필요한 연산이 너무 많음 -> 성능에 영향
/*
	배 이동
		- 배 위치 재계산
			- 망대 위치 재계산
				- 해적 위치 재계산
					- 앵무새 위치 재계산
	망대 이동
		- 망대 위치 재계산
			- 해적 위치 재계산
				- 앵무새 위치 재계산
	해적 이동
				- 해적 위치 재계산
					- 앵무새 위치 재계산
	앵무새 이동
					- 앵무새 위치 재계산
*/

//훨씬 낫다
/*
	배 이동
	망대 이동
	해적 이동
	앵무새 이동

		- 배 위치 재계산
			- 망대 위치 재계산
				- 해적 위치 재계산
					- 앵무새 위치 재계산
*/

class GraphNode
{
public:
	GraphNode()
		: dirty_(true) {}

	void setTransform(class Transform& local)
	{
		//local_ = local;
		dirty_ = true;
	}	//setTransform을 호출하면 dirty 플래그 ON

	void Render(Transform& parentworld, bool dirty)
	{
		dirty |= dirty_;
		if (dirty)	//플래그 체크 후 동작할지 말지 여부 결정
		{
			//world_ = local_.combine(parenWorld);
			dirty_ = false;	//동작 후 플래그 OFF
		}

		//...
	}

private:
	//class Transform& world_;
	bool dirty_;
};