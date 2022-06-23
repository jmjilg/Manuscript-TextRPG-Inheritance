
#include "Core.h"

/*
숙제 : 방어구 상점을 완성시킨다.
인벤토리 안의 아이템을 선택하여 장착하는 시스템을 만들어보자.
장착된 아이템의 능력치를 적용해본다.
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
