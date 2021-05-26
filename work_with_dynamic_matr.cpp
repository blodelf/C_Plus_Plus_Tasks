//1.	Написать программу, которая создает треугольный динамический массив. Заполнить его по своему усмотрению. Массив должен иметь вид прямоугольного треугольника при выводе.

 int n, m;
	cin >> n;
	cin >> m;
	int p = m;
	int **matr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		matr[i] = new int[p];
		for (int j = 0; j < p; j++)
			matr[i][j] = rand() % 10;
		p--;
	}

	p = m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < p; j++) {
			cout << matr[i][j] << " ";
		}
		cout << endl;
		p--;
	}
for(int i=0;i<n;i++)
delete[]matr[m];
delete[]matr;


/*2.	Написать программу, которая предоставляет пользователю меню, в котором есть такие варианты работы с двумерным массивом:
a) Добавить строку со случайными числами.
b) Добавить столбец со случайными числами.
c) Добавить строку с числами пользователя. (Запрашивается строка чисел после выбора этого пункта меню).
d) Добавить столбец с числами пользователя.
e) Удалить строку. (После этого запрашивается номер строки, которую нужно удалить).
f) Удалить столбец.(То же самое, что и в пункте в) ).
g) Поменять местами столбцы. (Запрашиваются номера столбцов).
h) Поменять местами строки. (Запрашивается номер строки).
i) Выход из программы.
После каждого из действий на экран должен выводиться текущий массив и снова список пунктов меню.*/

void Del(int **matr, int n);
void Menu();
void AddN(int **&matr, int &n, int m);
void AddM(int **&matr, int n, int &m);
void AddUserN(int **&matr, int &n, int m);
void AddUserM(int **&matr, int n, int &m);
void Print(int **matr, int n, int m);
void DeCol(int **&matr, int &n, int &m, int k);
void DelSTR(int **&matr, int &n, int m, int k1);
void SwapCol(int **&matr, int &n, int &m, int k,int k1);
void Swapstr(int **&matr, int &n, int &m, int k, int k1);
void main()
{
	
	int n;
	cout << "input sizw of n : " << endl;
	cin >> n;
	int m;
	cout << "input sizw of m : " << endl;
	cin >> m;

	int **matr = new int*[n];
	for (int i = 0;i < n;i++)
	{
		matr[i] = new int[m];
		for (int j = 0;j < m;j++)
			matr[i][j] = rand() % 10;
	}
	int q;


	do
	{

		Menu();
		q = _getch();
		cout << endl;
		int k1, k;
		switch (q - 48)
		{
		case 1:
			AddN(matr, n, m);
			break;
		case 2:
			AddM(matr, n, m);
			break;

		case 3:
			AddUserN(matr, n, m);
			break;

		case 4:
			AddUserM(matr, n, m);
			break;

		case 5:
			cout << "chose coloms : " << endl;
			k = _getch() - 48;
			DeCol(matr, n, m, k);
			break;
		case 6:
			cout << "choose row: " << endl;
			k = _getch() - 48;
			DelSTR(matr, n, m, k);
			break;
		case 7:
			cout << "choose coloms what you whant to swap " << endl;
			k = _getch() - 48;
			cout << k << endl;
			k1= _getch() - 48;
			cout << k1 << endl;
			SwapCol(matr, n, m, k, k1);
			break;
		case 8:
			cout << "choose str what you whant to swap " << endl;
			k = _getch() - 48;
			cout << k << endl;
			k1 = _getch() - 48;
			cout << k1 << endl;
			Swapstr(matr, n, m, k, k1);
			break;

		}

	} while (q != 27);
Del(matr, n);
	system("pause");
}


