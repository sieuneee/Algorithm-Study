#include <iostream>

using namespace std;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main(){
    int n, m;
    int r, c, d;
    int arr[50][50];
    
    cin >> n >> m;
    cin >> r >> c >> d;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    
    int cnt = 0;
    while(1){
        if(arr[r][c]==0) {
            arr[r][c] = 2;
            cnt ++;
        }
        bool flag = false;
        for(int i=0;i<4;i++){
            if(arr[r+dir[i][0]][c+dir[i][1]]==0){
                flag = true;
            }
        }
        if(flag){
            d--;
            if(d<0) d = 3;
            
            if(arr[r+dir[d][0]][c+dir[d][1]]==0) {
                r += dir[d][0];
                c += dir[d][1];
            }
        } else {
            int back = d+2;
            if(back>=4) back -= 4;
            if (arr[r+dir[back][0]][c+dir[back][1]]==1){
                break;
            } else {
                r += dir[back][0];
                c += dir[back][1];
            }
        }
    }
    
    cout << cnt;
    
    return 0;
}
