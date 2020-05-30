#include "array_and_ptr.h"
#include <stdio.h>
enum SwitchCase {
	Array_AND_PTR,
	TAILQ
};

int main()
{
	enum SwitchCase switchCase = TAILQ;

	switch(switchCase)
	{
	case Array_AND_PTR:
		showOneDimenArray();

		showTwoDimenArray();
		break;
	case TAILQ:
		tailq();
		break;
	default:
	        printf("你没有选择你喜欢的颜色");
	    }



}
