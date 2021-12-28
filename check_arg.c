#include"pcpy.h"

int check_arg(const char * SFILE,int arg_num ,int pronum)
{
	if((access(SFILE,F_OK))!=0){
		perror("check_arg error");
		exit(-1);
	}
	if(arg_num<3){
		printf("check_arg error :!");
		exit(-1);
	}
	if(pronum<=0||pronum>=100)
	{
		printf("check_arg error :!\n");
		exit(-1);
	}
	return 0;
}
