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


bool IsFileExist(const char *path)
{
    if((access(path, F_OK)) != -1)
    {   
        return true;   
    }   
    else  
    {   
        return false;
    }   
}


