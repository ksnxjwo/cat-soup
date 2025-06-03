#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 10
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main(void) {
	srand(time(NULL));
	int cat_position = 1, cat_previous_position = cat_position;
	int lev = 2; int soup = 0; int cp = 0; int cat_feel = 0;

	//이름짓기
	char catname[100];
	printf("****야옹이와수프****\n\n");
	printf("      /\\_/\\ \n");
	printf(" /\\  / o o \\\n");
	printf("//\\\\ \\~(*)~/\n");
	printf("`  \\/   ^ / \n");
	printf("   | \\|| || \n");
	printf("   \\ '|| || \n");
	printf("    \\)()-())\n\n");
	
	
	
	printf("야옹이의 이름을 지어주세요: "); 
	scanf_s("%s", catname, 100, sizeof(catname));
	printf("야옹이의 이름은 %s입니다.\n", catname);
	
	Sleep(2500);
	system("cls");
	
	

	while (1) {
		//상태
		printf("==================== 현재상태===================\n");
		printf("현재까지만든수프: %d개\n", soup);
		printf("CP: %d 포인트\n", cp);
		printf("%s이 기분(0~3): %d\n", catname, cat_feel);
		if (cat_feel == 0) {
			printf("  기분이 매우 나쁩니다.\n");
		}
		else if (cat_feel == 1) {
			printf("  심심해합니다.\n");
		}
		else if (cat_feel == 2) {
			printf("  식빵을 굽습니다.\n");
		}
		else if (cat_feel == 3) {
			printf("  골골송을 부릅니다.\n");
		}
		printf("집사와의관계(0~4): %d\n", lev);
		if (lev == 0) {
			printf(" 곁에 오는 것 조차 싫어합니다.");
		}
		else if (lev == 1) {
			printf(" 간식자판기취급입니다.");
		}
		else if (lev == 2) {
			printf(" 그럭저럭쓸만한집사입니다.");
		}
		else if (lev == 3) {
			printf(" 훌륭한집사로인정받고있습니다.");
		}
		else {
			printf(" 집사껌딱지입니다.");
		}
		printf("\n==================================================\n\n");
		Sleep(500);

		
	
		//룸 
		int roomdice = (rand() % 6) + 1;
		printf("%s이동: 집사와 친밀할 수록 냄비 쪽으로 갈 확률이 높아집니다.\n", catname);
		printf("주사위 눈이 3 이상이면 냄비 쪽으로 이동합니다.\n");
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이(가) 나왔습니다!\n", roomdice);

		cat_previous_position = cat_position;
		if (roomdice >= (6 - lev)) {
			//냄비 쪽으로 이동
			printf("냄비 쪽으로 이동합니다.\n\n");
			if (cat_position < BWL_PO) {
				 cat_position++;
			}
		}
		else {
			//집으로 이동
			printf("집 쪽으로 이동합니다.\n\n");
			if (cat_position > HME_POS) {
				 cat_position--;
			}
		}
		//수프 만들기
		if (cat_position == BWL_PO) {
			soup++;
			int soup_kind = rand() % 2;
			switch (soup_kind) {
			case 0:
				printf("%s(이)가 감자 수프를 만들었습니다!", catname);
				break;
			case 1:
				printf("%s(이)가 양송이 수프를 만들었습니다!", catname);
				break;
			case 2:
				printf("%s(이)가 브로콜리 수프를 만들었습니다!", catname);
				break;
			}
			printf("\n현재까지 만든 수프: %d개\n", soup);
		}


		//첫 줄
		printf("\n");
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n");
		//두 줄, 집 냄비 줄
		printf("#");
		for (int i = 1; i <= (ROOM_WIDTH - 2); i++) {
			if (i == HME_POS) {
				printf("H");
			}
			else if (i == BWL_PO) {
				printf("B");
			}
			else {
				printf(" ");
			}
		}
		printf("#\n");
		//세 줄, 고양이 줄
		printf("#");
		for (int i = 1; i <= (ROOM_WIDTH - 2); i++) {
			if (i == cat_position) {
				printf("C");
			}
			else if (i == cat_previous_position) {
				printf(".");
			}
			else {
				printf(" ");
			}
		}
		//네 줄
		printf("#\n");
		for (int i = 0; i < ROOM_WIDTH; i++) {
			printf("#");
		}
		printf("\n\n");

		Sleep(500);
		//상호작용
		int interaction;
		printf("\n어떤 상호작용을 하시겠습니까?\n");
		printf("0. 아무 것도 하지 않음    1. 긁어 주기\n");

		do {
			printf(">>");
			scanf_s("%d", &interaction);
			getchar();
		} while (interaction != 0 && interaction != 1);


		if (interaction == 0) {
			printf("아무 것도 하지 않습니다.\n");
			printf("4/6확률로 친밀도가 떨어집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");

			int dice = (rand() % 6) + 1;

			printf("%d(이)가 나왔습니다!\n", dice);
			if (dice > 4) {
				printf("다행이 친밀도가 떨어지지 않았습니다.");
			}
			else {
				if (lev > 0) {
					lev--;
					printf("친밀도가 떨어집니다.");
				}
				else {
					printf("친밀도가 최하입니다.");
				}
			}
		}
		else {
			printf("%s의 턱을 긁어주었습니다.\n", catname);
			printf("2/6확률로 친밀도가 높아집니다.\n");
			printf("주사위를 굴립니다. 또르륵...\n");

			int dice = (rand() % 6) + 1;

			printf("%d(이)가 나왔습니다!\n", dice);
			if (dice > 4) {
				if (lev < 4) {
					printf("친밀도가 높아집니다.");
					lev++;
				}
				else {
					printf("친밀도가 최상입니다.");
				}
			}
			else {
				printf("친밀도는 그대로입니다.");
			}
		}
		printf("현재 친밀도: %d", lev);

		Sleep(2500);
		system("cls");

		if (cat_position == HME_POS) {
			printf("%s은(는)자신의집에서편안함을느낍니다.\n", catname);
			//첫 줄
			printf("\n");
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n");
			//두 줄, 집 냄비 줄
			printf("#");
			for (int i = 1; i <= (ROOM_WIDTH - 2); i++) {
				if (i == HME_POS) {
					printf("H");
				}
				else if (i == BWL_PO) {
					printf("B");
				}
				else {
					printf(" ");
				}
			}
			printf("#\n");
			//세 줄, 고양이 줄
			printf("#");
			for (int i = 1; i <= (ROOM_WIDTH - 2); i++) {
				if (i == cat_position) {
					printf("C");
				}
				else if (i == cat_previous_position) {
					printf(".");
				}
				else {
					printf(" ");
				}
			}
			printf("#\n");
			for (int i = 0; i < ROOM_WIDTH; i++) {
				printf("#");
			}
			printf("\n\n");
			Sleep(2500);
			system("cls");
		}
	}
	return 0;
}