#include <iostream>

using namespace std;

int n;

int sol(int arr[20][20], int cnt, int type){
    int newarr[20][20];
    if(n==1) return arr[0][0];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            newarr[i][j] = 0;
        }
    }
    
    bool chk = false;
    
    if(type == 0){
        //up
        for(int j=0;j<n;j++){
            int idx = 0;
            for(int i=0;i<n;i++){
                if(arr[i][j]==0) continue;
                else if(newarr[idx][j] == arr[i][j] && chk==false) {
                    newarr[idx][j] += arr[i][j];
                    chk=true;
                } else {
                    if(idx!=0 || newarr[idx][j]!=0) idx++;
                    newarr[idx][j] = arr[i][j];
                    chk=false;
                }
            }
        }
        
    } else if (type == 1){
        //right
        for(int i=0;i<n;i++){
            int idx = n-1;
            for(int j=n-1;j>=0;j--){
                if(arr[i][j]==0) continue;
                if(newarr[i][idx] == arr[i][j] && chk==false ){
                    newarr[i][idx] += arr[i][j];
                    chk=true;
                } else{
                    if(idx!=n-1 || newarr[i][idx]!=0) idx--;
                    newarr[i][idx] = arr[i][j];
                    chk=false;
                }
            }
        }
        
    } else if (type == 2){
        //down
        for(int j=0;j<n;j++){
            int idx = n-1;
            for(int i=n-1;i>=0;i--){
                if(arr[i][j]==0) continue;
                if(newarr[idx][j] == arr[i][j] && chk==false ) {
                    newarr[idx][j] += arr[i][j];
                    chk=true;
                } else {
                    if(idx!=n-1 || newarr[idx][j]!=0) idx--;
                    newarr[idx][j] = arr[i][j];
                    chk=false;
                }
            }
        }
        
    } else {
        //left
        for(int i=0;i<n;i++){
            int idx = 0;
            for(int j=0;j<n;j++){
                if(arr[i][j]==0) continue;
                if(newarr[i][idx] == arr[i][j] && chk==false ){
                    newarr[i][idx] += arr[i][j];
                    chk=true;
                } else {
                    if(idx!=0 || newarr[i][idx]!=0) idx++;
                    newarr[i][idx] = arr[i][j];
                    chk=false;
                }
            }
        }
    }
    
    int max = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++){
            if(newarr[i][j] > max) max = newarr[i][j];
        }
    }
    
    if(cnt < 5) {
        for(int i=0;i<4;i++){
            int ret = sol(newarr, cnt+1, i);
            if(max < ret) max = ret;
        }
    }
    
    return max;
}

int main(){
    int arr[20][20];
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    int max = 0;
    for(int i=0;i<4;i++){
        int ret = sol(arr, 1, i);
        if(max < ret) max = ret;
    }
    
    cout << max;
    
    
    return 0;
}
