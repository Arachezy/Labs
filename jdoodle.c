#include <stdio.h>;
#include <ctype.h>;

int charToInt (char ch)
{
    ch = toupper(ch);
    
    if ((ch >= '0') && (ch <= '9'))
    {
        return ch - '0';
    }
    else
        return ch - 'A' + 10;
}

char intToChar (int ch)
{
    if ((ch >= 0) && (ch <= 9))
    {
        return ch + '0';
    }
    else
        return ch + 'A' - 10;
    
}

int main(int argc, char *argv) {
    int sysFrom = atoi(argv[1]);
	int sysTo = atoi(argv[2]);
    int num = 0;
	int i = 2;
    char newNum[];
    while (argv[i] != '\n';) {
        num = num * sysFrom + charToInt(argv[i]);
    }
    
    while (num != 0) {
        newNum = intToChar(num%sysTo);
        num /= sysTo;
    }
    
    return 0;
}

