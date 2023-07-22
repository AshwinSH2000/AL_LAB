#include<iostream>
using namespace std;
void swapit(int * a, int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int divide(int Qar[], int low, int high)
{
    int pivot=Qar[high];
    int i=low-1;
    for(int j=low; j<=high-1 ; j++)
    {
        if(Qar[j]<=pivot)
        {
            i++;
            swapit(&Qar[i],  &Qar[j]);
        }
    }
    swapit(&Qar[i+1], &Qar[high]);
    return i+1;
}

void QuickSort(int Qar[], int low, int high)
{
    if(low<high)
    {
        int pos=divide(Qar, low, high);
        QuickSort(Qar, low, pos-1);
        QuickSort(Qar, pos+1, high);
    }
}
int main()
{
	int i,n;
	cout<<"Enter the size of the array:";
	cin>>n;
	int a[n];
	cout<<"Enter the element now:\n";
	for(i=0 ; i<n ; i++)
	{
		cout<<"Element "<<i+1<<":";
		cin>>a[i];
	}
	int l=0, r=n-1;
	QuickSort(a,l,r);
	cout<<"\nThe sorted array is:\n";
	for(i=0 ; i<n ; i++)
		cout<<a[i]<<" ";
	return 0;
}



