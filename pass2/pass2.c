#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
FILE *finput, *foptab, *fsymtab, *foutput;
char optab[10][10];
char opco[10][10];

char sytab[10][10];
char syco[10][10];
char address[10], label[10], opcode[10], operand[10]; 
int i=0, j;
int i1=0, j1;

int found, found1;

finput=fopen("i2.txt", "r");
foptab=fopen("o.txt", "r");
fsymtab=fopen("s2.txt", "r");
foutput=fopen("out.txt", "w");

//Populating optab array
while (!feof(foptab))
{
fscanf(foptab, "%s\t%s", optab[i], opco[i]);
i++;
}
i-=1;
fclose(foptab);

//populating symtab array
while (!feof(fsymtab))
{
fscanf(fsymtab, "%s\t%s", sytab[i1], syco[i1]);
i1++;
}
i1-=1;
fclose(fsymtab);

//Generating machine codes
while(1)
{
found=11;
found1=11;

fscanf(finput, "%s\t%s\t%s\t%s", address, label, opcode, operand);

//If opcode is start do nothing, if its end exit the program
if (strcmp(opcode, "START")==0 || strcmp(opcode, "RESB")==0 || strcmp(opcode, "RESW")==0)
{
fprintf(foutput, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);
continue;
}
if (strcmp(opcode, "END")==0)
{
fprintf(foutput, "%s\t%s\t%s\t%s\n", address, label, opcode, operand);
exit(0);
}

//search opcode
for (j=0;j<i;j++){if (strcmp(opcode, optab[j])==0){found=j;}}

//search symtab
for (j1=0;j1<i1;j1++){if (strcmp(operand, sytab[j1])==0){found1=j1;}}


if (found!=11 && found1!=11)
{
fprintf(foutput, "%s\t%s\t%s\t%s\t%s%s\n", address, label, opcode, operand, opco[found], syco[found1]);
}

else if(found!=11 && found1==11) // Link addressing
{
char newop[10];
strcpy(newop, operand);
operand[strlen(operand)-2]='\0';

//search symtab again
for (j1=0;j1<i1;j1++){if (strcmp(operand, sytab[j1])==0){found1=j1;}}
int a=(int)strtol(strcat(opco[found],syco[found1]), NULL, 16);
a+=0x8000;
fprintf(foutput, "%s\t%s\t%s\t%s\t%x\n", address, label, opcode, newop, a);
}

else if (strcmp(opcode, "WORD")==0)
{
int len=strlen(operand);
int x, k;
len=6-len;
char opnew[10];
for (x=0;x<len;x++){opnew[x]='0';}
for (k=0;k<strlen(operand);k++){opnew[x++]=operand[k];}
opnew[x]='\0';
fprintf(foutput, "%s\t%s\t%s\t%s\t%s\n", address, label, opcode, operand, opnew);
}
else if (strcmp(opcode, "BYTE")==0)
{
int g;
fprintf(foutput, "%s\t%s\t%s\t%s\t", address, label, opcode, operand);
for (g=2;g<strlen(operand)-1;g++){fprintf(foutput, "%x", operand[g]);}
fprintf(foutput, "\n");
}
}

fclose(foutput);
fclose(finput);
}
