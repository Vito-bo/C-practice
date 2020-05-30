#include <stdio.h>

//1.
void Fnid_val(int *arr, int row, int col, int num)
{
	if (NULL != arr && row > 0 && col > 0)
	{
		int tmpRow = 0;
		int tmpCol = col - 1;
		while (tmpRow < row && col >= 0)
		{
			if (arr[tmpRow * col + tmpCol] == num)
			{
				printf("%d,intdex == %d\n", arr[tmpRow * col + tmpCol], tmpRow * col + tmpCol);
				break;
			} 
			else if (arr[tmpRow * col + tmpCol] > num)
			{
				--tmpCol;
			} 
			else
			{
				++tmpRow;
			}
		}
	}
} 
int main()
{
	int arr[4][4] = { 1, 2, 8, 9,
		2, 4, 9, 12,
		4, 7, 10, 13,
		6, 8, 11, 15 };
	Fnid_val((int*)arr, 4, 4, 15);
	return 0;
}

//2.
void ReplaceBlank(char *str, int len)
{
	int MLen = 0;//计算字符的个数
	int NumBlank = 0;//计算空格的数组
	int IndexofMLen = 0;
	int Indexofnew = 0;
	int newlen = 0;
	int i = 0;//从0号下标开始遍历
	if (str == NULL || len <= 0)
	{
		return;
	} 
	while(str[i] != '\0')
	{
			++MLen;
			if (str[i] == ' ')
			{
				++NumBlank;
			} +
				+i;
		} 
        newlen = MLen + NumBlank * 2;//a%20b%20c%20d a b c d
		if (newlen > len)//newlen是扩充后数组的大小，所以一定要小于len原来大小，不然放不下
		{
			return;
		} 
		IndexofMLen = MLen;
		Indexofnew = newlen;
		while (IndexofMLen >= 0 && Indexofnew >IndexofMLen)
		{
			if (str[IndexofMLen] == ' ')
			{
				str[Indexofnew--] = '0';
				str[Indexofnew--] = '2';
				str[Indexofnew--] = '%';
			} 
			else
			{
				str[Indexofnew--] = str[IndexofMLen];
			} -
				-IndexofMLen;
		}
} 
int main()
{
	char str[30] = "a b c d";
	int len = (sizeof(str) / sizeof (str[0]));
	ReplaceBlank(str, len);
	printf("%s\n", str);
	return 0;
}
//3.
int Fabio_for(int n)
{
	int f1 = 1;
	int f2 = 1;
	int f3 = 1;
	int i = 0;
	for (i = 3; i <= n; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
} 
int main()
{
	printf("%d\n", Fabio_for(2));
	return 0;
}

//4.
int Numberof1(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = (n - 1)&n;
	} 
	return count;
} 
int main()
{
	printf("%d\n", Numberof1(100));
	return 0;
}

//5.
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	//刚开始的时候，都指向起点，然后p1走k-1步后，p2和p1同时开始走，当p1走到最后一个的时候，p2指向的就是
	最后一个节点
		ListNode *p1 = pListHead;
	ListNode *p2 = pListHead;
	if (pListHead == NULL || k == 0) {
		return NULL;
	} 
	while (k - 1 > 0)
	{
			if (p1->next != NULL)
			{
				p1 = p1->next;
				--k;
			} 
			else
			{
				cout << "error" << endl;
				return NULL;
			}
		} 
	    while(p1->next != NULL)
		{
				p1 = p1->next;
				p2 = p2->next;
		} 
		return p2;
}
//6
struct ListNode* reverseList(struct ListNode* head){
	struct ListNode *rev_head = NULL;
	struct ListNode *prev = NULL;
	struct ListNode *pNode = head;
	while (pNode != NULL)
	{
		struct ListNode *pNext = pNode->next;
		if (pNext == NULL)
		{
			rev_head = pNode;
		} 
		pNode->next = prev;
		prev = pNode;
		pNode = pNext;
	} 
	return rev_head;
} 

//7
// 使用快排的划分 当然还可以使用堆进行求解
int Partion(int *arr, int left, int right)
{
	int tmp = arr[left];
	if (arr == NULL)
	{
		return -1;
	} 
	while (left < right)
	{
			while (left < right && arr[right] >= tmp)
			{
				right--;
			}
			if(left >= right)
			{
				break;
			} 
			else
			{
				arr[left] = arr[right];
			} 
			while (left < right && arr[left] <= tmp)
			{
					left++;
				} 
			if (left >= right)
				{
						break;
					} 
			else
					{
					arr[right] = arr[left];
				}
		} 
	arr[left] = tmp;
		return left;
} 

