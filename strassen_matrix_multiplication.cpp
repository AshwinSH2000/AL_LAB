#include<iostream>
using namespace std;
int a[10][10]={0};
int b[10][10]={0};
int c[10][10]={0};

void subtract(int az[][2], int bz[][2], int res[][2])
{
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
                res[i][j] = az[i][j] - bz[i][j];


}
void add(int az[][2], int bz[][2], int res[2][2])
{
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
            res[i][j] = az[i][j]+bz[i][j];

}
void multiply(int a[][2], int bz[][2], int res[][2])
{
    for(int i=0 ; i<2 ; i++)
        for(int j=0 ; j<2 ; j++)
        {   res[i][j]=0;
            for(int k=0 ; k<2 ; k++)
                res[i][j]+=a[i][k]*b[k][j];
        }

}

int check_power_of_two(int m, int n)
{
    if(n!=m)    return 0;
    else if(n!=1 && n!=2 && n!=4 && n!=8)   return 1;
    return 2;
}
void display(int a[][2])
{	cout<<"\n";
	
	for(int i=0 ; i<2 ; i++)
	{
		for(int j=0 ; j<2 ; j++)
			cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
int main()
{
	int m,n;
	cout<<"Enter the order of the first matrix:";
	cin>>m;
	cout<<"Enter the order of the second matrix:";
	cin>>n;
    switch(check_power_of_two(m,n))
    {
        case 0:cout<<"Order of Matrices are not equal";exit(0);
        case 1:cout<<"Matrix order is not a power of 2";exit(0);
        default:break;
    }
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
	//if order == 4, i will have 4 2x2 matrix


	int a1[2][2];
	int a2[2][2];
	int a3[2][2];
	int a4[2][2];
	int b1[2][2];
	int b2[2][2];
	int b3[2][2];
	int b4[2][2];
	for(l=0 ; l<2 ; l++)
        for(k=0 ; k<2 ; k++)
        {
            a1[l][k]=a[l][k];
            a2[l][k]=a[l][k+2];
            a3[l][k]=a[l+2][k];
            a4[l][k]=a[l+2][k+2];
            b1[l][k]=b[l][k];
            b2[l][k]=b[l][k+2];
            b3[l][k]=b[l+2][k];
            b4[l][k]=b[l+2][k+2];
        }
	//////////
	/*display(a1);
	display(a2);
	display(a3);
	display(a4);
	display(b1);
	display(b2);
	display(b3);
	display(b4);*/

//////////////////
    int d[2][2], e[2][2], f[2][2], j[2][2], i[2][2], g[2][2], h[2][2], dummy[2][2], dummy2[2][2];
    subtract(b2,b4,dummy);
	//display(dummy);
    multiply(a1,dummy,d);
	
    subtract(b3,b1,dummy);
	multiply(a4,dummy,e);

	add(a3,a4,dummy);
	multiply(b1,dummy,f);

	add(a1,a2,dummy);
	multiply(b4,dummy,g);

	subtract(a3,a1,dummy);
	add(b1,b2,dummy2);
	multiply(dummy,dummy2,h);

	subtract(a2,a4,dummy);
	add(b3,b4,dummy2);
	multiply(dummy,dummy2,i);

	add(a1,a4,dummy);
	add(b1,b4,dummy2);
	multiply(dummy,dummy2,j);

    int c1[2][2], c2[2][2], c3[2][2], c4[2][2];
	add(e,i,dummy);
    subtract(j,g,dummy2);
    add(dummy, dummy2, c1);

    add(d,g,c2);
    add(e,f,c3);
    add(d,h,dummy);
    subtract(j,f,dummy2);
    add(dummy,dummy2,c4);
	


	/*display(d);
	display(e);
	display(f);
	display(g);
	display(h);
	display(i);
	display(j);


	display(c1);
	display(c2);
	display(c3);
	display(c4);*/

	for(l=0 ; l<2 ; l++)
        for(k=0 ; k<2 ; k++)
         {
            c[l][k]=c1[l][k];
            c[l][k+2]=c2[l][k];
            c[l+2][k]=c3[l][k];
            c[l+2][k+2]=c4[l][k];
         }

	cout<<"The result of multiplication is:\n";

	for(l=0 ; l<n ; l++)
	{	for(m=0 ; m<n ; m++)
			cout<<c[l][m]<<"\t";
		cout<<"\n";
	}

	return 0;
}

/*c[0][0]=e+i+j-g;
	c[x][y+1]=d+g;
	c[x+1][y]=e+f;
	c[x+1][y+1]=d+h+j-f;*/



