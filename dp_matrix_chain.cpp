#include<iostream>
using namespace std;
int q;
int r[10];
int mat[10][10];
int kay[10][10];
int c(int i, int j)
{
	if(mat[i][j]>=0)
		return mat[i][j];
	if(i==j)	//only one matrix
	{
		mat[i][j]=0;
		return mat[i][j];
	}
	if(i==j-1)
	{
		mat[i][j]=r[i]*r[i+1]*r[i+2];
		return mat[i][j];
	}
	int u=36500;
	int t;
	for(int k=i ; k<j ; k++)
	{
		t=c(i,k)+c(k+1,j)+(r[i]*r[k+1]*r[j+1]);
		if(t<u)
		{
			u=t;
			kay[i][j]=k;
		}
	}
	mat[i][j]=u;
	return mat[i][j];
}
int main()
{
	int i,j;
	cout<<"How many matrices to multiply:";
	cin>>q;
	cout<<"Enter "<<q+1<<" rows:";
	for(i=0 ; i<=q ; i++)
		cin>>r[i];
		
	for(i=0 ; i<q; i++)
		for(j=0 ; j<q ; j++)
			mat[i][j]=-1;
			
	int cost=c(0,4);
	cout<<"The least cost of multiplying these matrices is "<<cost;	
}
