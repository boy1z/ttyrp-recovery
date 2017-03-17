/*  This file is a part of TTYRP based on TWRP by Marco Marcaccini (DeadSquirrel01)
 *
 *   It is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 */

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

static void usage()
{
    fprintf(stderr, "Usage: ttyrp_help --command\n"
                    "     --help: display help message\n"
                    "     --command: where 'command' is the command's name: display command info\n"
                    "     --list: displays all supported commands\n"
                    "ttyrp_help displays a short description of most important commands present in ttyrp.\n");
    exit(1);
}

// Define all short option (-# where # is a letter), not used but needed by getopt_long(), and long options (--option) for getopt_long()
static struct option longopts[] = {
           {"help",         0,  0,  'h' },
           {"list",         0,  0,  'T' },
           {"blkid",        0,  0,  'm' },
           {"cat",          0,  0,  'C' },
           {"cd",           0,  0,  'z' },
           {"chattr",       0,  0,  'n' },
           {"chgrp",        0,  0,  'k' },
           {"chmod",        0,  0,  'e' },
           {"chown",        0,  0,  'l' },
           {"chroot",       0,  0,  'B' },
           {"clear",        0,  0,  'o' },
           {"cp",           0,  0,  'b' },
           {"cpio",         0,  0,  'p' },
           {"cut",          0,  0,  'r' },
           {"date",         0,  0,  'q' },
           {"dd",           0,  0,  's' },
           {"df",           0,  0,  't' },
           {"diff",         0,  0,  'u' },
           {"dmesg",        0,  0,  'v' },
           {"e2fsck",       0,  0,  'E' },
           {"echo",         0,  0,  'D' },
           {"fdisk",        0,  0,  'f' },
           {"find",         0,  0,  'g' },
           {"fsck.exfat",   0,  0,  'j' },
           {"fsck.fat",     0,  0,  'i' },
           {"head",         0,  0,  'A' },
           {"hwclock",      0,  0,  'R' },
           {"install",      0,  0,  'x' },
           {"kill",         0,  0,  'w' },
           {"ls",           0,  0,  'a' },
           {"lsattr",       0,  0,  'y' },
           {"make_ext4fs",  0,  0,  'F' },
           {"mount",        0,  0,  'G' },
           {"mv",           0,  0,  'c' },
           {"poweroff",     0,  0,  'J' },
           {"reboot",       0,  0,  'M' },
           {"restorecon",   0,  0,  'H' },
           {"rm",           0,  0,  'd' },
           {"sh",           0,  0,  'I' },
           {"tail",         0,  0,  'K' },
           {"tar",          0,  0,  'L' },
           {"top",          0,  0,  'O' },
           {"touch",        0,  0,  'S' },
           {"twrp",         0,  0,  'N' },
           {"unzip",        0,  0,  'P' },
           {"vi",           0,  0,  'Q' },
           {0,              0,  0,  0 }
};

// cmd_supported_list() is used when using the option '--list'. It displays all command names defined in 'static struct option longopts[]'
static int cmd_supported_list()
{
  	struct option *thisopt;

    for(thisopt = longopts; thisopt->name != 0; thisopt++)
		printf("%s\n", thisopt->name);

    return 0;
}

/* Main function: puts getopt_long() in action with the options defined in 'static struct option longopts[]' which will print
 * the corresponding description
 */
