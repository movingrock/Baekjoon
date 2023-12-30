#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int arr[100];
    int n;
    int v;
    int cnt = 0;
    
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }
    cin >> v;
    
    for(int i = 0; i<n; i++){
        if(v == arr[i]) cnt++;
    }
    cout << cnt;
    return 0;
}