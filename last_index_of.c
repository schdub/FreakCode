#include <stdio.h>
 
int last_index_of(const char * s, const char c) {
    int ret;
    return (*s) ? (((ret = last_index_of(s + 1, c)) > -1) ? ret + 1 : (*s == c) - 1) : -1;
}
 
int main(void) {
    char buf[256], c;
    while (printf("Word and letter: ") && scanf("%s %c", buf, &c) == 2 && c != '*') {
        int pos = last_index_of(buf, c);
        if (pos < 0)
            printf("Not found.\n");
        else
            printf("Last index: %d\n", pos);
    }
    return 0;
}