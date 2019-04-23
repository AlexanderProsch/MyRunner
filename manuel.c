/*
** EPITECH PROJECT, 2018
** manuel
** File description:
** man
*/

#include "runner_includes.h"

void print_seperation_line(void)
{
    int x = 83;

    while (x != 0) {
        write(1, "_", 1);
        x--;
    }
    write(1, "\n\n", 2);
}

void display_instructions2(void)
{
    print_seperation_line();
    write(1, "HOW TO PLAY:\n", 13);
    print_seperation_line();
    write(1, "To avoid obstacles you have a few tools at your disposal:\n", 58);
    write(1, "-Pressing SPACE allows you to perform a jump\n", 45 );
    write(1, "-Pressing SPACE during a jump lets you perfom an ", 49);
    write(1, "additional jump\n-Pressing SHIFT at any momemnt allows", 53);
    write(1, "you to dash through obstacles\n be careful tho as you", 52);
    write(1, " will need time to get back to your normal", 42);
    write(1, " speed.\n-Both during a DASH and its recover you are ", 52);
    write(1, "invurnerable to damage and debuffs.\n", 36);
    print_seperation_line();
    write(1, "ENEMY TYPES:\n", 13);
    print_seperation_line();
    write(1, "As you play you will encounter up to four enemy types\n", 54);
    write(1, "-RED SHROOMS and BATS are randomly spawning obstacles.\n", 55);
    write(1, "-PURPLE SHROOMS and ROCKS are map generated obstacles.\n", 55);
    write(1, "-While PURPLE SHROOMS deal no damage, they should not", 53);
    write(1, " be taken lightly.\n", 19 );
    print_seperation_line();
}

void display_instructions(void)
{
    write(1, "\n", 1);
    print_seperation_line();
    write(1, "INSTRUCTIONS:\n", 14);
    print_seperation_line();
    write(1, "You can launch the game by giving it a file containing ", 55);
    write(1, "a map as argument.\nOnce in the game you can use W and S", 56 );
    write(1, " to maneuver yourself through the menu.\n", 40 );
    write(1, "Simply select PLAY two times to start the game and EXIT", 55);
    write(1, " to close it.\n", 14 );
    print_seperation_line();
    write(1, "MAPS AND OBSTACLES:\n", 20);
    print_seperation_line();
    write(1, "Every Map is a combination of up to 50 signs (\\n included", 57);
    write(1, ")\n . mean empty spaces\n R stand for rocks\n T stand for ", 56);
    write(1, "toxic mushrooms\n", 16 );
    write(1, "During each round the map is infintely repeated\nwith", 53);
    write(1, " randomly spawning enemies in between.\n", 39);
    write(1, "Example: ......T...RR...TT...T.TTR\\n\n", 37);
    write(1, "You can find some maps are in the -example_maps- folder\n", 56);
    display_instructions2();
}

int test_for_instructions(int argc, char **argv)
{
    int x = 0;
    if (argc != 2) {
        return (1);
    }
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h'
        && argv[1][2] == '\0') {
        display_instructions();
        return (1);
    } else {
        x = test_map(argv[1]);
        return (x);
    }
}