//8
void Little_K(int *arr, int len, int k)
{
	int par = 0;
	int start = 0;
	int end = len - 1;
	int index = Partion(arr, start, end);//使用上一个题目的Partion函数
	if (arr == NULL || len < 1)
	{
		return;
	} 
	if (arr == NULL || len < 0)
	{
			return 0;//假设数组当中不存放数字0
		} 
	while (index != mid)
		{
				if (index > mid)
				{//说明在左边找
					end = index - 1;
					index = Partion(arr, start, end);
				} 
				else
				{
					start = index + 1;
					index = Partion(arr, start, end);
				}
			} 
	        for (int i = 0; i < k; i++)
			{
				printf("%d ", arr[i]);
			}
}
int main()
{
	int arr[] = { 12, 21, 1, 4, 2, 65, 33, 5, 3 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Little_K(arr, len, 3);
	return 0;
} 

//9
int arrayLenHalfNum(int* arr, int len)
{
	int mid = len >> 1;
	int start = 0;
	int end = len - 1;
	int result = 0;
	int index = Partion(arr, start, end);//使用上一个题目的Partion函数
	if (arr == NULL || len < 0)
	{
		return 0;//假设数组当中不存放数字0
	} 
	while (index != mid)
	{
			if (index > mid)
			{//说明在左边找
				end = index - 1;
				index = Partion(arr, start, end);
			} 
			else
			{
				start = index + 1;
				index = Partion(arr, start, end);
			}
		} 
	    result = arr[mid];
		//以上数据当中 我们一直认为 数组的中位数就是我们需要找的数字
		//但是 并不一定数组当中频率最高的数字 就是中位数 所以得到这个result
		//之后 我们还需要判断一下这个数字出现的频率是否为整个长度的一半
		if (!checkIsMoreThanHalf(arr, result))
		{
			result = 0;
		}
		return result;
} 

//10
int checkIsMoreThanHalf(int *arr, int num)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < arr.length; i++)
	{
		if (arr[i] == num)
		{
			count++;
		}
	} 
	if (count * 2 <= arr.length)
	{
			return 0;
		} 
	return 1;
} 

//11
int MAX_Arry(int* arr, int sz)
{
	int MAX = arr[0];
	int sum = arr[0];

		int i = 1;
	if (arr == NULL || sz <= 1)
		return 0;
	for (i = 1; i < sz; i++)
	{
		if (sum < 0)
			sum = arr[i];
		else
		{
			sum += arr[i];
		} 
		if (sum > MAX)
			MAX = sum;
	} 
	return MAX;
} 
int main()
{
	int arr[] = { 1, -2, 3, 10, -4, 7, 2, -5 };
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("%d\n", MAX_Arry(arr, len));
	return 0;
} 

//12
char firstNotRepeate(char* str)
{
	const int size = 256;//表示
	int hashTable[size];
	int i;
	if (str == null) {
		return '\0';
	} 
	for (i = 0; i < size; i++) {
			hashTable[i] = 0;

		} 
	char *pHashKey = str;
			while (*(pHashKey) != '\0')
			{
				hashTable[*(pHashKey++)]++;
			} 
			pHashKey = str;
			while (*(pHashKey) != '\0')
			{
				if (hashTable[*(pHashKey)] == 1)
				{
					return *(pHashKey);
				} 
				pHashKey++;
			} 
			return '\0';
} 

//13
#define SIZE 256
#include<stdio.h>
char firstNotRepeate(char* str)
{
	char *pHashKey = str;
	int hashTable[SIZE];
	int i;
	for (i = 0; i < SIZE; i++) {
		hashTable[i] = 0;
	} 
	while (*(pHashKey) != '\0')
	{
			hashTable[*(pHashKey++)]++;
		} 
	pHashKey = str;
		while (*(pHashKey) != '\0')
		{
	
			if (hashTable[*(pHashKey)] == 2)
			{
				return *(pHashKey);
			} 
			pHashKey++;
		} 
		return '\0';
} 
int main()
{
	char ch = firstNotRepeate("qywyer23tdd");
	printf("%c\n", ch);
	return 0;
} 

//14
void findNumberAppearOnce(int[] arr, int len, int *num1, int *num2)
{
	int resultOR = 0;
	int i = 0;
	int indexOf1 = 0;
	int j = 0;
	if (arr == null || len < 2)
	{
		return null;
	} 
	*num1 = 0;
	*num2 = 0;
	//对数组当中每个数字进行异或,结果为两个不相同的数字异或结果
	for (i = 0; i < len; i++)
	{
		resultOR ^= arr[i];
	} 
	// 找出resultOR当中的第一个二进制1是第几位（右 == = 》左）
		indexOf1 = findNumberBits(resultOR);
	//遍历数组，第indexOf1为1的进行异或 不为1的进行异或

	for (j = 0; j < len; j++)
	{
		if (isBit(arr[j], indexOf1))
		{
			*num1 = *num1^arr[j];
		} 
		else
		{
			*num2 = *num2^arr[j];
		}
	}
} 
// 从右数的第bit为1
int findNumberBits(int number)
{
	int indexBit = 0;
	while ((number & 1) == 0 && indexBit < 8 * sizeof(int))
	{
		number = number >> 1;
		++indexBit;
	}
	return indexBit;
} 
bool isBit(int num, int index)
{
	num = num >> index;
	if ((num & 1) == 1)
	{
		return true;
	} 
	return false;
} 

