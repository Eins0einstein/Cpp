#include <iostream>
#include <fstream>
#include <cassert>
#include <string>
#include <cstring>
int KmpSearch(char* s, char* p,int []);
void GetNext(char* p, int next[]);
using namespace std;
int strlength = 0;
int result = 0;
int main()

{
	
	string file = "test.txt";
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 
	char s[100000];
	char *sptr = &s[0];
	infile >> noskipws;
	while (!infile.eof())
	{
		infile >> *sptr;
		sptr++;
		strlength++;
	}
	infile.close();             //关闭文件输入流 
	std::string str;
	std::cin >> str;
	int len = str.length();
    char *p = const_cast<char*>(str.c_str());
	int *next = new int[len];
	GetNext(p, next);
	KmpSearch(s, p, next);
	cout << endl;
	cout << "result is " << result << endl;
	system("pause");
}
int KmpSearch(char* s, char* p,int next[])
{
	int i = 0;
	int j = 0;
	int m = 0;
	int sLen = strlen(s);
	int pLen = strlen(p);
	while (i < sLen && j < pLen)
	{
		
		//①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++    
		if (j == -1 || s[i] == p[j])
		{
			if (j == 0)
			{
				m = i;
			}
			i++;
			j++;
		}
		else
		{
			//②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]    
			//next[j]即为j所对应的next值
			
			j = next[j];
		}
		if (j == pLen)
	    {
			int temp = m;
			if (((s[temp -1 ] > 64 && s[temp-1] < 91) || (s[temp-1] > 96 && s[temp-1] < 123)))
			{
				while (((s[temp] > 64 && s[temp] < 91) || (s[temp] > 96 && s[temp] < 123)) && temp < strlength)
				{
					temp--;
				}
			}
			else
			{
				temp--;
			}
			
		while (s[temp] < 65 || (s[temp] > 90 && s[temp] < 97) || s[temp]>122)
		{
					temp--;
		}
			while (((s[temp] > 64 && s[temp] < 91) || (s[temp] > 96 && s[temp] < 123)))
			{
				temp--;
			}
			temp++;
			cout << "before occurence : ";
			while (((s[temp] > 64 && s[temp] < 91) || (s[temp] > 96 && s[temp] < 123)))
			{
				cout << s[temp];
				temp++;
			}
			cout << "  after occurence :";
			int temp2 = m + pLen;
			if (((s[temp2+1] > 64 && s[temp2+1] < 91) || (s[temp2+1] > 96 && s[temp2+1] < 123)))
			{
				while (((s[temp2] > 64 && s[temp2] < 91) || (s[temp2] > 96 && s[temp2] < 123)) && temp2 < strlength)
				{
					temp2++;
				}
			}
			else
			{
				temp2++;
			}
			while (s[temp2]<65||(s[temp2]>90&&s[temp2]<97)||s[temp2]>122)
			{
				temp2++;
			}
			while (((s[temp2]>64&&s[temp2]<91)||(s[temp2]>96&&s[temp2]<123))&&temp2<strlength)
			{
				cout << s[temp2];
				temp2++;
			}
			cout << endl;
	        j = 0;
			result++;
	    }
		
	}
	return 0;
}
void GetNext(char* p, int next[])
{
	int pLen = strlen(p);
	next[0] = -1;
	int k = -1;
	int j = 0;
	while (j < pLen - 1)
	{
		//p[k]表示前缀，p[j]表示后缀
		if (k == -1 || p[j] == p[k])
		{
			++k;
			++j;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}
}
