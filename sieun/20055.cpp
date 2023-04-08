#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    int arr[201]; // 벨트 내구도
    int visit[201]; // 벨트 로봇 유무
    
    cin >> n >> k;
    for(int i=0;i<2*n;i++){
        cin >> arr[i];
        visit[i] = 0;
    }
    
    bool flag = true;
    int step = 0;
    int start = 0;
    int end = (start+n)%(n*2);
    
    while(flag){
        step++;
        
        //step 1
        start --;
        if(start<0) start+=2*n;
        end = (start+n-1)%(n*2);
        if(visit[end]==1) visit[end] = 0;
        
        //step 2
        for(int i=1;i<n;i++){
            int idx = end-i;
            if(idx<0) idx += 2*n;
            int next = (idx+1)%(2*n);

            if(visit[idx]==1 && arr[next]>0 && visit[next]==0){
                visit[idx]=0;
                visit[next]=1;
                arr[next]--;
            }
        }
        if(visit[end]==1) visit[end] = 0;
        
        //step 3
        if(arr[start]>0) {
            visit[start]=1;
            arr[start]--;
        }
        
        //step 4
        int cnt = 0;
        for(int i=0;i<n*2;i++){
            if(arr[i]==0) cnt++;
            if(cnt>=k) {
                flag = false;
                break;
            }
        }
    }
    
    cout << step;
    
    return 0;
}
