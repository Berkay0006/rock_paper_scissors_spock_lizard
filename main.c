#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LINE_SIZE 100
#define SHAPE_COUNT 5

enum {Rock, Lizard, SCISSORS, PAPER, SPOCK};
const char *SHAPE_STRINGS[] = {"🪨", "🦎", "✂️", "🗒️", "🖖"};

const int WINNING_SCORE = 5;

int win(int p1, int p2) {
int diff = p2 - p1;

if (diff == 0)
    return 0;
else if (diff == 1 || diff == 3 || diff == -2 || diff == -4)
    return 1;
else
    return -1;
}

int main() {
srand(time(NULL));

printf("Welcome to 🪨 🦎 ✂️ 🗒️ 🖖!\n");
printf("(s) single player\n");
printf("(e) EXIT\n");

char menu_choice;
while (1) {

printf("Select and item:\n");
menu_choice = getchar();
while (getchar() != '\n');

if (menu_choice == 'e')
    return 0;
else if (menu_choice == 's')
    break;
else
printf("❌ Wrong menu choice. Try again.\n");
}

printf("starting game🎉\n");
int player_score = 0, agent_score = 0;

while (player_score < WINNING_SCORE && agent_score < WINNING_SCORE) {
int player_choice;

while (1) {
printf("Select a shape:\n");
printf("0🪨 || 1🦎 || 2✂️ || 3🗒️ || 4🖖:\n");
if (scanf("%d", &player_choice) != 1) {
printf("❌ Invalid input. Try again.\n");
while (getchar() != '\n')
    continue;
}
if (player_choice < 0 || player_choice >= SHAPE_COUNT) {
printf("❌ The shape %d does not exist. Try again.\n", player_choice);
    continue;
}
    break;
}
while (getchar() != '\n');

int agent_choice = rand() % SHAPE_COUNT;
printf("Agent: %d\n", agent_choice);

int outcome = win(player_choice, agent_choice);
if (outcome == 1) {
player_score++;
} else if (outcome == -1) {
agent_score++;
}

printf("👫: %d 🤖: %d\n", player_score, agent_score);
} 

if (player_score >= WINNING_SCORE)
    printf("👫 Player won!\n");
else
    printf("🤖 Agent won!\n");

return 0;
}