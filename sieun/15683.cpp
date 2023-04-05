#include <iostream>

using namespace std;

int n, m;
int arr[9][9];

int minVal = 64;
int idx=0;
int cctv[9][3];


void move(int newArr[9][9], int y, int x, int type){
    if(type==0){ // up
        for(int i=y;i>=0;i--){
            if(newArr[i][x]==6) return;
            if(newArr[i][x]==0) {
                newArr[i][x] = -1;
            }
        }
    }else if(type==1){ // right
        for(int i=x;i<m;i++){
            if(newArr[y][i]==6) return;
            if(newArr[y][i]==0) {
                newArr[y][i] = -1;
            }
        }
    } else if(type==2){ // down
        for(int i=y;i<n;i++){
            if(newArr[i][x]==6) return;
            if(newArr[i][x]==0) {
                newArr[i][x] = -1;
            }
        }
    } else { // left
        for(int i=x;i>=0;i--){
            if(newArr[y][i]==6) return;
            if(newArr[y][i]==0) {
                newArr[y][i] = -1;
            }
        }
    }
    return;
}


void cal(int chk[9]){
    int newArr[9][9];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            newArr[i][j] = arr[i][j];
        }
    }
    
    for(int i=0;i<idx;i++){
        if(cctv[i][0]==1){
            move(newArr, cctv[i][1], cctv[i][2], chk[i]);
        } else if (cctv[i][0]==2){
            move(newArr, cctv[i][1], cctv[i][2], chk[i]);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+2)%4);
        } else if (cctv[i][0]==3){
            move(newArr, cctv[i][1], cctv[i][2], chk[i]);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+1)%4);
        } else if (cctv[i][0]==4) {
            move(newArr, cctv[i][1], cctv[i][2], chk[i]);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+1)%4);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+3)%4);
        } else {
            move(newArr, cctv[i][1], cctv[i][2], chk[i]);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+1)%4);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+2)%4);
            move(newArr, cctv[i][1], cctv[i][2], (chk[i]+3)%4);
        }
    }
    
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(newArr[i][j]==0) {
                cnt ++;
            }
        }
    }
    if(cnt < minVal) minVal = cnt;
    return;
}


void sol(int chk[9], int num){
    if(num > idx) {
        cal(chk);
        return ;
    }
    
    int newChk[9];
    for(int i=0;i<idx;i++){
        newChk[i] = chk[i];
    }
    
    for(int i=0;i<4;i++){
        if(cctv[num][0]==2 && i>1) continue;
        if(cctv[num][0]==5 && i>0) continue;
        newChk[num] = i;
        sol(newChk, num+1);
    }
    
    return;
}


int main(){
    
    cin >> n >> m;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
            if(arr[i][j]!=0 && arr[i][j]!=6) {
                cctv[idx][0] = arr[i][j];
                cctv[idx][1] = i;
                cctv[idx][2] = j;
                idx++;
            }
        }
    }
    
    int chk[9];
    for(int i=0;i<idx;i++){
        chk[i] = 0;
    }
    
    for(int i=0;i<4;i++){
        if(cctv[0][0]==2 && i>1) continue;
        if(cctv[0][0]==5 && i>0) continue;
        chk[0] = i;
        sol(chk, 1);
    }
    
    
    cout << minVal;
    
    
    return 0;
}
