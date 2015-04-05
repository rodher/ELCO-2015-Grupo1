#include <stdio.h>
#include <string.h>

#define MAIL_CMD "./scripts/sendmail.sh "
#define PIC_CMD "./scripts/takepicture.sh "


int main(int argc, char const *argv[])
{
	char timestamp[10];
	char mail_command[100];
	char pic_command[100];

	strcpy(timestamp, " 2015");

	strcpy(pic_command, PIC_CMD);
	strcat(pic_command, timestamp);

	strcpy(mail_command, MAIL_CMD);
	strcat(mail_command, argv[1]);
	strcat(mail_command, timestamp);

	system(pic_command);
	system(mail_command);

	return 0;
}