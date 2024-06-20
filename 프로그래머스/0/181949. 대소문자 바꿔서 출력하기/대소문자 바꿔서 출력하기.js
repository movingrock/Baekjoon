const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    
    newStr = "";
    
    for(let i =0 ; i<str.length; i++){
        if(str[i].charCodeAt() >= 65 && str[i].charCodeAt() <97) newStr +=(String.fromCharCode(str[i].charCodeAt()+32));
        else newStr += (String.fromCharCode(str[i].charCodeAt()-32));
    }
    console.log(newStr);
});