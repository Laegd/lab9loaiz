#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h> 
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

queue <int> Q;

int** createG(int size)
{
	int** G;
	G = (int**)malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++)
	{
		G[i] = (int*)malloc(size * sizeof(int));
	}
	for (int i = 0; i < size; i++)
	{
		G[i][i] = 0;
		for (int j = i + 1; j < size; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
		}
	}
	return G;
};

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
};

void bfsd(int** G, int size, int s, int* dist)
{
	Q.push(s);
	dist[s] = 0;
	while (!Q.empty())
	{
		s = Q.front();
		Q.pop();
		for (int i = 0; i < size; i++)
		{
			if (G[s][i] == 1 && dist[i] == INT_MAX)
			{
				Q.push(i);
				dist[i] = dist[s] + G[s][i];
			}
		}
	}
};
//#PotatoFreeGureev


int main()
{
	srand(time(NULL));
	int** G = NULL;
	int nG = 0, s;
	cout << "Vvedite razmer grafa: ";
	cin >> nG;
	cout << endl;

	G = createG(nG);
	printG(G, nG);

	cout << "\nVvedite startovuy vershinu: ";
	cin >> s;

	/*Q.push(i);
	Q.pop();
	s = Q.front() смотрит
	Q.empty - когда ноль - очередь не пустая, единица - пустая*/

	int* dist = (int*)malloc(nG * sizeof(int));
	for (int i = 0; i < nG; i++)
	{
		dist[i] = INT_MAX;
	}
	bfsd(G, nG, s - 1, dist);

	for (int i = 0; i < nG; i++)
	{
		cout << dist[i] << " ";
	}
	return 0;
}