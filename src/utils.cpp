#include "utils.h"


int MakeUniqSeq()
{
	static int seq = 0;
	if (0 == seq)
	{
		++seq;
	}
	return seq;
}


