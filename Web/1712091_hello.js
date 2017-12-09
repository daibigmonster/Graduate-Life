'use strict'
var  name = 'Dai Jian';
console.log(`Hello,${name}!`);

var xiaoyang = {
    name : '小羊羊',
    birth : 1991,
    school : 'Songlei Middle school',
    height : 1.75,
    weitght : 58,
    score : 95

};

console.log(xiaoyang.name);
console.log(xiaoyang.birth);
console.log(xiaoyang.school);
console.log(xiaoyang.weitght);

var arry = ['dai','guan','baidu','alibaba','tencent']
for(var key in arry){
    console.log(key);
    console.log(arry[key]);
}

var m = new Map([[1, 'x'], [2, 'y'], [3, 'z']]);
m.forEach(function (value, key, map) {
    console.log(value + key);
});
