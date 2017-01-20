/*Ontology
Quora has many questions on different topics, and a common product use-case for our @mention selectors and search service is to look-up questions under a certain topic as quickly as possible.
For this problem, imagine a simplified version of Quora where each question has only one topic associated with it. In turn, the topics form a simplified
ontology where each topic has a list of children, and all topics are descendants of a single root topic.
Design a system that allows for fast searches of questions under topics. There are NN topics, MM questions, and KK queries, given in this order. Each query has a desired topic as well as a desired string prefix. For each query, return the number of questions that fall under the queried topic and begin with the desired string. When considering topics, we want to include all descendants of the queried topic as well as the queried topic itself. In other words, each query searches over the subtree of the topic.
The topic ontology is given in the form of a flattened tree of topic names, where each topic may optionally have children. If a topic has children, they are listed after it within parentheses, and those topics may have children of their own, etc. See the sample for the exact input format. The tree is guaranteed to have a single root topic.
For ease of parsing, each topic name will be composed of English alphabetical characters, and each question and query text will be composed of English alphabetical characters, spaces, and question marks. Each question and query text will be well behaved: there will be no consecutive spaces or leading/trailing spaces. All queries, however, are case sensitive.
Constraints
For 100% of the test data, 1≤N,M,K≤1051≤N,M,K≤105 and the input file is smaller than 5MB
For 50% of the test data, 1≤N,M,K≤2⋅1041≤N,M,K≤2⋅104 and the input file is smaller than 1MB
Input Format
Line 1: One integer NN
Line 2: NN topics arranged in a flat tree (see sample)
Line 3: One integer MM
Line 4...M+3: Each line contains a topic name, followed by a colon and a space, and then the question text.
Line M+4: One integer KK
Line M+5...M+K+4: Each line contains a topic name, followed by a space, and then the query text.
Output Format
Line 1...K: Line ii should contain the answer for the iith query.
Sample Input
6
Animals ( Reptiles Birds ( Eagles Pigeons Crows ) )
5
Reptiles: Why are many reptiles green?
Birds: How do birds fly?
Eagles: How endangered are eagles?
Pigeons: Where in the world are pigeons most densely populated?
Eagles: Where do most eagles live?
4
Eagles How en
Birds Where
Reptiles Why do
Animals Wh
Sample Output
1
2
0
3
**************************************************OUTPUT********************************************************************************
NOTE: Below is the running example for the flattree provided with the challenge. Max number of question per Topics(Node) = 10
COMPILE : g++ Ontology.cpp
RUN : ./a.out
INPUT :
Enter number of Topics (N)
6
N topics arranged in a flat tree:Animals ( Reptiles Birds ( Eagles Pigeons Crows ) )
Enter Number of questions(M)
5
Each line contains a topic name, followed by a colon and a space, and then the question text
Reptiles: Why are many reptiles green?
Birds: How do birds fly?
Eagles: How endangered are eagles?
Pigeons: Where in the world are pigeons most densely populated?
Eagles: Where do most eagles live?
Number of queries (K)
4
Line M+5...M+K+4: Each line contains a topic name, followed by a space, and then the query text
Eagles How en
Birds Where
Reptiles Why do
Animals Wh
OUTPUT:
1
2
0
3
*/
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
	getline (cin, strtemp);
	cin>>M;
  	string *str1 = new string[M];
	for(i=0;i<M;i++)getline(cin,str1[i]);	
	cin>>K;
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
