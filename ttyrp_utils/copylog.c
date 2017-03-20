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
#include <string.h>
#include <getopt.h>

// usage() function displays help message
static void usage()
{
    fprintf(stderr, "Usage: copylog --path + press Enter ->/path/to/recovery/log\n"
                    "     -h  or  --help: display help message\n"
                    "    [-p  or  --path]+press Enter: is the destination of recovery.log\n"
                    "       e.g. $ 'copylog --path '+ press Enter /sdcard/logs' will create /sdcard/logs/recovery.log\n"
                    "copylog copies recovery log to a defined destination\n");
    exit(1);
}

// This function open recovery.log and permit its copy (will run then in copylog() )
void copy(char *out_str, char *in_str) {
    int c;
    in_str = "/tmp/recovery.log";

    FILE *in_ptr = fopen(in_str, "r");
    FILE *out_ptr = fopen(out_str, "w");

    /* check if recovery.log is present (it should), and
     * same thing for the destination where recovery.log will be copied to */
    if (!in_ptr) {
        perror("Cannot open recovery.log");
        exit(1);
    }

    if (!out_ptr) {
        perror("Can't open destination file");
        exit(1);
    }

    // copy file one char at a time
    while ((c = fgetc(in_ptr)) != EOF) {
        fputc(c, out_ptr);
    }

    // close files
    fclose(in_ptr);
    fclose(out_ptr);
}

/* This functions asks for the destination
  * where recovery.log will be copied to, and
  * which must be without 'recovery.log at the end
  * because it is already included, and then
  * it performs the copy */
void copylog() {
    char str[52], in_str[20], out_str[52];
    char *str_ptr = str;
    char *out_ptr = out_str;
    char *in_ptr = in_str;

    // Get name of the destination where recovery.log will be copied to
    printf(" Enter recovery.log destination path: ");
    scanf("%s", str_ptr);
    strcpy(out_str, strcat(str, "/recovery.log"));
    copy(out_str, in_str);
}

/* getopt() function creates the short options (-letter)
 * and long options (--option) */
static struct option longopts[] = {
    {"help",   0,  0,  'h' },
    {"path",   0,  0,  'p' },
    {0,        0,  0,   0 }
};

int main(int argc, char **argv)
{
	int index, c = 0;

        while ((c = getopt_long(argc, argv, "hp",
                                longopts, &index)) != -1)
        {
            switch (c)
            {
                case 'h':
                    usage(); // Displays help message
                    break;
                case 'p':
                    copylog(); // Copies recovery.log to the defined destination
                    break;
            }
        }
        if (argc < 2)   // If no options are used it will print the "help" message
            usage();    // which corresponds to usage() function
        return 0;
}
