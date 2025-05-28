#include <string>
#include <vector>

using namespace std;

int toSec(string pos){
    int min = stoi(pos.substr(0, 2));
    int sec = stoi(pos.substr(3, 2));
    int time = min * 60 + sec;
    return time;
}

string toStr(int time) {
    int min = time / 60;
    int sec = time % 60;
    string pos = (min < 10 ? "0" : "") + to_string(min) + ":" + (sec < 10 ? "0" : "") + to_string(sec);
    return pos;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    int startSec = toSec(op_start);
    int endSec = toSec(op_end);
    int posSec = toSec(pos);
    int videoSec = toSec(video_len);
    
    for(int i =0; i<commands.size(); i++){
        if(posSec >= startSec && posSec <= endSec) posSec = endSec;
        if(commands[i] == "next"){
            if(posSec + 10 >= videoSec) posSec = videoSec;
            else posSec += 10;
        }else{
            if(posSec - 10 <= 0) posSec = 0;
            else posSec -= 10;
        }
    }
    
    if(posSec >= startSec && posSec <= endSec) posSec = endSec;
    
    answer = toStr(posSec);
    
    return answer;
}