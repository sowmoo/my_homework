#include <stdio.h>
#include <string.h>
#include <Windows.h>

void frequency_count(int *alphabetlist, char *ciphertext);
void print_alphabet_list(int *alphabetlist);
void change_text(char findalphabet, char changealphabet, char *text);
void print_text(char *text);
void print_change_list(char *changelist);

int main()
{
	int alphabetlist[26] = { 0 };
	char ciphertext[] = {"MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVC\n\n"
						 "TVWJCZAAXZBCSSCJXBQCJZCOJZCNSPOXBXSBTVWJC\n\n"
					     "JZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLH\n\n"
						 "JZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX\n\n" 
						};

	char changelist[26] = { 0 };

	print_text(ciphertext);
	frequency_count(alphabetlist, ciphertext);
	print_alphabet_list(alphabetlist);
	print_change_list(changelist);


	while (1)
	{
		printf("변경하실 알파벳을 입력해주세요 >> ");
		char findalphabet = getchar();

		
		while (getchar() != '\n');
		if (findalphabet == '.')
		{
			break;
		}
		
		printf("어떤 알파벳으로 변경하시겠습니까? >> ");
		char changealphabet = getchar();
		system("cls");

		while (getchar() != '\n');

		changelist[findalphabet - 65] = changealphabet;
		printf("\n");

		print_alphabet_list(alphabetlist);
		print_change_list(changelist);
		change_text(findalphabet, changealphabet, ciphertext);
		print_text(ciphertext);


	}

}

void frequency_count(int *alphabetlist, char *ciphertext)
{
	int len = strlen(ciphertext);
	for (int i = 0; i < len; i++)
	{
		if (*(ciphertext + i) >= 65 && *(ciphertext + i) <= 90)
		{
			alphabetlist[*(ciphertext + i) - 65]++;
		}
	}
}


void print_alphabet_list(int *alphabetlist)
{
	for (int i = 0; i < 26; i++)
	{
		if (i % 6 == 0)
		{
			printf("\n");
		}

		printf("%c : %5d    ", 65 + i, alphabetlist[i]);
	}

	printf("\n");
}


void print_text(char *text)
{
	printf("%s\n\n", text);
}

void change_text(char findalphabet, char changealphabet, char *text)
{
	int len = strlen(text);

	for (int i = 0; i < len; i++)
	{
		if (*(text + i) == findalphabet)
		{
			text[i] = changealphabet;
		}
	}
}

void print_change_list(char *changelist)
{
	for (int i = 0; i < 26; i++)
	{
		if (i % 6 == 0)
		{
			printf("\n");
		}
		printf("%c -> %c\t", 65 + i, changelist[i]);
	}

	printf("\n\n");
}


