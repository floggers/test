#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

char chess_borad[MAX_ROW][MAX_COL];

int screen(){
	printf("***************************************\n");
	printf("             1.��ʼ��Ϸ\n");
	printf("             0.�˳���Ϸ\n");
	printf("***************************************\n");
	printf("���������ѡ��:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init() {
	for (int row = 0;row < MAX_ROW;row++){
		for (int col = 0;col < MAX_COL;col++){
			chess_borad[row][col] = ' ';
		}
	}
}
void print() {
	for (int row = 0;row < MAX_ROW;row++) {
		printf("| %c | %c | %c |\n",chess_borad[row][0],chess_borad[row][1],chess_borad[row][2]);
		if (row != 2){
			printf("|---|---|---|\n");
		}
	}
}
void PlayerMove() {
	int row, col;
	printf("���������!\n");
	while (1) {
		printf("������һ������(row,col)!\n");
		scanf("%d %d", &row, &col);
		if (chess_borad[row][col] != ' ') {
			printf("�ô���������,����������!\n");
			continue;
		}
		else if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("�Ƿ�����,����������!\n");
			continue;
		}
		else {
			chess_borad[row][col] = 'x';
			break;
		}
	}
}

void ComputerMove() {
			printf("������������!\n");
			while (1) {
				int row = rand() % MAX_ROW;
				int col = rand() % MAX_COL;
				if (chess_borad[row][col] != ' ') {
					continue;
				}
				else {
					chess_borad[row][col] = 'o';
					break;
				}
			}
		}

int IsFull() {
	for (int row = 0;row < MAX_ROW;row++) {
		for (int col = 0;col < MAX_COL;col++) {
			if (chess_borad[row][col] == ' '){
				return 0;
			 }
	    }
	}
	return 1;
}

char CheckGameOver() {
		for (int row = 0;row < MAX_ROW;row++) {
				if (chess_borad[row][0] == chess_borad[row][1] && chess_borad[row][0] == chess_borad[row][2]) {
						return chess_borad[row][0];
					}
				}
		for (int col = 0;col < MAX_COL;col++) {
				if (chess_borad[0][col] == chess_borad[1][col] && chess_borad[0][col] == chess_borad[2][col]) {
						return chess_borad[0][col];
					}
				}
				if (chess_borad[0][0] == chess_borad[1][1] && chess_borad[0][0] == chess_borad[2][2]) {
					return chess_borad[0][0];
				}
				if (chess_borad[0][2] == chess_borad[1][1] && chess_borad[0][2] == chess_borad[2][0]){
						return chess_borad[0][2];
				}
				if (IsFull()) {
						return 'q';
					}
						return ' ';
			}
void Game() {
     //1.��ʼ������
	 Init();
	 char winner=' ';
	 while (1) {
		 system("cls");
	 //2.��ӡ����
		 print();
	 //3.�������
		 PlayerMove();
	 //4.�����Ϸ�Ƿ����
		  winner = CheckGameOver();
		 if (winner != ' ') {
			 break;
		 }
	 //5.��������
		 ComputerMove();
	 //6.�����Ϸ�Ƿ����
		  winner = CheckGameOver();
		  if (winner !=' '){
			  break;
		  }
	 }
	 system("cls");
	 if (winner == 'x'){
		 printf("��ϲ��,��Ӯ�˵���!\n");
		 print();
	 }
	 else if (winner == 'o'){
		 printf("���ź�,����ʤ��!\n");
		 print();
	 }
	 else if (winner == 'q'){
		 printf("��͵��Դ�ƽ��!\n");
		 print();
	 }
	 else {
		 printf("������!\n");
	 }
}

int main() {
	while (1)
	{
		int choice = screen();
		if (choice == 1) {
			Game();
		}
		else if (choice==0)
		{
			printf("�´��ټ�!\n");
			break;
		}
	}
	system("pause");
	return 0;
}