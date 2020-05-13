#include<stdio.h>
#include<string.h>
#define inf 0x3f3f3f3f
int map[110][110], dis[110], visit[110];
/*
关于三个数组：map数组存的为点边的信息，比如map[1][2]=3，表示1号点和2号点的距离为3
dis数组存的为起始点与每个点的最短距离，比如dis[3]=5，表示起始点与3号点最短距离为5
visit数组存的为0或者1，1表示已经走过这个点。
*/
int n, m;
int dijstra()
{
	int i, j, pos = 1, min, sum = 0;
	memset(visit, 0, sizeof(visit));//初始化为.，表示开始都没走过
	for (i = 1; i <= n; ++i)
	{
		dis[i] = map[1][i];
	}
	visit[1] = 1;
	dis[1] = 0;
	for (i = 1; i<n; i++)
	{
		min = inf;
		for (j = 1; j <= n; ++j)
		{
			if (visit[j] == 0 && min>dis[j])
			{
				min = dis[j];
				pos = j;
			}
		}
		visit[pos] = 1;//表示这个点已经走过
		for (j = 1; j <= n; ++j)
		{
			if (visit[j] == 0 && dis[j]>dis[pos] + map[pos][j])//更新dis的值
				dis[j] = dis[pos] + map[pos][j];
		}
	}
	return dis[n];
}
int main()
{
	int i, j;
	while (~scanf("%d%d", &n, &m), n || m)//n表示n个点，m表示m条边
	{
		for (i = 1; i <= n; ++i)
		{
			for (j = 1; j <= n; ++j)
			{
				map[i][j] = inf;//开始时将每条边赋为最大值
			}
		}
		int a, b, c;
		for (i = 1; i <= m; ++i)
		{
			scanf("%d%d%d", &a, &b, &c);
			if (c<map[a][b])//防止有重边
				map[a][b] = map[b][a] = c;
		}
		int count = dijstra();
		printf("%d\n", count);
	}
	return 0;
}