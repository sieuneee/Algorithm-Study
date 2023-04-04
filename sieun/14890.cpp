#include <iostream>

using namespace std;

int n, l;
int arr[100][100];

bool sol(int idx, int type){
    int a[100];
    int check[100];

    for(int i=0;i<n;i++){
        if(type==0){
            a[i] = arr[idx][i];
        } else {
            a[i] = arr[i][idx];
        }
        check[i] = 0;
    }
    
    int now = a[0];

    for(int i=1;i<n;i++){
        if(a[i]==now) {
            continue;
        } else if (a[i]==now+1) {
            if(i-l<0) {
                return false;
            }
            for(int j=i-1;j>=i-l;j--){
                if(a[j]!=now || check[j]==1) {
                    return false;
                }
                check[j] = 1;
            }
            now++;
        } else if (a[i]==now-1) {
            if(i+l > n) {
                return false;
            }
            for(int j=i;j<i+l;j++){
                if(a[j]!=now-1 || check[j]==1) {
                    return false;
                }
                check[j] = 1;
            }
            now--;
            i += (l-1);
        } else {
            return false;
        }
    }
 
    
    return true;
    
}


int main(){
    
    cin >> n >> l;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(sol(i, 0)) cnt++;
        if(sol(i, 1)) cnt++;
    }
    
    cout << cnt ;
    
    return 0;
}
