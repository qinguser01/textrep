#include"pcpy.h"

int block(const char * SFILE,int pronum)
{
	int FileSize;
	int fd = open(SFILE,O_RDONLY);

	FileSize = lseek(fd,0,SEEK_END);

	if(FileSize %pronum ==0)
		return FileSize / pronum;
	else
		return FileSize / pronum +1;
}
