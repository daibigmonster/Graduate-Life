import requests
headers={
	'Cookie':'_zap=e0f0ef95-ac34-4022-a70e-467e7dd79d0e; __utma=51854390.357622983.1504531780.1504876739.1505484455.4; __utmz=51854390.1505484455.4.4.utmcsr=zhihu.com|utmccn=(referral)|utmcmd=referral|utmcct=/; __utmv=51854390.100-1|2=registration_date=20130802=1^3=entry_date=20130802=1; q_c1=513505d2d1d649e884d7dab78d017ff7|1504532723000|1504532723000; r_cap_id="MDgyMGY1NTAxMjVhNGQ3NDlkZTAxYjA5YzIzNmQ0MzY=|1504532723|11d7046956c898dff63b4fce0ec896dbe8359ddf"; cap_id="Y2QzODdjZWUxYmZhNDEwMzlkMzEwOGEyZTU1YTdkMGE=|1504532723|6cc6209fb39f74b91356d849e168a86b735da907"; d_c0="ADACKIlcUwyPTtL4jAH0DKicPKodjAt_tWM=|1504532723"; z_c0=Mi4xLXkwU0FBQUFBQUFBTUFJb2lWeFREQmNBQUFCaEFsVk4tdWZVV1FEWXFfdFNRcUZOWGVUSGI2THdZMWZFZGZheDRR|1504533242|75e4acd8729575cdea918d3186eceed651596346; aliyungf_tc=AQAAAKdGZwG7dgkAUhmme6fiBRcVYT1Q; _xsrf=f975a525-c61c-4670-96ef-ada7c7a0cd28; __utmb=51854390.0.10.1505484455; __utmc=51854390',
	'Host':'www.zhihu.com',
	'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/53.0.2785.116 Safari/537.36',}
r=requests.get('https://www.zhihu.com',headers=headers)
print(r.text)

