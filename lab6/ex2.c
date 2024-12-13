#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef enum {
    NINJA = 1,
    SHAMAN = 2,
    SURA = 3,
    WARRIOR = 4,
    LYCAN = 5,
} Class;

const char* class_to_str(Class c) {
    static char* class_names[5] = {
        "NINJA", "SHAMAN", "SURA",
        "WARRIOR", "LYCAN",
    };

    return class_names[c];
}

typedef struct {
    char name[100];
    int level_points;
} Dungeon;

Dungeon dungeons[5] = {
    { "Demon Tower", 1 },
    { "Spider Queen's Nest", 2 },
    { "Devil's Catacomb", 3 },
    { "Erebus", 4 },
    { "Serpent Temple", 5 },
};

typedef struct {
    Class class;
    int level;
    char *name;
} Character;

int character_count = 0;
Character* characters[3];

Character* character_new(Class class, const char* name) {
    Character* new_character = (Character*) malloc(sizeof(Character));

    size_t name_len = strlen(name);
    new_character->name = malloc(name_len + 1);
    strncpy(new_character->name, name, name_len);
    new_character->class = class;
    new_character->level = 0;

    return new_character;
}

void character_update_name(Character* character) {
    gets(character->name);
}

void character_fight(Character* character) {
    int dungeon_idx = rand() % 5;
    printf("You fought in %s", dungeons[dungeon_idx].name);
    int points = (((character->class + rand() % 42) % 3) 
            * dungeons[dungeon_idx].level_points) % 17;
    printf("Because you're a %s, you get %d points",
            class_to_str(character->class), points);
    character->level += points;
}

void character_see_stats(Character* character) {
    const char *class = class_to_str(character->class);
    puts("Here are your character stats:");
    printf("Name: %s\n"
           "Class: %s\n"
           "Level: %d\n", character->name, class, character->level);
}

void win(const char* arg) {
    system(arg);
}

int main() {
    srand(time(NULL));

    puts("Welcome to Shinsoo!");
    puts("Start by creating your first character!\n");

    while (1) {
        puts("Actions:\n"
             "1. Create a new character\n"
             "2. Change the name of one of your characters\n"
             "3. Fight in a dungeon\n"
             "4. See your stats\n");

        int option;
        scanf("%d", &option);
		getchar();

        if (option < 1 || option > 4) {
            continue;
        }

        unsigned which;
        switch (option) {
        case 1:
            if (character_count >= 3) {
                puts("don't be greedy! you already have 3 characters :P");
                break;
            }

            puts("Choose your class:\n"
                 "1. NINJA\n"
                 "2. SHAMAN\n"
                 "3. SURA\n"
                 "4. WARRIOR\n"
                 "5. LYCAN\n");

            int class;
            scanf("%d", &class);
			getchar();

            if (class < 1 || class > 5) {
                puts("that's not a class :(");
                break;
            }

            puts("Choose your name:");
            char name[256];
            scanf("%255s", name); 

            characters[character_count++] = character_new(class, name);
            puts("Your new character is ready for battle\n");

            break;
        case 2:
            puts("Which one? 1, 2, or...\n");

            scanf("%d", &which);
			getchar();

            if (which > character_count) {
                puts("I don't think you own that character :(");
                break;
            }

            character_update_name(characters[which - 1]);
            break;
        case 3:
            puts("Which one? 1, 2, or...\n");

            scanf("%d", &which);
			getchar();

            if (which > character_count) {
                puts("I don't think you own that character :(");
                break;
            }

            character_fight(characters[which - 1]);
            break;
        case 4:
            puts("Which one? 1, 2, or...\n");

            scanf("%d", &which);
			getchar();

            if (which > character_count) {
                puts("I don't think you own that character :(");
                break;
            }

            character_see_stats(characters[which-1]);
            break;
        default:
            puts("wrong option");
            break;
        }
    }
}
