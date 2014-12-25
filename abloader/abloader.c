#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
    {
        char input[10], inp[10], start[10],pn[10];
        int address;
        FILE *fp1, *fp2;
        fp1=fopen("input.txt","r");
        fp2=fopen("output.txt","w");

        fscanf(fp1,"%s",input);

        while(strcmp(input,"E")!=0)
        {
            if(strcmp(input,"H")==0)
            {
		fscanf(fp1,"%s",pn);
                fscanf(fp1,"%s",start);
                fscanf(fp1,"%s",inp);
                fscanf(fp1,"%s",input);
            }

            else if(strcmp(input,"T")==0)
            {
                fscanf(fp1,"%x",&address);
                fscanf(fp1,"%s",input);
		fscanf(fp1,"%s",input); //if input doesnt have hex after the address, omit this line
                continue;
            }
            else if (strlen(input)>2)
            {
                fprintf(fp2,"%06x\t%c%c\n",address++,input[0],input[1]);
                fprintf(fp2,"%06x\t%c%c\n",address++,input[2],input[3]);
                fprintf(fp2,"%06x\t%c%c\n",address++,input[4],input[5]);
                fscanf(fp1,"%s",input);
            }
		
	else
			{
				fprintf(fp2,"%06x\t%c%c\n",address++,input[0],input[1]);
				fscanf(fp1,"%s",input);
			}
				
        }
        fclose(fp1);
        fclose(fp2);
        printf("*****FINISHED*******");
        return 0;
    }
