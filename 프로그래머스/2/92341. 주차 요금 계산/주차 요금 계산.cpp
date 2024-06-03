#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int Calculate(string start, string end){
    int time = 0;
    int hourS = stoi(start.substr(0, 2));
    int hourE = stoi(end.substr(0, 2));
    int minuteS = stoi(start.substr(3, 2));
    int minuteE = stoi(end.substr(3, 2));
    
    if(minuteE < minuteS){
        time += (60 - minuteS) + minuteE;
        time += (hourE - hourS - 1) * 60;
    }else{
        time += minuteE - minuteS;
        time += (hourE - hourS) * 60;
    }
    
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<string, string> m;
    
    map<string, int> car;
    
    for(int i =0; i<records.size(); i++){
        istringstream iss(records[i]);
        string buffer;
        vector<string> result;
        
        while(getline(iss, buffer, ' ')){
            result.push_back(buffer);
        }     
        
        if(result[2] == "IN"){
            m.insert({result[1], result[0]});
        }
        else if(result[2] == "OUT"){
            // 시간 돈 계산
            string start = m[result[1]];
            string end = result[0];
            int time = Calculate(start, end);
            m.erase(result[1]);
            if(car.find(result[1]) != car.end()) car[result[1]] += time;
            else car.insert({result[1], time});
        }
    }
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        int time = Calculate(iter->second, "23:59");
        if(car.find(iter->first) != car.end()) car[iter->first] += time;
        else car.insert({iter->first, time});
    }
    
    for(auto iter = car.begin(); iter != car.end(); iter++){
        int money = fees[1];
        int time = iter->second;
        if(time > fees[0]){
            time -= fees[0];
            money += (ceil( (double)time / (double)fees[2]) * fees[3]);
        }
        answer.push_back(money);
    }
    
    
    return answer;
}