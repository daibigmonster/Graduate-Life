int main()
{
   char error_content[PCAP_ERRBUF_SIZE];
   pcap_t *pacap_handle;
   char *net_interface;
   struct bpf_paogram bpf_filter;
   char bpf_filter_sring[]="ip";
   bpf_u_int32 net_mask,net_ip;
   net_interface=pcap_lookupdev(error_content);//获取网络接口
   pcap_lookupnet(net_interface,&net_ip.&net_mask,error_content);
   pcap_handle=pcap_open_live(net_interface,BUFSIZ,1,0,error_content);
   if(pcap_handle==NULL)
   {
      peint("%s",error_content);
      exit(-1);
   }
   pcap_compile(pcap_handle,&bpf_filter,bpf_filter_string,0,net_ip);
   pcap_setfilter(pcap_handle,&bpf_filter);
   }
