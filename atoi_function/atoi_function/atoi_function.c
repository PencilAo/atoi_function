#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
 //atoi函数模拟实现
int main()
{
    char arr[20] = "12344";
    int ret = atoi(arr);
    printf("%d", ret);
    return 0;
}
#include <ctype.h>
#include <limits.h>
#include <assert.h>
enum S
{
    VALID,
    INVALID
}s = INVALID; //默认非法
int my_atoi(const char* str)
{
    assert(str);
    int flag = 1;
    if (*str == '\0')
    {
        return 0;
    }
    while (isspace(*str))
    {
        str++;
    }
    if (*str == '+')
    {
        flag = 1;
        str++;
    }
    else if(*str == '-')
    {
        flag = -1;
        str++;
    }
    long long  ret = 0;
    while (*str)
    {
        if ('1' <= *str && *str <= '9')
        {
            ret = ret * 10 + flag * (*str - '0');
            //越界
            if (ret > INT_MAX || ret < INT_MIN)
            {
                return 0;
            }
        }
        else
        {
            return (int)ret;
        }
        str++;
    }
    if (*str == '\0')
    {
        s = VALID;
    }
    return (int)ret;
}
int main()
{
    char arr[100];
    gets(arr);
    int ret = my_atoi(arr);
    if (s == INVALID)
    {
        printf("非法值: %d", ret);
    }
    if (s == VALID)
    {
        printf("合法值: %d", ret);
    }
    return 0;
}