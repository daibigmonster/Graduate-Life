'use strict';
var a = ['daijian','guanboyang','google','baidu']
var i, x = 1;
for (i = 1; i < 11; i++) {
    x *= i;
}
console.log(x);
for(var key of a){
    console.log(`Hello,${key}!`);
}