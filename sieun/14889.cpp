#include <iostream>
#define MAX_VAL 361000

using namespace std;

int n;
int arr[20][20];
int minDiff = MAX_VAL;

int cal(int check[20]){
    int aIdx = 0, bIdx = 0;
    int arrA[10];
    int arrB[10];
    
    for(int i=0;i<n;i++){
        if(check[i]==1){
            arrA[aIdx] = i; aIdx++;
        } else {
            arrB[bIdx] = i; bIdx++;
        }
    }
    
    int a = 0, b = 0;
    for(int i=0;i<n/2;i++){
        for(int j=i;j<n/2;j++){
            a += arr[arrA[i]][arrA[j]] + arr[arrA[j]][arrA[i]];
            b += arr[arrB[i]][arrB[j]] + arr[arrB[j]][arrB[i]];
        }
    }
    
    if(a<=b){
        return b-a;
    } else {
        return a-b;
    }
}


void sol(int ck[20], int idx, int cnt){
//    cout <<idx << " " << cnt << endl;
    if(cnt >= n/2){
        int val = cal(ck);
//        cout << "val : " << val << endl;
        if(val < minDiff) minDiff = val;
        return ;
    }
    if(idx >= n) return;
    

    sol(ck, idx+1, cnt);
    
    int newCk[20];
    for(int i=0;i<n;i++) {
        newCk[i] = ck[i];
    }
    newCk[idx] = 1;
    sol(newCk, idx+1, cnt+1);
    
}


int main(){
    
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    
    int ck[20];
    for(int i=0;i<n;i++){
        ck[i] = 0;
    }
    sol(ck, 1, 0);
    
    int newCk[20];
    for(int i=0;i<n;i++) newCk[i] = ck[i];
    newCk[0] = 1;
    sol(newCk, 1, 1);
    
    cout << minDiff;
    
    return 0;
}
