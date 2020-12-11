#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef unsigned long long ulong;

int check(char** arr, int i, int j, int H, int W){
    int neibor = 0;
    if (i - 1 > 0 && j - 1 > 0)//left up
        if (arr[i - 1][j - 1] == 1)
            neibor++;
    if (j - 1 > 0)//left
        if (arr[i][j - 1] == 1)
            neibor++;
    if (j + 1 < W)//right
        if (arr[i][j + 1] == 1)
            neibor++;
    if (i - 1 > 0)//up
        if (arr[i - 1][j] == 1)
            neibor++;
    if (i + 1 < H)//down
        if (arr[i + 1][j] == 1)
            neibor++;
    if (i - 1 > 0 && j + 1 < W)//right up
        if (arr[i - 1][j + 1] == 1)
            neibor++;
    if (i + 1 < H && j - 1 > 0)
        if (arr[i + 1][j - 1] == 1)
            neibor++;
    if (i + 1 < H && j + 1 < W)
        if (arr[i + 1][j + 1] == 1)
            neibor++;
    return neibor;
}
void game_next(char** arr, int height, int width){

    int neibors = 0;
    char **tmp = (char **) malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        tmp[i] = (char *) malloc(width * sizeof(char));
    }
    for (int i = 0; i < height; i++) //copy
        for (int j = 0; j < width; j++)
            tmp[i][j] = arr[i][j];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
        {
            neibors = check(arr, i, j, height, width);
            if (!((neibors == 2 || neibors == 3) && arr[i][j] == 1))
                tmp[i][j] = 0;
            if (neibors == 3 && arr[i][j] == 0)
                tmp[i][j] = 1;
        }

    for (int i = 0; i < height; i++) //copy
        for (int j = 0; j < width; j++)
            arr[i][j] = tmp[i][j];


}

void getDataBMP(char* path, char* output, int max, int dump){
    FILE* image;
    image = fopen(path, "rb");

    int size, offset, width, height, skip_int;
    fseek(image, 2, SEEK_SET);

    fread(&size, 4, 1, image);
    fseek(image, 10, SEEK_SET);

    fread(&offset, 4, 1, image);
    fread(&skip_int, 4, 1, image);
    fread(&width, 4, 1, image);
    fread(&height, 4, 1, image);// + 4 = 26
    //fseek(image, 0, SEEK_SET);
    //fread(&saveHeader, 54, 1, image);
    fseek(image, 54, SEEK_SET);

    printf("1 %d\n", height);
    printf("2 %d\n", width);


    char **arr = (char **) malloc(height * sizeof(char *));
    for (int i = 0; i < height; i++) {
        arr[i] = (char *) malloc(width * sizeof(char));
    }

    unsigned char *bytes = (unsigned char*)malloc((size - 54) * sizeof(unsigned char));
	fread(bytes, 1, size, image);

    int k = 0;
	for (int i = height - 1; i >= 0; i--) {
		for (int j = 0; j < width; j++) {
			if (bytes[k*3] == 255)
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
			k++;
		}
	}
	//for (int i = 0; i < height; i++) {
	//	for (int j = 0; j < width; j++)
    //        printf("%d", arr[i][j]);
    //    printf("\n");
	//}


    printf("\n");

    //start game
    //we have array and lets change it...

    for (int i = 0; i < max; i++){
        if (i % dump == 0){
            fclose(image);
            image = fopen(path, "rb");

            char result[150];
            sprintf(result, "%s%d.bmp", output, i);
            printf("%s\n", result);
            FILE* save = fopen(result, "wb");
            char s;
            fseek(image, 0, SEEK_SET);
            for (int i = 0; i < offset; i++) {
                fread(&s, 1, 1, image);
                fwrite(&s, 1, 1, save);
            }
            fseek(image, 54, SEEK_SET);
            fseek(save, 54, SEEK_SET);
            unsigned char black = 0;
            unsigned char white = 255;


            for (int i = height - 1; i >= 0; i--)
                for (int j = 0; j < width; j++)
                    {
                        //printf("h:%d w:%d\n", i, j);
                        if (arr[i][j] == 1){
                            fwrite(&black, 1, 1, save);
                            fwrite(&black, 1, 1, save);
                            fwrite(&black, 1, 1, save);
                        }
                        else{
                            fwrite(&white, 1, 1, save);
                            fwrite(&white, 1, 1, save);
                            fwrite(&white, 1, 1, save);
                        }
                     }

        }

        game_next(arr, height, width);
    }




    //fseek(image, 1, 2);
    //fread(&bmp, 1, 54, image);

    //char **bw_Map =(char **)malloc(bmp.biHeight * sizeof(char*)); //short *
    //for (size_t i = 0; i < bmp.biHeight; i++)
    //    bw_Map[i] = malloc(bmp.biWidth * sizeof(char));

    //fseek( image, 0, SEEK_END);
    //int filesize = ftell(image);
    // восстановим указатель в файле:
    //fseek( image, sizeof(BMPheader), SEEK_SET);


    //printf("1 %d\n", bmp.bfSize);
    //printf("2 %d\n", filesize);

    //fread(bmp.bfType, 1, 2, image);
    //printf("%d", bmp.bfType);

    //printf("%d", convert_length(bmp.bfSize));
    //value_to_array(bmp.biHeight);
}


int main(int argc, char* argv[])
{
    char* file =  argv[2];
    char* output = argv[4];
    int max = 100;
    int dump = 1;
    for (int i = 0; i < argc; i++)
    {
        if (!strcmp(argv[i], "--max_iter"))
            max = atoi(argv[i+1]);
        else if (!strcmp(argv[i], "--dump_freq"))
            dump = atoi(argv[i+1]);

    }
    printf("%s\n", file);
    printf("%s\n", output);
    printf("%d\n", max);
    printf("%d\n", dump);

    getDataBMP(file, output, max, dump);
    return 0;
}

//cd C:\Users\Mi\Desktop\LearnAS\lab14\bin\Debug
//lab14.exe --input pa4.bmp --output C:\Users\Mi\Desktop\LearnAS\lab14\bin\ --max_iter 500 --dump_freq 50

cd C:\Users\Mi\Desktop\LearnAS\lab14\bin\Debug
lab14.exe --input pa4.bmp --output C:\Users\Mi\Desktop\LearnAS\lab14\bin\ --max_iter 100 --dump_freq 5
