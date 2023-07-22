#include<iostream>
using namespace std;
int n;
int weight[10];
int profit[10];
int max(int a, int b)
{	
	if(a>=b)	return a;
	else 		return b;
}
int f(int i, int c)		
{
	if(i==n-1)
	{	
	    if(c<weight[n-1]) 	return 0;
		else return profit[n-1];
	}
	if(c<weight[i]) return f(i+1,c);
	else return max(   f(i+1,c)  ,   f( i+1 , c-weight[i] ) + profit[i] );	
}
int main()
{	
	int total_profit=0;
	int capacity,i;
	cout<<"Enter the total number of items";
	cin>>n;
	cout<<"Enter the profit and weight of each of those items";
	for(i=0 ; i<n ; i++)
	{
		cout<<"Item "<<i+1<<" :";
		cout<<"\nprofit:"; cin>>profit[i];
		cout<<"\nweight:"; cin>>weight[i];
	}
	cout<<"Enter the total capacity of the knapsack:";
	cin>>capacity;
	total_profit=f(0,capacity);
	cout<<"\nTotal Profit = "<<total_profit;
	return 0;
}
