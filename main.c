#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

static bool copy_file(const char *, const char *);
static bool copy_files(char *, char *);
void make_dir(char *);
static void usage();

const char *src_file = "template.txt";  //テンプレートファイルの名前

int main(int argc, char *argv[]) {
  if (argc != 3) {
    usage();
    return 0;
  }
  char path[256] = "../";
  strcat(path, argv[1]);
  make_dir(path);
  copy_files(path, argv[2]);

  return 0;
}

void make_dir(char *dirname) {
  if (mkdir(dirname, S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP |
                         S_IROTH | S_IWOTH | S_IXOTH) != 0) {
    perror("mkdir");
    exit(-1);
  }
}

static bool copy_file(const char *src_fname, const char *dst_fname) {
  FILE *fin = fopen(src_fname, "rb");
  if (!fin) {
    perror("failed to open file");
    return false;
  }
  FILE *fout = fopen(dst_fname, "wb");
  if (!fout) {
    perror("failed to opne destination file");
    return false;
  }

  while (1) {
    int c = fgetc(fin);
    if (c == EOF) break;

    fputc(c, fout);
  }

  fclose(fout);
  fclose(fin);
  return true;
}

static bool copy_files(char *dirname, char *file_extention) {
  char *file_names[] = {"/a", "/b", "/c", "/d", "/e", "/f", "/g", "/Ex"};

  int i = 0;
  while (i < 8) {
    char file_name1[256] = "";
    strcat(file_name1, dirname);
    strcat(file_name1, file_names[i]);
    strcat(file_name1, file_extention);
    //一つ上の階層にファイルを作る。
    if (!copy_file(src_file, file_name1)) {
      fprintf(stderr, "failed to copy file\n");
      return false;
    }
    i++;
  }
  return true;
}

static void usage() { printf("Usage: ./a.out [abc-ID] [file extention]\n"); }