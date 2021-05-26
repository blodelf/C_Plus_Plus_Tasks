//1.	Создать текстовый файл и записать в него фразу “Здравствуй, мир!”

	FILE *F;
	F = fopen("file.txt", "w");
	fputs("Hello world!",F);
//fputs ввод строки 
	fclose(F);
//закрытие документа 
	cout << "MEM" << endl;
	
	
//2.	Создать текстовый файл и записать в него 6 строк. Записываемые строки вводятся с клавиатуры

	FILE *F;
	F = fopen("TEXT2.txt", "w");
// open file 
	for (int i = 0;i < 6;i++)
	{
		char str[30];
		cin.getline(str, 40);
		fputs(str, F);
		fputs("\n", F);

	}
	fclose(F);
	

//3.	Дан массив строк. Записать их в файл, расположив каждый элемент массива на отдельной строке с сохранением порядка

	const int n = 40;
	FILE *f;
	f = fopen("file3.txt", "w");
	char str[n];
	cin.getline(str, 40);
	int k = strlen(str);
	for (int i = 0;i < k;i++)
	{
		putc(str[i], f);
		putc('\n', f);
	}
fclose(f);


//4.	В конец существующего текстового файла записать новую строку с текстом “До свидания, люди!”
const int n = 400;
	FILE *f;
	f = fopen("file5.txt", "r+");
	char str[n];
	cin.getline(str, 40);
	fseek(f, n-20, SEEK_END);
	fputs(str, f);


fclose(f);


//5.	Дан текстовый файл. Подсчитать количество строк в нем
int Countlines(FILE *f);
void main()
{
	const int n = 400;
	FILE *f;
	f = fopen("xxx.txt", "r");

	cout << Countlines(f) << endl;


fclose(f);


	system("pause");
}
int Countline(FILE *f)
{
	int i = 0;
	char buf[100];
	while (fgets(buf, 100, f))
		i++;
	return i;
}


//6.	Дан текстовый файл. Подсчитать количество символов в нем

int Countchar(FILE *f);
void main()
{
	const int n = 400;
	FILE *f;
	f = fopen("xxx.txt", "r");
	
	cout << Countchar(f) << endl;


fclose(f);


	system("pause");
}
int Countchar(FILE *f)
{
	int i = 0;
	int k = 0;
	char buf[100];
	while (getc(f)!=EOF)
k=k+strlen(fgets(buf, 100, f));
	
	return k+1;
}


//7.	Дан текстовый файл. Подсчитать количество символов в каждой строке
void Countchar(FILE *f);
void main()
{
	const int n = 400;
	FILE *f;
	f = fopen("xxx.txt", "r");
	
	Countchar(f);


fclose(f);


	system("pause");
}
void Countchar(FILE *f)
{
	int i = 0;
	int k = 0;
	char buf[100];
	while (getc(f) != EOF)
	{
		
		if (getc(f) != '\n')
		{
			k = strlen(fgets(buf, 100, f));
			cout << k+1 << endl;
		}
		k = 0;
	}
	
}


//8.	Имеется текстовый файл. Удалить из него третью строку. Результат записать в другой файл
	const int n = 100;
	FILE *f;
	FILE *f1;
	f = fopen("xxx.txt", "r");
	f1 = fopen("xxx1.txt", "w");
	char buf[100];
		int count = 0;
	while (fgets(buf, 100, f))
	{
		count++;
		if (count == 3)
			continue;
		fputs(buf, f1);
	}
fclose(f);


//9.	Удалить из текстового файла его последнюю строку. Результат записать в другой файл
	const int n = 100;
	FILE *f;
	FILE *f1;
	f = fopen("xxx.txt", "r");
	f1 = fopen("xxx1.txt", "w");
	char buf[100];
	int count = 0;
	int temp = 0;
	while (fgets(buf, 100, f))
	{
		temp++;
	}
	rewind(f);
	while (fgets(buf, 100, f))
	{
		count++;
		if (count == temp)
			continue;
		fputs(buf, f1);
	}
	fclose(f);
	fclose(f1);

