#include<stdlib.h>
#include<stdio.h>
#include<signal.h>

void handle_sigtstp(int sig)
{
printf("stop not allowed \n");
}

void handle_sigtcont(int sig)
{
printf("input number\n");
fflush(stdout);
}


int main(int argc,char *argv[])
{
struct sigaction sa;

// this is for stopping
sa.sa_handler=&handle_sigtstp;
sa.sa_flags=SA_RESTART;
sigaction(SIGTSTP,&sa,NULL);

//this is for continuing

/*sa.sa_handler=&handle_sigtcont;
sa.sa_flags=SA_RESTART;
sigaction(SIGCONT,&sa,NULL);
*/

// this is system command we should not use this because it may be change for different unix/linux so we shuld use userdefined system
//signal(SIGTSTP,&handle_sigtstp);
int x;
printf("input number:");
scanf("%d",&x);
printf("result %d*5=%d\n",x,x*5);
return 0;
}
