import java.util.*;

class Solution {
    int answer = 0;
    
    public int solution(int[] numbers, int target) {
        System.out.println(numbers.length);
        dfs(0, 0, numbers, target);
        
        return answer;
    }
    
    public void dfs(int index, int sum, int[] numbers, int target){
        if(index == numbers.length && sum == target) answer++;
        if(index >= numbers.length) return;
        
        dfs(index+1, sum + numbers[index], numbers, target);
        dfs(index+1 , sum - numbers[index], numbers, target);
    }
}