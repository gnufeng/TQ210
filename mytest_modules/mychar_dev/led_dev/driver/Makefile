obj-m := led_driver.o

KDIR := /home/myroot/TQ210/kernel/linux

all:
	make -C $(KDIR) M=$(PWD) CROSS_COMPILE=arm-linux- ARCH=arm

clean:
	rm -rf *.ko *.o *.mod.o *.mod.c *.symvers *.bak *.order  .tmp_versions/ .built-in.o.cmd .led_driver.ko.cmd .led_driver.mod.o.c .led_driver.o.cmd .led_driver.mod.o.cmd