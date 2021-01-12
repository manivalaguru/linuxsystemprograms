#include<stdio.h>
#include<signal.h>
#include<sys/types.h>
#include<unistd.h>
void handler_sigstp(int signum);
int main()
{
pid_t pid;
printf("testing SIGSTOP\n");
pid=getpid();
printf("open terminal and issue following command\n");
printf("kill -SIGCONT %d or kill -cont %d or kill -18 %d\n",pid,pid,pid);
raise(SIGSTOP);
printf("received signal sigcont\n");
return 0;
}
