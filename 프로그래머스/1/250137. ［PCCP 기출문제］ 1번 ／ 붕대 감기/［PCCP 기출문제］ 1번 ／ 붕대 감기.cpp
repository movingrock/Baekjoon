#include <string>
#include <vector>
#include <iostream>

using namespace std;

int heal(int health, int maxHealth, int flag, int amount) {
    // 공격 당했을때    
    if(flag == 0){
        if(health - amount > 0){
            health -= amount;
        }else {
            health = -1;
        }
    }else {
        // 공격당하지 않아 체력회복
        if(health + amount < maxHealth){
            health += amount;
        }else {
            health = maxHealth;
        }
    }
    return health;
}

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int lastTime = attacks[attacks.size()-1][0];
    int cnt = 0;
    int attackCnt = 0;
    int bandageCnt = 0;
    
    int maxHealth  = health;
    
    while(cnt<=lastTime){
        // 공격당함
        if(attacks[attackCnt][0] == cnt) {
            health = heal(health, maxHealth, 0, attacks[attackCnt][1]);
            bandageCnt = 0;
            attackCnt++;

        }else{
            health = heal(health, maxHealth, 1, bandage[1]);
            bandageCnt++;
            if(bandageCnt == bandage[0]){
                bandageCnt = 0;
                health = heal(health, maxHealth, 1, bandage[2]);
            }
        }
        
        if(health == -1) break;
        
        cnt++;
    }
    
    answer = health;
    
    return answer;
}