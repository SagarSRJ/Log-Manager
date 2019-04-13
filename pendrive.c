#include <stdio.h>
#include <stdlib.h>
#include <string.h>




char* substring(char*,int,int);
char* finput();
int str_srch(char*,char*);

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
	f=fopen("/var/log/syslog","r");
	if(f)
	{
		printf("File opened successfully\n");
		while(buff=finput())
		{
		/////////


				if(str_srch(buff,"New USB device found")==1){
				        int flag=0;

				        if(flag==0) flag=str_srch(buff,"idVendor");
					if(flag==1) {
		//printf(" USB Found date\\\:%s \n time:%s \n  query:     %s\n",date,time,buff);
		da=substring(buff,0,6);
		ti=substring(buff,8,16);
		printf(" USB Found \nDate:%s \nTime:%s \n",da,ti);
		waste=finput();
		pro=finput();
		pro=substring(pro,62,strlen(pro));
		man=finput();
		man=substring(man,66,strlen(man));
		ser1=finput();
		ser1=substring(ser1,66,strlen(ser1));
		printf("PRODUCT : %s\nManufacturer : %s\nSerial Number : %s\n",pro,man,ser1);
		printf("_________________________________________________________\n");

		}
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

