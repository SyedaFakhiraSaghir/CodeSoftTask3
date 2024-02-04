#include <iostream>
using namespace std;

//--------------------------------------------D I S P L A Y    B O A R D------------------------------------------------------
void DisplayBoard(char **board)
{
	cout<<"-------------"<<endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<< "| "<< board[i][j]<<" ";
		}
		cout<<"|"<< endl <<"-------------"<<endl;
	}
	cout<<endl;
}

//--------------------------------------------C H E C K    W I N N E R ------------------------------------------------------
char CheckWin(char **board)
{
    int checkodiag = 0, checkxdiag = 0;
    int checkorow = 0, checkxrow = 0;
    int checkocol = 0, checkxcol = 0;
    for (int i = 0; i < 3; i++)
    {	
        checkorow=0;
		checkxrow=0;
		checkocol=0;
		checkxcol=0;
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (board[i][j] == 'O')
                {
                    checkodiag++;
                }
                else if (board[i][j] == 'X')
                {
                    checkxdiag++;
                }
            }
            if (board[i][j] == 'O')
            {
                checkorow++;
            }
            if (board[i][j] == 'X')
            {
                checkxrow++;
            }
            if (board[j][i] == 'O')
            {
                checkocol++;
            }
            if (board[j][i] == 'X')
            {
                checkxcol++;
            }
        }
        if (checkorow == 3 || checkocol == 3 || checkodiag == 3)
        {
            return 'O';
        }
        else if (checkxcol == 3 || checkxrow == 3 || checkxdiag == 3)
        {
            return 'X';
        }
    }
    return ' ';
}

//--------------------------------------------C H E C K    D R A W------------------------------------------------------
bool CheckDraw(char **board)
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[i][j]==' ')
			{
				return false;
			}
		}
	}
	return true;
}

//-------------------------------------------- U P D A T I N G   B O A R D ------------------------------------------------------
bool updateBoard(char **board, char p, int turn)
{
		if(turn == 1 && board[0][0]==' ')
		{
			board[0][0]=p;
		}
		else if(turn == 2 && board[1][0]==' ')
		{
			board[1][0]=p;
		}
		else if(turn == 3 && board[2][0]==' ')
		{
			board[2][0]=p;
		}
		else if(turn == 4 && board[0][1]==' ')
		{
			board[0][1]=p;
		}
		else if(turn == 5 && board[1][1]==' ')
		{
			board[1][1]=p;
		}
		else if(turn == 6 && board[2][1]==' ')
		{
			board[2][1]=p;
		}
		else if(turn == 7 && board[0][2]==' ')
		{
			board[0][2]=p;
		}
		else if(turn == 8 && board[1][2]==' ')
		{
			board[1][2]=p;
		}
		else if(turn == 9 && board[2][2]==' ')
		{
			board[2][2]=p;
		}
		else
		{
			return false;
		}
		return true;
}

main()
{
	newplayers:
	cout<<endl<<"****************************************************************************"<<endl ;
	cout<<"************************* T I C    T A C    T O E **************************" << endl;
	cout<<"****************************************************************************" << endl;
	string player1, player2;
	char X='X', O='O';
	//-------------------------------------------I N P U T T I N G    N A M E S ------------------------------------------------------
	cout <<"\nEnter the name of player 1: ";
	cin>> player1;
	cout <<"Enter the name of player 2: ";
	cin>> player2;
	cout << player1 << "'s Symbol : "<< X <<endl;
	cout << player2 << "'s Symbol : "<< O <<endl;
	char **board=new char*[3];
	char c='1';
	for(int j=0;j<3;j++)
	{
		board[j]=new char[3];
	}
	
	playagain:
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=c;
			c++;
		}
	}
	DisplayBoard(board);
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			board[i][j]=' ';
		}
	}
	int turn;
	while(1)
	{
		//--------------------------------------------P L A Y E R   1 ------------------------------------------------------	
		again1:
		cout<< player1 <<"'s turn : ";
		cin >> turn;
		if(!updateBoard(board, 'X', turn))
		{
			cout<<"Invalid entry!";
			goto again1;
		}
		DisplayBoard(board);
		if(CheckDraw(board))
		{
			cout<<"Draw";
			break;
		}
		
		char win=CheckWin(board);
		if(win!=' ')
		{
			if(win=='X')
			{
				cout<<"Winner : "<< player1;
				break;
			}
			if(win=='O')
			{
				cout<<"Winner : "<< player2;
				break;
			}
		}
		//************************************ S W I T C H I N G    P L A Y E R **************************************************
		
		//--------------------------------------------P L A Y E R   2 ------------------------------------------------------
		again2:
		cout<< player2 <<"'s turn : ";
		cin >> turn;
		if(!updateBoard(board, 'O', turn))
		{
			cout<<"Invalid entry!";
			goto again2;
		}
		DisplayBoard(board);
		if(CheckDraw(board))
		{
			cout<<"Draw";
			break;
		}
		win=CheckWin(board);
		if(win!=' ')
		{
			if(win=='X')
			{
				cout<<"Winner : "<< player1;
				break;
			}
			if(win=='O')
			{
				cout<<"Winner : "<< player2;
				break;
			}
		}
	}
	char choice;
	cout<<"\nDo you want to play again [Y/N] :";
	cin>> choice;
	if(choice== 'n' || choice== 'N')
	{
		exit(1);
	}
	cout<<"Are the players same as before [Y/N]:";
	cin>> choice;
	if(choice== 'n' || choice== 'N')
	{
		goto newplayers;
	}
	else
	{
		goto playagain;
	}
}