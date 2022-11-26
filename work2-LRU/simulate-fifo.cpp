#include<iostream>
using namespace std;  

#define Max1 25  
#define Max2 15  

int saveCount[Max1][Max1];  
int x_save, y_save;  
int now_couont = 0;  

struct pt {  
	int pno;     
	int bno;     
	int flag;     
	int order;    
};  

void input(int *a, int n)  
{  
	for (int i = 0; i < n; i++) {  
		cin >> *a;  
		a++;  
	}  
}  

void output(int *a, int n)  
{  
	for (int i = 0; i < n; i++) {  
		cout << *a << ' ';  
		a++;  
	}  
	cout << '\n';  
}  

void fifo(int*List_pages, int*bs, int n, int m)  
{  
	pt ptlist[Max1];  


	int k = 0, flag, cn = 0, i, j;  
	for (j = 0; j < m; j++)
	{   
		bs[j] = -100;  
	}  

	for (i = 0; i < n; i++)  
	{  
		flag = 0;  
		for (j = 0; j < m; j++)  
			if (List_pages[i] == bs[j]) {  
				flag = 1;  
				break;  
			}  

		if (flag == 1)  
		{  
			if (i >= m) {   
				ptlist[i].bno = j + 1;  
				ptlist[i].flag = 1;   
				ptlist[i].pno = List_pages[i];  
			}  
			else { 
				ptlist[i].flag = 0;  
				ptlist[i].pno = List_pages[i];  
				bs[k] = List_pages[i];
				ptlist[i].bno = k + 1;  
				k = (k + 1) % m;  
				cn++;  
			}  
		}  
		else {   
			ptlist[i].flag = 0;  
			ptlist[i].pno = List_pages[i];  

			bs[k] = List_pages[i];
			ptlist[i].bno = k + 1;  
			k = (k + 1) % m;  
			cn++;  
		}  

		cout << "第 " << i << "次进入 \n";  
		for (int i = 0; i < m; i++)  
		{  
			saveCount[now_couont][i] = bs[i];  
		}  
		now_couont++;  
	}  
	cout << "计算结果：\n";  
	cout << "---------------------------------------------------------------------\n";  
	cout << "缺页个数：" << '\t' << cn << '\n';  
	cout << "---------------------------------------------------------------------\n";  
	cout << "访问次数：" << '\t' << n << '\n';  
	cout << "---------------------------------------------------------------------\n";  
	cout << "缺页率为：" << '\t' << (float)cn / n << '\n';  
	cout << "---------------------------------------------------------------------\n";  
	cout << "操作顺序：\n";  
	cout << "---------------------------------------------------------------------\n";  
	for (i = 0; i < m; i++)  
	{  
		cout << List_pages[i] << "\t!!缺页,还未存入!!\t" << "现已直接存入内存块!\t" << ptlist[i].bno << '\n';  
		cout << "本次序列： >>>>>  ";  
		for (int j = 0; j < y_save; j++)  
		{  
			if (saveCount[i][j] != -1 && saveCount[i][j] != -100)  
				cout << saveCount[i][j] << ' ';  
		}  
		cout << endl;  
		cout << "---------------------------------------------------------------------\n";  
	}  
	for (i = m; i < n; i++)  
	{  
		if (ptlist[i].flag == 0)  
			cout << List_pages[i] << "\t!!缺页,还未存入!!\t" << "操作：调出块号为：" << ptlist[i].bno << "--页号为" << ptlist[i].pno << "的进程" << '\n';  
		else  
			cout << List_pages[i] << "\t!!命中,已经存入!!\t" << "操作：查询块号为：" << ptlist[i].bno << "--页号为" << ptlist[i].pno << "的进程" << '\n';  
		cout << "本次序列： >>>>>  ";  
		for (int j = 0; j < y_save; j++)  
		{  
			if (saveCount[i][j] != -1 && saveCount[i][j] != -100)  
				cout << saveCount[i][j] << ' ';  
		}  
		cout << endl;  
		cout << "---------------------------------------------------------------------\n";  
	}  

}  

void initGroup(int x , int y)  
{  
	x_save = x;  
	y_save = y;  
	for (int i = 0; i < Max1; i++)  
		for (int j = 0; j < Max1; j++)  
			saveCount[i][j] = -1;  
}  

int main()  
{  
	int List_pages[Max1], bs[Max1];  
	int n, m;  

	cout << "输入内存块大小：\n";  
	cin >> m;  
	cout << "输入序列个数：\n";  
	cin >> n;  
	initGroup(n, m);  

	cout << "请输入访问序列：\n";  
	input(List_pages, n);  
	cout << "访问序列：" << endl;  
	output(List_pages, n);  
	cout << "---------------------------------------------------------------------\n";  
	cout << '\n';  
	fifo(List_pages, bs, n, m);  
	return 0;
}