void Del(int **matr, int n)
{
	for (int i = 0;i < n;i++)
		delete[]matr[i];

	delete[]matr;
}
void Menu()
{

	cout << "if you wanna exit , press ESC : " << endl;
	cout << "Press 1 to add string : " << endl;
	cout << "Press 2 to add coloums : " << endl;
	cout << "Press 3 to add user string : " << endl;
	cout << "Press 4 to add user colums : " << endl;
	cout << "Press 5 to delete user coloms : " << endl;
	cout << "Press 6 to delete user str : " << endl;
	cout << "Press 7 to swap coloms : " << endl;
	cout << "Press 8 to swap str : " << endl;


}
void AddN(int **&matr, int &n, int m)
{
	int *mas = new int[m];
	for (int i = 0;i < m;i++)
		mas[i] = rand() % 10;

	int **temp = new int*[n + 1];
	for (int i = 0;i < n;i++)
		temp[i] = matr[i];
	temp[n] = mas;
	n++;
	delete[]matr;
	matr = temp;
	Print(matr, n, m);
}
void AddM(int **&matr, int n, int &m)
{
	int **temp = new int*[n];
	for (int i = 0;i < n;i++)
	{
		temp[i] = new int[m + 1];
		for (int j = 0;j < m;j++)
			temp[i][j] = matr[i][j];
		temp[i][m] = rand() % 10;
	}
	m++;
	for (int i = 0;i < n;i++)
		delete[]matr[i];
	delete[]matr;
	matr = temp;
	Print(matr, n, m);


}
void Print(int **matr, int n, int m)
{
	system("cls");
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++)
			cout << matr[i][j] << "\t";
		cout << endl;
	}
}
void AddUserN(int **&matr, int &n, int m)
{
	int *mas = new int[m];
	int z;
	for (int i = 0;i < m;i++) {
		z = _getch();
		cout << z - 48 << endl;
		mas[i] = (char)z - 48;
	}
	int **temp = new int*[n + 1];
	for (int i = 0;i < n;i++)
		temp[i] = matr[i];
	temp[n] = mas;
	n++;
	delete[]matr;
	matr = temp;
	Print(matr, n, m);
}
void AddUserM(int **&matr, int n, int &m)
{
	int **temp = new int*[n];
	for (int i = 0;i < n;i++)
	{
		temp[i] = new int[m + 1];
		for (int j = 0;j < m;j++)
			temp[i][j] = matr[i][j];
		temp[i][m] = _getch() - 48;
		cout << temp[i][m] << endl;

	}

	m++;
	for (int i = 0;i < n;i++)
		delete[]matr[i];
	delete matr;
	matr = temp;
	Print(matr, n, m);

}
void DeCol(int **&matr, int &n, int &m, int k)
{

	int **temp = new int*[n];

	for (int i = 0;i < n;i++)
		temp[i] = new int[m - 1];


	for (int i = 0; i < n; i++)
	{
		int p = 0;
		for (int j = 0; j < m; j++)
		{
			if (j == k)
				continue;
			temp[i][p++] = matr[i][j];
		}
	}

	m--;
	for (int i = 0;i < n;i++)
		delete[] matr[i];
	delete[]matr;
	matr = temp;
	Print(matr, n, m);
}
void DelSTR(int **&matr, int &n, int m, int k1)
{
	int **temp = new int*[n - 1];
	int * tt = matr[k1];
	int p = 0;
	for (int i = 0;i < n;i++)
	{
		if (i == k1)
			continue;
		temp[p++] = matr[i];
	}


	n--;

	delete tt;
	delete[]matr;

	matr = temp;
	Print(matr, n, m);
}
void SwapCol(int **&matr, int &n, int &m, int k, int k1)
{
	int *temp=new int[m];
	for (int i = 0;i< n;i++)
	{
		*temp = matr[i][k];
		matr[i][k] = matr[i][k1];
		matr[i][k1] = *temp;
	}
Print(matr, n, m);
}
void Swapstr(int **&matr, int &n, int &m, int k, int k1)
{
	{
		int *temp = new int[m];
		temp = matr[k];
			matr[k] = matr[k1];
			matr[k1] = temp;
		
		Print(matr, n, m);
	}
}