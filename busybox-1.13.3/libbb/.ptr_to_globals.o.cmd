cmd_libbb/ptr_to_globals.o := arm-linux-gcc -Wp,-MD,libbb/.ptr_to_globals.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.13.3)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wmissing-prototypes -Wmissing-declarations -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -Os    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(ptr_to_globals)"  -D"KBUILD_MODNAME=KBUILD_STR(ptr_to_globals)" -c -o libbb/ptr_to_globals.o libbb/ptr_to_globals.c

deps_libbb/ptr_to_globals.o := \
  libbb/ptr_to_globals.c \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/errno.h \
    $(wildcard include/config/.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/features.h \
    $(wildcard include/config/c99.h) \
    $(wildcard include/config/c95.h) \
    $(wildcard include/config/ix.h) \
    $(wildcard include/config/ix2.h) \
    $(wildcard include/config/ix199309.h) \
    $(wildcard include/config/ix199506.h) \
    $(wildcard include/config/en.h) \
    $(wildcard include/config/en/extended.h) \
    $(wildcard include/config/x98.h) \
    $(wildcard include/config/en2k.h) \
    $(wildcard include/config/gefile.h) \
    $(wildcard include/config/gefile64.h) \
    $(wildcard include/config/e/offset64.h) \
    $(wildcard include/config/d.h) \
    $(wildcard include/config/c.h) \
    $(wildcard include/config/ile.h) \
    $(wildcard include/config/ntrant.h) \
    $(wildcard include/config/tify/level.h) \
    $(wildcard include/config/i.h) \
    $(wildcard include/config/ern/inlines.h) \
    $(wildcard include/config/ern/inlines/in/libc.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/predefs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/cdefs.h \
    $(wildcard include/config/espaces.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/wordsize.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/gnu/stubs.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/linux/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/errno.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/errno-base.h \

libbb/ptr_to_globals.o: $(deps_libbb/ptr_to_globals.o)

$(deps_libbb/ptr_to_globals.o):
