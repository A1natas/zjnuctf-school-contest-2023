

#include <stdio.h>
#include <Windows.h>
#include <iostream>

#define obf1 __asm{\
__asm jmp $ \
}
#define shit1 __asm {\
__asm call $+6 \
__asm _emit 0xe8 \
__asm add dword ptr ss : [esp] , 8 \
__asm ret \
__asm _emit 0xe8 \
}
#define shit2 __asm {\
__asm _emit 0xeb \
__asm _emit 0xff \
__asm _emit 0xc0 \
__asm _emit 0x48 \
}

void printflag() {
    const char* text = "别看这个函数了，你看不出来的，还是想想怎么睡醒吧";
    shit2;
    unsigned char* p = (unsigned char*)calloc(sizeof(unsigned char), 8388608);
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    while (*p) {
        ++p;
        ++* p;
        ++* p;
        ++* p;
        ++* p;
        --p;
        --* p;
    }
    ++p;
    while (*p) {
        ++p;
        ++* p;
        ++* p;
        ++p;
        while (*p) {
            ++* p;
            ++* p;
            ++* p;
            ++* p;
            ++* p;
            ++* p;
            ++* p;
            ++* p;
            ++p;
        }
        ++* p;
        ++* p;
        while (*p) {
            --p;
        }
        ++p;
        --* p;
    }
    ++p;
    ++p;
    putchar(*p);
    ++p;
    ++p;
    putchar(*p);
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    ++p;
    ++* p;
    putchar(*p);
    --p;
    --* p;
    putchar(*p);
    ++p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    --p;
    --p;
    --p;
    ++* p;

    putchar(*p);
    --p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    ++p;
    ++p;
    ++p;
    putchar(*p);
    ++p;
    ++p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    --p;
    putchar(*p);
    ++p;
    ++p;
    ++p;
    ++p;
    ++p;
    --* p;
    --* p;
    --* p;
    --* p;
    --* p;
    --* p;
    --* p;
    putchar(*p);
    putchar(*p);
    --p;
    --p;
    --* p;
    putchar(*p);
    --p;
    --p;
    --p;
    --p;
    --* p;
    putchar(*p);
    ++p;
    ++p;
    putchar(*p);
    --p;
    ++* p;
    putchar(*p);
    --p;
    --p;
    --p;
    --p;
    --* p;
    putchar(*p);
    ++p;
    ++p;

    --* p;
    --* p;
    --* p;
    putchar(*p);
    ++p;
    ++p;
    --* p;
    --* p;
    --* p;
    putchar(*p);
    ++p;
    putchar(*p);
    ++p;
    ++p;
    ++p;
    ++p;
    --* p;
    putchar(*p);
    --p;
    --p;
    --p;
    --p;
    putchar(*p);
    while (*p) {
        --p;
    }
    ++p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    ++p;
    ++p;
    --* p;
    --* p;
    --* p;
    putchar(*p);
    ++p;
    ++p;
    ++* p;
    putchar(*p);
    putchar(*p);
    --p;
    --* p;
    --* p;
    --* p;
    putchar(*p);
    while (*p) {
        ++p;
    }
    --p;
    --p;
    --p;
    --p;
    --p;
    --* p;
    putchar(*p);
    while (*p) {
        --p;
    }
    ++p;
    ++p;
    ++* p;
    ++* p;
    putchar(*p);
    --p;
    --p;
    ++* p;
    ++* p;
    ++* p;

    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    ++p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    ++* p;
    putchar(*p);
    putchar(*p);
    putchar(*p);
    putchar(*p);
    putchar(*p);
    --p;
    putchar(*p);
    p = NULL;
    free(p);

}

int main()
{
    std::cout << "你这个年龄段，你睡得着觉?" << std::endl;
    std::cout << "等你醒了我再把符拉格给你" << std::endl;

    printf("                          . .                                                \n");
    printf("          L # # # # # # # W W # # # # # # # L .                              \n");
    printf("    : # # # # E .                       , D # # # f                          \n");
    printf("K # #                                             i # # t                    \n");
    printf("# .                                                   K # W                  \n");
    printf("                                                        . # K                \n");
    printf("                                                            G # :            \n");
    printf("                                                              j # .          \n");
    printf("                                K K           #                 L # ,        \n");
    printf("                              # G f D       E f                   # #        \n");
    printf("                              E             #                       #        \n");
    printf("                              E               # #                   : #      \n");
    printf("                              # D                                     # .    \n");
    printf("                              D #                                     E #    \n");
    printf("                              #                                         #    \n");
    printf("                              #                                         # :  \n");
    printf("                              E K . t #           : ;                   L G  \n");
    printf("                                L # D             # t                   . #  \n");
    printf("                                                  L                       #  \n");
    printf("                                                  #                       # .\n");
    printf("                                                  : E                     # ,\n");
    printf("                                                                          # i\n");
    printf("                                                                          # i\n");
    printf("                      i                                                   # ;\n");
    printf("                    # ;                                                   # ,\n");
    printf("              : # E                                                       #  \n");
    printf("          j # # :                                                         #  \n");
    printf("        ; W ,                                                             #  \n");
    printf("        #                     j .                                       f L  \n");
    printf("      , W                   E :                                         #    \n");
    printf("        # j i , ; j D # # j                                           j #    \n");
    printf("        . K # # W E f ,                                               # K    \n");
    printf("                                                                      #      \n");
    printf("                                                                  : #        \n");
    printf("                                                                . # W        \n");
    printf("                                                              : # ;          \n");
    printf("                                                            t # .            \n");
    printf("                                                          K # ;                           ");

    printf("Z");
    while (1) {
        Sleep(1500);
        printf("z");
    }
    printf("\n");
    obf1;
    std::cout << "睡醒了？那给你吧" << std::endl;
    printflag();
}

