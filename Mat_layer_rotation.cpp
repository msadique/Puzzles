#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    long rt;
	int n,m;
	cin>>n>>m>>rt;	
	long mat[n][m];
	int x,y;
	for	( x = 0; x < n; x++ )
	for( y = 0; y < m; y++ )
	cin>>mat[ x ][ y ];
	int s = 0;
	int rs ;
    int l = m < n ? m/2 : n/2;
    
	int R = 1,i=0,j=0,k=0,d,d1,i2flag=1,iflag=1,jflag=1;
	while(k<l)
	{
		i2flag=1;iflag=1;jflag=1;R=1;
        d = mat[i][j];s=0;
		rs =rt%((2*((m-1)+(n-1)))-(8*k));
		while( s < rs )
		{
			if( R == 1 )
				i++;
			else if( R == 2 )
			j++;
			else if( R == 3 )
			i--;
			else if( R == 4 )
			j--;
			d1 = mat[ i ][ j ];
			mat[ i ][ j ] = d;
			d = d1;
			if( i == n - ( k + 1 ) && iflag )
			{	
				R++;
				iflag=0;
			}
			if(	i == k && i2flag )
			{
				R++;
				i2flag=0;
			}
			if( j == m - ( k + 1 ) && jflag )
			{
				R++;
				jflag=0;
			}
			if( i == k && j == k )
			{
				R=1;
				iflag=1;
				jflag=1;
				i2flag=1;
				s++; 
				d = mat[i][j];
			}
		}
		k++;
		i=k;
		j=k;
	}
	for( i = 0; i < n; i++ )
	{
		for( j = 0; j < m; j++ )
		cout<<mat[ i ][ j ]<<" ";
		cout<<"\n";
	}
    return 0;
}
