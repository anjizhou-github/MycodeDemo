#include <stdio.h>
#include "array_and_ptr.h"
#include "tailq.h"
#include "linear_list_in_seq.h"

enum SwitchCase {
	Array_AND_PTR,
	TAILQ,
	LINEAR_LIST_IN_SQE
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
		tailq1();
		break;
	case LINEAR_LIST_IN_SQE:
		linear_list_in_seq_main();
		break;
	default:
	        printf("default");
	    }
}
