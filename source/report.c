#include <stdio.h>
#include <string.h>
#include <Windows.h>

void frequency_count(int *alphabetlist, char *ciphertext); // 알파벳 카운팅 
void print_alphabet_list(int *alphabetlist); // 카운팅된 알파벳 출력 
void change_text(char findalphabet, char changealphabet, char *text); //원래 문장의 알파벳을 변경 하는 함수 
void print_text(char *text);   //암호문 출력함수 main함수 char ciphertext[] 배열 출력
void print_change_list(char *changelist); //어떤 알파벳을 바꿨는지 현재진행상황 출력 

int main()
{
	int alphabetlist[26] = { 0 };
	char ciphertext[] = { "MXDXBVTZWVMXNSPBQXLIMSCCSGXSCJXBOVQXCJZMOJZCVC\n\n"
						 "TVWJCZAAXZBCSSCJXBQCJZCOJZCNSPOXBXSBTVWJC\n\n"
						 "JZDXGXXMOZQMSCSCJXBOVQXCJZMOJZCNSPJZHGXXMOSPLH\n\n"
						 "JZDXZAAXZBXHCSCJXTCSGXSCJXBOVQX\n\n"
	}; //암호문 

	char changelist[26] = { 0 };

	/*
		 초기화를 위해 한번씩 출력 do while을 써야 하나 고민瑛립 ....
		 do while은 지저분해서 보기싫음  
		 어차피 내부 로직상으로는 큰차이없음 
	*/
	print_text(ciphertext); //암호문 출력 char ciphertext[]
	frequency_count(alphabetlist, ciphertext); //각 알파벳별 개수 카운팅 
	print_alphabet_list(alphabetlist); // 알파벳 카운팅 결과 출력 
	print_change_list(changelist); // 바뀐결과 출력 (내가 현재 어떤걸 교채했는지를 알기위함) 


	while (1)
	{
		printf("변경하실 알파벳을 입력해주세요 >> ");
		char findalphabet = getchar();

		while (getchar() != '\n'); //버퍼 청소해주기 

		if (findalphabet == '.')
		{
			break;
		}

		printf("어떤 알파벳으로 변경하시겠습니까? >> ");
		char changealphabet = getchar(); 
		system("cls"); //화면지우기 

		while (getchar() != '\n'); //버퍼 청소해주기 

		changelist[findalphabet - 65] = changealphabet; 
		/* 
			a - 65 = 0
			b - 65 = 1
			...
			
			함으로 좀더 작업량을 줄일수있음 
		*/
		printf("\n");

		print_alphabet_list(alphabetlist); //암호문 출력 char ciphertext[]
		print_change_list(changelist); //각 알파벳별 개수 카운팅
		change_text(findalphabet, changealphabet, ciphertext); // 알파벳 카운팅 결과 출력 
		print_text(ciphertext);// 바뀐결과 출력 (내가 현재 어떤걸 교채했는지를 알기위함) 

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


void print_text(char *text) // 레포트과제 ~!!! 암호문 출력 함수 
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
