#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    int n,fd1,fd2[2],pid;
    char s1[1024],s2[1024];
    fd1=open('a.txt',O_RDONLY,0764)   ;
    n=read(fd1,s1,sizeof(s1));
    pipe(fd2);
    pid=frok();
    if(pid==-1)    {
        printf("unsucessful process creation");
        exit(1);
    }
    else if(pid==0){
       close(fd2[1]);
       n=read(fd[0],s2,sizeof(s2));
       fd2[n]='\0';
       printf("receive msg from pipe");
       puts(s2);
    }
    else{
        close(fd2[0])       ;
        write(fd2[1],s1,n);
    }
}