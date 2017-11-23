#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int charToInt(char ch);
char intToChar(int ch);
int toNewSys(int sysTo, int sysFrom, char* newNum, char* oldNum);

int main(int argc, char *argv[]) {
	
	int sysFrom = atoi(argv[1]);
	int sysTo = atoi(argv[2]);
	char newNum[100];
	
	toNewSys(sysTo, sysFrom, newNum, argv[3]);
	printf("%s", newNum);

	return 0;
}


int charToInt(char ch)
{
	ch = toupper(ch);

	if ((ch >= '0') && (ch <= '9'))
	{
		return ch - '0';
	}
	else
		return ch - 'A' + 10;
}

char intToChar(int ch)
{
	if ((ch >= 0) && (ch <= 9))
	{
		return ch + '0';
	}
	else
		return ch + 'A' - 10;

}

int toNewSys(int sysTo, int sysFrom, char* newNum, char* oldNum)
{
	int i = 0;
	int intPart = 0;
	double fractPart = 0;

	while (oldNum[i] != '\0') {
		if (oldNum[i] == '.') {
			i++;
			break;
		}
		intPart = intPart * sysFrom + charToInt(oldNum[i]);
		i++;
	}

	while (oldNum[i] != '\0') {
		fractPart = (fractPart + charToInt(oldNum[i])) / sysFrom;
		i++;
	}

	i = 0;
	if (intPart == 0) {
		newNum[i] = intToChar(0);
		i++;
	}
	while (intPart != 0) {
		newNum[i] = intToChar(intPart%sysTo);
		intPart /= sysTo;
		i++;
	}

	i--;
	for (int j = 0; j <= (i / 2); j++){
		char swap = newNum[i - j];
		newNum[i - j] = newNum[j];
		newNum[j] = swap;
	}
	i++;

	if (fractPart != 0){
		newNum[i] = '.';
		i++;
	}
	
	int j = 0;
	while ((fractPart != 0) || (j >= 50)) {
		newNum[i] = intToChar((int)(fractPart * sysTo));
		fractPart = fractPart*sysTo - (int)(fractPart*sysTo);
		i++;
		j++;
	}
	newNum[i] = '\0';
	return 0;
}
