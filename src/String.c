#include "String.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

String *String_New(const char *s)
{
    String *result = (String *)malloc(sizeof(String));

    if (s == NULL)
    {
        result->length = 0;
        result->data = NULL;
    }
    else
    {
        result->length = strlen(s);
        result->data = (char *)calloc(result->length + 1, sizeof(char));

        for (size_t i = 0; i < result->length; ++i)
        {
            result->data[i] = s[i];
        }

        result->data[result->length] = '\0';
    }

    return result;
}

void String_Println(String *s)
{
    if (s == NULL)
    {
        return;
    }

    for (size_t i = 0; i < s->length; ++i)
    {
        putchar(s->data[i]);
    }

    putchar('\n');
}

String *String_Add(String *a, String *b)
{
    if (a == NULL)
    {
        return String_New(b->data);
    }
    if (b == NULL)
    {
        return String_New(a->data);
    }

    String *result = String_New(NULL);
    result->length = a->length + b->length;
    result->data = (char *)calloc(result->length + 1, sizeof(char));

    for (size_t i = 0; i < a->length; ++i)
    {
        result->data[i] = a->data[i];
    }
    for (size_t i = 0; i < b->length; ++i)
    {
        result->data[a->length + i] = b->data[i];
    }

    result->data[result->length] = '\0';
    return result;
}

String *String_Multiply(String *s, size_t count)
{
    String *result = String_New(NULL);

    if (s == NULL || count == 0)
    {
        return result;
    }

    result->length = s->length * count;
    result->data = (char *)calloc(result->length + 1, sizeof(char));

    for (size_t i = 0; i < count; ++i)
    {
        for (size_t j = 0; j < s->length; ++j)
        {
            result->data[i * s->length + j] = s->data[j];
        }
    }

    result->data[result->length] = '\0';
    return result;
}

void String_Delete(String *s)
{
    if (s == NULL)
    {
        return;
    }

    free(s->data);
    free(s);
}
