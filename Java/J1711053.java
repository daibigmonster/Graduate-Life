/* 
 * 代理设计也是在Java开发中使用较多的一种设计模式，所谓的代理设计就是指
 * 有一个代理主题来操作真是主题，真是主题执行具体的业务操作，而代理主题
 * 负责其他相关业务的处理，就好像在生活中经常使用的代理上网一样，客户通过
 * 网络代理链接网络，由代理服务器完成用户权限和访问限制等与上网操作相关的
 * 操作
 */
interface Network{
	public void browse();
}
class Real implements Network{
	public void browse(){
		System.out.println("上网浏览信息");
	}
}

class Proxy implements Network{
	private Network network;
	public Proxy(Network network){
		this.network = network;
	}
}