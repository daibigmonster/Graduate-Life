/*这两个函数是随IP6出现的新函数，对于IP4和IP6都使用
*/
//只支持IP4的inet_pton的inet_ntop的简化版本
int int_pton(int family,const char *strptr,void *addrptr){
    if(family==AF_INET){
        struct in_addr int_val;
        if(inet_aton(strptr,&in_val))
            memcpy(addrptr,&in_val,sizeof(struct in_addr));
            return (1);
        }
        return 0;
    errno=EAFNOSUPPORT;
    return (-1);
}
const char* inet_ntop(int family,const void *addrptr,char *strptr,size_t len)
{
    const u_char *p=(const u_char*)addrptr;
    if(family==AF_INET){
        char temp[INET_ADDRSTRLEN];
        snprintf(temp,sizeof(temp),"%d.%d.%d.%d",p[0],p[1],p[2],p[3]);
        if(strlen(temp)>=len){
            errno=ENOSPC;
            return (NULL);
        }
        strcpy(strptr,temp);
        return (strptr);
    }
    errno=EAFNSUPPORT;
    return (NULL);
}