//14
#define MAX 256
char *DeleteChars(char *str1, char *str2)
{
	if (str1 == NULL || str2 == NULL)
		return NULL;
	int hashtable[MAX] = { 0 };
	//将str2中字符对应的hashtable数组中的位置上的值设为ture
	while (*str2 != '\0')//"come"
	{
		hashtable[*str2] = 1;
		++str2;
	} 
	char *p = str1;
	char *q = str1;
	while (*p != '\0')
	{
		if (!hashtable[*p])
		{
			*q++ = *p;
		} p
			++;//因为后面需要找到值 覆盖掉这个为true的值
	} *
		q = '\0';
	return str1;
} 
int main()
{
	char str1[] = "Welcome biter";
	char str2[] = "come";
	printf("%s\n", DeleteChars(str1, str2));
	return 0;
} 

//15
void Palindrome(int num)
{
	int newed = 0;
	int n = num;
	while (num>0)
	{
		newed = newed * 10 + num % 10;
		num /= 10;
	}
	if (n == newed)
	{
			printf("Yes\n");
		} 
	else
		{
		printf("No\n");
	}
} 

//16
//设置两个指针，p1, p2, 开始p1, p2均位于链接的头部。
//p1 每次步进两步，
//p2 每次步进一步
//当p1到达链表的末尾时，p2所在的位置就是链表的中间元素
//时间复杂度为O(n)
Node *FindMidleNode(pList plist)
{
	Node *pFast = NULL;
	Node *pSlow = NULL;
	assert(plist != NULL);
		pFast = plist->next;
	pSlow = plist->next;
	while (pFast != NULL && pFast->next != NULL)
	{
		pFast = pFast->next->next;
		pSlow = pSlow->next;
	} 
	return pSlow;
}

//17
//函数pow(x, y)实现运算x^y，即x的y次方，这里x和y都为整数。
//算法的基本思想是，减少乘法次数，重复利用结算结果，例如：
//x ^ 4，如果逐个相乘的话，需要四次乘法。
//如果我们这样分解(x ^ 2)*(x ^ 2)就只需要2两次乘法，
//因为x ^ 2的结果我们可以重复利用。所以我们最好做对称的分解指数y，
//然后求x ^ (y / 2)的平方。
//具体算法如下：
//1 如果y为偶数，直接计算mypow(x, y / 2)*mypow(x, y / 2)；
//2 如果y为奇数，则y - 1为偶数，回到了第一种情况。

int Mypow(int x, int y)
{
	int result = 0;
	int tmp = 0;
	if (y == 1) return x;
	tmp = mypow(x, y / 2);
	if (y & 1 != 0) //奇数
	{
		result = x * tmp * tmp;
	}

	else
	{
		result = tmp * tmp;
	} 
	return result;
} 
void SumK(int *arr, int len, int k, int *num1, int *num2)
{
	int low = 0; //从前往后遍历
	int high = len - 1;//从后往前遍历
	int sum;
	while (low <= high)
	{
		sum = arr[low] + arr[high];
		if (sum < k)
		{
			low++;
		} 
		else if (sum > k)
		{
			high--;
		} 
		else
		{
			*num1 = low;
			*num2 = high;
			break;
		}
	}
}

//18
//1、第一种解法O（logn)
int isPower(int n)//8
{
	if (n < 1)
	{
		return 0;
	}
	int i = 1;
	for (i = 1; i <= n; i <<= 1)//0000 1000 0000 1000
	{
		if (i == n)
		{
			return 1;
		}
	} 
	return 0;
} 
// 2、第二种解法 O(1)
int isPower(int n)
{
	int m = 0;
	if (n < 1)
	{
		return 0;
	} 
	m = n & (n - 1);
	if (m == 0)
	{
		return 1;
	} 
	return 0;
}

//19
void Compress(char *str)
{
	int count = 1;
	int i = 0;
	assert(str != NULL);
	while (str[i] != '\0')
	{
		if (str[i] == str[i + 1])
		{
			count++;
		} 
		else
		{
			if (count != 1)
			printf("%d", count);
			printf("%c", str[i]);
			count = 1;
		} 
		i++;
	} 
	printf("\n");
} 
int main()
{
	Compress("xxyyyz");
	Compress("xyyyz");
	Compress("xxxxx");
	Compress("aabbccdaa");
	return 0;
}

//20
void Deblank(char *str)
{
	int flag = 0; //代表没开始处理空格
	int p = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		//遇到空格 还没开始处理
		if (!flag &&str[i] == ' ')// 遇到空格 让i往后走到不是空格的地方
		{
			i++;
		} 
		// 遇到不是空格 还没开始处理
		else if (!flag &&str[i] != ' ')//不是空格的字符向前赋值
		{
			flag = 1; //开始处理空格
			str[p++] = str[i++];
		} 
		// 遇到空格 开始处理了
		else if (flag &&str[i] == ' ')
		{
			flag = 0; //不处理
			str[p++] = str[i++];
		} 
		else
		{
			str[p++] = str[i++];
			flag = 1;
		}
	} 
	if (str[p - 1] == ' ') //结尾处多余空格
		str[p - 1] = '\0';
	else
	    str[p] = '\0';
} 
int main()
{
	char str[] = " as adad q ";
	Deblank(str);
	printf("%s", str);
	return 0;
}