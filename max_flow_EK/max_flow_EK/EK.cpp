 /*
 ��������Edmonds-Karp�㷨������������ʱ��ʹ��BFS�㷨
 Ford-Fulkerson�㷨ʹ�õ���DFS�㷨
 */

#include <iostream>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring> 
#include <math.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f
#define maxn 100

int n, m, st, en, flow[maxn][maxn], pre[maxn];
int q[maxn], curr_pos, st_pos, end_pos;
bool wh[maxn];
int max_flow;

void Init()//��ʼ��
{
	int i, a, b, c;
	printf("��������������ͼ��������ݣ�����ͼ���ܵ���,�ܱ����������(һ���0��ʼ)���յ��ţ����Կո����\n");
	scanf_s("%d%d%d%d", &n, &m, &st, &en);
	printf("��������ߵ�������յ��ţ��Լ�����Ȩֵ�����Կո����\n");
	for (i = 0; i != m; ++i)
	{
		scanf("%d%d%d", &a, &b, &c);
		flow[a][b] += c;
	}
	return;
}

bool Bfs(int st, int en)//������Դ��
{
	st_pos = -1, end_pos = 0;
	memset(wh, 0, sizeof wh);
	wh[st] = 1;
	q[0] = st;
	while (st_pos != end_pos)
	{
		curr_pos = q[++st_pos];
		for (int i = 1; i != n + 1; ++i)
		{
			if (!wh[i] && flow[curr_pos][i] > 0)
			{
				wh[i] = 1;
				pre[i] = curr_pos;
				if (i == en)
				{
					return true;
					
				}
				q[++end_pos] = i;
			}
		}
	}
	 
	return false;
}

int EK(int start_pos, int end_pos)
{
	int i, minn;
	printf("����ͼ��Ѱ�ҵ��������·����Ϊ:\n");
	while (Bfs(start_pos, end_pos))//����
	{
		minn = INF;

		for (i = end_pos; i != start_pos; i = pre[i])
		{
			minn = min(minn, flow[pre[i]][i]);
		}
		

		printf("%d", end_pos);
		for (i = end_pos; i != start_pos; i = pre[i])
		{
			printf(" %d", pre[i]);
		}
		printf("\n");

		for (i = end_pos; i != start_pos; i = pre[i])
		{
			flow[pre[i]][i] -= minn;
			//flow[i][pre[i]] += minn;//���򻡼��ϸ�ֵ������ԭ��������⣩
		}
		max_flow += minn;
	}
	return max_flow;
}

int main()
{

	//freopen("test.in", "r", stdin);
	//freopen("test.out", "w", stdout);

	Init();
	printf("\n���������Ϊ:%d\n", EK(st, en));
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
/*
�ڸ��ļ���������Ӧ�Ĳ��԰�������ͼ�ļ���
�������ݸ�ʽ��
8 9 0 7
0 1 1
0 3 3
0 5 6
1 2 2
3 4 5
5 6 4
2 7 4
4 7 3
6 7 2


*/

