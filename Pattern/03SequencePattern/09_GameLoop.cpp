//09_GameLoop.cpp

/*
	게임 시간 진행을 유저 입력, 프로세서 속도와 디커플링
*/

//기본 패턴
/*
	while (true)
	{
		processInput();
		update();
		render();
	}
*/

//변형 1. 프레임을 정함
//-> 빨라지는 건 막을 수 있음, 느려지는 건 불가능(하드웨어 성능, OS 등)
/*
	while (true)
	{
		double start = getCurrentTime();
		processInput();
		update();
		render();

		sleep(start + MS_PER_FRAME - getCurrentTime());
	}
*/

//변형 2. 가변 시간 간격
//-> 현실 시간과 게임 시간의 괴리가 거의 없음
//-> 치명적인 단점 : 부동 소수점의 반올림 오차 발생
/*
	double lastTime = getCurrentTime();
	while (true)
	{
		double current = getCurrentTime();
		double elapsed = current - lastTime;
		processInput();
		update();
		render();
		lastTime = current;
	}
*/

//변형 3. 따라잡기
//-> 렌더링은 고정시간
//-> lag변수는 실제 시간이 얼마나 지났는지
/*
	double previous = getCurrentTime();
	double lag = 0.0;
	while (true)
	{
		double current = getCurrentTime();
		double elapsed = current - previous;
		previous = current;
		lag += elpased;
		processInput();

		while(lag >= MS_PER_UPDATE)
		{
			update();
			lag -= MS_PER_UPDATE;
		}
		render();
	}
*/

//변형 4. 중간에 끼는 경우
//-> 업데이트는 고정시간, 렌더링은 가변시간
//render(lag / MS_PER_UPDATE);
//복잡하다고 함