#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#define Maxbuf 1 << 16
int main(int argc, char **argv){
    int fd_target, fd_copy;
    int ret;
    char buf[Maxbuf];
    fd_target = open(argv[1],  O_RDONLY);
    //S_IRUSR| S_IWUSR 讓user可讀可寫 
    fd_copy = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR| S_IWUSR);

    while((ret = read(fd_target, buf, 1)) > 0){//一次讀一個字
        write(fd_copy, buf, 1);
    }
    close(fd_target);
    close(fd_copy);
    return 0;
}