#include<iostream>

using namespace std;

int main(){
    int n, b, c;
    int arr[1000000];
    
    long ret = 0;
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> b >> c;
    
    
    ret += n;
    for(int i=0;i<n;i++){
        if(arr[i]-b <= 0) continue;
        if((arr[i]-b)%c!=0) {
            ret += ((arr[i]-b)/c+1);
        } else {
            ret += (arr[i]-b)/c;
        }
    }
    
    cout << ret;
    
    return 0;
}
