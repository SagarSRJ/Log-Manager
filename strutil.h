#include <string.h>
#include <stdlib.h>


char* substring(char*,int,int);




char* substring(char *a,int b,int c)
{
	int l,n,i;
	char *subs;
	l=strlen(a);
	n=c-b;
	if(!((n>0)&&(b>=0&&b<l)&&(c>0&&c<=l)))
	{
		return NULL;
	}
	subs=(char*)malloc((n+1)*sizeof(char));
	for(i=0;i<n;i++)
	{
		subs[i]=a[b++];
	}
	subs[i]='\0';
	return subs;
}

