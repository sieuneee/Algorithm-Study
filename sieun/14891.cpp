#include <iostream>

using namespace std;


int arr[4][8];
int n;

void rotation(int num, int dir){
    if(dir==1) {
        int tmp = arr[num][7];
        for(int i=7;i>0;i--){
            arr[num][i] = arr[num][i-1];
        }
        arr[num][0] = tmp;
    } else {
        int tmp = arr[num][0];
        for(int i=0;i<7;i++){
            arr[num][i] = arr[num][i+1];
        }
        arr[num][7] = tmp;
    }

    return;
}


void sol(int num, int dir){
    int chk[4] = {0, 0, 0, 0};
    chk[num] = dir;
    
    for(int i=num-1;i>=0;i--){
        if(arr[i][2]!=arr[i+1][6]) {
            chk[i] = chk[i+1]*-1;
        }
    }
    
    for(int i=num+1;i<4;i++){
        if(arr[i][6]!=arr[i-1][2]) {
            chk[i] = chk[i-1]*-1;
        }
    }
    
    for(int i=0;i<4;i++){
        if(chk[i]!=0){
            rotation(i, chk[i]);
        }
    }
    
    return;
}

int main(){
    
    for(int i=0;i<4;i++){
        for(int j=0;j<8;j++){
            char c;
            cin >> c;
            if(c=='0') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    
    cin >> n;
    for(int i=0;i<n;i++){
        int num, dir;
        cin >> num >> dir;
        sol(num-1, dir);
    }
    
    int score  = 0;
    if(arr[0][0]==1) score += 1;
    if(arr[1][0]==1) score += 2;
    if(arr[2][0]==1) score += 4;
    if(arr[3][0]==1) score += 8;
    
    cout << score;
    
    return 0;
}
