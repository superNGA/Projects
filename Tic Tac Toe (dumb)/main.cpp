#include<iostream>

using namespace std;

void Grid_print(char* moves)
{
	cout << moves[0] << " | " << moves[1] << " | " << moves[2] << endl;
	cout << "__|___|__\n";
	cout << moves[3] << " | " << moves[4] << " | " << moves[5] << endl;
	cout << "__|___|__\n";
	cout << moves[6] << " | " << moves[7] << " | " << moves[8] << endl;

	return;
}

char WinChecker(char* moves)
{
	//checking rows
	for (int i = 0; i < 9; i+=3)
	{
		if (moves[i] == moves[i + 1] && moves[i + 1] == moves[i + 2])
		{
			return moves[i];
		}
	}

	//checking columns
	for (int i = 0; i < 3; i++)
	{
		if (moves[i] == moves[i + 3] && moves[i + 3] == moves[i + 6])
		{
			return moves[i];
		}
	}

	//checking daigonal 1
	if (moves[0] == moves[4] && moves[4] == moves[8])
	{
		return moves[0];
	}

	//checking daigonal 2
	if (moves[2] == moves[4] && moves[4] == moves[6])
	{
		return moves[2];
	}

	return 'A';
}

int CompMove(char* moves)
{
	//check if I am wining

	//checking rows
	for (int i = 0; i < 9; i += 3)
	{
		if (moves[i] == moves[i + 1] || moves[i] == moves[i + 2] || moves[i + 1] == moves[i + 2])
		{
			if (moves[i] != 'X')
			{
				return i;
			}
			else if (moves[i + 1] != 'X')
			{
				return i + 1;
			}
			else
			{
				return i + 2;
			}
		}
	}

	//checking column
	for (int i = 0; i < 3; i++)
	{
		if (moves[i] == moves[i + 3] || moves[i] == moves[i + 6] || moves[i + 3] == moves[i + 6])
		{
			if (moves[i] != 'X')
			{
				return i;
			}
			else if (moves[i + 3] != 'X')
			{
				return i + 3;
			}
			else
			{
				return i + 6;
			}
		}
	}

	//checking daigonal
	if (moves[0] == moves[4] || moves[4] == moves[8] || moves[0] == moves[8])
	{
		if (moves[0] != 'X')
		{
			return 0;
		}
		else if (moves[4] != 'X')
		{
			return 4;
		}
		else
		{
			return 8;
		}
	}

	//checking daigonal 2
	if (moves[2] == moves[4] || moves[4] == moves[6] || moves[6] == moves[2])
	{
		if (moves[2] != 'X')
		{
			return 2;
		}
		else if (moves[4] != 'X')
		{
			return 4;
		}
		else
		{
			return 6;
		}
	}

	//decide its move
	for (int i = 0; i < 9; i++)
	{
		if (moves[i] != 'X')
		{
			return i;
		}
	}
}

void GameLoop()
{
	char moves[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //moves array
	int usermove;
	for (int i = 0; i < 9; i++)
	{
		system("cls"); //clearing screen

		Grid_print(moves); //printing grid

		//checcking winner
		if (WinChecker(moves) == 'X')
		{
			cout << "\nyou won !\n\n";
			break;
		}
		else if (WinChecker(moves) == 'O')
		{
			cout << "\nyou lost you stupi NIGGA !\n\n";
			break;
		}

		//user move
		if (i % 2 == 0)
		{
			cout << "\n\nEnter move : ";
			cin >> usermove;
			usermove--;

			while (moves[usermove] == 'X' || moves[usermove] == 'O')
			{
				cout << "\n\nspace is taken, play another move : ";
				cin >> usermove;
			}

			moves[usermove] = 'X';
		}
		else //computer move
		{
			moves[CompMove(moves)] = 'O';
		}
	}
}

int main(void)
{
	GameLoop();

	return 0;
}