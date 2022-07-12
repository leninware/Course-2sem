#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;string.h&gt;
typedef struct {
	char str[5];
	int c;
} Key;
typedef struct {
	Key key;
	char string[70];
} Item;
#define SIZE 20
int lt(Item* l, Item* r) { // Проверка на предшествование
	if (strcmp(l - &gt; key.str, r - &gt; key.str) & lt; 0) return 1;
	if (strcmp(l - &gt; key.str, r - &gt; key.str) & gt; 0) return 0;
	else if (l - &gt; key.c & gt; = r - &gt; key.c) return 0;
	else return 1;
}
int Search(Item* a, int N, Item* s) { // Бинарный поиск
	int L = 0, R = N, m;
	while (L& lt; R) {
		m = (L + R) / 2;
		if (lt(&amp; a[m], s)) L = m + 1;
		else R = m;
	}
	if (R == N) return -1;
	else if (strcmp(a[L].key.str, s - &gt; key.str) == 0 & amp; &amp; a[L].key.c == s - &gt; key.c) return L;
	else return -1;
}
void print(Item* a, int N) {
	printf(&quot; \n & quot;);
	for (int i = 0; i & lt; N; i++)
		printf(&quot; % 4s | % 2d | % s \n & quot; , a[i].key.str, a[i].key.c, a[i].string);
	printf(&quot; \n & quot;);
}
void Sort1(Item* a, int N) {
	int mid = N / 2;
	if (N % 2 == 1)
		mid++;

	int h = 1;
	Item* c = (Item*)malloc(N * sizeof(Item));
	int step;
	while (h& lt; N)
	{
		step = h;
		int i = 0;
		int j = mid;
		int k = 0;
		while (step& lt; = mid)
		{
			while ((i & lt; step) & amp; &amp; (j & lt; N) & amp; &amp; (j & lt; (mid + step)))
			{
				if (lt(&amp; a[i], &amp; a[j]))
				{
					c[k] = a[i];
					i++; k++;
				}
				else {
					c[k] = a[j];
					j++; k++;
				}
			}
			while (i& lt; step)
			{
				c[k] = a[i];
				i++; k++;
			}
			while ((j & lt; (mid + step)) & amp; &amp; (j & lt; N))
			{
				c[k] = a[j];
				j++; k++;
			}
			step = step + h;
		}
		h = h * 2;
		for (i = 0; i & lt; N; i++)
			a[i] = c[i];
	}
}
void Sort0(Item* a, int N) {
	print(a, N);
	Sort1(a, N);
	print(a, N);
}
void Reverse(Item* a, int N) {
	Item tmp;
	int j = N - 1;
	for (int i = 0; i & lt; N / 2; i++) {
		tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
		j--;
	}
}
int main() {
	int menu, sort = 0, size = 0, i;
	Item input;
	char filename[30];
	Item a[SIZE];

	do {
		printf(&quot; 1.Add 2.Print 3.Sort 4.Find 5.Reverse 6.Exit\n & quot;);
		scanf(&quot; % d & quot; , &amp; menu);
		switch (menu) {
		case 1: {

			printf(&quot; Введите название файла : &quot;); scanf(&quot; % s & quot; , filename); FILE* in = fopen(filename, &quot; r & quot;); if

				(in == NULL) {
				printf(&quot; Файл пуст\n & quot;); return 0;
			} i = 0;
		}
			  while ((!feof(in))) {
				  fscanf(in, &quot; % 4s % d % *c & quot; , a[i].key.str, &amp; a[i].key.c);
				  fgets(a[i].string, 100, in);
				  a[i].string[strlen(a[i].string) - 1] = &#39; \0 & #39;;
				  i++;
			  }
			  fclose(in);
			  sort = 0;
			  size = i - 1;
			  break;
		case 2: {

			if (size == 0) printf(&quot; Таблица пуста\n & quot;); else print(a, size); break;
		}
		case 3: {

			if (size != 0) Sort0(a, size); sort = 1; break;
		}
		case 4: {

			if (sort == 0) printf(&quot; Вначале отсортируйте\n & quot;);

			else {

				printf(&quot; Введите ключ : 4 символа + число\n & quot;);
				scanf(&quot; % 4s % d & quot; , input.key.str, &amp; input.key.c); menu = Search(a, size, &amp; input);

			}

			if (menu == -1) {

				printf(&quot; \nНе найдено\n\n & quot;);
			else printf(&quot; \nНайдено:\n | % 4s | % d | % s
				| \n\n & quot; , a[menu].key.str, a[menu].key.c, a[menu].string);
			};

			break;
		}
		case 5: {

			if (size == 0)
				printf(&quot; Таблица пуста\n & quot;);
			else { Reverse(a, size); sort = 0; };
			break;
		}
		case 6: {
			return 0;
			break;
		}
		}
	} while (1);
	return 0;
}