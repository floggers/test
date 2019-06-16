#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

#define MAX_ROW 3
#define MAX_COL 3

char chess_borad[MAX_ROW][MAX_COL];

int screen(){
	printf("***************************************\n");
	printf("             1.开始游戏\n");
	printf("             0.退出游戏\n");
	printf("***************************************\n");
	printf("请输入你的选择:");
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
	printf("玩家请落子!\n");
	while (1) {
		printf("请输入一组坐标(row,col)!\n");
		scanf("%d %d", &row, &col);
		if (chess_borad[row][col] != ' ') {
			printf("该处已有棋子,请重新落子!\n");
			continue;
		}
		else if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("非法坐标,请重新输入!\n");
			continue;
		}
		else {
			chess_borad[row][col] = 'x';
			break;
		}
	}
}

void ComputerMove() {
			printf("电脑正在落子!\n");
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
     //1.初始化棋盘
	 Init();
	 char winner=' ';
	 while (1) {
		 system("cls");
	 //2.打印棋盘
		 print();
	 //3.玩家落子
		 PlayerMove();
	 //4.检测游戏是否结束
		  winner = CheckGameOver();
		 if (winner != ' ') {
			 break;
		 }
	 //5.电脑落子
		 ComputerMove();
	 //6.检测游戏是否结束
		  winner = CheckGameOver();
		  if (winner !=' '){
			  break;
		  }
	 }
	 system("cls");
	 if (winner == 'x'){
		 printf("恭喜你,打赢了电脑!\n");
		 print();
	 }
	 else if (winner == 'o'){
		 printf("很遗憾,电脑胜利!\n");
		 print();
	 }
	 else if (winner == 'q'){
		 printf("你和电脑打平了!\n");
		 print();
	 }
	 else {
		 printf("出错了!\n");
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
			printf("下次再见!\n");
			break;
		}
	}
	system("pause");
	return 0;
}