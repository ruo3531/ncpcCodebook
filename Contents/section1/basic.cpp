// c++ code
std::ios::sync_with_stdio(false); // 加速

#include <bits/stdc++.h>
lower_bound(a, a + n, k);     //最左邊 ≥ k 的位置
upper_bound(a, a + n, k);     //最左邊 > k 的位置
upper_bound(a, a + n, k) - 1; //最右邊 ≤ k 的位置
lower_bound(a, a + n, k) - 1; //最右邊 < k 的位置
[lower_bound, upper_bound) //等於 k 的範圍
equal_range(a, a+n, k);

// 從小到大
priority_queue<int, vector<int>, greater<int>>pq

insert(it,x)//向vector的任意迭代器it處插入一個元素x
erase(it)//刪除迭代器爲it處的元素，erase(first,last)
//刪除一個區間[first,last)內的所有元素，時間複雜度均爲O(N)

set
insert(x)	//將x插入set中	O(log(n)) 
count(x)	//回傳x是否存在於set中()	O(log(n)) 
erase(x)	//刪除在set中的x	O(log(n)) 
clear()	//刪除set中所有元素	O(n)
empty()	//回傳是否為空	O(1)
size()	//回傳共有幾個元素	O(1)

map
insert(x)	//將x這個pair插入map中	O(log(n)) 
count(x)	//回傳x這個key是否在map中	O(log(n)) 
erase(x)	//刪除在map中key為x的	O(log(n)) 

double cnt = 3.5555;
cout << fixed << setprecision(3) << cnt ;
	
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	set<int>s;
	for(int i = 0; i < 10; i++){
		s.insert(i);
	}
	cout << "lower bound: " << *s.lower_bound(5) << '\n';// 5
	cout << "upper bound: " << *s.upper_bound(5) << '\n';// 6
 
	if(s.lower_bound(20) == s.end()){
		cout << "all elements are less than 20\n";
	}
}
