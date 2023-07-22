#include<iostream>
using namespace std;
int a[10][10]={0};
int b[10][10]={0};
int c[10][10]={0};
	
void breakit(int x, int y)
{
	
	int a1=a[x][y];	
	int a2=a[x][y+1];
	int a3=a[x+1][y];
	int a4=a[x+1][y+1];
	int b1=b[x][y];
	int b2=b[x][y+1];
	int b3=b[x+1][y];
	int b4=b[x+1][y+1];
	
	int d=a1*(b2-b4);
	int e=a4*(b3-b1);
	int f=b1*(a3+a4);
	int g=b4*(a1+a2);
	int h=(a3-a1)*(b1+b2);
	int i=(a2-a4)*(b3+b4);
	int j=(a1+a4)*(b1+b4);
	
	c[x][y]=e+i+j-g;	
	c[x][y+1]=d+g;
	c[x+1][y]=e+f;
	c[x+1][y+1]=d+h+j-f;
}
int main()
{	
	int m,n;
	cout<<"Enter the order of the first matrix:";
	cin>>m;
	cout<<"Enter the order of the second matrix:";
	cin>>n;
	cout<<"Enter the first matrix:\n";
	int l, k;
	for(l=0 ; l<m ; l++)
		for(k=0 ; k<m ; k++)
		{
			cout<<"a["<<l<<"]["<<k<<"] = ";
			cin>>a[l][k];
		}
	cout<<"Enter the second matrix:\n";
	for(l=0 ; l<n ; l++)
		for(k=0 ; k<n ; k++)
		{
			cout<<"b["<<l<<"]["<<k<<"] = ";
			cin>>b[l][k];
		}
	for(l=0 ; l<m ; l+=2)
	{
		for(k=0 ; k<n ; k+=2)
		{
			breakit(l,k);
		}
	}		
	/*
	have a variable i point to number or rows in the matrix
	lets  assume row is a power of 2
	
	 while i>=0
	 		break th array into subarrays
			when i becomes 2 send it to the mltiply func
			
			
	*/
	cout<<"The result of multiplication is:\n";
	
	for(l=0 ; l<n ; l++)
	{	for(m=0 ; m<n ; m++)
			cout<<c[l][m]<<"\t";
		cout<<"\n";
	}
		
	return 0;
}




