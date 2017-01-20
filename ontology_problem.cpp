#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
int check(string str, string *str2,string str3,int j,int n);
int main()
{
	string strtemp ;
	int N,M,K;
	int i,j,st_ct,k;
	char temp[100];
	int flag,tcount=0;
	char *stk;
	cin>>N;
	cin.ignore( 5000000, '\n') ;
	getline (cin, strtemp);
	cin>>M;
	cin.ignore( 5000000, '\n') ;
  	string *str1 = new string[M];
	for(i=0;i<M;i++)getline(cin,str1[i]);	
	cin>>K;
	 cin.ignore( 5000000, '\n') ;
	string *str2 = new string[K];
	for(i=0;i<K;i++)getline(cin,str2[i]);
	vector<string> strings;
	stringstream f(strtemp);
    	string s;    
    	while (getline(f, s, ' ')) 
	{
        	strings.push_back(s);
    	}
	for(i=0 ; i<K ; i++ )
	{	
		flag=0;st_ct=0;tcount=0;
		for(j=0;str2[i][j]!=' ';j++)
		temp[j]=str2[i][j];
		temp[j]='\0';
		string str3(temp);
		k=0;
		while( k < strings.size() )
		{
			if(strings[k++] == str3)
			{ flag =1; break; }
		}
		if(flag==1)
		{
			tcount += check(str2[i],str1,strings[k-1],j+1,M);
			if(strings[k]=="(")
			{
				while(k<strings.size())
				{
					if(strings[k]=="(")
						st_ct++;
					else if(strings[k]==")")
						st_ct--;
					else if( st_ct == 0 )
						break;
					else
					tcount += check(str2[i],str1,strings[k],j+1,M);
					k++;
				}
			}
		}
		cout<<tcount<<"\n";
	}
	return 0;

}
int check(string str1, string *str2,string str3,int j,int n)
{
	int i,k,flag=0,count=0;
	for(i=0;i<n;i++)
	{
		flag=0;	
		stringstream f(str2[i]);
    		string s;    
    		getline(f, s, ':');
		if( s == str3 )
		{	flag=1;
			int l = str3.size()+2;
			for(k=j;k<str1.size();k++)
			if(str1[k]!=str2[i][(l)+(k-j)])
			{flag=0;break;}
			if(flag==1)
			count++;
		}
	}
	return count;
}
