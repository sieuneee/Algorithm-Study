#include <iostream>
#define MAX_VALUE 100000000
#define MIN_VALUE -100000000
using namespace std;

int n;
int arr[100];

int minValue = MAX_VALUE;
int maxValue = MIN_VALUE;

int calculate(int a, int b, int type){
    if(type == 0){
        return a + b;
    } else if (type == 1){
        return a - b;
    } else if (type == 2){
        return a * b;
    } else {
        return a / b;
    }
}

void sol(int cal[4], int val, int idx){
    if(idx >= n-1){
        if(minValue > val) minValue = val;
        if(maxValue < val) maxValue = val;
        return ;
    }
  
    for(int i=0;i<4;i++){
        if(cal[i] > 0){
            int newCal[4];
            for(int i=0;i<4;i++){
                newCal[i] = cal[i];
            }
            newCal[i] -= 1;
            int newVal = calculate(val, arr[idx+1], i);
            sol(newCal, newVal, idx+1);
        }
    }
}

int main(){
    int cal[4];
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    for(int i=0;i<4;i++){
        cin >> cal[i];
    }

    for(int i=0;i<4;i++){
        if(cal[i] > 0){
            int newCal[4];
            for(int i=0;i<4;i++){
                newCal[i] = cal[i];
            }
            newCal[i]--;
            int val = calculate(arr[0], arr[1], i);
            sol(newCal, val, 1);
        }
    }
    
    cout << maxValue << endl << minValue << endl;
    
    
    return 0;
}
