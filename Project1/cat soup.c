﻿#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

#define ROOM_WIDTH 15
#define HME_POS 1
#define BWL_PO (ROOM_WIDTH -2)

int main(void) {
	srand(time(NULL));
	int cat_position = 1, cat_previous_position = cat_position;
	int lev = 2; int soup = 0; int cp = 0; int cat_feel = 3; 
	int rat = 0; int laser = 0; int scratcher = 0; int tower = 0;
	int SCRATCHER_POS = 0; int TOWER_POS = 0;
	int home_point = 0;
	int repetition = 1;
	
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
		
		if (repetition == 3) {
			printf("돌발상황 발생\n\n");
			printf("고양이가 컵을 깨버렸다.\n");
			printf("당신이 해야 할 일은?\n\n");
			printf("1. 고양이에게 혼낸다.\n");
			printf("2. 고양이에게 간식을 준다.\n");
			printf("3. 컵을 치운다\n");

			while (1) {
				int choice;
				printf(">>");
				scanf_s("%d", &choice);
				getchar();
				if (choice == 1) {
					printf("고양이가 기분이 나빠졌습니다.\n");
					printf("기분, 친밀도가 최하로 조정되고 모든 CP가 사라집니다.\n");
					cat_feel = 0;
					cp = 0;
					lev = 0;
					break;
				}
				else if (choice == 2) {
					printf("고양이가 기분이 좋아졌습니다.\n");
					cat_feel++;
					if (cat_feel > 3) {
						cat_feel = 3;
					}
					break;
				}
				else if (choice == 3) {
					printf("컵을 치웠습니다.\n");
					printf("당연히 컵을 먼저 치워야죠.\n");
					printf("고양이는 아무것도 몰라요.\n");
					break;
				}
			}
			repetition++;
			Sleep(2500);
			system("cls");
			continue;
		}
		
		
		
		
		
		
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
			printf(" 간식자판기 취급입니다.");
		}
		else if (lev == 2) {
			printf(" 그럭저럭 쓸만한 집사입니다.");
		}
		else if (lev == 3) {
			printf(" 훌륭한 집사로 인정받고 있습니다.");
		}
		else {
			printf(" 집사껌딱지입니다.");
		}
		printf("\n==================================================\n\n");
		Sleep(500);

		
	
		//기분 주사위
		int feeldice = (rand() % 6) + 1;
		printf("6-친밀도: 그냥 기분이 나빠집니다.\n");
		printf("주사위를 굴립니다. 또르륵...\n");
		printf("%d이(가) 나왔습니다!\n", feeldice);
		if (feeldice <= 6 - lev) {
			if (cat_feel > 0) {
				printf("아무 이유 없이 기분이 나빠집니다. 고양이니까?\n");
				cat_feel--;
			}
			else {
				printf("기분이 최하입니다.\n");
			}
		}

		
		
		cat_previous_position = cat_position;
		if (cat_feel == 3) {
			//냄비 쪽으로 이동
			printf("냄비 쪽으로 이동합니다.\n\n");
			if (cat_position < BWL_PO) {
				 cat_position++;
			}
		}
		else if (cat_feel == 0) {
			//집으로 이동
			printf("집 쪽으로 이동합니다.\n\n");
			if (cat_position > HME_POS) {
				cat_position--;
			}
		}
		else if (cat_feel == 1){
			if (scratcher == 0 && tower == 0) {
				if (cat_feel > 0) {
					printf("놀 거리가 없어서 기분이 매우 나빠집니다.\n");
					cat_feel--;
				}
				else {
					printf("기분이 최하입니다.\n");
				}
			}
			else {
				int distance_S = abs(cat_position - SCRATCHER_POS);
				int distance_T = abs(cat_position - TOWER_POS);
				if (distance_S < distance_T) {
					printf("%s는 심심해서 스크래처 쪽으로 이동합니다.\n\n", catname);
					if (cat_position < SCRATCHER_POS) {
						cat_position++;
					}
					else if (cat_position > SCRATCHER_POS) {
						cat_position--;
					}
				}
				else if (distance_T < distance_S) {
					printf("%s는 심심해서 캣타워 쪽으로 이동합니다.\n\n", catname);
					if (cat_position < TOWER_POS) {
						cat_position++;
					}
					else if (cat_position > TOWER_POS) {
						cat_position--;
					}
				}
			}
		}
		else if (cat_feel == 2) {
			printf("%s은(는) 기분좋게 식빵을 굽고 있습니다.\n", catname);
		}
		
		if (cat_position == HME_POS) {
			home_point++;
			if (home_point >= 2) {
				if (cat_feel < 3) {
					cat_feel++;
					printf("집에서 %d턴 쉼 기분+1\n", home_point);
				}
				else {
					printf("집에서 %d턴 쉼 기분이 최상입니다.\n", home_point);
				}
			}
		}
		else {
			home_point = 0;
		}

		//수프 만들기
		if (cat_position == BWL_PO) {
			soup++;
			int soup_kind = rand() % 3;
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

		if (cat_position == SCRATCHER_POS) {
			if (cat_feel < 3) {
				printf("%s은(는) 스크래처를 긁고 놀았습니다. 기분이 조금 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 1);
				cat_feel++;
			}
			else {
				printf("%s은(는) 스크래처를 긁고 놀았습니다. 기분이 최상입니다.\n", catname);
			}
		}
		if (cat_position == TOWER_POS) {
			if (cat_feel < 2) {
				printf("%s은(는) 캣타워를 뛰어다니며 놀았습니다. 기분이 제법 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 2);
				cat_feel += 2;
			}
			else if (cat_feel == 3) {
				printf("%s은(는) 캣타워를 뛰어다닙니다. 기분이 최상입니다.\n", catname);
			}
			else if (cat_feel == 2) {
				printf("%s은(는) 캣타워를 뛰어다니며 놀았습니다. 기분이 제법 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 1);
				cat_feel++;
			}
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
			else if (i == SCRATCHER_POS) {
				printf("S");
			}
			else if (i == TOWER_POS) {
				printf("T");
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
		
		printf("0. 아무 것도 하지 않음\n");
		printf("1. 긁어 주기\n");
		if (rat == 1 && laser == 0) {
			printf("2. 장난감쥐로놀아주기\n");
		}
		if (laser == 1 && rat == 0) {
			printf("2. 레이저 포인터로 놀아 주기\n");
		}
		if (rat == 1 && laser == 1) {
			printf("2. 장난감쥐로놀아주기\n");
			printf("3. 레이저 포인터로 놀아 주기\n");
		}

		while (1) {
			printf(">>");
			scanf_s("%d", &interaction);
			getchar();

			if (interaction == 0) {
				printf("아무 것도 하지 않습니다.\n");
				if (cat_feel > 0) {
					printf("%s의 기분이 나빠졌습니다: %d->%d\n", catname, cat_feel, cat_feel - 1);
					cat_feel--;
				}
				else {
					printf("기분이 최하입니다.\n");
				}
				printf("친밀도는 주사위를 던져서 눈이 5 이하이면 1 감소\n");

				int dice = (rand() % 6) + 1;
				printf("%d(이)가 나왔습니다!\n", dice);

				if (dice == 6) {
					printf("다행이 친밀도가 떨어지지 않았습니다.");
				}
				else {
					if (lev > 0) {
						lev--;
						printf("집사와의 관계가 나빠집니다.");
					}
					else {
						printf("친밀도가 최하입니다.");
					}
				}
				break;
			}
			else if (interaction == 1) {
				printf("%s의 턱을 긁어주었습니다.\n", catname);
				printf("%s의 기분은 그대로입니다: %d\n", catname, cat_feel);
				printf("친밀도는 주사위 5 이상이면 1 증가\n");

				int dice = (rand() % 6) + 1;
				printf("%d(이)가 나왔습니다!\n", dice);

				if (dice == 5 || dice == 6) {
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
				break;
			}
			else if (interaction == 2) {
				if ((rat == 1 && laser == 0) || (rat == 1 && laser == 1)) {
					printf("장난감 쥐로 %s와 놀아주었습니다.\n", catname);
					if (cat_feel < 3) {
						printf("%s의 기분이 조금 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 1);
						cat_feel++;
					}
					else {
						printf("%s의 기분은 최상입니다: %d\n", catname, cat_feel);
					}
					printf("친밀도는 주사위 4 이상이면 1 증가\n");

					int dice = (rand() % 6) + 1;
					printf("%d(이)가 나왔습니다!\n", dice);

					if (dice >= 4) {
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
					break;
				}
				else if (rat == 0 && laser == 1) {
					printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", catname);
					if (cat_feel == 3) {
						printf("%s의 기분은 최상입니다: %d\n", catname, cat_feel);
					}
					else if (cat_feel == 2) {
						printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 1);
						cat_feel++;
					}
					else {
						printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 2);
						cat_feel += 2;
					}
					printf("친밀도는 주사위 2 이상이면 1 증가\n");
					int dice = (rand() % 6) + 1;
					printf("%d(이)가 나왔습니다!\n", dice);
					if (dice >= 2) {
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
					break;
				}
			}
			else if (interaction == 3) {
				if (laser == 0 || rat == 0) {
					continue;
				}
				printf("레이저 포인터로 %s와 신나게 놀아 주었습니다.\n", catname);
				if (cat_feel == 3) {
					printf("%s의 기분은 최상입니다: %d\n", catname, cat_feel);
				}
				else if (cat_feel == 2) {
					printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 1);
					cat_feel++;
				}
				else {
					printf("%s의 기분이 꽤 좋아졌습니다: %d -> %d\n", catname, cat_feel, cat_feel + 2);
					cat_feel += 2;
				}
				printf("친밀도는 주사위 2 이상이면 1 증가\n");
				int dice = (rand() % 6) + 1;
				printf("%d(이)가 나왔습니다!\n", dice);
				if (dice >= 2) {
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
				break;
			}
		}

		int cp_increase;
		if ((cat_feel - 1) < 0) {
			cp_increase = 0;
		}
		else {
			cp_increase = (cat_feel - 1) + lev;
		}
		cp += cp_increase;
		printf("\n\n%s의 기분(0~3): %d\n", catname, cat_feel);
		printf("집사와의 친밀도(0~4): %d\n", lev);
		printf("%s의 기분과 친밀도에 따라서 CP가 %d포인트 생산되었습니다.\n", catname, cp_increase);
		printf("보유 CP: %d 포인트\n\n", cp);
		


		printf("상점에서 물건을 살 수 있습니다.\n");
		printf("어떤 물건을 구매할까요?\n");
		printf(" 0. 아무 것도 사지 않는다.\n");
		printf(" 1. 장난감 쥐: 1 CP"); if (rat == 1) { printf(" (품절)"); } printf("\n");
		printf(" 2. 레이저 포인터: 2 CP"); if (laser == 1) { printf(" (품절)"); } printf("\n");
		printf(" 3. 스크래처: 4 CP"); if (scratcher == 1) { printf(" (품절)"); } printf("\n");
		printf(" 4. 캣타워: 6 CP"); if (tower == 1) { printf(" (품절)"); } printf("\n");
		while (1) {
			int buy;
			printf(">>");
			scanf_s("%d", &buy);
			getchar();

			if (buy == 0) {
				break;
			}
			else if (buy == 1) {
				if (rat == 1) {
					printf("장난감 쥐를 이미 구매했습니다.\n");
					continue;
				}
				else if (cp >= 1) {
					printf("장난감 쥐를 구매했습니다.\n");
					rat = 1;
					cp -= 1;
					printf("보유 CP %d 포인트\n", cp);
				}
				else {
					printf("CP가 부족합니다.\n");
				}
				break;
			}
			else if (buy == 2) {
				if (laser == 1) {
					printf("레이저 포인터를 이미 구매했습니다.\n");
					continue;
				}
				else if (cp >= 2) {
					printf("레이저 포인터를 구매했습니다.\n");
					laser = 1;
					cp -= 2;
					printf("보유 CP %d 포인트\n", cp);
				}
				else {
					printf("CP가 부족합니다.\n");
				}
				break;
			}
			else if (buy == 3) {
				if (scratcher == 1) {
					printf("스크래쳐를 이미 구매했습니다.\n");
					continue;
				}
				else if (cp >= 4) {
					printf("스크래처를 구매했습니다.\n");
					scratcher = 1;
					cp -= 4;
					printf("보유 CP %d 포인트\n", cp);
					
					while (1) {
						SCRATCHER_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (SCRATCHER_POS != HME_POS && SCRATCHER_POS != BWL_PO && SCRATCHER_POS != TOWER_POS) {
							break;
						}
					}
				}
				else {
					printf("CP가 부족합니다.\n");
				}
				break;
			}
			else if (buy == 4) {
				if (tower == 1) {
					printf("캣타워를 이미 구매했습니다.\n");
					continue;
				}
				else if (cp >= 6) {
					printf("캣타워를 구매했습니다.\n");
					tower = 1;
					cp -= 6;
					printf("보유 CP %d 포인트\n", cp);
					while (1) {
						TOWER_POS = (rand() % (ROOM_WIDTH - 2)) + 1;
						if (TOWER_POS != HME_POS && TOWER_POS != BWL_PO && TOWER_POS != SCRATCHER_POS) {
							break;
						}
					}
				}
				else {
					printf("CP가 부족합니다.\n");
				}
				break;
			}
			else {
				continue;
			}
		}
		repetition++;
		Sleep(2500);
		system("cls");

	}
	return 0;
}