#include<iostream>
#include <string>
using namespace std;

char makeAscii(int n){
 	if(n>=65 && n<=91) return (char)n;
    else return n;
}

int make10bit(string str, int x){
    int ans = 0;
    int cnt = 64;
    for(int i = x+1; i<x+8; i++){
        ans += (str[i] - '0') * cnt;
        cnt /= 2;
    }
    return ans;
}

string make6bit(int n) {
    string ans = "";
    string tmp = "";
    while(n != 0){
        tmp += to_string(n%2);
        n /= 2;
    }
    while(tmp.length() <6){
     	tmp += '0';   
    }

    for(int i = 0; i<tmp.length(); i++){
    	ans += tmp[tmp.length() - 1 -i];  
    }
    return ans;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		string str;
        cin >> str;
        string ans = "";
        
        for(int i= 0; i<str.length();  i++){
            if(str[i] >= 'A' && str[i] <='Z') ans += make6bit(str[i] - 'A');
            else if(str[i] >= 'a' && str[i] <='z') ans += make6bit(str[i] - 'a' + 26);
            else if(str[i] >= '0' && str[i] <= '9') ans += make6bit(str[i] - '0' + 52);
            else if(str[i] == '+') ans += make6bit(62);
            else if(str[i] == '-') ans += make6bit(63);
        }

        string realAnswer = "";
        for(int i= 0; i<ans.length(); i += 8){
        	realAnswer += makeAscii(make10bit(ans, i));
        }
        cout << "#" << test_case << " " << realAnswer << endl;
	}
	return 0;
}



