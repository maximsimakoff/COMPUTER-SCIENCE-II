/***********************************************************
Author: Maxim Simakoff
Date: 1/24/24
Effort: 40 Minutes
Purpose: This program displays 31 0's in an almost binary looking way and then you can place/remove
or display flags represented as 1's wherever. If you place a flag at digit 5 you can then remove
it from 5.
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int* flag_holder, int flag_position);
void unset_flag(unsigned int* flag_holder, int flag_position);
int check_flag(unsigned int flag_holder, int flag_position);
void display_32_flags(unsigned int flag_holder);

int main(int argc, char* argv[])
{
	unsigned int flag_holder = 0;

	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);

	display_32_flags(flag_holder);

	unset_flag(&flag_holder, 31);
	unset_flag(&flag_holder, 3);
	set_flag(&flag_holder, 9);

	display_32_flags(flag_holder);
	return 0;
}

void set_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder = *flag_holder | (1 << flag_position);
}
int check_flag(unsigned int flag_holder, int flag_position)
{
	return (flag_holder >> flag_position) & 1;
}

void unset_flag(unsigned int* flag_holder, int flag_position)
{
	*flag_holder = *flag_holder & ~(1 << flag_position);
}
void display_32_flags(unsigned int flag_holder)
{
	int i = 31;
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}