int main(int argc, char **argv)
{
	int index, c = 0;

        while ((c = getopt_long(argc, argv, "",
                                longopts, &index)) != -1)
        {
                switch (c)
               {
                       case 'h':
                               usage();
                               break;
                       case 'a':
                               printf("List information about the FILEs (the current directory by default)\n");
				break;
                       case 'b':
                               printf("Copy SOURCE to DEST, or multiple SOURCE(s) to DIRECTORY.\n");
				break;
                       case 'c':
                               printf("Rename SOURCE to DEST, or move SOURCE(s) to DIRECTORY.\n");
				break;
                       case 'd':
                               printf("rm removes each specified file.  By default, it does not remove directories.\n");
				break;
                       case 'e':
                               printf("chmod changes the file mode bits of each given file according to mode\n"
                                       "which can be either a symbolic representation of changes to make\n"
                                       "or an octal number representing the bit pattern for the new mode bits.\n"
                                      );
				break;
                       case 'f':
                               printf("fdisk is a dialog-driven program for creation and manipulation of partition tables\n");
				break;
                       case 'g':
                               printf("GNU find searches the directory tree rooted at each given starting-point\n");
				break;
                       case 'i':
                               printf("fsck.fat  verifies the consistency of MS-DOS filesystems and optionally tries to repair them.\n");
				break;
                       case 'j':
                               printf("fsck.exfat  checks  an exFAT file system for errors\n");
				break;
                       case 'k':
                               printf("Change the group of each FILE to GROUP.\n");
				break;
                       case 'l':
                               printf("Change the owner and/or group of each FILE to OWNER and/or GROUP.\n");
				break;
                       case 'm':
                               printf("blkid It can determine the type of content that a block device holds\n");
				break;
                       case 'n':
                               printf("chattr changes the file attributes on a Linux file system\n");
				break;
                       case 'o':
                               printf("clear clears the screen if this is possible, including its scrollback buffer\n");
				break;
                       case 'p':
                               printf("GNU cpio copies files between archives and directories\n");
				break;
                       case 'q':
                               printf("Display the current time in the given FORMAT, or set the system date\n");
				break;
                       case 'r':
                               printf("Print selected parts of lines from each FILE to standard output\n");
				break;
                       case 's':
                               printf("Copy a file, converting and formatting according to the operands.\n"
                                      "It can be used for flash images like boot.img and recovery.img or dump them to an image\n");
				break;
                       case 't':
                               printf("Show information about the file system on which each FILE resides, or all file systems by default\n");
				break;
                       case 'u':
                               printf("Compare FILES line by line\n");
				break;
                       case 'v':
                               printf("dmesg is used to examine or control the kernel ring buffer\n");
				break;
                       case 'w':
                               printf("kill is used to kill a process (PID)\n");
				break;
                       case 'x':
                               printf("install copies files (often just compiled) into destination locations you choose\n");
				break;
                       case 'y':
                               printf("lsattr lists the file attributes on a second extended file system\n");
				break;
                       case 'z':
                               printf("The cd utility shall change the working directory of the current shell execution environment \n");
				break;
                       case 'A':
                               printf("Print the first 10 lines of each FILE to standard output\n");
				break;
                       case 'B':
                               printf("Run COMMAND with root directory set to NEWROOT\n");
				break;
                       case 'C':
                               printf("Concatenate FILE(s) to standard output\n");
				break;
                       case 'D':
                               printf("Echo the STRING(s) to standard output\n");
				break;
                       case 'E':
                               printf("e2fsck is used to check the ext2/ext3/ext4 family of file systems\n");
				break;
                       case 'F':
                               printf("Create ext4 images and format partitions to ext4 fs\n");
				break;
                       case 'G':
                               printf("The mount command serves to attach the filesystem found on some device to the big file tree\n");
				break;
                       case 'H':
                               printf("This program is primarily used to set the security context on one or more files\n");
				break;
                       case 'I':
                               printf("The sh utility is a command language interpreter that shall execute commands read from a command line " 
                                      "string, the standard input, or a specified  file\n");
				break;
                       case 'J':
                               printf("poweroff is used to shutdown the system\n");
				break;
                       case 'K':
                               printf("Print the last 10 lines of each FILE to standard output\n");
				break;
                       case 'L':
                               printf("GNU tar is an archiving program designed to store multiple files in a single file, "
                                      "and to manipulate such archives.\n");
				break;
                       case 'M':
                               printf("reboot is used to reboot the system\n");
				break;
                       case 'N':
                               printf("The twrp command can do various things present in TWRP recovery, "
                                      "like flashing zips, backing up and wipe partitions\n");
				break;
                       case 'O':
                               printf("The top program provides a dynamic real-time view of a running system. "
                                      "It can display system summary information as well as a list of processes "
                                       "or threads currently being managed by the Linux kernel\n");
				break;
                       case 'P':
                               printf("unzip will list, test, or extract files from a  ZIP "
                                          "archive,  commonly  found  on  MS-DOS systems\n");
				break;
                       case 'Q':
                               printf("The vi utility is a screen-oriented text editor\n");
				break;
                       case 'R':
                               printf("hwclock is a tool for accessing the Hardware Clock\n");
				break;
                       case 'S':
                               printf("touch can create new empty files and change timestamps\n");
                break;
                       case 'T':
                                cmd_supported_list();
                break;
			default:
                               usage();
			break;
               }
        }
  if (argc < 2)          /* If no options are used it will print the "help" message */
		usage(); /* which corresponds to usage() function */
}
