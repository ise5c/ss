#include <stdio.h>
#include <string.h>

void main()
{
FILE *input, *output;
char line[100];
int lctr;
char stad[6];

input=fopen("in.txt", "r");
output=fopen("output.txt", "w");

while (!feof(input))
{
    fscanf(input, "%s", line);
    if (line[0]=='H')
    {
    continue;
    }
    else if (line[0]=='T')
    {
    memcpy(stad, &line[1], 6);
    stad[6]='\0';
    lctr=(int)strtol(stad, NULL, 16);
    int i=9;
    while(line[i]!='\0')
        {
        fprintf(output, "%x %c%c\n", lctr, line[i], line[i+1]);
        i+=2;
        lctr++;
        }
    }
    
}
fclose(input);
fclose(output);
}