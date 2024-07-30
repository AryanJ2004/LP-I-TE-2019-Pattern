#include <stdio.h>
#include <string.h>

struct mnt {
    char mnm[50];
    int index;
} mnt[50];

FILE *fp, *fp1, *fp2, *fp3;
void readLine(char *buff, FILE *fp);
void callmac();
void handleNonMacro(char *buff);
int mntc = 0, mdtc = 0;
char instr[50][50];
char buff[50];

int main() {
    char ch;
    fp = fopen("E:/Codes/in.txt", "r");
    if (fp == NULL) {
        perror("Error opening input file");
    }

    fp1 = fopen("E:/Codes/inter.dat", "w");
    fp2 = fopen("E:/Codes/mdt.dat", "w");
    fp3 = fopen("E:/Codes/mnt.dat", "w");
    printf("\n\nInput File\n");
    printf("\n======================================\n");
    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }
    rewind(fp);

    while (1) {
        readLine(buff, fp);
        if (feof(fp)) break;
        if (strcmp(buff, "MACRO") == 0) {
           callmac();
        } else if (strcmp(buff, "END") != 0) {
            handleNonMacro(buff);
        }
    }

    printf("\n\nMNT TABLE");
    printf("\n======================================");
    printf("\nMacro Name\tStarting Index");
    for (int i = 0; i < mntc; i++) {
        printf("\n%s\t\t%d", mnt[i].mnm, mnt[i].index);
        fprintf(fp3, "\n%s\t\t%d", mnt[i].mnm, mnt[i].index);
    }

    printf("\n\nMDT TABLE");
    printf("\n======================================");
    printf("\nOpcode\t\t\tIndex");
    for (int i = 0; i < mdtc; i++) {
        printf("\n%s\t\t%d", instr[i], i);
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fp1 = fopen("E:/Codes/inter.dat", "r");

    printf("\n\nIntermediate Code");
    printf("\n======================================");
    while ((ch = fgetc(fp1)) != EOF) {
        printf("%c", ch);
    }
    fclose(fp1);

    return 0;
}

void readLine(char *buff, FILE *fp) {
    int i = 0;
    char ch;
    while ((ch = fgetc(fp)) != '\n' && ch != EOF) {
        buff[i++] = ch;
    }
    buff[i] = '\0';
}

void callmac() {
    readLine(buff, fp);
    fprintf(fp1, "\n%s", buff);
    strcpy(mnt[mntc].mnm, buff);
    mnt[mntc].index = mdtc;
    mntc++;

    while (1) {
        readLine(buff, fp);
        if (strcmp(buff, "MEND") == 0) {
            break;
        }
        strcpy(instr[mdtc], buff);
        fprintf(fp2, "\n%s", buff);
        mdtc++;
    }
}

void handleNonMacro(char *buff) {
    fprintf(fp1, "\n%s", buff);
}
