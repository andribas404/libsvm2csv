/*
Copyright 2019 Andrey Petukhov
*/

#include <cstdio>
#include <cerrno>
#include "libsvm2csv.h"

int main() {
    const char* src = "train1000.txt";
    const char* dst = "train.csv";

    FILE *fin = fopen(src, "r");
    FILE *fout = fopen(dst, "w");

    if (fin == NULL || fout == NULL) {
        return errno;
    }

    convert(fin, fout);

    return 0;
}
