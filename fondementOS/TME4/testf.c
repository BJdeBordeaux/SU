#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main() 
{
	int status,i;

for (i = 0; i < 10; i++)

{

  status = fork();

  if (status == 0 || status == -1) break;//每次循环时，假设发现是子进程就直接从创建子进程的循环中跳出来。不让你进入循环，这样就保证了每次仅仅有父进程来做循环创建子进程的工作
}

if (status == -1)

{
  //error

}

else if (status == 0) //每一个子进程都会运行的代码
{
  //sub process
    printf("child process %d\n", getpid());
    printf("End child process: %d\n", getpid());
    exit(EXIT_SUCCESS);
}

else{
  //parent process
  wait(&status);
  printf("End parent process: %d\n", getpid());
  return 0;
}
} 
 
//注意：标注的 return 0 对程序结果影响很大