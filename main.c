#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *first, *end;
    char path1[51];
    char path2[51];
    char *ptr_path2=path2;
    char *ptr_path1 = path1;
    printf("Podaj sciezke do pliku:\n");
    scanf("%30s",path1);
    fflush(stdin);
    int size = strlen(path1);

    if(*(ptr_path1+size-1)!='p'||*(ptr_path1+size-2)!='m'||*(ptr_path1+size-3)!='b'||*(ptr_path1+size-4)!='.')
    {
        printf("Unsupported File Format");
        return 7;
    }
    else if(size>30){
        printf("Unsupported File Format");
        return 7;
    }
    if(strlen(path1)==30)
        while(getchar()!='\n');
    first = fopen(path1, "rb");
    if(first == NULL)
    {
        printf("couldn't open file");
        return 4;
    }
    if(first!=NULL)
    {
        *(ptr_path2+0)='c';
        *(ptr_path2+1)='o';
        *(ptr_path2+2)='p';
        *(ptr_path2+3)='y';
        *(ptr_path2+4)='_';
        for(int i=0; i<size+1; i++)
        {
            *(ptr_path2+i+5)=*(ptr_path1+i);
        }

    }

    end = fopen(ptr_path2, "wb");
     if(end == NULL)
    {
        fclose(first);
        printf("couldn't create file");
        return 5;
    }
    char znak;

    while(1)
    {
        znak = fgetc(first);
        if(feof(first)!=0)
        {
            break;
        }


            fprintf(end,"%c",znak);

    }

    printf("File saved");
    fclose(first);
    fclose(end);
    return 0;

}