//10.	Имеется текстовый файл. Удалить из него первую строку, в конце которой стоит вопросительный знак. Результат записать в другой файл
	const int n = 100;
	FILE *f;
	FILE *f1;
	f = fopen("xxx.txt", "r");
	f1 = fopen("xxx1.txt", "w");
	char buf[100];
	bool j = true;
	while (fgets(buf, 100, f))
	{
		if (j == true)
		{
			if (buf[strlen(buf)-2] != '?')
			{
				fputs(buf, f1);
			}
			else
				j = false;
		}
		else
			fputs(buf, f1);
	}
	fclose(f);
	fclose(f1);

//11.	Удалить из текстового файла всю информацию. Дополнительный файл не использовать
	const int n = 100;
	FILE *f;
	
	f = fopen("xxx.txt", "w");
	


	
	fclose(f);
	
	
//12.	Имеется текстовый файл. Добавить в него строку из двенадцати черточек (------------), разместив ее: а) после пятой строки; б) после последней из строк, в которых нет пробела. Если таких строк нет, то новая строка должна быть добавлена после всех строк имеющегося файла. В обоих случаях результат записать в другой файл

void AddStr(FILE *f, FILE *f2);
void addstr(FILE*f, FILE *f2);
void main()
{
	FILE *f;
	FILE *f2;
	f = fopen("xxx.txt", "r");
	f2 = fopen("xxx2.txt", "w");
	char buf[100];

		fgets(buf, 100, f2);
		addstr(f, f2);
	



	fclose(f);
	fclose(f2);

	system("pause");
}
void AddStr(FILE *f, FILE *f2)
{
	int count = 0;
	char buf[100];


	
	while (fgets(buf, 100, f))
	{
		fputs(buf, f2);
		if (count == 4)
		{
			fputs("---------------\n", f2);
		}
		count++;
	}
}
void addstr(FILE*f, FILE *f2)
{
	int count = 0;
	char buf[200];
	int k;
	while (fgets(buf, 200, f))
	{
		if (strstr(buf, " ") == 0)
		{
			k = count;
		}
			count++;
		
	}
	rewind(f);
	count = 0;
	while (fgets(buf, 200, f))
	{
		fputs(buf, f2);
		if (count == k)
		fputs("---------------\n", f2);
			count++;
		
	}

}
//13.	Имеется текстовый файл. Напечатать: а) его первую строку; б) его пятую строку; в) его первые 5 строк; г) его строки с s1-й по s2-ю; д) весь файл.

void read1(FILE*f);
void read2(FILE*f);
void read3(FILE*f);
void read4(FILE*f);
void main()
{
	FILE *f;
	
	f = fopen("xxx.txt", "r");
	
	char buf[100];
	fgets(buf, 100, f);
	read1(f);
	rewind(f);
	read2(f);
	rewind(f);
	read3(f);
	rewind(f);
	read4(f);



	fclose(f);
	

	system("pause");
}
void read1(FILE*f)
{
	char buf[100];
	while (fgets(buf, 200, f))
	{
		cout << fgets(buf, 200, f) << endl;
		break;
	}
}
void read2(FILE*f)
{
	char buf[100];
	int count = 0;
	while (fgets(buf, 200, f))
	{
		count++;
		if (count == 5)
		{
			cout << buf << endl;
			break;
		}
	}

}
void read3(FILE*f)
{
	int s, s1;
	cin >> s >> s1;
	char buf[100];
	int count = 0;
	while (fgets(buf, 200, f))
	{
		count++;
		if ((count>=s)&&(count <= s1))
		{
			cout << buf << endl;
			
		}
	}
}
void read4(FILE*f)
{
	char buf[100];
	
	while (fgets(buf, 200, f))
	{
		cout << buf << endl;
	}
	
}