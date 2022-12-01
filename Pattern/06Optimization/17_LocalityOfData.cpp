//17_LocalityOfData.cpp

/*
	CPU 캐시를 최대한 활용할 수 있도록 데이터를 배치해 메모리 접근 속도를 높임

	- CPU의 연산속도는 빠르나 메모리에서 데이터를 가져오는 속도가 빠른 것이 아님(캐시 미스)
*/

/*
	캐시 히트 - 캐시에서 원하는 데이터를 찾음
	캐시 미스 - 캐시에서 데이터를 찾지 못해 주메모리에서 데이터를 가져옴

	캐시 : CPU의 레지스터
*/


/*
	언제 ?
	- 성능문제가 있을때 고려해볼만 함
*/

/*
	어떻게 ?
	- 포인터가 아닌 메모리에 연속적인 정적 배열 사용
*/

//{
//	AIComponent* aiComponent = new AICoponent[MAX_ENTITIES];
//	PhysicsComponent* physicsComponent = new PhysicsCoponent[MAX_ENTITIES];
//	RenderComponent* renderComponent = new RenderCoponent[MAX_ENTITIES];
//}

/*
	배열의 전체 풀에 대해서 작업을 다 할 필요는 없음
	-> 플래그 변수를 둬서 일부에만 작업
*/

//for (int i = 0; i < numParticles_; i++)
//{
//	if (particles_[i].isActive())
//	{
//		particles_[i].update();
//	}
//}

/*
	빈번히 사용하는 코드에 대해서 성능을 올리고 싶을 때 연속적인 메모리 배치를 생각할만 함
	-> 빈번한 코드와 한산한 코드를 나눠야 함
*/