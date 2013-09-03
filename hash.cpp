/*
Neng Gu 
25939297
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
char ** destList=(char**)malloc(5695806*sizeof(char*));
int destN[5695806][3]={0,0};
int count[5695806]={0};
int hash(char * key) {
  int sum = 0;
  int len = strlen(key);
  for (int i = 0; i < len; i++) {
		sum += i*key[i];
  }
  return sum%100000;
}

int main(){   
  char	* str;
  char line[162];
  int destNum=0;
  int k;
	for (int i = 0; i < 5695806; i++)
    {destList[i] = (char*)malloc((60) * sizeof(char));
	}
	int top[50][3]={0,0};  
	int topn=0;  
  FILE *file=fopen("output.txt","r");
  int i=0;
  int g=0;
  int temp=0,tt1=0,tt2=0,tt3=0;
	  while(fgets(line,sizeof(line),file)!=NULL) {
	  	if(i==5691951){break;}	  	
		str=strtok(line," \n");
		if(str){
				temp=hash(str);
				*(destList+i)=strdup(str);
				destN[temp][0]++;
				destN[temp][1]=i;
				for(g=0;g<50;g++)
				{
					
					if(temp==top[g][2])
						{
							top[g][0]++;
							for(int n=g;n>0;n--)
							{
								if(top[n][0]>top[n-1][0])
									{	tt1=top[n][0];
										top[n][0]=top[n-1][0];
										top[n-1][0]=tt1;
										tt2=top[n][1];
										top[n][1]=top[n-1][1];
										top[n-1][1]=tt2;
										tt3=top[n][2];
										top[n][2]=top[n-1][2];
										top[n-1][2]=tt3;
									}
							}
							break;							
						}
						else {
							if(destN[temp][0]>top[g][0]){									
									for(int n=49;n>g;n--)
									{
										top[n][0]=top[n-1][0];
										top[n][1]=top[n-1][1];
										top[n][2]=top[n-1][2];	
									}						
									top[g][0]=destN[temp][0];
									top[g][1]=i;
									top[g][2]=temp;
									break;
								
							}
							else{continue;}							
						}
				}
			}				
				printf( "%d\n",i);
		i++;
		}
	fclose(file);
//	printf( "AAAAAAAAAAAAAAAAAAA\n");
	for(int h=0;h<50;h++)
	{
		printf( "Destination is %s, Number is %d \n",*(destList+top[h][1]),top[h][0]);
	}			  
  return 0;
}

