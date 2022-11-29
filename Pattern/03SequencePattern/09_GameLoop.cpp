//09_GameLoop.cpp

/*
	���� �ð� ������ ���� �Է�, ���μ��� �ӵ��� ��Ŀ�ø�
*/

//�⺻ ����
/*
	while (true)
	{
		processInput();
		update();
		render();
	}
*/

//���� 1. �������� ����
//-> �������� �� ���� �� ����, �������� �� �Ұ���(�ϵ���� ����, OS ��)
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

//���� 2. ���� �ð� ����
//-> ���� �ð��� ���� �ð��� ������ ���� ����
//-> ġ������ ���� : �ε� �Ҽ����� �ݿø� ���� �߻�
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

//���� 3. �������
//-> �������� �����ð�
//-> lag������ ���� �ð��� �󸶳� ��������
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

//���� 4. �߰��� ���� ���
//-> ������Ʈ�� �����ð�, �������� �����ð�
//render(lag / MS_PER_UPDATE);
//�����ϴٰ� ��