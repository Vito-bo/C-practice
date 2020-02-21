#include <stdio.h>


#if 0
//力扣-925.长按键入
bool isLongPressedName(char * name, char * typed)
{
	int i = 0, j = 0, c1, c2;
	while (name[i] != '\0'&&typed[j] != '\0')
	{
		c1 = 0;
		c2 = 0;
		while (name[i] == name[i + 1])
		{
			c1++;
			i++;
		}
		while (typed[j] == typed[j + 1])
		{
			c2++;
			j++;
		}
		if (typed[j] == name[i] && c2 >= c1)
		{
			i++;
			j++;
		}
		else
		{
			return false;
		}
	}
	if (name[i] != '\0')
		return false;
	return true;
}
#endif

//力扣-917仅仅反转字母
int apl(char *S, int n)
{
	if (S[n] >= 'a' && S[n] <= 'z')
		return 1;
	else if (S[n] >= 'A' && S[n] <= 'Z')
		return 1;
	else
		return 0;
}
char * reverseOnlyLetters(char * S)
{
	int i = 0, j = strlen(S) - 1;
	while (i <= j)
	{
		while (i<strlen(S) && apl(S, i) == 0)
			i++;
		while (j >= 0 && apl(S, j) == 0)
			j--;
		if (i <= j)
		{
			char temp = S[i];
			S[i] = S[j];
			S[j] = temp;
			i++;
			j--;
		}
	}
	return S;
}