

#include <stdio.h>

/*
//��ָoffer
//[i][j]=i*col+j
void Find_val(int* arr, int row, int col, int num, int* px, int* py)
{
	int tmpRow = 0;
	int tmpCol = col - 1;
	while (tmpRow < row && col >= 0)
	{
		if (arr[tmpRow*col + tmpCol] == num)
		{
			*px = tmpRow;
			*py = tmpCol;
			break;
		}
		else if (arr[tmpRow*col + tmpCol] > num)
		{
			tmpCol--;
		}
		else
			tmpRow++;
	}
}
int main()
{
	int arr[4][4] = {
		1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15
	};
	int x = -1;
	int y = -1;
	Find_val((int*)arr, 4, 4, 7, &x, &y);
	printf("%d,%d\n", x, y);
	return 0;
}
*/

//ħ����
//��1-9���η���3*3�����������ӺͶ���ͬ

#define Row 3

void Show(int arr[][Row])
{
	int i = 0;
	int j = 0;
	for (i = 0; i < Row; i++)
	{
		for (j = 0; j < Row; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
void Func(int arr[][Row], int row, int col)
{
	int tmpRow = 0;
	int tmpCol = Row / 2;
	int i = 2;
	arr[tmpRow][tmpCol] = 1;
	for (i = 2; i <= Row*Row; i++)
	{
		//˵����һ�У���һ���������ݵ�
		if (arr[(tmpRow - 1 + Row) % Row][(tmpCol + 1) % Row] != 0)
		{
			//�ı������� �в������ı�
			tmpRow = (tmpRow + 1 + Row) % Row;
		}
		else
		{

			tmpRow = (tmpRow - 1 + Row) % Row;
			tmpCol = (tmpCol + 1) % Row;
		}
		//�����if else���ִ�����ȷ������һ�����ݵ�����
		arr[tmpRow][tmpCol] = i;
	}
}

int main()
{
	int arr[3][3] = { 0 };
	Func(arr, 3, 3);
	Show(arr, 3);
	return 0;
}

