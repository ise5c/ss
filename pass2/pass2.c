
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#define prog_length 10
int main() 
{ 
    FILE *finput,*foptab,*fsymtab,*foutput; 
      
    char optab[20][20],opco[20][20],symtab[20][20],syco[20][20]; 
      char address[20],label[20],opcode[20],operand[20]; 
      int i=0,j=0,i1=0,j1=0; 
      int found,found1; 
  
    finput=fopen("i2.txt", "r"); 
      foptab=fopen("o.txt", "r"); 
      fsymtab=fopen("s2.txt", "r"); 
      foutput=fopen("p2outp.txt", "w"); 
  
    while (!feof(foptab)) 
      { 
            fscanf(foptab,"%s\t%s",optab[i],opco[i]); 
            i++; 
      } 
      i-=1; 
      fclose(foptab); 
  
    while (!feof(fsymtab)) 
      { 
            fscanf(fsymtab,"%s\t%s",symtab[i1],syco[i1]); 
            i1++; 
      } 
      i1-=1; 
      fclose(fsymtab); 
  
    while(1) 
      { 
            found=prog_length; //length of input file
            found1=prog_length; 
    
        fscanf(finput,"%s\t%s\t%s\t%s",address,label,opcode,operand); 
            
        if (strcmp(opcode,"START")==0 || strcmp(opcode,"RESB")==0 || strcmp(opcode,"RESW")==0) 
            { 
                  fprintf(foutput,"%s\t%s\t%s\t%s\n",address,label,opcode,operand); 
                  continue; 
            } 
            
        if (strcmp(opcode,"END")==0) 
            { 
                  fprintf(foutput,"%s\t%s\t%s\t%s\n",address,label,opcode,operand); 
                  exit(0); 
            } 
            
        for (j=0;j<i;j++)
           {
              if (strcmp(opcode,optab[j])==0)
              {
                    found=j;
              }
            } 
            for (j1=0;j1<i1;j1++)
           {
              if (strcmp(operand,symtab[j1])==0)
              {
                    found1=j1;
              }
           } 
            if (found!=prog_length && found1!=prog_length) 
            { 
                  fprintf(foutput,"%s\t%s\t%s\t%s\t%s%s\n",address,label,opcode,operand,opco[found],syco[found1]); 
            } 
            
        else if (strcmp(opcode,"WORD")==0) 
            { 
                  int len=strlen(operand); 
                  int x,k,j; 
                  char opnew[20];
            len=6-len; 
      
            for (x=0;x<len;x++)
                 {
                    opnew[x]='0';
                 } 
                  for (k=0;k<strlen(operand);k++)
                  {
                    opnew[x++]=operand[k];
                  } 
                  opnew[x]='\0'; 
      
            fprintf(foutput,"%s\t%s\t%s\t%s\t%X\n",address,label,opcode,operand,atoi(opnew)); 
        }   

            else if(strcmp(opcode,"BYTE")==0) 
            { 
                  int g; 
                  fprintf(foutput,"%s\t%s\t%s\t%s\t",address,label,opcode,operand); 
            
                  for(g=2;g<strlen(operand)-1;g++)
              {
                           if(operand[0]=='X')
                             {
                           
                     fprintf(foutput,"%c",operand[g]);
                  }
                          else {
                 fprintf(foutput,"%X",operand[g]);    
                }    
              }     
                  fprintf(foutput,"\n");
             
            } 
      }
 
      fclose(foutput); 
      fclose(finput);
    
}  