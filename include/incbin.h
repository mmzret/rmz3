// https://gist.github.com/mmozeiko/ed9655cf50341553d282

#define STR2(x) #x
#define STR(x) STR2(x)

#define INC4BPP(name)      \
  __asm__(                 \
      ".section .rodata\n" \
      ".incbin \"" name    \
      ".4bpp\"\n"          \
      ".incbin \"" name ".gbapal\"\n");

#define INCLZ(name)        \
  __asm__(                 \
      ".section .rodata\n" \
      ".incbin \"" name    \
      ".lz\"\n"            \
      ".incbin \"" name ".lz.gbapal\"\n");

#define INCBIN(file)       \
  __asm__(                 \
      ".section .rodata\n" \
      ".incbin \"" file "\"\n");

#define INCBIN8(name, file)      \
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

#define INCBIN_STATIC(name, file)   \
  __asm__(".section .rodata\n" STR( \
      name) ":\n"                   \
            ".incbin \"" file "\"\n");
