#define LINE 256
#define WORD 30
#include <string.h>
#include <stdio.h>



int Getline(char s[])
{
int i=strlen(s);
return i;
}


int getword(char w[])
{
int i=strlen(w);
return i;
}

int substring(char *str1, char*str2)
{
int j=strlen(str1);
int k=0;
int c=0;
int l=strlen(str2);
for(int i=0;i<j;i++)
{
if(c==l)
return 1;

if(str1[i]!=' '&&str1[i]!='\t'&&str1[i]!='\n'&&str1[i]==str2[k])
{
k++;
c++;
}
else
{
k=0;
c=0;
}

}
return 0;
}


int similar(char *s, char *t, int n)
{
int c=0;
int len1=getword(s);
int len2=getword(t);
if(len2<len1-n||len2>len1)
return 0;
int j=0;
int i=0;
while(i<len1)
{
if(s[i]==t[j])
{
i++;
j++;
}
else
{
i++;
c++;
}
}

if(c<=n&&j==len2)
return 1;
else
return 0;
}


void print_lines(char *str)
{
char line[LINE];
int i=0;
while(fgets(line,LINE,stdin)!=NULL)
{i++;
if(i>=3)
{
if(substring(line,str)==1)
printf("%s\n",line);
}

}
}

void print_similar_words(char *str)
{

char c[LINE];



int k=0;
while(fgets(c,LINE,stdin)!=NULL)
{k++;

int j;
if(k>=3)
{
for(int i=0;i<strlen(c);i++)
{j=0;
char o[WORD]="";
while(c[i]!='\n'&&c[i]!='\t'&&c[i]!=' ')
{

o[j]=c[i];
j++;
i++;
}

if(similar(o,str,1)==1)
printf("%s\n",o);

}
}

}
}




