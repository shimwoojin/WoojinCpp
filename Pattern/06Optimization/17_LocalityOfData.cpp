//17_LocalityOfData.cpp

/*
	CPU ĳ�ø� �ִ��� Ȱ���� �� �ֵ��� �����͸� ��ġ�� �޸� ���� �ӵ��� ����

	- CPU�� ����ӵ��� ������ �޸𸮿��� �����͸� �������� �ӵ��� ���� ���� �ƴ�(ĳ�� �̽�)
*/

/*
	ĳ�� ��Ʈ - ĳ�ÿ��� ���ϴ� �����͸� ã��
	ĳ�� �̽� - ĳ�ÿ��� �����͸� ã�� ���� �ָ޸𸮿��� �����͸� ������

	ĳ�� : CPU�� ��������
*/


/*
	���� ?
	- ���ɹ����� ������ ����غ��� ��
*/

/*
	��� ?
	- �����Ͱ� �ƴ� �޸𸮿� �������� ���� �迭 ���
*/

//{
//	AIComponent* aiComponent = new AICoponent[MAX_ENTITIES];
//	PhysicsComponent* physicsComponent = new PhysicsCoponent[MAX_ENTITIES];
//	RenderComponent* renderComponent = new RenderCoponent[MAX_ENTITIES];
//}

/*
	�迭�� ��ü Ǯ�� ���ؼ� �۾��� �� �� �ʿ�� ����
	-> �÷��� ������ �ּ� �Ϻο��� �۾�
*/

//for (int i = 0; i < numParticles_; i++)
//{
//	if (particles_[i].isActive())
//	{
//		particles_[i].update();
//	}
//}

/*
	����� ����ϴ� �ڵ忡 ���ؼ� ������ �ø��� ���� �� �������� �޸� ��ġ�� �����Ҹ� ��
	-> ����� �ڵ�� �ѻ��� �ڵ带 ������ ��
*/