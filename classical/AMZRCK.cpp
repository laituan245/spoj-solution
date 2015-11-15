// AMZRCK - Amz Rock
// http://www.spoj.com/problems/AMZRCK/

#include <vector>
#include<string>
#include<algorithm>
#include <iostream>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<stdio.h>
#include <set>
using namespace std;

inline void inp( int &n )
{
   n=0;
   int ch=getchar_unlocked();int sign=1;
   while(ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
   while(ch >= '0' && ch <= '9' )
           n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
   n=n*sign;
}

int main () {
	int array[43];
	array[0]=1; array[1]=2; array[2]=3; array[3]=5; array[4]=8; array[5]=13;
	array[6]=21; array[7]=34; array[8]=55; array[9]=89; array[10]=144; array[11]=233;
	array[12]=377; array[13]=610; array[14]=987; array[15]=1597; array[16]=2584;
	array[17]=4181; array[18]=6765; array[19]=10946; array[20]=17711; array[21]=28657;
	array[22]=46368; array[23]=75025; array[24]=121393; array[25]=196418; array[26]=317811;
	array[27]=514229; array[28]=832040; array[29]=1346269; array[30]=2178309; array[31]=3524578;
	array[32]=5702887; array[33]=9227465; array[34]=14930352; array[35]=24157817; array[36]=39088169;
	array[37]=63245986; array[38]=102334155; array[39]=165580141; array[40]=267914296; array[41]=433494437; array[42]=701408733;
	
	int t, n;
	inp(t);
	for (int i = 0; i < t; i++) {
		inp (n);
		cout << array[n]  << "\n";
	}
}
