/*
 * tq_668@126.com, www.embedsky.net
 *
 */



#include <common.h>
#include <command.h>
#include <nand.h>

#ifdef CONFIG_CMD_MENU

#ifdef CONFIG_EMBEDSKY_FAT
#include <def.h>
#include <vfat.h>
#endif

#ifdef CONFIG_EmbedSky_LCD
#include <lcd/s5pv210_fb.h>
#endif /* CONFIG_EmbedSky_LCD */

extern char console_buffer[];
extern int readline (const char *const prompt);
//extern char awaitkey(unsigned long delay, int* error_p);
//extern void download_nkbin_to_flash(void);
//extern int boot_zImage(ulong from, size_t size);
//extern char bLARGEBLOCK;

#ifdef CONFIG_EmbedSky_LCD
void lcd_menu_usage()
{
	printf("\r\n##### LCD select Menu #####\r\n");
	printf("[1] T43\" screen.\r\n");
	printf("[2] A70\" screen.\r\n");
	printf("[3] A104\" screen.\r\n");
	printf("[4] VGA1024768\" screen.\r\n");
	printf("[5] W35\" screen.\r\n");
	printf("[6] VGA640480\" screen.\r\n");
	printf("[7] VGA7213\" screen.\r\n");
	printf("[8] VGA1280X800\" screen.\r\n");
	printf("[r] Reboot u-boot\r\n");
//	printf("[s] Reinitializtion lcd.\r\n");
	printf("[q] Return Parameter Menu \r\n");
	printf("Enter your selection: ");
}
void lcd_menu_shell()
{
	char c;
	char cmd_buf[256];
	while (1)
	{
		lcd_menu_usage();
		c = getc();
		printf("%c\n", c);
		switch (c)
		{
			case '1':
			{
				sprintf(cmd_buf, "setenv lcdtype X480Y272;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
			}
			case '2':
			{
				sprintf(cmd_buf, "setenv lcdtype X800Y480;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
			}
			case '3':
			{
				sprintf(cmd_buf, "setenv lcdtype X800Y600;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
			}
			case '4':
			{
				sprintf(cmd_buf, "setenv lcdtype X1024Y768;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
			}
			case '5':
			{
				sprintf(cmd_buf, "setenv lcdtype X320Y240;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
			}
			case '6':
			{
				sprintf(cmd_buf, "setenv lcdtype X640Y480;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
				break;
			}
			case '7':
			{
				sprintf(cmd_buf, "setenv lcdtype VGA7213;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
				break;
			}
			case '8':
			{
				sprintf(cmd_buf, "setenv lcdtype VGA1280X800;");
				run_command(cmd_buf, 0);
				run_command("saveenv;", 0);
				break;
				break;
			}
			case 'R':
			case 'r':
			{
				strcpy(cmd_buf, "reset");
				run_command(cmd_buf, 0);
				break;
			}
//			case 'S':
//			case 's':
//			{
//				tq210_lcd_init();	
//				break;
//			}

			case 'Q':
			case 'q':
			{
				return;
				break;
			}

		}
	}
}
#endif /* CONFIG_EmbedSky_LCD */

void param_menu_usage(void)
{
	printf("\r\n##### Parameter Menu #####\r\n");
	printf("[1] Set NFS boot parameter \r\n");
	printf("[2] Set Yaffs boot parameter for Android or Standard Linux \r\n");
	printf("[3] Set UBIfs boot parameter for Android or Standard Linux \r\n");
	printf("[4] Set parameter \r\n");
	printf("[5] View the parameters \r\n");
#ifdef CONFIG_EmbedSky_LCD
	printf("[c] Choice lcd type.\r\n");	
#endif /* CONFIG_EmbedSky_LCD */
	printf("[d] Delete parameter \r\n");
	printf("[i] Display nand flash infomation.\r\n");
	printf("[s] Save the parameters to Nand Flash \r\n");
	printf("[q] Return main Menu \r\n");
	printf("Enter your selection: ");
}


void param_menu_shell(void)
{
	char c;
	char cmd_buf[256];
	char name_buf[20];
	char val_buf[256];
	char param_buf1[25];
	char param_buf2[25];
	char param_buf3[25];
	char param_buf4[64];
	char param_buf5[10];

	while (1)
	{
		param_menu_usage();
		c = getc();
		printf("%c\n", c);
		switch (c)
		{
			case '1':
			{
				sprintf(cmd_buf, "setenv bootargs ");

				printf("Enter the PC IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf1,console_buffer);
				printf("Enter the SKY210/TQ210 IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf2,console_buffer);
				printf("Enter the Mask IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf3,console_buffer);
				printf("Enter NFS directory:(eg: /opt/EmbedSky/root_nfs)\n");
				readline(NULL);
				strcpy(param_buf4,console_buffer);
				sprintf(cmd_buf, "setenv bootargs noinitrd init=/init console=ttySAC%d root=/dev/nfs nfsroot=%s:%s ip=%s:%s:%s:%s:www.embedsky.com:eth0:off", SERIAL_PORT_NUM, param_buf1, param_buf4, param_buf2, param_buf1, param_buf2, param_buf3);
				printf("bootargs: noinitrd init=/init console=ttySAC%d root=/dev/nfs nfsroot=%s:%s ip=%s:%s:%s:%s:www.embedsky.com:eth0:off\n", SERIAL_PORT_NUM, param_buf1, param_buf4, param_buf2, param_buf1, param_buf2, param_buf3);

				run_command(cmd_buf, 0);
				break;
			}

			case '2':
			{
				sprintf(cmd_buf, "setenv bootargs noinitrd root=/dev/mtdblock3 rootfstype=yaffs2 init=/init console=ttySAC%d", SERIAL_PORT_NUM);
				printf("bootargs: noinitrd root=/dev/mtdblock3 rootfstype=yaffs2 init=/linuxrc console=ttySAC%d\n", SERIAL_PORT_NUM);

				run_command(cmd_buf, 0);
				break;
			}

			case '3':
			{
				sprintf(cmd_buf, "setenv bootargs noinitrd ubi.mtd=3 root=ubi0:rootfs rootfstype=ubifs init=/init console=ttySAC%d", SERIAL_PORT_NUM);
				printf("bootargs: noinitrd ubi.mtd=4 root=ubi0:rootfs rootfstype=ubifs init=/init console=ttySAC%d\n", SERIAL_PORT_NUM);

				run_command(cmd_buf, 0);
				break;
			}

			case '4':
			{
				sprintf(cmd_buf, "setenv ");

				printf("Name: ");
				readline(NULL);
				strcat(cmd_buf, console_buffer);

				printf("Value: ");
				readline(NULL);
				strcat(cmd_buf, " ");
				strcat(cmd_buf, console_buffer);
				printf("%s\n",cmd_buf);

				run_command(cmd_buf, 0);
				break;
			}

			case '5':
			{
				strcpy(cmd_buf, "printenv ");
				printf("Name(enter to view all paramters): ");
				readline(NULL);
				strcat(cmd_buf, console_buffer);
				run_command(cmd_buf, 0);
				break;
			}

			case 'D':
			case 'd':
			{
				sprintf(cmd_buf, "setenv ");

				printf("Name: ");
				readline(NULL);
				strcat(cmd_buf, console_buffer);

				run_command(cmd_buf, 0);
				break;
			}

			case 'S':
			case 's':
			{
				sprintf(cmd_buf, "saveenv");
				run_command(cmd_buf, 0);
				break;
			}
			case 'I':
			case 'i':
			{
				strcpy(cmd_buf, "nand disinfo");
				run_command(cmd_buf, 0);
				break;
			}

#ifdef CONFIG_EmbedSky_LCD
			case 'C':
			case 'c':
			{
				lcd_menu_shell();
				break;
			}
#endif /* CONFIG_EmbedSky_LCD */

			case 'Q':
			case 'q':
			{
				//sprintf(cmd_buf, "saveenv");
				//run_command(cmd_buf, 0);
				return;
				break;
			}
		}
	}
}


#define USE_USB_DOWN		1
#define USE_TFTP_DOWN		2
#define USE_SD_DOWN		3

void main_menu_usage(char menu_type)
{

	printf("\r\n#####	 Boot for TQ210 Main Menu	#####\r\n");

	if( menu_type == USE_USB_DOWN)
	{
		printf("#####     EmbedSky USB download mode     #####\r\n\n");
	}
	else if( menu_type == USE_TFTP_DOWN)
	{
		printf("#####     EmbedSky TFTP download mode     #####\r\n\n");
	}
#ifdef CONFIG_CMD_MENU_SD
	else if( menu_type == USE_SD_DOWN)
	{
		printf("#####     EmbedSky SD download mode     #####\r\n\n");
	}
#endif

	if( menu_type == USE_USB_DOWN)
	{
#ifdef CONFIG_WINCE_NK
		printf("[1] Download u-boot or other bootloader to Nand Flash\r\n");
#else
		printf("[1] Download u-boot or STEPLDR.nb1 or other bootloader to Nand Flash\r\n");
#endif
	}
	else if(( menu_type == USE_TFTP_DOWN) || ( menu_type == USE_SD_DOWN))
	{
		printf("[1] Download u-boot.bin to Nand Flash\r\n");
	}
	printf("[2] Download Eboot (eboot.nb0) to Nand Flash\r\n");
	printf("[3] Download Linux Kernel (zImage.bin) to Nand Flash\r\n");
#ifdef CONFIG_EmbedSky_LCD
	printf("[4] Download LOGO Picture (logo.bin) to Nand  Flash\r\n");
#endif /* CONFIG_EmbedSky_LCD */
	printf("[5] Download UBIFS image (root.ubi) to Nand Flash\r\n");
	printf("[6] Download YAFFS image (root.bin) to Nand Flash\r\n");
	printf("[7] Download Program to SDRAM and Run it\r\n");

	printf("[8] Boot the system\r\n");
	printf("[9] Format the Nand Flash\r\n");
	printf("[0] Set the boot parameters\r\n");
	printf("[a] Download User Program\r\n");

	if( menu_type == USE_USB_DOWN)
	{
		printf("[n] Enter TFTP download mode menu\r\n");
	}
	else if( menu_type == USE_TFTP_DOWN)
	{
		printf("[n] Set TFTP parameters(PC IP,TQ210 IP,Mask IP...)\r\n");
	}

	if( menu_type == USE_TFTP_DOWN)
	{
		printf("[p] Test network (TQ210 Ping PC's IP)\r\n");
	}

	printf("[r] Reboot u-boot\r\n");

	if( menu_type == USE_USB_DOWN)
	{
#ifdef CONFIG_CMD_MENU_SD
		printf("[s] Enter SD download mode menu\r\n");
#endif
	}
	else if(( menu_type == USE_TFTP_DOWN) || ( menu_type == USE_SD_DOWN))
	{
		printf("[s] Download STEPLDR.nb1 to Nand Flash\r\n");
	}

	printf("[t] Test Linux Image (zImage)\r\n");
#ifndef CONFIG_TQ210
	if( menu_type == USE_USB_DOWN)
	{
		printf("[q] quit from menu\r\n");
	}
	else
#endif
	if(( menu_type == USE_TFTP_DOWN) || ( menu_type == USE_SD_DOWN))
	{
		printf("[q] Return main Menu \r\n");
	}

	printf("Enter your selection: ");
}


void tftp_menu_shell(void)
{
	char keyselect;
	char cmd_buf[200];

	while (1)
	{
		main_menu_usage(USE_TFTP_DOWN);
		keyselect = getc();
		printf("%c\n", keyselect);
		switch (keyselect)
		{
			case '1':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "tftp 0xc0008000 u-boot.bin; nand erase bios; nand write  0xc0008000 bios $(filesize)");
#else
				strcpy(cmd_buf, "tftp 0xc0008000 u-boot.bin; nand erase 0x0 0x80000; nand write.jffs2 0xc0008000 0x0 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
			break;
			}

			case '2':
			{
				sprintf(cmd_buf, "tftp 0xc0008000 eboot.nb0; nand erase 0x80000 0x80000; nand write.jffs2 0xc0008000 0x80000 $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '3':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "tftp 0xc0008000 zImage.bin; nand erase kernel; nand write.jffs2 0xc0008000 kernel $(filesize)");
#else
				strcpy(cmd_buf, "tftp 0xc0008000 zImage.bin; nand erase 0x300000 0x400000; nand write.jffs2 0xc0008000 0x300000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

#ifdef CONFIG_EmbedSky_LCD
			case '4':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "tftp 0xc0008000 logo.bin; nand erase logo; nand write.jffs2 0xc0008000 logo $(filesize)");
#else
				strcpy(cmd_buf, "tftp 0xc0008000 logo.bin; nand erase 0x100000 0x200000; nand write.jffs2 0xc0008000 0x100000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}
#endif /* CONFIG_EmbedSky_LCD */

			case '5':
			{
				strcpy(cmd_buf, "tftp 0x40008000 root.ubi;nand erase root;ubi part root;ubi create rootfs;ubi write 0x40008000 rootfs $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '6':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "tftp 0x40008000 root.bin; nand erase root; nand write.yaffs 0x40008000 root $(filesize)");
#else
				strcpy(cmd_buf, "tftp 0x40008000 root.bin; nand erase 0x700000 0xF8D0000; nand write.yaffs 0x40008000 0x700000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '7':
			{
				char tftpaddress[12];
				char filename[32];

				printf("Enter downloads to SDRAM address:\n");
				readline(NULL);
				strcpy(tftpaddress, console_buffer);

				printf("Enter program name:\n");
				readline(NULL);
				strcpy(filename, console_buffer);

				sprintf(cmd_buf, "tftp %s %s", tftpaddress, filename);
				printf("tftp %s %s\n", tftpaddress, filename);
				run_command(cmd_buf, 0);

				sprintf(cmd_buf, "go %s", tftpaddress);
				run_command(cmd_buf, 0);
				break;
			}

			case '8':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				printf("Start Linux ...\n");
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 kernel;bootm 0xc0008000");
#else
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 0x300000 0x400000;bootm 0xc0008000");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '9':
			{
				strcpy(cmd_buf, "nand scrub ");
				run_command(cmd_buf, 0);
				break;
			}

			case '0':
			{
				param_menu_shell();
				break;
			}

			case 'A':
			case 'a':
			{
				char filename[32];

				printf("Enter program name:\n");
				readline(NULL);
				strcpy(filename, console_buffer);

				sprintf(cmd_buf, "tftp 0xc0008000 %s; nand erase 0x0 $(filesize+1); nand write.jffs2 0xc0008000 0x0 $(filesize+1)", filename);
				run_command(cmd_buf, 0);
				break;
			}

			case 'N':
			case 'n':
			{
				char param_buf1[25];
				char param_buf2[25];
				char param_buf3[25];

				printf("Enter the TFTP Server(PC) IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf1,console_buffer);
				sprintf(cmd_buf, "setenv serverip %s",param_buf1);
				run_command(cmd_buf, 0);

				printf("Enter the TQ210 IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf2,console_buffer);
				sprintf(cmd_buf, "setenv ipaddr %s",param_buf2);
				run_command(cmd_buf, 0);

				printf("Enter the Mask IP address:(xxx.xxx.xxx.xxx)\n");
				readline(NULL);
				strcpy(param_buf3,console_buffer);
				sprintf(cmd_buf, "setenv netmask %s",param_buf3);
				run_command(cmd_buf, 0);

				printf("Save TFTP IP parameters?(y/n)\n");
				if (getc() == 'y' )
				{
					printf("y");
					getc() == '\r';
					printf("\n");
					sprintf(cmd_buf, "saveenv");
					run_command(cmd_buf, 0);
				}
				else
				{
					printf("Not Save it!!!\n");
				}
				break;
			}

			case 'P':
			case 'p':
			{
				char *serverip;
				serverip=getenv("serverip");
				printf("TQ210 ping PC IP:ping %s\n",serverip);
				sprintf(cmd_buf, "ping %s",serverip);
				run_command(cmd_buf, 0);
				break;
			}

			case 'R':
			case 'r':
			{
				strcpy(cmd_buf, "reset");
				run_command(cmd_buf, 0);
				break;
			}
			
			case 's':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "tftp 0xc0080000 stepldr.nb1; nand erase bios; nand write  0xc0008000 bios $(filesize)");
#else
				strcpy(cmd_buf, "tftp 0xc0008000 stepldr.nb1; nand erase 0x0 0x80000; nand write.jffs2 0xc0008000 0x0 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
			break;
			}

			case 'T':
			case 't':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				strcpy(cmd_buf, "tftp 0xc0008000 zImage.bin; bootm 0xc0008000");
				run_command(cmd_buf, 0);
				break;
			}

			case 'Q':
			case 'q':
			{
				return;
				break;
			}
		}
	}

}

#ifdef CONFIG_CMD_MENU_SD
void sd_menu_shell(void)
{
	char keyselect;
	char cmd_buf[200];

	while (1)
	{
		main_menu_usage(USE_SD_DOWN);
		keyselect = getc();
		printf("%c\n", keyselect);
		switch (keyselect)
		{
			case '1':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 u-boot.bin; nand erase bios; nand write 0xc0008000 bios $(filesize)");
#else
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 u-boot.bin; nand erase 0x0 0x80000; nand write.jffs2 0xc0008000 0x0 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
			break;
			}

			case '2':
			{
				sprintf(cmd_buf, "fatload mmc 0 0xc0008000 eboot.nb0; nand erase 0x80000 0x80000; nand write.jffs2 0xc0008000 0x80000 $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '3':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 zImage.bin; nand erase kernel; nand write.jffs2 0xc0008000 kernel $(filesize)");
#else
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 zImage.bin; nand erase 0x300000 0x400000; nand write.jffs2 0xc0008000 0x300000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

#ifdef CONFIG_EmbedSky_LCD
#if 1
			case '4':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 logo.bin; nand erase logo; nand write.jffs2 0xc0008000 logo $(filesize)");
#else
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 logo.bin; nand erase 0x100000 0x200000; nand write.jffs2 0xc0008000 0x100000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}
#else
			case '4':
			{
				FAT_Init();
				strcpy(cmd_buf, "nand erase root;ubi part root;ubi create rootfs;ubi OEMwrite 0xc0008000 rootfs images\\\\root_big.ubi");
				//strcpy(cmd_buf, "nand write.OEMyaffs 0xc0008000 root images\\\\root.bin");
				printf("%s\n",cmd_buf);
				run_command(cmd_buf, 0);
				break;
			}
#endif
#endif /* CONFIG_EmbedSky_LCD */
			case '5':
			{
				strcpy(cmd_buf, "fatload mmc 0 0x40008000 root.ubi;nand erase root;ubi part root;ubi create rootfs;ubi write 0x40008000 rootfs $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '6':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "fatload mmc 0 0x40008000 root.bin; nand erase root; nand write.yaffs 0x40008000 root $(filesize)");
#else
				strcpy(cmd_buf, "fatload mmc 0 0x40008000 root.bin; nand erase 0x700000 0xF8D0000; nand write.yaffs 0x40008000 0x700000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '7':
			{
				char sdaddress[12];
				char filename[32];

				printf("Enter downloads to SDRAM address:\n");
				readline(NULL);
				strcpy(sdaddress, console_buffer);

				printf("Enter program name:\n");
				readline(NULL);
				strcpy(filename, console_buffer);

				sprintf(cmd_buf, "fatload mmc 0 %s %s", sdaddress, filename);
				printf("fatload mmc 0 %s %s\n", sdaddress, filename);
				run_command(cmd_buf, 0);

				sprintf(cmd_buf, "go %s", sdaddress);
				run_command(cmd_buf, 0);
				break;
			}

			case '8':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				printf("Start Linux ...\n");
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 kernel;bootm 0xc0008000");
#else
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 0x300000 0x400000;bootm 0xc0008000");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '9':
			{
				strcpy(cmd_buf, "nand scrub ");
				run_command(cmd_buf, 0);
				break;
			}

			case '0':
			{
				param_menu_shell();
				break;
			}

			case 'A':
			case 'a':
			{
				char filename[32];

				printf("Enter program name:\n");
				readline(NULL);
				strcpy(filename, console_buffer);

				sprintf(cmd_buf, "fatload mmc 0 0xc0008000 %s; nand erase 0x0 $(filesize+1); nand write.jffs2 0xc0008000 0x0 $(filesize+1)", filename);
				run_command(cmd_buf, 0);
				break;
			}

			case 'R':
			case 'r':
			{
				strcpy(cmd_buf, "reset");
				run_command(cmd_buf, 0);
				break;
			}
			
			case 's':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 stepldr.nb1; nand erase bios; nand write  0xc0008000 bios $(filesize)");
#else
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 stepldr.nb1; nand erase 0x0 0x80000; nand write.jffs2 0xc0008000 0x0 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
			break;
			}

			case 'T':
			case 't':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				strcpy(cmd_buf, "fatload mmc 0 0xc0008000 zImage.bin; bootm 0xc0008000");
				run_command(cmd_buf, 0);
				break;
			}

			case 'Q':
			case 'q':
			{
				return;
				break;
			}
		}
	}

}
#endif

void menu_shell(void)
{
	char keyselect;
	char cmd_buf[200];

	while (1)
	{
		main_menu_usage(USE_USB_DOWN);
		keyselect = getc();
		printf("%c\n", keyselect);
		switch (keyselect)
		{
			case '1':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase bios; nand write  0xc0008000 bios $(filesize)");
#else
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase 0x0 0x80000; nand write.jffs2 0xc0008000 0x0 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}
			
			case '2':
			{
				sprintf(cmd_buf, "dnw 0xc0008000; nand erase 0x80000 0x80000; nand write.jffs2 0xc0008000 0x80000 $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '3':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase kernel; nand write.jffs2 0xc0008000 kernel $(filesize)");
#else
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase 0x300000 0x400000; nand write.jffs2 0xc0008000 0x300000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

#ifdef CONFIG_EmbedSky_LCD
			case '4':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase logo; nand write.jffs2 0xc0008000 logo $(filesize)");
#else
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase 0x100000 0x200000; nand write.jffs2 0xc0008000 0x100000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}
#endif /* CONFIG_EmbedSky_LCD */

			case '5':
			{
				strcpy(cmd_buf, "dnw 0x40008000;nand erase root;ubi part root;ubi create rootfs;ubi write 0x40008000 rootfs $(filesize)");
				run_command(cmd_buf, 0);
				break;
			}

			case '6':
			{
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "dnw 0x40008000; nand erase root; nand write.yaffs 0x40008000 root $(filesize)");
#else
				strcpy(cmd_buf, "dnw 0x40008000; nand erase 0x700000 0xF8D0000; nand write.yaffs 0x40008000 0x700000 $(filesize)");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '7':
			{
				char addr_buff[12];
				printf("Enter download address:(eg: 0xc0008000)\n");
				readline(NULL);
				strcpy(addr_buff,console_buffer);
				sprintf(cmd_buf, "dnw %s;go %s", addr_buff, addr_buff);
				run_command(cmd_buf, 0);
				break;
			}

			case '8':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				printf("Start Linux ...\n");
#ifdef CONFIG_MTD_DEVICE
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 kernel;bootm 0xc0008000");
#else
				strcpy(cmd_buf, "nand read.jffs2 0xc0008000 0x300000 0x400000;bootm 0xc0008000");
#endif /* CONFIG_MTD_DEVICE */
				run_command(cmd_buf, 0);
				break;
			}

			case '9':
			{
				strcpy(cmd_buf, "nand scrub ");
				run_command(cmd_buf, 0);
				break;
			}

			case '0':
			{
				param_menu_shell();
				break;
			}

			case 'A':
			case 'a':
			{
				strcpy(cmd_buf, "dnw 0xc0008000; nand erase 0x0 $(filesize+1); nand write.jffs2 0xc0008000 0x0 $(filesize+1)");
				run_command(cmd_buf, 0);
				break;
			}

			case 'N':
			case 'n':
			{
				tftp_menu_shell();
				break;
			}

			case 'R':
			case 'r':
			{
				strcpy(cmd_buf, "reset");
				run_command(cmd_buf, 0);
				break;
			}
			
#ifdef CONFIG_CMD_MENU_SD
			case 'S':
			case 's':
			{
				sd_menu_shell();
				break;
			}
#endif

			case 'T':
			case 't':
			{
#ifdef CONFIG_EmbedSky_LCD
				embedsky_user_logo();
#endif /* CONFIG_EmbedSky_LCD */
				strcpy(cmd_buf, "dnw 0xc0008000; bootm 0xc0008000");
				run_command(cmd_buf, 0);
				break;
			}

#ifdef CONFIG_TQ210
			case 'Q':
			case 'q':
			{
				return;	
				break;
			}
#endif
		}
				
	}
}

int do_menu (cmd_tbl_t *cmdtp, int flag, int argc, char *argv[])
{
	menu_shell();
	return 0;
}

U_BOOT_CMD(
	menu,	3,	0,	do_menu,
	"display a menu, to select the items to do something",
	"\n"
	"\tdisplay a menu, to select the items to do something"
);

#endif

