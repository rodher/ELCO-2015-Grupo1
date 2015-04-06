#include <stdio.h>
#include <string.h>
#include <time.h>
#include <wiringPi.h>

#define MAIL_CMD "./scripts/sendmail.sh "
#define PIC_CMD "./scripts/takepicture.sh "
#define PIR_PIN 2


void takePicAndSend(){
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	char timestamp[30];
	char mail_command[100];
	char pic_command[100];

	sprintf(timestamp,"%d-%02i-%02i-%02i%02i%02i", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

	strcpy(pic_command, PIC_CMD);
	strcat(pic_command, timestamp);

	strcpy(mail_command, MAIL_CMD);
	strcat(mail_command, argv[1]);
	strcat(mail_command, " ");
	strcat(mail_command, timestamp);

	system(pic_command);
	system(mail_command);
}

static int presence=0;
static void pir_isr (void) { presence = 1; }

int main(int argc, char const *argv[])
{
	wiringPiSetup();
  	pinMode (PIR_PIN, INPUT);
  	wiringPiISR (PIR_PIN, INT_EDGE_RISING, pir_isr);

  	while(1){
  		if(presence){
  			takePicAndSend();
  			presence = 0;
  		}
  	}

	return 0;
}