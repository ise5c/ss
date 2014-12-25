#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
char temp1[10], temp[50], bitmask[20];
FILE *fin, *fout;
int saddr,saddr1, addr, i, a;

printf("Enter actual starting address\n");
scanf("%s", temp1);
saddr=(int)strtol (temp1, NULL ,16);
saddr1=saddr;

fin=fopen("RLIN.txt","r");
fout=fopen("relocoutp2.txt","w");

while(temp[0]!='T'){fscanf(
fin, "%s", temp);}

while (temp[0]!='E')
{
fscanf(fin, "%s", temp);
addr=(int)strtol (temp, NULL ,16);
fscanf(fin, "%s", bitmask);
saddr1=saddr;
fscanf(fin, "%s", temp);

i=0;
do{
a=(int)strtol (temp, NULL ,16);
if (bitmask[i++]=='1')
{fprintf(fout, "%x %x\n", (addr+saddr1), (a+saddr));saddr1+=3;}
else
{
fprintf(fout, "%x %x\n", (addr+saddr1), a);saddr1+=3;
}
fscanf(fin, "%s", temp);
}while(temp[0]!='T' && temp[0]!='E');

}

fclose(fin);
fclose(fout);
}