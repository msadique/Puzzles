/*Alexey is trying to develop a program for a very simple microcontroller. It makes readings from various sensors over time, and these readings must happen at specific regular times. Unfortunately, if two of these readings occur at the same time, the microcontroller freezes and must be reset.

There are N different sensors that read data on a regular basis. For each i from 1 to N, the reading from sensor i will occur every Ai milliseconds with the first reading occurring exactly Ai milliseconds after the microcontroller is powered up. Each reading takes precisely one millisecond on Alexey's microcontroller.

Alexey wants to know when the microcontroller will freeze after he turns it on.

Input

The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.

The first line contains single integer N denoting the number of sensors.

The second line contains N space-separated integers A1, A2, ..., AN denoting frequency of measurements. Namely, sensor i will be read every Ai milliseconds with the first reading occurring Ai milliseconds after the microcontroller is first turned on.

Output

For each test case, output a single line containing the number of milliseconds until the microcontroller freezes.

 

Constraints

1 ≤ T ≤ 10
2 ≤ N ≤ 500
1 ≤ Ai ≤ 109
 

Subtasks

Subtask #1 (10 points) 1 ≤ T ≤ 10, 2 ≤ N ≤ 9, 1 ≤ Ai ≤ 500
Subtask #2 (20 points) 1 ≤ T ≤ 10, 2 ≤ N ≤ 500, 1 ≤ Ai ≤ 1000
Subtask #3 (70 points) original constraints
Example

Input:
3
3
2 3 5
4
1 8 7 11
4
4 4 5 6

Output:
6
7
4
 

Explanation

Case 1: in 6 milliseconds, the third reading will be attempted from the 1st sensor and the second reading will be attempted from the 2nd sensor.

Case 2: in 7 milliseconds the seventh reading will be attempted from the 1st sensor and the first reading will be attempted from the 3rd sensor.

Case 3: in 4 milliseconds, the first readings from the first two sensors will be attempted.

CodeChef is a non-commercial competitive programming community
*/
#include<iostream>
#include<math.h>
#define LIM 9592
using namespace std;
struct node {
 		int x;
		node *next;
	};
 

int main(){
	long long int pr[LIM];
	pr[0] = 2;
	long int lim = 1; 
	
	for(int i = 3; i < 100000; i++ ){
		bool flag = false;
		for(int j = 0; j < lim; j++ ){
			if( i % pr[ j ] == 0 ){
				flag = true;
				break;	
			}
			
		}
		if( !flag ){
			pr[ lim ] = i;
			lim++;
		}
		
	}
	int test;
	cin>>test;
	
	while( test-- ){
	int n;
	cin>>n;
	
	long long int a[ n ],max = 0,ans = 999999999999999999;
	node *root[ n ];
	
	for( int i = 0; i < n; i++ ){
		cin>>a[ i ];
	}
	for( int i = 0; i < n; i++ ){
		long long int x=a[ i ];
		root[ i ] = NULL;
		for(int k = 0;k < LIM && x != 1; k++ ){
				if( x % pr[ k ] == 0 ) {
					node *newnode = new node;
					newnode->x = pr[ k ];
					newnode->next = NULL;
					if( root[ i ] == NULL ) root[ i ] = newnode;
					else{
						node *ptr = root[ i ];
						while( ptr->next != NULL ){
							ptr = ptr->next;
						}
						ptr->next = newnode;
					}
					x /= pr[ k ];
					k--;
				}
			}
		}
	for( int i = 0; i < n; i++ ){
		node *ptr = root[ i ];
		while( ptr ) {
			ptr = ptr->next;	
		}
	}
	
		
	for( int i = 0; i < n ; i++ ){
		for( int j = i+1; j < n; j++ ){
			long long int lcm = 1;
			node *ptr1,*ptr2;
			if( a[ i ] < a[ j ]) {
				ptr1 = root[ i ];
				ptr2 = root[ j ];
			}
			else{
				ptr1 = root[ j ];
				ptr2 = root[ i ];
			}
			while( ptr1 != NULL && ptr2 != NULL ){
				if( ptr1->x == ptr2->x ) {
					lcm = 1LL * lcm * ptr1->x;
					ptr1 = ptr1->next;
					ptr2 = ptr2->next;	
				}
				else if( ptr1->x < ptr2->x ){
					lcm = 1LL * lcm * ptr1->x;
					ptr1 = ptr1->next;
				}
				else {
					lcm = 1LL * lcm * ptr2->x;
					ptr2 = ptr2->next;
				}
			}
			node *ptrf = ptr1 == NULL ? ptr2 : ptr1;
			while( ptrf != NULL ){
				lcm = 1LL * lcm * ptrf->x;
				ptrf = ptrf->next;
			}
			if( lcm < ans ) 
				ans = lcm;			
		}
	}
	
	cout<< ans <<"\n";
	}
} 