'use strict'
var  name = 'Dai Jian';
console.log(`Hello,${name}!`);

// function foo(a,b) {
//     var i ,rest = [];
//     if(arguments.length > 2){
//         for(i = 2;i < arguments.length;i++){
//             rest.push(arguments[i]);
//         }
//     }
//     console.log('a = ' + a);
//     console.log('b = ' + b);
//     console.log(rest);
    
// }

// foo(1,2,3,4,5)

function ex2(a,b,...rest) {
    console.log('a = ' + a);
    console.log('b = ' + b);
    console.log(rest);
}

ex2(1,2,3,4,5)


// function sum(...rest) {
//     var n = 0;
//     for (var x of rest){
//         n += x;
//     }
//     console.log(n);
// }

// sum(1,2,3,4,5);

var person = {
    name: '小明',
    gender: 'male',
    passport: 'G-12345678',
    school: 'No.4 middle school',
    address: {
        city: 'Beijing',
        street: 'No.1 Road',
        zipcode: '100001'
    },
    birth : 1989,
    age : function () {
        var y = new Date().getFullYear();
        return y - this.birth;        
    }
};
var { name, address: { city, zipcode } } = person;
console.log(name);
console.log(city);
console.log(zipcode);
console.log(person.age())

var winthis = this;
function getAge() {
    var y = new Date().getFullYear();
    return y - this.birth;
}

var xiaoming = {
    name: '小明',
    birth: 1990,
    age: getAge
};