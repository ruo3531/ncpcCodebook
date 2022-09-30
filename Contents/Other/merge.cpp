#include<bits/stdc++.h>
using namespace std;

#define M 100010
// int cnt = 0;
void printarr(int arr[],int l,int r){
    for(int i=l;i<=r;i++){
        printf(" %d",arr[i]);
    }
    puts("");
}

int merge(int arr[], int l, int r, int mid){
    int L = l, R = mid+1;
    int tmplen = r-l+1, tmpi = 0;
    int tmp[M]={0};
	int cnt = 0;
    while(L <= mid && R <= r){
        if(arr[L]<=arr[R]){
            tmp[tmpi]=arr[L];
            L++;
        }
        else{
            tmp[tmpi]=arr[R];
			cnt += mid-L+1;
            R++;
        }
        tmpi++;
    }
    if(L>mid){
        while(R<=r){
            tmp[tmpi]=arr[R];
            R++;
            tmpi++;
        }
    }
    else{
        while(L<=mid){
            tmp[tmpi]=arr[L];
            L++;
            tmpi++;
        }
    }
    //L>mid&&R>r才可以全部跑過
    L=l;
    for (tmpi=0; tmpi<tmplen; tmpi++) {
        arr[L] = tmp[tmpi];
        L++;
    }

	// printf("%d %d %d:",l,mid,r);
    // printarr(arr,l,r);
	return cnt;
}

int mergeSort(int arr[],int l,int r){
	if(r <= l) return 0;
	int mid=(l+r)/2;
	int cnt = 0;
	cnt += mergeSort(arr, l, mid);
	cnt += mergeSort(arr, mid+1, r);
	cnt += merge(arr, l, r, mid);
    return cnt;
}

int main(){
	int n;
	while(cin >> n){
		if(n == 0) break;
		int arr[M] = {0};
		for(int i = 0; i < n; i++){
			cin >> arr[i];
		}
		if(mergeSort(arr, 0, n-1)%2) cout << "Marcelo\n";
		else cout << "Carlos\n";
	}
	
}