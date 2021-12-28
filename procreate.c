#include"pcpy.h"


int procreate(const char * SFILE ,const char * DFILE,int pronum,int blocksize)
{
	int flag;
	pid_t pid;

	int pos;
	char cblock[10];
	char cpos[10];
	bzero(cblock,sizeof(cblock));
	bzero(cpos,sizeof(cblock));
	for(flag=0;flag<pronum;flag++)
	{
		pid=fork();
		if(pid==0)
			break;
	}
	if(pid>0)
	{
		printf("parent pid[%d] ...\n",getpid());
		pid_t zpid;
		while((zpid=waitpid(-1,NULL,WNOHANG))!=-1)
		{
			if(zpid>0)
			{
				printf("parent wait success[%d]\n",zpid);
			}
		}
	}
	else if(pid==0)
	{
		pos=flag*blocksize;
		sprintf(cblock,"%d",blocksize);
		sprintf(cpos,"%d",pos);
		execl("/home/studycolin/0322/1228/COpy","./COpy",SFILE,DFILE,cblock,cpos,NULL);
	}else
	{
		perror("fork call failed");
		exit(-1);
	}
	return 0;
}
