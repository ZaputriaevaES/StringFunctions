#include <stdio.h>
#include <stdlib.h>

size_t strlenmy(const char *str);

char * strcatmy(char * strl, const char * str2);
char * strncatmy(char * str1, const char * str2, size_t n);

char * strcpymy(char * str1, const char * str2);
char * strncpymy(char * str1, const char * str2, size_t n);

int    strcmpmy(const char * str1, const char * str2);
int    strncmpmy(const char * str1, const char * str2, size_t n);

char * strchrmy(char * str, int ch);
char * strrchrmy(char * str, int ch);

char * strpbrkmy(char * str1, const char * str2);

size_t strspnmy(const char * str1, const char * str2);
size_t strcspnmy(const char * str1, const char * str2);

int    putsmy(const char * str);
char * fgetsmy(char * str, int num, FILE * stream);
char * strdupmy(char * str);


int main(void)
{
    char       str1[] = "hegllogeorge";
    const char str2[] = "ytgf";
    char       str3[20]; 

    //printf("%d\n", strlenmy(str2));
    //printf("%s\n", strcatmy(str1, str2));
    //printf("%s\n", strncatmy(str1, str2, 1));    
    //printf("%s\n", strcpymy(str1, str2));
    //printf("%s\n", strncpymy(str1, str2, 7));
    //printf("%d\n", strcmpmy(str1, str2));
    //printf("%d\n", strncmpmy(str1, str2, 3));
    //printf("%p\n", strchrmy(str1, 'g'));
    //printf("%p",   strrchrmy(str1, 'k'));
    //printf("%c",   *strpbrkmy(str1, str2));
    //printf("%d\n", strspnmy(str1, str2));
    //printf("%d\n", strcspnmy(str1, str2));
    //putsmy(str2);
    //fgetsmy(str3, 6, stdin);
    //printf("%s", str3);
    //char * copy = strdupmy(str1);
    //printf("%s", copy);
    //free(copy);

    return 0;
}

size_t strlenmy(const char *str)
{
    size_t i = 0;
    while(str[i] != '\0')
    {
        i++;
    }
    return i;
}

char * strcatmy(char * str1, const char * str2)
{
    size_t len1 = strlenmy(str1);

    char * pstr1 = str1;
    pstr1 += len1;

    while(*str2 != '\0')
    {
        *(pstr1++) = *(str2++);
    }

    *(pstr1) = '\0';

    return str1;
}

char * strncatmy(char * str1, const char * str2, size_t n)
{
    size_t len1 = strlenmy(str1);

    char * pstr1 = str1;
    pstr1 += len1;

    while(n-- > 0 && *str2 != '\0')
    {
        *(pstr1++) = *(str2++);
    }

    *(pstr1) = '\0';

    return str1;
}

char * strcpymy(char * str1, const char * str2)
{
    char * pstr1 = str1;

    while(*str2 != '\0')
    {
        *(pstr1++) = *(str2++);
    }

    *(pstr1) = '\0';

    return str1;
}

char * strncpymy(char * str1, const char * str2, size_t n)
{
    char * pstr1 = str1;
    int k = n;

    while(k-- > 0 && *str2 != '\0')
    {
        *(pstr1++) = *(str2++);
    }

    if(k >= 0)
    {
        while(k-- > 0 && *str2 != '\0')
        {
            *(pstr1++) = '\0';
        }
    }

    else
        *(pstr1) = '\0';

    return str1;
}

int    strcmpmy(const char * str1, const char * str2)
{
    int dif = 0; // difference of ANSI codes

    while((dif = (*str1 - *str2)) == 0 && *str1 != '\0' && *str2 != '\0')
    {
        str1++;
        str2++;
    }

    return dif;
}

int    strncmpmy(const char * str1, const char * str2, size_t n)
{
    int dif = 0; // difference of ANSI codes

    while(n-- > 0 && (dif = (*str1 - *str2)) == 0 && *str1 != '\0' && *str2 != '\0')
    {
        str1++;
        str2++;
    }

    return dif;
}

char * strchrmy(char * str, int ch)
{
    while(*str != '\0')
    {
        if (*str == ch)
        {
            return str;
        }
        str++;
    }

    return NULL;
}

char * strrchrmy(char * str, int ch)
{
    char * pch = NULL;

    while(*str != '\0')
    {
        if (*str == ch)
        {
            pch = str;
        }
        str++;
    }

    return pch;
}

char * strpbrkmy(char * str1, const char * str2)
{

    for(; *str1 != '\0'; str1++)
    {
        for(const char * pstr2 = str2; *pstr2 != '\0'; pstr2++)
        {
            if (*pstr2 == *str1)
                return str1;
        }
    }

/*
    while(*str1 != '\0')
    {
        const char * pstr2 = str2;
        while(*pstr2 != '\0')
        {
            if (*pstr2 == *str1)
                return str1;
            pstr2++;
        }    
        str1++;
    }
*/

    return NULL;
}

size_t strspnmy(const char * str1, const char * str2)
{
    size_t counter = 0;

    for(; *str1 != '\0'; str1++)
    {
        int a = 0;
        for(const char * pstr2 = str2; *pstr2 != '\0'; pstr2++)
        {
            if (*str1 == *pstr2)
            {
                counter += 1;
                a = 1;
                break;
            }
        }
        if (a == 0)
            break;
    }

    return counter;
}

size_t strcspnmy(const char * str1, const char * str2)
{
    size_t counter = 0;

    for(; *str1 != '\0'; str1++)
    {
        int a = 0;
        for(const char * pstr2 = str2; *pstr2 != '\0'; pstr2++)
        {
            if(*str1 == *pstr2)
            {
                a = 1;
                break;
            }
        }
        if (a == 1)
            break;
        counter += 1;
    }

    return counter;
}

int    putsmy(const char * str)
{
    int a = 0;

    while(*str != '\0')
    {
        if ((a = putc(*(str++), stdout)) == EOF)  //putc() возвращает записанный символ или EOF
            return a;
    }

    if ((a = putc('\n', stdout)) == EOF)
        return a;

    return a;
}

char * fgetsmy(char * str, int num, FILE * stream)
{
    char * pstr = str;

    while(num-- > 0 && ((* pstr = getc(stream)) != '\n'))
    {
        if (*(pstr++) == EOF)
            return NULL;
    }

    *pstr = '\0';

    return str;
}

char * strdupmy(char * str)
{
    size_t len = strlenmy(str);
    char * copy = (char*) calloc(len + 1, sizeof(char)); 
    
    if (copy == NULL) return NULL;

    char * pcopy = copy;

    for(;*str != '\0'; pcopy++, str++)
    {
        *pcopy = *str;
    }

    *pcopy = '\0';

    return copy;
}