#include <stdio.h>
#include <string.h>
#include <Windows.h>

void frequency_count(int *alphabetlist, char *ciphertext); // ���ĺ� ī���� 
void print_alphabet_list(int *alphabetlist); // ī���õ� ���ĺ� ��� 
void change_text(char findalphabet, char changealphabet, char *text); //���� ������ ���ĺ��� ���� �ϴ� �Լ� 
void print_text(char *text);   //��ȣ�� ����Լ� main�Լ� char ciphertext[] �迭 ���
void print_change_list(char *changelist); //�ٲ� ����� �ٽ���� 

int main()
{
	int alphabetlist[26] = { 0 };
	char ciphertext[] = { "MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVC\n\n"
						 "TVWJCZAAXZBCSSCJXBQCJZCOJZCNSPOXBXSBTVWJC\n\n"
						 "JZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLH\n\n"
						 "JZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX\n\n"
	}; //��ȣ�� 

	char changelist[26] = { 0 };

	/*
		 �ʱ�ȭ�� ���� �ѹ��� ��� do while�� ��� �ϳ� ��Ή����� ....
		 do while�� �������ؼ� �������  
		 ������ ���� ���������δ� ū���̾��� 
	*/
	print_text(ciphertext); //��ȣ�� ��� char ciphertext[]
	frequency_count(alphabetlist, ciphertext); //�� ���ĺ��� ���� ī���� 
	print_alphabet_list(alphabetlist); // ���ĺ� ī���� ��� ��� 
	print_change_list(changelist); // �ٲ��� ��� (���� ���� ��� ��ä�ߴ����� �˱�����) 


	while (1)
	{
		printf("�����Ͻ� ���ĺ��� �Է����ּ��� >> ");
		char findalphabet = getchar();

		while (getchar() != '\n'); //���� û�����ֱ� 

		if (findalphabet == '.')
		{
			break;
		}

		printf("� ���ĺ����� �����Ͻðڽ��ϱ�? >> ");
		char changealphabet = getchar(); 
		system("cls"); //ȭ������� 

		while (getchar() != '\n'); //���� û�����ֱ� 

		changelist[findalphabet - 65] = changealphabet; 
		/* 
			a - 65 = 0
			b - 65 = 1
			...
			
			������ ���� �۾����� ���ϼ����� 
		*/
		printf("\n");

		print_alphabet_list(alphabetlist); //��ȣ�� ��� char ciphertext[]
		print_change_list(changelist); //�� ���ĺ��� ���� ī����
		change_text(findalphabet, changealphabet, ciphertext); // ���ĺ� ī���� ��� ��� 
		print_text(ciphertext);// �ٲ��� ��� (���� ���� ��� ��ä�ߴ����� �˱�����) 

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


void print_text(char *text) // ����Ʈ���� ~!!! ��ȣ�� ��� �Լ� 
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