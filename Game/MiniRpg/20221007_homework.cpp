/*
    과제
    게임 만들기
    위의 예제를 활용해서 게임을 만들어보자
    1. 전투 구현
    - 플레이어 정의
    - 몬스터 정의
    - 공격 키 만들기
    2. 게임 승리, 패배 이벤트 추가
    3. 몬스터 외에 충돌시 발생하는 이벤트 2개이상 구현
*/

#include "20221007_homework.h"

int main()
{

    Player p1 = init_player();
    mini_rpg(&p1);

    return 0;
}