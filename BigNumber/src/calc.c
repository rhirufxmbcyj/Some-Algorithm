#include "calc.h"

#define MAX(a,b)    ((a)>(b)?(a):(b))
#define MIN(a,b)    ((a)<(b)?(a):(b))

char *reverse_string(char *src_str)
{
    int len = strlen(src_str);
    char *dst_str = malloc(len + 1);
    memset(dst_str, 0, len + 1);
    for (int i = 0; i < len; i++)
        dst_str[i] = src_str[len - 1 - i];
    memcpy(src_str, dst_str, len);
    free(dst_str);
    return src_str;
}


char *big_add(char *s1, char *s2)
{
    char dst_str[1024] = { 0 };
    //2负 或 前正后负
    if ((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-' && s2[0] == '-'))
    {
        s2[0] = '0';
        return big_sub(s1, s2);
    }
    //前负后正
    if (s1[0] == '-' && s2[0] != '-')
    {
        s1[0] = '0';
        return big_sub(s2, s1);
    }
    reverse_string(s1);
    reverse_string(s2);
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int carry = 0;

    int i = 0;
    for (; i < MIN(len1, len2); i++)
    {
        char result = s1[i] - 0x30 + s2[i] - 0x30 + carry;
        carry = 0;
        if (result >= 10)
        {
            carry = 1;
            result -= 10;
        }
        dst_str[i] = result + 0x30;
    }
    //长度不同时处理
    if (len1 > len2)
    {
        for (; i < len1; i++)
            dst_str[i] = s1[i];
    }
    else
    {
        for (; i < len2; i++)
            dst_str[i] = s2[i];
    }

    return reverse_string(dst_str);
}

char *big_sub(char *s1, char *s2)
{
    //2正 2负 前正后负 前负后正(去掉符号 获取加的结果 加上负号)
    //考虑负数情况
    char dst_str[1024] = { 0 };
    //2负 		都变正，后-前
    if(s1[0]=='-' && s2[0]=='-')
    {
        s1[0] = '0';
        s2[0] = '0';
        return big_sub(s2, s1);
    }
    //前正后负 	变正，相加
    if (s1[0] != '-' && s2[0] == '-')
    {
        s2[0] == '0';
        return big_add(s1, s2);
    }
    //前负后正	去掉符号 获取加的结果 加上负号
    if (s1[0] == '-'&&s2[0] != '-')
    {
        s1[0] = '0';
        char *result = big_add(s1, s2);
        memcpy(dst_str, result, strlen(result));
        reverse_string(dst_str);
        strcat(dst_str, "-");
        return reverse_string(dst_str);
    }
    //两正
    int check = check_bos(s1, s2);
    //前小后大
    if (check == SECOND_BIGGER)
    {

    }
    //前大后小
    else if (check == FIRST_BIGGER)
    {
        reverse_string(s1);
        reverse_string(s2);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        int i = 0;
        int borrow = 0;
        for (; i < MIN(len1, len2); i++)
        {
            if (s1[i] - borrow < s2[i])
            {
                dst_str[i] = (s1[i] - 0x30 + 10 - borrow) - (s2[i] - 0x30) + 0x30;
                borrow = 1;
            }
            else
            {
                dst_str[i] = (s1[i] - 0x30) - borrow - (s2[i] - 0x30) + 0x30;
                borrow = 0;
            }
        }
        if (len1 > len2)
        {
            for (; i < len1; i++)
            {
                if (borrow)
                {
                    if (s1[i] == '0')
                        dst_str[i] = s1[i]
                }
            }
        }
    }
    else
    {
        dst_str[0] = '0';
    }
    return dst_str;
}

//1前大  2后大  0相等
int check_bos(char *s1, char *s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (s1[0] == '-' && s2[0] != '-')
    {
        return SECOND_BIGGER;
    }
    else if (s1[0] != '-' && s2[0] == '-')
    {
        return FIRST_BIGGER;
    }
    else if (s1[0] == '-' && s2[0] == '-')
    {
        if (len1 < len2)
            return FIRST_BIGGER;
        else if (len1 > len2)
            return SECOND_BIGGER;
        for (int i = 1; i < len1; i++)
        {
            if (s1[i] < s2[i])
                return FIRST_BIGGER;
            else if (s1[i] > s2[i])
                return SECOND_BIGGER;
        }
    }
    for (int i = 1; i < len1; i++)
    {
        if (s1[i] < s2[i])
            return SECOND_BIGGER;
        else if (s1[i] > s2[i])
            return FIRST_BIGGER;
    }
    return EQUAL;
}

int main()
{
    char a[] = "123456789123456789123456789123456789";
    char b[] = "234567890234567890234567890234567890234567890";
    //printf("%s\n",big_add(a, b));
    return 0;
}

