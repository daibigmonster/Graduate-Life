/*readn、writen和readline函数
字节流套接字（例如TCP套接字）上的read和write函数所表现的行为不同于通常文件的IO，字节流套就自上调用read或write输入或输出的字节数可能比请求的数量少，然而这并不是出错的状态。这个现象的原因在于内核中用于套接字的缓冲区可能已经达到了极限。此时所需的是调用者再次调用read或write函数，以输出或输入剩余的字节
#include "unp.h"
ssize_t raadn(int files,void *buff,size_t nbytes);
ssize_t written(int files,const void *buff,size_t nbytes);
ssize_t readline(int files,void *buff,size_t maxlen);
*/
#include "unp.h"
ssize_t readn(int fd,void *vptr,size_t n)
{
    size_t nleft;
    ssize_t nread;
    char *ptr;
    ptr=vptr;
    nleft=n;
    while(nleft>0){
        if((nread=read(fd,ptr,nleft))<0){
            if(errno=ENTER)
                nread=0;
            else
                return -1;
        }
        else if(nread==0)break;
    }
    return n-nleft;
}
ssize_t writen(int fd,const void *vptr,size_t n)
{    
    size_t nleft;
    ssize_t nwritten;
    const char *ptr;
    ptr=vptrl
    nleft=n;
    while(nleft>0){
        if((nwirtten=write(fd,ptr,nleft))<0)
        {
            if(nwritten<0&&errno==ENTER)
                nwritten=0;
            else
                return -1;
         }
         nleft-=written;
         ptr+=nweitten;
    }
    return n;
 }
 #include "unp.h"
ssize_t readline(int fd.void *vptr,size_t maxlen)
{
    ssize_t n,rc;
    char c,*ptr;
    ptr=vptr;
    for(n=1;n<maxlen;n++){
    again:
       if((rc=read(fd,&c,1))==1){
           *ptr++=c;
           if(c=='\n')break}
       else if(rc==0)
           *ptr=0;
           return(n-1);
       }
       else{
           if(errno==ENTER)
               goto again;
           return -1;
       }
       *ptr=0;
       return n;
  }
       
