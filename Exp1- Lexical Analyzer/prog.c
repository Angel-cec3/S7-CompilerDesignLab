#include<ctype.h>
#include<stdio.h>
#include<string.h>
void main()
{
    FILE *f1;
    char c,str[10];
    int lineno=0,num=0,i=0;
    f1=fopen("input.txt","r");
    while((c=getc(f1))!=EOF) // TO READ THE GIVEN INPUT FILE
    {
        if(isdigit(c)) // TO RECOGNIZE NUMBERS
        {
            num=c-48;//That is, subtracting by 48 translates the char values '0'..'9' to the int values 0..9
            c=getc(f1);
            while(isdigit(c))
            {
                num=num*10+(c-48);
                c=getc(f1);
            }
            printf("%d is a number \n",num);
            ungetc(c,f1);//ungetc() returns previously read character back to the stream so that it could be read again.
        }
        else if(isalpha(c)) // TO RECOGNIZE KEYWORDS AND IDENTIFIERS
        {
            str[i++]=c;
            c=getc(f1);
            while(isdigit(c)||isalpha(c)||c=='_'||c=='$')
            {
                str[i++]=c;
                c=getc(f1);
            }
            str[i++]='\0';
            if(strcmp("for",str)==0||strcmp("while",str)==0||strcmp("do",str)==0||
            strcmp("int",str)==0||strcmp("float",str)==0||strcmp("char",str)==0||
            strcmp("double",str)==0||strcmp("static",str)==0||
            strcmp("switch",str)==0||strcmp("case",str)==0) // TYPE 32 KEYWORDS
            printf("%s is a keyword\n",str);
            else
            printf("%s is a identifier\n",str);
            ungetc(c,f1);
            i=0;
        }
        else if(c==' '||c=='\t') // TO IGNORE THE SPACE
            printf("\n");
        else if(c=='\n') // TO COUNT LINE NUMBER IN INPUT FILE
            lineno++;
        else // TO FIND SPECIAL SYMBOL
            printf("%c is a special symbol\n",c);
    }
    printf("Total no. of lines in input file are: %d\n",lineno);
    fclose(f1);
}
