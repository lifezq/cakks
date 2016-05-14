#include<stdio.h>
#include<assert.h>

int getProgramBits()
{
    return sizeof(int*)*8;
}

int main(int argc, char* argv[])
{
    printf("bits:\t%d\n", getProgramBits());
    assert(argc > 1);
    return 0;
}

