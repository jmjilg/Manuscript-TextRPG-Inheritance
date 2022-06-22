
#include "Core.h"

/*
숙제 : 상점 관리자를 만들고 상점 클래스를 설계한다.
상점 클래스는 무기, 방어구 상점이 있다.
상속 구조로 설계를 해보자. Stage와 비슷하다.

상점 관리자 초기화 함수에서 상점 객체를 생성하고 vector를 이용해서 관리한다.
각 상점들은 판매할 원본 아이템 목록을 가지게 된다.

아이템 구조는 Obj를 상속받는 Item 클래스를 만들고
Item 을 상속받는 무기와 방어구를 만든다.

상점에서는 각 상점에 맞는 아이템 목록을 만들어서 가지고 있도록 하고
아이템을 구매하면 복사해서 넣어주는 코드를 만들어보자.
*/

int main()
{
	srand((unsigned int)time(0));

	if (!GET_SINGLE(CCore)->Init())
	{
		DESTROY_SINGLE(CCore);
		return 0;
	}

	GET_SINGLE(CCore)->Run();

	DESTROY_SINGLE(CCore);

	return 0;
}
