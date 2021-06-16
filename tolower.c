#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<ctype.h>
#define Maxbuf 256
int main(int argc, char **argv){
    int fd, ret, pos = 0;
    char buf[Maxbuf];
    fd = open(argv[1], O_RDWR , S_IRUSR | S_IWUSR);
    while((ret = read(fd, buf + pos, 1)) > 0){
        if(isupper(buf[pos])){
            buf[pos] = 'a' + buf[pos] - 'A';
        }
        pos++;
    }
    lseek(fd, 0, SEEK_SET);
    ret = write(fd, buf, pos);
    return 0;
}