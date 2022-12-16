#include <bits/stdc++.h>
using namespace std;
struct LRU_node{
	int key, value;
};
bool cmp(const LRU_node &a, const LRU_node &b){
	return a.key > b.key;
}
struct LRU{
	int arr[105];
	vector<LRU_node>vec;
	int vids[105];
	void Init(){
		memset(vids, 0, sizeof(vids));
		memset(arr, 0, sizeof(arr));
		vec.clear();
	}
	void slove(){
		int n, m;
		printf("please input scanf value and lru capacitiy:");
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i ++){
			scanf("%d", &arr[i]);
		}
		int flag = 0;
		int r = 0;
		while(r < n){
			LRU_node a;
			a.key = r;
			a.value = arr[r];
			if(!vids[a.value]){
				flag ++;
				printf("*: ");
				if(vec.size() < m){
					vec.push_back(a);
					vids[a.value] ++;
					sort(vec.begin(), vec.end(), cmp);
				}
				else{
					sort(vec.begin(), vec.end(), cmp);
					LRU_node en = vec[vec.size() - 1];
					vids[en.value] --;
					vec.pop_back();
					vec.push_back(a);
					vids[a.value] ++;
					sort(vec.begin(), vec.end(), cmp);
				}
				for(int i = 0; i < vec.size(); i ++){
					printf("%d ", vec[i].value);
				}
				printf("\n");
			}
			else{
				for(int i = 0; i < vec.size(); i ++){
					if(vec[i].value == a.value){
						vec[i].key = a.key;
						break;
					}
				}
				sort(vec.begin(), vec.end(), cmp);
				for(int i = 0; i < vec.size(); i ++){
					printf("%d ", vec[i].value);
				}
				printf("\n");
			}
			r ++;
		}
		printf("Number of page breaks = %d Total number of visits = %d\n", flag, n);
		printf("f = %lf\n", double(flag) / double(n));
	}
}l;
int main(){
	l.Init();
	l.slove();
	return 0;
}
