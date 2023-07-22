#include<iostream>
using namespace std;

struct MM
{
	int min, max;
	MM minmax(int a[], int , int);
};

MM MM::minmax(int a[], int low, int high)
{
	struct MM p1, p2;
	struct MM pair;
	int mid;
	if(low == high) 	//only one element in the array
	{
		pair.min=a[0];
		pair.max=a[0];
		return pair;
	}
	if (high== (low+1))	//only 2 elements in the array
	{
		pair.min=( a[low] > a[high] ? a[high] : a[low] );
		pair.max=( a[low] > a[high] ? a[low] : a[high] );
		return pair;
	}
	mid=(low+high)/2;
	p1=minmax(a,low,mid);
	p2=minmax(a,mid+1, high);
	pair.min=( p1.min >= p2.min ? p2.min : p1.min );
	pair.max=( p1.max >= p2.max ? p1.max : p2.max );
	return pair;
}
int main()
{
	int a[10];
	int n;
	cout<<"How many elements in the array:";
	cin>>n;
	cout<<"Enter the elements of the array:\n";
	for(int i=0 ; i<n ; i++)
	{
		cout<<"\nelement "<<i+1<<": ";
		cin>>a[i];
	}
	struct MM pair;
	pair=pair.minmax(a,0,n-1);
	cout<<"\nThe maximum element in the array is "<<pair.max;
	cout<<"\nThe minimum element in the array is "<<pair.min;
}






