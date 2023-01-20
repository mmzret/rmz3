// https://gist.github.com/mmozeiko/ed9655cf50341553d282

#define STR2(x) #x
#define STR(x) STR2(x)

/*
    .section .rodata

    .global incbin_xxx_start
    .balign 16
    incbin_xxx_start:
        .incbin yyy.bin

    .global incbin_xxx_end
        .balign 1
        incbin_xxx_end:

#define INCBIN(name, file)                                               \
  __asm__(".section .rodata\n" \
            ".global incbin_" STR(name) "_start\n" \
            ".balign 16\n" \
            "incbin_" STR(name) "_start:\n" \
            ".incbin \"" file "\"\n" \
            \
            ".global incbin_" STR(name) "_end\n" \
            ".balign 1\n" \
            "incbin_" STR(name) "_end:\n" \
    );
*/

#define INCBIN8(name, file) \
  __asm__(".section .rodata\n" \
            ".global " STR(name) "\n" \
            STR(name) ":\n" \
            ".incbin \"" file "\"\n" \
    ); \
    extern const u8* name;

#define INCBIN16(name, file)     \
  __asm__(".section .rodata\n" \
            ".global " STR(name) "\n" \
            ".balign 2\n" \
            STR(name) ":\n" \
            ".incbin \"" file "\"\n" \
    ); \
  extern const u16* name;

/*
INCBIN(foobar, "binary.bin");

int main()
{
    printf("start = %p\n", &incbin_foobar_start);
    printf("end = %p\n", &incbin_foobar_end);
    printf("size = %zu\n", (char*)&incbin_foobar_end - (char*)&incbin_foobar_start);
    printf("first byte = 0x%02x\n", ((unsigned char*)&incbin_foobar_start)[0]);
}
*/
