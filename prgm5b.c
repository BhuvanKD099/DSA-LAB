#include<stdio.h>
void towers(int, char,char,char);
int main()
{
	int n;
	printf("enter the numbre of disks:");
	scanf("%d",&n);
	towers(n,'A','B','C');
	return 0;
}
void towers(int n,char A,char B,char C)
{
	if(n==1)
	{
		printf("\n move disk 1 from peg %c to peg%c,A,C);
		return ;
	}
	towers(n-1,A,C,B);
	printf("\n move disk %d from peg %d to peg%c,n,A,C);
	towers(n-1,B,A,C);
}
