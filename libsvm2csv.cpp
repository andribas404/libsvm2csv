#include <cstdio>

void convert(const char* src, const char* dest) {
    FILE *fin = fopen(src, "r");
    FILE *fout = fopen(dest, "w");
    for (;;) {
        int c = fgetc(fin);
        if (c == EOF) {
            break;
        }
        fputc(c, fout);
    }
}

int main() {
    convert("train1000.txt", "train.csv");
    return 0;
}
