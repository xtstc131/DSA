#include <iostream>
#include <stdio.h>

using namespace std;	
int main()
{
	int m, n;
	int count = 0;
	cin >> m >> n ;
	int *array;
	array = new int[5];
	for (int i = 0 ; i< m;i++)
	{
		scanf_s("%d", &array[i]);
	}
	while (count < n)
	{
		int x, y;
		cin >> x >> y;
		
			int num = 0;
			for (int i = 0; i < m; i++)
			{
				if (array[i] >= x && array[i] <= y)
				{
					//cout << array[i]<<endl;
					num++;
				}
			}
			cout << num<<endl;
	
		count++;
	}
}