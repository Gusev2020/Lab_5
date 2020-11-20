// laba5.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "locale.h"
#include <queue>
 
using namespace std;
int vis[5] = {0, 0, 0, 0, 0};
int **matr;//указатель для массива указателей


void BFS(int s , int n)
{
	queue <int> Q;
	Q.push(s);
	vis[s] = 1;
	while(!Q.empty())
	{
		s = Q.front();
		printf("%d", s);
		Q.pop();
		for(int i = 0;i < n; i++)
		{
			if((matr[s][i] == 1) && !vis[i])
			{
				Q.push(i);
				vis[i] = 1;
			}
		}
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	int n,i,j;
  
  cout << "Input matrix order:";
  cin >> n;
  
  matr = (int**)malloc(n * sizeof(int*));
  //выделение памяти под массив указателей
  for(i=0; i<n; i++){
    matr[i] = (int*)malloc(n * sizeof(int));
  }
    //выделение памяти для массива значений
  for( i = 0; i < n; i++)
  {
	for( j = 0; j < n; j++)
	{
		if(i == j) 
		{
			matr[i][j] = 0;
		}  

		if (i < j)
		{
			matr[i][j] = rand()%2;
			matr[j][i] = matr[i][j];
		}
	}
  }
  printf( "Result: ");
  for(i = 0; i < n; i++)
  {
	cout << "\n";
		for (j = 0; j < n; j++)
		  printf("%d\t",matr[i][j]);
    
  }
  printf( " \n   ");
  
  BFS(4, n);


  
    getch();
}

