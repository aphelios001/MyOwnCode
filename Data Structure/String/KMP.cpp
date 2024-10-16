//C++下标从0开始的版本，即用std::string
#include<bits/stdc++.h>
using namespace std;
string s, t;
int prefix[10000];//因为万能头的next有定义，所以用prefix代替next
void get_next()
{
	int j=-1,i = 0;
	prefix[0] = -1;
	while (i < (int)t.length())
	{
		if (j == -1 || t[i] == t[j])
		{
			i++;
			j++;

			/*
			
			朴素版getnext
			prefix[i] = j;

			*/

			//以下为get_nextval，即优化版getnext

			if (t[i] != t[j])
			{
				prefix[i] = j;
			}
			else
			{
				prefix[i] = prefix[j];
			}

		}
		else
		{
			j = prefix[j];
		}
	}
}
int kmp(int pos)//pos代表从主串第pos个字符开始查找
{
	int i = pos-1, j = 0;//i要对应第pos个字符的下标
	while (i < (int)s.length() && j < (int)t.length())
	{
		if (j == -1 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
		{
			j = prefix[j];
		}
	}
	if (j == t.length())
	{
		return i - j;
	}
	else
	{
		return -1;
	}
}
int main()
{
	cin >> s >> t;//s是主串，t是模式串
	get_next();
	cout << kmp(1);
	return 0;
}