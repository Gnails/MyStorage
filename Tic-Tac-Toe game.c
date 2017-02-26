#define Y 'O' 
#define N 'N' 
#include<stdio.h>
#include<memory.h>
#include<stdlib.h>

bool Check(int s[][3], char m)
{
	if (s[(m - '0' - 1) / 3][(m - '0' - 1) % 3] != 0)
		return 0;
	return 1;
}

void Move_1(char b[][5],int s[][3],char m)
{
	if (m=='\n')
		Move_1(b, s, getchar());
	else
	{
		if (!Check(s, m))
				{
					printf("This position was OCCUPIED,please try again! \n");
					Move_1(b, s, getchar());
				}
		else
		{
		
				int m_tem;
				m_tem = m - '0';

				s[(m_tem - 1) / 3][(m_tem - 1) % 3] = 1;
				switch (m)
				{
				case '1': b[0][0] = N; break;
				case '2': b[0][2] = N; break;
				case '3': b[0][4] = N; break;
				case '4': b[2][0] = N; break;
				case '5': b[2][2] = N; break;
				case '6': b[2][4] = N; break;
				case '7': b[4][0] = N; break;
				case '8': b[4][2] = N; break;
				case '9': b[4][4] = N; break;
				}
	}
	}
}

void Move_2(char b[][5], int s[][3], char m)
{
	if (m == '\n')

		Move_2(b, s, getchar());
	
	else
	{

		if (!Check(s, m))
		{
			printf("This position was OCCUPIED,please try again! \n");
			Move_2(b, s, getchar());
		}
		else
		{	
	
				int m_tem;
				m_tem = m - '0';

				s[(m_tem - 1) / 3][(m_tem - 1) % 3] = 2;
				switch (m)
				{
				case '1': b[0][0] = Y;	break;
				case '2': b[0][2] = Y;	break;
				case '3': b[0][4] = Y;	break;
				case '4': b[2][0] = Y;	break;
				case '5': b[2][2] = Y;	break;
				case '6': b[2][4] = Y;	break;
				case '7': b[4][0] = Y;	break;
				case '8': b[4][2] = Y;	break;
				case '9': b[4][4] = Y;	break;
				}
	}
	
	}

}

void show_board(char board[][5])
{
	for (int i = 0; i < 5; i++)
	{
		    printf("                        ");
		for (int j = 0; j < 5; j++)
			printf("   %c", board[i][j]);
		    printf("\n");


	}
}
void show_Array(int symplify[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			printf("%c", symplify[i][j]+'0' );
		printf("\n");


	}
}
bool Judge(int c[][3],int jud)
{
	int s[3][3];
	int sum[4] = {0};
	memset(s, 0, 36);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (c[i][j] == jud)
				s[i][j] = 1;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			sum[0] = sum[0] + s[i][j];
			sum[1] = sum[1] + s[j][i];
			if (sum[0] == 3 || sum[1] == 3)
				return 1;
			if (i == j )
				sum[2] += s[i][j];
			if (i == 2 - j)
				sum[3] += s[i][j];
		}
		sum[0] = 0;
		sum[1] = 0;
		if (sum[2] == 3 || sum[3] == 3)
			return 1;
	}
	return 0;
}
int Fight(char board[][5],int symplify[][3],int c)
{
	char m;
	printf("ROUND %c : Ready Go!\n", c + '0');
	printf("It's N's turn now! please select the area:\n\n\n");
	show_board(board);
	Move_1(board, symplify, getchar());
	show_board(board);
	if (Judge(symplify, 1))

	{
		printf("The N player wins! Game Over!  please enter Y to have another or N to end !\n");
		while(getchar() == '\n')
			switch(getchar())
		{
			case 'Y': return 8;
			case 'N':return 88;
			default:;
		}
	}
	printf("It's O's turn now! please select the area:\n");
	Move_2(board, symplify, getchar());
	show_board(board);	
	if (Judge(symplify, 2))
	{
		printf("The 0 player wins! Game Over!  please enter Y to have another or N to end !\n");
		while ((m=getchar()) != 'Y'||m!='N')
			switch (m)
		{
			case 'Y': return 8;
			case 'N':return 88;
			default:;
		}
	}
	printf("This turn is over,The Next Beggin!\n\n\n\n");
	return 0;
}
void Configration(char b[][5],char bc[][5])
{
	for(int i = 0; i < 5;i++ )
	{
		for (int j = 0; j  < 5; j ++)
		b[i][j] = bc[i][j];
	}
}
void main()
{
	
	char board1[5][5] = {
		{ '1', '|', '2', '|', '3' },
		{ '-', '-', '-', '-', '-' },
		{ '4', '|', '5', '|', '6' },
		{ '-', '-', '-', '-', '-' },
		{ '7', '|', '8', '|', '9' },

	};
	char boardc[5][5] = {
		{ ' ', '|', ' ', '|', ' ' },
		{ '-', '-', '-', '-', '-' },
		{ ' ', '|', ' ', '|', ' ' },
		{ '-', '-', '-', '-', '-' },
		{ ' ', '|', ' ', '|', ' ' }
	};
	char board[5][5] = {
		{ ' ', '|', ' ', '|', ' ' },
		{ '-', '-', '-', '-', '-' },
		{ ' ', '|', ' ', '|', ' ' },
		{ '-', '-', '-', '-', '-' },
		{ ' ', '|', ' ', '|', ' ' }};

	
	int symplify[3][3] = {2};
	memset(symplify, 0,36);
	show_Array(symplify);
	printf("this is the area division of board!\n\n\n");
	show_board(board1);
	int c = 0;
	while (1)
	{
		c++;
		switch (Fight(board, symplify, c))
		{
		case 0:; break;
		case 8:{
			   Configration(board, boardc);
			   memset(symplify, 0, 36);
			   c = 1;
			   Fight(board, symplify, c); 
		} 
			break;
		case 88:exit(0);
		}
	}
}
