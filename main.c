#include "math.h"

int main (void)
{
	int user_selection = 0;


	display_home_menu();
	get_char_input(&user_selection);
	printf("User selection: %c\n", user_selection);

	return 0;
}