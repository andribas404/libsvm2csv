#include <cstdio>

void convert(FILE *fin, FILE *fout) {
    for (;;) {
        int c = fgetc(fin);
        if (c == EOF) {
            break;
        }
        fputc(c, fout);
    }
}
