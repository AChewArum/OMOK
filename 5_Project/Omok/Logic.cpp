int who = 3;

int upcheck(int board[6][6])
{
	int count = 0;
	int check = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			count = 0;
			if (board[j][i] != 0)
			{
				for (int k = 1; k < 5; k++)
				{
					if (board[j][i] == board[j][i + k])
					{
						count++;
						if (count == 4)
						{
							if (board[j][i] == 1)
							{
								check = 3;
							}
							else
							{
								check = 2;
							}
						}
					}

				}
			}
		}
	}
	return check;
}

int rowcheck(int board[6][6]) {
	int count = 0;
	int check = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			count = 0;
			if (board[j][i] != 0)
			{
				for (int k = 1; k < 5; k++)
				{
					if (board[j][i] == board[j + k][i])
					{
						count++;
						if (count == 4)
						{
							check = 1;
							if (board[j][i] == 1)
							{
								who = 1;
							}
							else
							{
								who = 0;
							}
						}
					}

				}
			}
		}
	}
	return check;
}

int lupcheck(int board[6][6]) {

	int count = 0;
	int check = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			count = 0;
			if (board[j][i] != 0)
			{

				for (int k = 1; k < 5; k++)
				{

					if (board[j][i] == board[j + k][i + k])
					{
						count++;

						if (count == 4)
						{
							check = 1;
							if (board[j][i] == 1)
							{
								who = 1;
							}
							else
							{
								who = 0;
							}
						}
					}

				}
			}

		}
	}

	return check;
}

int rupcheck(int board[6][6]) {
	int count = 0;
	int check = 0;
	for (int i = 4; i < 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			count = 0;
			if (board[j][i] != 0)
			{
				for (int k = 1; k < 5; k++)
				{
					if (board[j][i] == board[j + k][i - k])
					{
						count++;
						if (count == 4)
						{
							check = 1;
							if (board[j][i] == 1)
							{
								who = 1;
							}
							else
							{
								who = 0;
							}
						}
					}

				}
			}
		}
	}
	return check;
}

//½Â¸® Ã¼Å©
int checkWin(int board[6][6])
{
	int i = 0;
	int check = 0;
	check = check + lupcheck(board);
	check = check + rupcheck(board);
	check = check + upcheck(board);
	check = check + rowcheck(board);
	if (check > 0)
	{
		if (who)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		return 0;
	}
}
