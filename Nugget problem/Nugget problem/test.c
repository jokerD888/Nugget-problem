#define _CRT_SECURE_NO_WARNINGS 1


//�ϰ���һ����飨��n�飬n��2���ݣ�n��2����, ������Ĺ�Ա�õ��������ص�һ�飬���Ĺ�Ա�õ����������һ�顣
//������һ̨�Ƚ�������������ϣ�������ٵıȽϴ����ҳ����غ�����Ľ�顣�����Լ��ĳ�����и����Է�����
#include<stdio.h>
#include<stdio.h>
#include<assert.h>
//��Сֵ                            ���϶��¶���                                   �ӵݹ�������¶���return��Сֵ    
//        8��           7.8  3.5  2.1  4.9  5.0  6.7  0.7  4.9                            0.7
//   ��   4��         7.8  3.5  2.1 4.9         5.0 6.7   0.7 4.9                      2.1  0.7
//   ��   2��       7.8  3.5     2.1  4.9      5.0  6.7    0.7  4.9             3.5  2.1      5.0 .07
//                   3.5          2.1            5.0         0.7                         
//���ֵ����
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
	if (left == right)//��n=1;(nΪ�������
	{
		float max = 0;
		max = *(p + right);
		return max;
	}
	if (right - left == 1)//��n=2;
	{
		la = *(p + left);
		ra = *(p + right);
		return (Max(la, ra));
	}
	if (right - left > 1)//��n>2;
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
	//�ݹ����
	if (left == right)//��n=1;(nΪ�������
	{
		float min = 0;
		min = *(p + right);
		return min;
	}
	//�ݹ����
	if (right - left == 1)//��n=2;
	{
		la = *(p + left);
		ra = *(p + right);
		return (Min(la, ra));
	}

	if (right - left > 1)//��n>2;
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
	printf("%��������������\n");
	scanf("%d", &n);
	float* p = malloc(n * sizeof(float));
	printf("��ֱ�����%d����ӵ�����:\n",n);
	for (i = 0; i < n; i++)
	{
		scanf("%f", (p + i));
	}
	printf("���صĽ���: ");
	max = Find_max(p, 0, n - 1);
	printf("%.1f\n", max);

	printf("����Ľ���: ");
	min = Find_min(p, 0, n - 1);
	printf("%.1f\n", min);

	//�ͷŶ�̬�ڴ�
	free(p);
	p = NULL;
	return 0;
}
