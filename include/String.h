#pragma once

#include <stddef.h>

typedef struct
{
    size_t length;
    char *data;
} String;

String *String_New(const char *s);

void String_Println(String *s);

String *String_Add(String *a, String *b);

String *String_Multiply(String *s, size_t count);

void String_Delete(String *s);