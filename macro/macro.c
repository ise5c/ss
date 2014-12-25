# include <stdio.h>  
# include <string.h>  
# include <stdlib.h> 
 
struct deftab  
{  
   char m_label[20];  
   char m_opcode[20];  
   char m_operand[20];  
}d[20];
  
int main()  
{   
    char label[20],opcode[20],operand[20],newlabel[20],newoperand[20],c1[20],d1,d2;  
    char macroname[20];  
      int i,lines;  
      char str1=65,str2=65;
  
    FILE *finput,*foutput,*fdeftab;  
  
    finput=fopen("macin.dat","r");  
      foutput=fopen("macout.dat","w");  
      fdeftab=fopen("deftab.dat","w");  
  
    fscanf(finput,"%s\t%s\t%s\n",label,opcode,operand);  
  
    while(strcmp(opcode,"END")!=0)  
      {   
            if(strcmp(opcode,"MACRO")==0)  
            {  
                  strcpy(macroname,label);  
                  fscanf(finput,"%s%s%s",label,opcode,operand);  
                  lines=0;  
      
                  while(strcmp(opcode,"MEND")!=0)  
                  {  
                    fprintf(fdeftab,"%s\t%s\t%s\n",label,opcode,operand);  
                    strcpy(d[lines].m_label,label);  
                    strcpy(d[lines].m_opcode,opcode);  
                    strcpy(d[lines].m_operand,operand);  
                    fscanf(finput,"%s%s%s",label,opcode,operand);  
                    lines++;  
                  }   

        }   
            else if(strcmp(opcode,macroname)==0)  
            {    
                for(i=0;i<lines;i++)  
                  {  
                      int j=0;
                    d1=d[i].m_label[0];
                    d2=d[i].m_opcode[0];
 
    
                    if(d1 == '$')
                {
                         fprintf(foutput,"$%c%c",str1,str2);
                         while(d[i].m_label[++j])
                    {
                             fprintf(foutput,"%c",d[i].m_label[j]);
                         }
                         fprintf(foutput,"\t %s\t%s\n",d[i].m_opcode,d[i].m_operand); 
                     }
     
                else if(d2 == '$')
                {
                         fprintf(foutput,"%s\t",d[i].m_label);
                         fprintf(foutput,"$%c%c",str1,str2);
      
                      while(d[i].m_opcode[++j])
                    {
                             fprintf(foutput,"%c",d[i].m_opcode[j]);
                         }
                         fprintf(foutput,"\t%s\n",d[i].m_operand);
                         str2++;
                     }
     
     
                      else
                        fprintf(foutput,"%s\t%s\t%s\n",d[i].m_label,d[i].m_opcode,d[i].m_operand); 
  
                  }  
            }  
            else  
                  fprintf(foutput,"%s\t%s\t%s\n",label,opcode,operand);  
            fscanf(finput,"%s%s%s",label,opcode,operand);  
      }  
      fprintf(foutput,"%s\t%s\t%s\n",label,opcode,operand);  
      fclose(finput);  
      fclose(foutput);  
      fclose(fdeftab);  
  
      printf("macroprocessing completed\n");  
}
