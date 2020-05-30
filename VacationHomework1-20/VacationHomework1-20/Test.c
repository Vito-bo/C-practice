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
	int MLen = 0;//�����ַ��ĸ���
	int NumBlank = 0;//����ո������
	int IndexofMLen = 0;
	int Indexofnew = 0;
	int newlen = 0;
	int i = 0;//��0���±꿪ʼ����
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
		if (newlen > len)//newlen�����������Ĵ�С������һ��ҪС��lenԭ����С����Ȼ�Ų���
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
	//�տ�ʼ��ʱ�򣬶�ָ����㣬Ȼ��p1��k-1����p2��p1ͬʱ��ʼ�ߣ���p1�ߵ����һ����ʱ��p2ָ��ľ���
	���һ���ڵ�
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
// ʹ�ÿ��ŵĻ��� ��Ȼ������ʹ�öѽ������
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
	int index = Partion(arr, start, end);//ʹ����һ����Ŀ��Partion����
	if (arr == NULL || len < 1)
	{
		return;
	} 
	if (arr == NULL || len < 0)
	{
			return 0;//�������鵱�в��������0
		} 
	while (index != mid)
		{
				if (index > mid)
				{//˵���������
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
	int index = Partion(arr, start, end);//ʹ����һ����Ŀ��Partion����
	if (arr == NULL || len < 0)
	{
		return 0;//�������鵱�в��������0
	} 
	while (index != mid)
	{
			if (index > mid)
			{//˵���������
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
		//�������ݵ��� ����һֱ��Ϊ �������λ������������Ҫ�ҵ�����
		//���� ����һ�����鵱��Ƶ����ߵ����� ������λ�� ���Եõ����result
		//֮�� ���ǻ���Ҫ�ж�һ��������ֳ��ֵ�Ƶ���Ƿ�Ϊ�������ȵ�һ��
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
	const int size = 256;//��ʾ
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
	//�����鵱��ÿ�����ֽ������,���Ϊ��������ͬ�����������
	for (i = 0; i < len; i++)
	{
		resultOR ^= arr[i];
	} 
	// �ҳ�resultOR���еĵ�һ��������1�ǵڼ�λ���� == = ����
		indexOf1 = findNumberBits(resultOR);
	//�������飬��indexOf1Ϊ1�Ľ������ ��Ϊ1�Ľ������

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
// �������ĵ�bitΪ1
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
	//��str2���ַ���Ӧ��hashtable�����е�λ���ϵ�ֵ��Ϊture
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
			++;//��Ϊ������Ҫ�ҵ�ֵ ���ǵ����Ϊtrue��ֵ
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
//��������ָ�룬p1, p2, ��ʼp1, p2��λ�����ӵ�ͷ����
//p1 ÿ�β���������
//p2 ÿ�β���һ��
//��p1���������ĩβʱ��p2���ڵ�λ�þ���������м�Ԫ��
//ʱ�临�Ӷ�ΪO(n)
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
//����pow(x, y)ʵ������x^y����x��y�η�������x��y��Ϊ������
//�㷨�Ļ���˼���ǣ����ٳ˷��������ظ����ý����������磺
//x ^ 4����������˵Ļ�����Ҫ�Ĵγ˷���
//������������ֽ�(x ^ 2)*(x ^ 2)��ֻ��Ҫ2���γ˷���
//��Ϊx ^ 2�Ľ�����ǿ����ظ����á���������������ԳƵķֽ�ָ��y��
//Ȼ����x ^ (y / 2)��ƽ����
//�����㷨���£�
//1 ���yΪż����ֱ�Ӽ���mypow(x, y / 2)*mypow(x, y / 2)��
//2 ���yΪ��������y - 1Ϊż�����ص��˵�һ�������

int Mypow(int x, int y)
{
	int result = 0;
	int tmp = 0;
	if (y == 1) return x;
	tmp = mypow(x, y / 2);
	if (y & 1 != 0) //����
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
	int low = 0; //��ǰ�������
	int high = len - 1;//�Ӻ���ǰ����
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
//1����һ�ֽⷨO��logn)
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
// 2���ڶ��ֽⷨ O(1)
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
	int flag = 0; //����û��ʼ����ո�
	int p = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		//�����ո� ��û��ʼ����
		if (!flag &&str[i] == ' ')// �����ո� ��i�����ߵ����ǿո�ĵط�
		{
			i++;
		} 
		// �������ǿո� ��û��ʼ����
		else if (!flag &&str[i] != ' ')//���ǿո���ַ���ǰ��ֵ
		{
			flag = 1; //��ʼ����ո�
			str[p++] = str[i++];
		} 
		// �����ո� ��ʼ������
		else if (flag &&str[i] == ' ')
		{
			flag = 0; //������
			str[p++] = str[i++];
		} 
		else
		{
			str[p++] = str[i++];
			flag = 1;
		}
	} 
	if (str[p - 1] == ' ') //��β������ո�
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