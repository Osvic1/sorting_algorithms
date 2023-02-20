#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - compares two cards by value and kind
 * @a: pointer to first card
 * @b: pointer to second card
 * Return: negative if a < b, zero if a == b, positive if a > b
 */
int compare_cards(const void *a, const void *b)
{
char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
"9", "10", "Jack", "Queen", "King"};
kind_t kinds[] = {SPADE, HEART, CLUB, DIAMOND};
const card_t *card_a = *(const card_t **)a;
const card_t *card_b = *(const card_t **)b;
size_t i;

for (i = 0; i < 13; i++)
if (card_a->value == values[i] || card_b->value == values[i])
break;
if (card_a->value != card_b->value)
return (i % 13 - (i + 1) % 13);
for (i = 0; i < 4; i++)
if (card_a->kind == kinds[i] || card_b->kind == kinds[i])
break;
return (i % 4 - (i + 1) % 4);
}

/**
 * sort_deck - sorts a deck of cards using qsort
 * @deck: pointer to pointer to head of doubly linked list
 */
void sort_deck(deck_node_t **deck)
{
deck_node_t **array;
deck_node_t *node;
size_t n = 0, i;

if (!deck || !*deck || !(*deck)->next)
return;

    /* create an array of pointers to nodes */
node = *deck;
while (node)
n++, node = node->next;

array = malloc(sizeof(*array) * n);

for (i = 0, node = *deck; i < n; i++, node = node->next)
array[i] = node;

   /* sort the array using compare_cards function */
qsort(array, n, sizeof(*array), compare_cards);

   /* rearrange the nodes according to the sorted array */
for (i = 0; i < n - 1; i++)
{
array[i]->next = array[i + 1];
array[i + 1]->prev = array[i];
}

   /* update head and tail of list */
array[0]->prev = NULL;
array[n - 1]->next = NULL;
*deck = array[0];

free(array);
}
