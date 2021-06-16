#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#define Maxbuf 1 << 16
int main(int argc, char **argv){
    int fd_input, fd_output, ret, pos = 0;
    char buf[Maxbuf];
    fd_input = open(argv[1], O_RDONLY);
    fd_output = open(argv[2], O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    while((ret = read(fd_input, buf + pos, 1)) > 0){
        pos++;
    }
    lseek(fd_output, 0, SEEK_SET);
    pos--;
    while((ret = write(fd_output, buf + pos, 1)) > 0 && pos > -1){
        pos--;
    }
    return 0;
}
