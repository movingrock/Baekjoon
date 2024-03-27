#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i= 0; i<participant.size(); i++){
        if(m.find(participant[i]) == m.end()) m[participant[i]]++;
        else m[participant[i]]++;
    }
    
    for(int i = 0; i<completion.size(); i++){
        if(m.find(completion[i]) != m.end()) m[completion[i]]--;
    }
    
    for (auto iter = m.begin() ; iter !=  m.end(); iter++)
    {
        if(iter->second > 0) answer = iter->first;
    }

    return answer;
}