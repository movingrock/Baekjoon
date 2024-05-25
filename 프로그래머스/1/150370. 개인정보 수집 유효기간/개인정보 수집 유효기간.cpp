#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, string> m;
    vector<pair<string, string>> v;
    for(int i =0; i<terms.size(); i++){
        istringstream iss(terms[i]);
        string buffer;
        vector<string> result;

        while(getline(iss, buffer, ' ')) {
        	result.push_back(buffer);
        }
        m.insert({result[0], result[1]});
    }
    
    for(int i=0; i<privacies.size(); i++){
        istringstream iss(privacies[i]);
        string buffer;
        vector<string> result;

        while(getline(iss, buffer, ' ')) {
        	result.push_back(buffer);
        }
        v.push_back({result[0], result[1]});
    }
    
    // 오늘 날짜
    int tyear = stoi(today.substr(0, 4));
    int tmonth = stoi(today.substr(5, 2));
    int tday = stoi(today.substr(8,2));
    
    for(int i=0; i<v.size(); i++){
        string date = v[i].first;
        // 유효기간 계산
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8,2)) - 1;
        int limit = stoi(m[v[i].second]);
        month += limit;
        
        if(day == 0) {
            month-=1;
            if(month == 0){
                year--;
                month = 12;
            }
            day = 28;
        }
        
        while(month > 12){
            year++;
            month -= 12;
        }
        
        // cout << year << " " << month << " " << day << endl;
        
        // 파기 해야되는거 today보다 작을때
        if(year < tyear){
            answer.push_back(i+1);
        }else if(year == tyear){
            if(month < tmonth){
                answer.push_back(i+1);
            }
            else if(tmonth == month){
                if(day < tday){
                    answer.push_back(i+1);     
                }
            }
        }
        
    }
    
    return answer;
}