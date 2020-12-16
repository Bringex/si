#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>



union header{
    char array[4];
    struct {
         unsigned int size;
    } info;
};
union frames{
    unsigned char array[8];
    struct {
        unsigned int sizefile;
        unsigned int len;
    } info;
};

char* cutStr(char *name){
    int indexDot = 0;
    for (int i = strlen(name) - 1; i >= 0; i--)
        if (name[i] == '.')
            indexDot = i;
    int lenEnd = strlen(name) - indexDot;
    char *newStr = malloc(indexDot + 1);
    char *end = malloc(lenEnd + 1);
    char *answer = malloc(strlen(name) + 5);

    for (int i = 0; i < indexDot; i++)
        newStr[i] = name[i];
    for (int i = indexDot; i < strlen(name); i++)
        end[i - indexDot] = name[i];
    end[lenEnd] = '\0';
    newStr[indexDot] = '\0';

    sprintf(answer, "%s_copy%s", newStr, end);


    printf("%s\n", answer);
    return answer;
}

long long fileSize(char *name){
    FILE *file = fopen(name, "rb");
    //printf("%s", name);
    fseek(file, 0, SEEK_END);
    return ftell(file);
}

void list (char *name){
    FILE *file = fopen(name, "rb");
    union header heado;
    fread(heado.array, 4, 1, file);

    for (int i = ftell(file); i < heado.info.size;){
        union frames frame;
        fread(frame.array, 8, 1, file);

        char *namer = malloc(frame.info.len + 1);
        fread(namer, frame.info.len, 1, file);
        namer[frame.info.len] = '\0';

        printf("%s\n", namer);

        fseek(file, frame.info.sizefile, SEEK_CUR);
        i = ftell(file);
    }
}


void push(char *names[], int countFiles, char *saveName){
    FILE *file = fopen(saveName, "wb");

    union header head;
    head.info.size = 0;
    for (int i = 0; i < countFiles; i++){
        head.info.size += fileSize(names[i]) + strlen(names[i]);
    }
    head.info.size += countFiles * 8;

    fwrite(head.array, 4, 1, file);

    for (int i = 0; i < countFiles; i++){
        union frames head;
        head.info.sizefile = fileSize(names[i]);
        head.info.len = strlen(names[i]);

        fwrite(head.array, 8, 1, file);
        fwrite(names[i], strlen(names[i]), 1, file);


        FILE *readFile = fopen(names[i], "rb");
        int s;
        while((s = getc(readFile)) != EOF){
            fwrite(&s, 1, 1, file);
        }
    }



    //convert.size = BE(10);
    //fwrite(convert.array, 1, 4, file);


    //fwrite(&countFiles, sizeof(long long), 1, file);

    //for (int i = 0; i < countFiles; i++){

        //fwrite(&names[i], 8, 1, file);
        //
        //b8 size = fileSize(names[i]);
        //printf("%s\n", names[i]);
        //printf("%d\n", fileSize(names[i]));
        //fwrite(&size, 8, 1, file);


    //}

}

void pop(char *name){
    FILE *file = fopen(name, "rb");
    union header heado;
    fread(heado.array, 4, 1, file);

    for (int i = ftell(file); i < heado.info.size;){
        union frames frame;
        fread(frame.array, 8, 1, file);

        char *namer = malloc(frame.info.len + 1);
        fread(namer, frame.info.len, 1, file);
        namer[frame.info.len] = '\0';
        //cutStr(namer);
        printf("%s\n", namer);
        FILE *newFile = fopen(cutStr(namer), "wb");
        int s;
        for (i = 0; i < frame.info.sizefile; i++){
            s = fgetc(file);
            //printf("%d", s);
            fwrite(&s, 1, 1, newFile);
        }

        fclose(newFile);
        i = ftell(file);
    }

}

int main(int argc, char* argv[])
{
    printf("format: %s\n", argv[1]);
    char *ArcName = argv[3];
    if (argv[4][2] == 'c'){
        printf("%d\n", argc - 5);
        char **names = (char **)malloc((argc - 5) * sizeof(char *));
        printf("Files: ");
        for (int i = 5; i < argc; i++){
            names[i - 5] = malloc(strlen(argv[i]));
            names[i - 5] = argv[i];
            printf("%s  ", names[i - 5]);
        }
        printf("\n");
        push(names, argc - 5, ArcName);
    }
    else if (argv[4][2] == 'e'){
        //extract
        pop(ArcName);
    }
    else{
        //list
        list(ArcName);
    }

    return 0;
}
//C:\Users\Mi\Desktop\LearnAS\la15\bin\Debug
//arc --file  arc.arc --list
//arc --file  arc.arc --extract
//arc --file  arc.arc --create text.txt text1.txt one.bmp two.bmp
//arc --file  arc.arc --create text.txt text1.txt
// 1     2      3      4
