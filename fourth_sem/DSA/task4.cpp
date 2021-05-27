#include <iostream>
#include <vector>
#include <queue>

// func just checks if cell was used_cell and if coordinates are valid
#define is_turn_valid(i,j) if(!used_cell[i][j] && i >= 0 && i < M && j >= 0 && j < N)



int main()
{
    // M, N - size of chess-board MxN
    // x, y - coordinates of square that we need to reach
	int M, N, x, y;
	std::cin >> M >> N >> x >> y;
	x--;
    y--;

    // now creating queue of pairs - our coordinates
	std::queue<std::pair<int,int>> q;
	q.push({0,0});

    // array for checking whether cell was used_cell
	bool used_cell[101][101] = {false};

	int d[101][101] = {0};

    // our figure is in 0,0 - so we set used_cell to 0,0
	used_cell[0][0] = true;
	bool is_reachable = false;


	while (!q.empty()) 
    {
		int i = q.front().first, j = q.front().second;
        
        // when we took coordinates, we just pop pair from queue
		q.pop();

        // checking if knight can make such turns:
        // if so, we just set the cell to be used_cell, and push to queue our new coordinate

        is_turn_valid(i - 2, j + 1)
		{
			used_cell[i - 2][j + 1] = true;
			q.push({ i - 2,j + 1 });
			d[i - 2][j + 1] = d[i][j] + 1;
		}
		is_turn_valid(i - 2, j + 1)
		{
			used_cell[i - 2][j - 1] = true;
			q.push({ i - 2,j - 1 });
			d[i - 2][j - 1] = d[i][j] + 1;
		}

        is_turn_valid(i - 1, j - 2)
		{
			used_cell[i - 1][j - 2] = true;
			q.push({ i - 1,j - 2 });
			d[i - 1][j - 2] = d[i][j] + 1;
		}

		is_turn_valid(i - 1, j + 2)
		{
			used_cell[i - 1][j + 2] = true;
			q.push({ i - 1,j + 2 });
			d[i - 1][j + 2] = d[i][j] + 1;
		}

		is_turn_valid(i + 2, j + 1)
		{
			used_cell[i + 2][j + 1] = true;
			q.push({ i + 2,j + 1 });
			d[i + 2][j + 1] = d[i][j] + 1;
		}
        
		is_turn_valid(i + 2, j - 1)
		{
			used_cell[i + 2][j - 1] = true;
			q.push({ i + 2,j - 1 });
			d[i + 2][j - 1] = d[i][j] + 1;
		}

		is_turn_valid(i + 1, j + 2)
		{
			used_cell[i + 1][j + 2] = true;
			q.push({ i + 1,j + 2 });
			d[i + 1][j + 2] = d[i][j] + 1;
		}

		is_turn_valid(i + 1, j - 2)
		{
			used_cell[i + 1][j - 2] = true;
			q.push({ i + 1,j - 2 });
			d[i + 1][j - 2] = d[i][j] + 1;
		}
		
		if (used_cell[x][y]) 
        {
			is_reachable = true;
			break;
		}
	}


	if (is_reachable)
		std::cout << d[x][y];
	else
		std::cout << "NEVAR";

	return 0;
}
