#include<iostream>

using namespace std;

int n;
int arr[15][2];

int maxValue = 0;

void sol(int a[15], int idx){
    if(idx >= n) {
        int val = 0;
        for(int i=0;i<n;i++){
            if(a[i]==1) val+=arr[i][1];
        }
        if(val > maxValue) maxValue = val;
        
        return;
    }

    if(arr[idx][0] + idx <= n) {
        int newA[15];
        for(int i=0;i<n;i++) newA[i] = a[i];
        newA[idx] = 1;
        sol(newA, idx+arr[idx][0]);
    }
    sol(a, idx+1);
}

int main(){
    cin >> n;
    int a[15];
    
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
        a[i] = 0;
    }

    sol(a, 0);

    cout << maxValue ;
    
    return 0;
}
