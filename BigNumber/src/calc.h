#include <stdio.h>
#include <string.h>

//翻转字符串
char *reverse_string(char *src_str);
//s1 + s2
char *big_add(char *s1, char *s2);
//s1 - s2
char *big_sub(char *s1, char *s2);

#define     FIRST_BIGGER      1
#define     SECOND_BIGGER     2
#define     EQUAL             0
//检查大小big or small   1前大  2后大  0相等
int check_bos(char *s1, char *s2);







