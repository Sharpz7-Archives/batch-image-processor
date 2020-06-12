#include <stdlib.h>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

void remove_extension(char* s) {
  char* dot = 0;

  while (*s) {
    if (*s == '.') {
        dot = s;
    } else if (*s == '/') {
        dot = 0;
    }
    s++;
  }

  if (dot) {
      *dot = '\0';
  }
}


void pictureTesting(char *imgFile) {
    int width, height, channels;

    char fullFile[80];
    sprintf(fullFile, "%s%s", "./images/", imgFile);
    unsigned char *img = stbi_load(fullFile, &width, &height, &channels, 0);
    if(img == NULL) {
        printf("Error in loading the image\n");
        exit(1);
    }

    remove_extension(imgFile);
    sprintf(fullFile, "%s%s%s", "./processed/", imgFile, ".jpg");
    stbi_write_jpg(fullFile, width, height, channels, img, 100);

    stbi_image_free(img);
}

int main() {
    mkdir("./processed", 0777);
    printf("Created Folder\n");

    struct dirent *de;  // Pointer for directory entry

    DIR *dr = opendir("./images");

    if (dr == NULL)  {
        printf("Could not open current directory" );
        return 0;
    }

    while ((de = readdir(dr)) != NULL) {

        if (de->d_type != DT_DIR) {
            printf("%s\n", de->d_name);
            pictureTesting(de->d_name);
        }
    }

    closedir(dr);
    return 0;
}