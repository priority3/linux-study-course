#include <bits/stdc++.h>
using namespace std;
/**
 *  * LRU算法的实现：可以使用一个结构体，来储存对应的数据
 *   * 那么使用一个vector动态数组来储存当前的物理块中的内容
 *    * 那么每访问一次就更新结构体中的value值，那么对vector数组
 *     * 进行对应sort排序,即按照value从大到小排序，然后每次弹出队尾
 *      * 将最小的value值的结构体弹出
 *       * 测试数据如下 
 *       16 4
 *       0 1 2 4 3 4 5 1 2 5 1 2 3 4 5 6
 *        * **/
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
