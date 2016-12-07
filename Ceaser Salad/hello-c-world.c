#include <stdio.h>


void readFile(){
    FILE *fp, *ofp;
    fp = fopen("input1.txt", "r");
    
    
    if (fp == NULL) {
      fprintf(stderr, "Can't open input file!\n");
    }
    int number;
    number = fgetc(fp);
    printf("%d", number);

}
int main() {
    printf("Hello World!\n");
    return 0;
}
