#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(void)
{
	pid_t pid;
	pid = fork();
	pid_t  zpid;
	int status;
	if(pid>0)
	{
		printf("parent pid %d\n",getpid());
		zpid = wait(&status);
		if(WIFEXITED(status))
		{
			printf("zpid %d ,%d\n",zpid,WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status))
		{
			printf("zpid %d,%d",zpid,WTERMSIG(status));
		}
	}else if(pid == 0){
		printf("child pid %d\n",getpid());
		while(1);
	}else{
		perror("fork is failed\n");
		exit(-1);
	}
	return 0;
}
