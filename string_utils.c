/**
 * @file string_utils.c
 * @brief 字符串处理工具函数实现文件
 * @note 实现字符串操作相关函数
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "string_utils.h"

/**
 * @brief 去除字符串首尾空白字符
 * @details 移除字符串开头和结尾的空格、制表符、换行符等空白字符
 *          使用双指针技术，从两端向中间处理，原地修改字符串
 * @param str 要处理的字符串，函数会直接修改此字符串
 * @note 函数会直接修改传入的字符串，不会分配新内存
 * @note 如果整个字符串都是空白字符，结果将是空字符串
 * @warning 如果str为NULL，可能导致程序崩溃
 */
void trimString(char *str)
{
    if (str == NULL)
        return;

    // 去除开头的空白字符
    char *start = str;
    while (isspace((unsigned char)*start))
    {
        start++;
    }

    // 如果字符串全是空白字符
    if (*start == '\0')
    {
        str[0] = '\0';
        return;
    }

    // 去除结尾的空白字符
    char *end = str + strlen(str) - 1;
    while (end > start && isspace((unsigned char)*end))
    {
        end--;
    }

    // 移动字符串到开头
    int len = end - start + 1;
    memmove(str, start, len);
    str[len] = '\0';
}

/**
 * @brief 检查字符串是否为空
 * @details 检查字符串是否为NULL、空字符串或只包含空白字符
 *          使用isspace函数检查每个字符是否为空白字符
 * @param str 要检查的字符串
 * @return 如果字符串为空或只包含空白字符返回true，否则返回false
 * @note 空白字符包括空格、制表符、换行符等
 * @note 如果str为NULL，返回true
 */
bool isEmptyString(const char *str)
{
    if (str == NULL)
        return true;

    while (*str)
    {
        if (!isspace((unsigned char)*str))
        {
            return false;
        }
        str++;
    }
    return true;
}