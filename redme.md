# 好大的标题
## 比好大小一点的标题
### 有点小的标题
#### 最小的标题
* 斜体 *
** 粗体 **
*** 粗斜体 ***
` WANGQING `

* 论文
	* 好论文
		* 更好的论文
* 不是论文
	* 不好的论文
		* 更不好的论文

1. 好不容易学习
	1. 还不让学习
		1. 怎么才能偷摸学习
2. 放假
	1. 放假让学习
		1. 放假怎么才能不学习`唉`
> 引用文本
>> 再引用文本
>>> zaiazia引用文本
>>>> zaizaizai引用文本

学习吧，在[github](https://github.com)上好好学习

你也可以在[github][1]上学

[1]:https://github.com

去网站上上传图片[sm.ms](https://sm.ms/)

上传图片![捕获.PNG](https://i.loli.net/2021/11/25/jgwa7i9XuyVoWTM.png)


```bash
sudo apt-get install git

```

```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
	printf("就是测试c就是玩\n");
	return 0;
}

```

```cpp
#include<iostream>
using namespace std;

int main()
{
	printf("就是测试c++就是玩\n");
	return 0;

}
```
```c
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
	printf("zpid %d ,%d",zpid,WTERMSIG(status));
}
}else if(pid==0){
	printf("child pid %d\n",getpid());
	while(1);
}else{
	perror("fork is failed\n");
	exit(-1);
	}
	return 0;
}
```
* wait阻塞型回收僵尸进程，
	* 会暂停所有进程，直到子进程结束再开始
1. waitpid非阻塞型回收僵尸进程
	1. 会等待子进程结束的同时，进行其他进程
2. 当子进程结束时，父进程并未结束，且父进程没有回收子进程就会产生僵尸进程
	2. 主要是PCB没有回收，造成了泄露
