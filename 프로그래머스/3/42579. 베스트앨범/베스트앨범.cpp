#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> p1, pair<int, string> p2){
    if(p1.first == p2.first) p1.second < p2.second;
    
    return p1.first > p2.first;
}

bool cmp2(pair<int, int> p1, pair<int, int> p2){
    if(p1.first == p2.first) p1.second < p2.second;
    
    return p1.first > p2.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    map<string, int> m;
    for(int i = 0; i<genres.size(); i++){
        if(m.find(genres[i]) == m.end()) m.insert({genres[i], plays[i]});
        else m[genres[i]] += plays[i];
    }
    vector<pair<int, string>> sum;
    
    for(auto iter = m.begin(); iter != m.end(); iter++){
        sum.push_back(make_pair(iter->second, iter->first));
    }
    sort(sum.begin(), sum.end(), cmp);
    
    // for(int i= 0; i<sum.size(); i++){
    //     cout << sum[i].first << " " << sum[i].second << endl;
    // }
    
    for(int i = 0; i<sum.size(); i++){
        vector<pair<int, int>> bestTwo; // 횟수 genres에서의 번호
        for(int j = 0; j<genres.size(); j++){
            if(sum[i].second == genres[j]) bestTwo.push_back(make_pair(plays[j], j));
        }
        sort(bestTwo.begin(), bestTwo.end(), cmp2);
        if(bestTwo.size() == 1) answer.push_back(bestTwo[0].second);
        else {
            answer.push_back(bestTwo[0].second);
            answer.push_back(bestTwo[1].second);
            }
    }
    
    return answer;
}

// 장르별로 합 구하기
// 이름이랑 합 pair

// classic 인거 0 2 3
// 500 150 800 
// 위 아래 pair로 묶어서
// 재생수대로 내림차순
// 앞에 두개의 번호 출력 번호는 오름차순(번호 작은게 먼저 되게)