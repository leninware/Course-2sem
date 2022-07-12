#include <stdio.h>
#include <time.h>
#include <stdlib.h>
struct List;
typedef List* Link_List;
typedef char* str;
struct List{
	Link_List next;
	str body;
};

str Alphabet =(str)"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789\0";
Link_List First, Last, Barrier;
int Lenght;
void add_first(str);
void add_back(str);
void remove_element(str);
void remove_element(int);
void print_lenght();
void print_list();
bool str_cmp(str, str);
void print_menu();
void insert_element(str, str);
void erase_list();
void generate_list(int);
str get_random_str(int);

int main()
{
	Barrier = new List;
	Barrier->body = NULL;
	Barrier->next = NULL;
	First = Last = Barrier;
	int cmd, id, len;
	str line = new char[20], line2 = new char[20];
	print_menu();
	for(;;)
	{
		printf("\nEnter the command: ");
		scanf("%d", &cmd);
		switch(cmd)
		{
			case 0:
				return 0;
			case 1:
				printf("Enter a new item: ");
				scanf("%s", line);
				add_first(line);
				line = new char[20];
				break;
			case 2:
				printf("Enter a new item: ");
				scanf("%s", line);
				add_back(line);
				line = new char[20];
				break;
			case 3:
				printf("Enter the element after which you want to insert: ");
				scanf("%s", line);
				printf("Enter a new item: ");
				scanf("%s", line2);
				insert_element(line, line2);
				line = new char[20];
				break;
			case 4:
				printf("Enter the item you want to delete: ");
				scanf("%s", line);
				remove_element(line);
				break;
			case 5:
				move();
				break;
			case 6:
				erase_list();
				break;
			case 7:
				print_lenght();
				break;
			case 8:
				print_list();
				break;
			case 9:
				print_menu();
				break;
			case 10:
				printf("Enter the length of the new list: ");
				scanf("%d", &len);
				generate_list(len);
				break;
			default:
				printf("Unknown command!\n");
				break;
		}
	}
}

str get_random_str(int lenght)
{
	str s = new char [lenght+1];
	for(int i = 0; i < lenght; i++)
	{
		//srand(time(NULL));
		s[i] = Alphabet[rand() % 62];
	}
	s[lenght] = '\0';
	return s;
}

void generate_list(int n)
{
	erase_list();
	for(int i = 0; i < n; i++)
	{
		add_first(get_random_str(rand()%10 + 3));
	}
}

void add_first(str element)
{
	Link_List tmp = First;
	First = new List;
	First->body = element;
	First->next = tmp;
	if(Last == Barrier)
	Last = First;
	Lenght++;
}

void add_back(str element)
{
	if(Last == Barrier)
	{
		add_first(element);
		return;
	}
	Link_List tmp = new List;
	Last->next = tmp;
	tmp->body = element;
	tmp->next = Barrier;
	Last = tmp;
	Lenght++;
}

void remove_element(str element)
{
	if(First == Barrier)
	{
		printf("List is empty!");
		return;
	}
	Link_List prev = NULL, cur = First;
	while(cur != Barrier)
	{
		if(str_cmp(cur->body, element))
		{
			if(!prev)
				First = cur->next;
			else
				prev->next = cur->next;
			delete cur;
			Lenght--;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
	printf("\nItem with this value not exists!\n");
}

void move()
{
	if (Lenght<=1)
		return;
	Link_List tmp = First;
	Link_List mid = First;
	for(int i = 1; tmp->next != Barrier; i++)
	{
		tmp = tmp->next;
		if (i==Lenght/2-1)
		mid = tmp;
	}
	tmp->next = First;
	First = mid->next;
	mid->next = Barrier;
}

void erase_list()
{
	Link_List tmp, cur = First;
	while(cur != Barrier)
	{
		tmp = cur->next;
		delete cur;
		cur = tmp;
	}
	First = Last = Barrier;
	Lenght = 0;
}

void insert_element(str old, str frash)
{
	if(First == Barrier)
	{
		printf("List is empty!");
		return;
	}
	Link_List cur = First;
	while(cur != Barrier)
	{
		if(str_cmp(cur->body, old))
		{
			Link_List f = new List;
			f->body = frash;
			f->next = cur->next;
			cur->next = f;
			Lenght++;
			return;
		}
		cur = cur->next;
	}
	printf("\nItem with this value not exists!\n");
}

void print_lenght()
{
	printf("List lenght is %d\n", Lenght);
}

bool str_cmp(str s1, str s2)
{
	int i;
	for(i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
		if(s1[i] != s2[i])
			return false;
	return s1[i] == s2[i];
}

void print_list()
{
	if(First == Barrier)
	{
		printf("List is empty\n");
		return;
	}
	printf("List:\n");
	Link_List tmp = First;
	for(int i = 1; tmp != Barrier; i++)
	{
		f("(%d) %s ", i, tmp->body);
		tmp = tmp->next;
	}
	printf("\n");
}

void print_menu()
{
	printf("available commands:\n");
	printf("0 --- exit programm\n");
	printf("1 --- Add an item to the top of the list.\n");
	printf("2 --- Add an item to the end of the list\n");
	printf("3 --- Insert an item in the list after another one\n");
	printf("4 --- Remove an item from the list by value\n");
	printf("5 --- Rearrange the first and second half of the list\n");
	printf("6 --- Erase list\n");
	printf("7 --- Print the list length\n");
	printf("8 --- Print list\n");
	printf("9 --- Print this menu\n");
	printf("10 --- Generation list by length\n");
	printf("\n");
}
