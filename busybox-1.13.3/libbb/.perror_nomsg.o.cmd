cmd_libbb/perror_nomsg.o := arm-linux-gcc -Wp,-MD,libbb/.perror_nomsg.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.13.3)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wmissing-prototypes -Wmissing-declarations -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -Os    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(perror_nomsg)"  -D"KBUILD_MODNAME=KBUILD_STR(perror_nomsg)" -c -o libbb/perror_nomsg.o libbb/perror_nomsg.c

deps_libbb/perror_nomsg.o := \
  libbb/perror_nomsg.c \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config///.h) \
    $(wildcard include/config/nommu.h) \
    $(wildcard include/config//nommu.h) \
    $(wildcard include/config//mmu.h) \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/byteswap.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/byteswap.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/endian.h \
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
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/endian.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/arpa/inet.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/netinet/in.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/stdint.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/wchar.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/uio.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/typesizes.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/time.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include/stddef.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/select.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/select.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sigset.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/time.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/sysmacros.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/pthreadtypes.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/uio.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/sockaddr.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/socket.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/sockios.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/in.h \
  /usr/local/arm/4.3.2/bin/../lib/gcc/arm-none-linux-gnueabi/4.3.2/include/stdbool.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/mount.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/ioctls.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/ioctls.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/asm-generic/ioctl.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/bits/ioctl-types.h \
  /usr/local/arm/4.3.2/bin/../arm-none-linux-gnueabi/libc/usr/include/sys/ttydefaults.h \

libbb/perror_nomsg.o: $(deps_libbb/perror_nomsg.o)

$(deps_libbb/perror_nomsg.o):
