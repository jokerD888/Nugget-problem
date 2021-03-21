#define _CRT_SECURE_NO_WARNINGS 1


//老板有一袋金块（共n块，n是2的幂（n≥2））, 最优秀的雇员得到其中最重的一块，最差的雇员得到其中最轻的一块。
//假设有一台比较重量的仪器，希望用最少的比较次数找出最重和最轻的金块。并对自己的程序进行复杂性分析。
#include<stdio.h>
#include<stdio.h>
#include<assert.h>
//最小值                            自上而下二分                                   从递归出口自下而上return最小值    
//        8个           7.8  3.5  2.1  4.9  5.0  6.7  0.7  4.9                            0.7
//   分   4个         7.8  3.5  2.1 4.9         5.0 6.7   0.7 4.9                      2.1  0.7
//   分   2个       7.8  3.5     2.1  4.9      5.0  6.7    0.7  4.9             3.5  2.1      5.0 .07
//                   3.5          2.1            5.0         0.7                         
//最大值类似
float Min(float a, float b)
{
	return a < b ? a : b;
}
float Max(float a, float b)
{
	return a > b ? a : b;
}
float Find_max(float*p, int left, int right)
{
	assert(p);
	float la ,ra;
	int mid = 0;
	if (left == right)//若n=1;(n为金块数）
	{
		float max = 0;
		max = *(p + right);
		return max;
	}
	if (right - left == 1)//若n=2;
	{
		la = *(p + left);
		ra = *(p + right);
		return (Max(la, ra));
	}
	if (right - left > 1)//若n>2;
	{
		mid = (right + left) / 2;
		la = Find_max(p, left, mid);
		ra = Find_max(p, mid, right);
		return (Max(la, ra));
	}
}
float Find_min(float* p, int left, int right)
{
	assert(p);
	float la, ra;
	int mid = 0;
	//递归出口
	if (left == right)//若n=1;(n为金块数）
	{
		float min = 0;
		min = *(p + right);
		return min;
	}
	//递归出口
	if (right - left == 1)//若n=2;
	{
		la = *(p + left);
		ra = *(p + right);
		return (Min(la, ra));
	}

	if (right - left > 1)//若n>2;
	{
		mid = (right + left) / 2;
		la = Find_min(p, left, mid);
		ra = Find_min(p, mid, right);
		return (Min(la, ra));
	}
}
int main(void)
{
	int n = 0;
	int i = 0;
	float min = 0;
	float max = 0;
	printf("%请输入金块数量：\n");
	scanf("%d", &n);
	float* p = malloc(n * sizeof(float));
	printf("请分别输入%d块金子的重量:\n",n);
	for (i = 0; i < n; i++)
	{
		scanf("%f", (p + i));
	}
	printf("最重的金子: ");
	max = Find_max(p, 0, n - 1);
	printf("%.1f\n", max);

	printf("最轻的金子: ");
	min = Find_min(p, 0, n - 1);
	printf("%.1f\n", min);

	//释放动态内存
	free(p);
	p = NULL;
	return 0;
}
