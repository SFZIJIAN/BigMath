#include "String.h"

int main()
{
    String *s1 = String_New("Hello,");
    String *s2 = String_New(" world!");

    String *repeat = String_Multiply(s1, 0);

    String_Println(repeat);

    String_Delete(s1);
    String_Delete(s2);
    String_Delete(repeat);
    return 0;
}