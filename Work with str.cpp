//9.	Имеется текстовый файл. Переписать в другой файл те его строки, в которых имеется более 30-ти символов.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;
void IFT(FILE *f);
void IFMore30(FILE *f);
void IfMore3P(FILE *f);
void IfZad(FILE *f);
void main()
{
	FILE *f;
	f = fopen("qwe.txt", "r");
	IfZad(f);
	cout << endl;
	system("pause");
}
void IFT(FILE *f)
{
	char buf[100];
	do
	{
		char s = getc(f);
		fgets(buf, 100, f);
		if (s == 'T')
			cout << s << buf << endl;
	} while (strstr(buf,"\0")!=0);
}
void IFMore30(FILE *f)
{
	char buf[100];
	while(fgets(buf, 100, f))
		if (strlen(buf) >= 30)
			cout << buf << endl;
}
void IfMore3P(FILE *f)
{
	char buf[255];
	while (fgets(buf, 255, f))
	{
		int count = 0;
		int n = strlen(buf);
		for (int i = 0;i < n;i++)
			if (buf[i] == ' ')
				count++;
		if (count >= 3)
			cout << buf << endl;
	}
}
void IfZad(FILE *f)
{
	char buf[255];
	while (fgets(buf, 255, f))
	{
		if (strstr(buf, "It was i!") != 0)
			cout << buf << endl;
	}
}


//