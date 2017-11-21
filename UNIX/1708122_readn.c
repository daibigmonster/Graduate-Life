#include"unp.h"
static int read_cnt;
static char *read_ptr;
static char read_buf[MAXLINE];
static ssize_t
my_read(int fd,char *ptr)
{
    if(read_cnt<=0){
        again:
            if((read_cnt=read(fd,read_buf,sizeof(read_buf)))<0){
                if(errno==ENTER)
                    goto again;
                return -1;
            }
            else if(read_cnt==0)
                return 0;
            read_ptr=read_buf;
        }
    read_cnt--;
    *ptr=*read_ptr++;
    return 1;
}
ssize_t readline(int fd,void *vptr,size_t maxlen)
{
    size_t n,rc;
    char c,*ptr;
    ptr=vptr;
    for(n=1;n<maxlen;n++){
        if((rc=my_read(fd,&c))==1){
            *ptr++=c;
            if(c=='\n')break;
        }else if(rc==0){
            *ptr=0;
            return n-1;
        }else
            return -1
    }
    *ptr=0;
    return n;
}
ssize_t readlinebuf(void **vptptr)
{
    if(read_cnt)
        *vptrptr=read_ptr;
    return(read_cnt);
} 
//内部函数my_read每次最多读MSXLINE个字符，然后每次返回一个字符
//readline函数本身的唯一变化是用my_read调用取代read
//realinebuf这个函数能够展露内部缓冲区的状态，便于调用这查看在当前文本行之后是否收到了新的数据。
