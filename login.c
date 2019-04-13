#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* finput();
int str_srch(char*,char*);

char* substring(char*,int,int);

FILE *f;
char *match;
int matlen;



int main()
{
char *buff;
char time[10],date[10];
char *ti;
char *da;
char *pro;
char *man;
char *ser;
char *ser1;
char *waste;
long i,j;
f=fopen("/var/log/auth.log","r");
if(f)
{
printf("File opened successfully\n");
while(buff=finput())
{
/////////


		if(str_srch(buff,"authentication failure")==1){
                        

				da=substring(buff,0,6);
				ti=substring(buff,8,16);
				printf(" Intruder Authentication Failure  \nDate:%s \nTime:%s \n",da,ti);
                                printf("___________________________________________________\n");
				

}
/////////
}
fclose(f);
}
else
{
printf("File not opened successfully\n");
}
return 0;
}

char* finput()
{	
	char x,*y;	
	char arr[1024];
	int i,s;
	i=0;
	while(x=fgetc(f))
	{	
		if(x=='\n')
		{	
			break;	
		}
		arr[i++]=x;
		if(x==EOF)
		{
			return NULL;
		}
	}
	s=i;
	y=(char*)malloc((i+1)*sizeof(char));
	i--;	
	while(i>=0)
	{	
		y[i]=arr[i];	
		i--;
	}
	y[s]='\0';
	return y;
}

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

int str_srch(char *str, char * search)
{
	
	long c1=0,c2=0,i,j,flg;
	

	while (str[c1]!='\0')
		c1++;
                c1--;

	while (search[c2]!='\0')
		c2++;
                c2--;


	for(i=0;i<=c1-c2;i++)
	{ 
		for(j=i;j<i+c2;j++)
		{
			flg=1;
			if (str[j]!=search[j-i])
			{
				flg=0;
			   break;
			}
		}
		if (flg==1)
			break;
	}
	if (flg==1)
		return 1;
	else
		return 0;
}

