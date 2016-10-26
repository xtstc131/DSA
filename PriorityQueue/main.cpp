#include "PQMin.h"
int main()
{
	int a[] = { 2,4,65,8,2,8,1,0,99,77 };
	PQMin<int> pq(a,10);
	cout<<pq.getMin();
	getchar();

}
