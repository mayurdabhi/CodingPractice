#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch[50];
    unsigned char c;
    int i;
	int *p;
	p = &i;
    FILE *fp;
    fp=fopen("D:\link.txt", "r+");
    fputs("Hello World",fp);
    fclose(fp);
        fp=fopen("D:\link.txt", "r+");

    while((c = getc(fp))!=EOF)
       printf("%c", c);

     i = fseek(fp,2L,SEEK_CUR);
    printf("%d\n",i);
    //fgets(ch,50,fp);
    c = getc(fp);
   printf("%c", ch);
    fclose(fp);
    return 0;
}
