#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "deck.h"

#define CARD_VALUES "Ace 2 3 4 5 6 7 8 9 10 Jack Queen King"
#define CARD_SUITS "Spades Hearts Clubs Diamonds"

/**
 * _get_card_value - get the value of a card
 * @value: value of a card
 *
 * Return: an integer representing the value of a card
 */
static int _get_card_value(const char *value)
{
    char *p = (char *)CARD_VALUES;
    int val = 1;

    while (*p)
    {
        if (*p == *value)
            return (val);
        if (*p == ' ')
            val++;
        p++;
    }

    return (-1);
}

/**
 * _get_card_suit - get the suit of a card
 * @suit: suit of a card
 *
 * Return: an integer representing the suit of a card
 */
static int _get_card_suit(const char *suit)
{
    char *p = (char *)CARD_SUITS;
    int val = 1;

    while (*p)
    {
        if (*p == *suit)
            return (val);
        if (*p == ' ')
            val++;
        p++;
    }

    return (-1);
}

/**
 * _sort_deck_node - sort two adjacent deck nodes
 * @left: left deck node
 * @right: right deck node
 */
static void _sort_deck_node(deck_node_t **left, deck_node_t **right)
{
    deck_node_t *tmp = *left;

    if (!(*left)->prev)
    {
        *left = (*right);
        *right = tmp;
        tmp = (*left)->prev;
        (*left)->prev = NULL;
        (*left)->next = tmp;
        tmp->prev = (*left);
    }
    else if (!(*right)->next)
    {
        tmp = (*left)->prev;
        (*left)->prev = (*right);
        (*left)->next = NULL;
        (*right)->prev = tmp;
        (*right)->next = (*left);
        tmp->next = (*right);
    }
    else
    {
        tmp = (*left)->prev;
        (*left)->prev = (*right);
        (*left)->next = (*right)->next;
        (*right)->prev = tmp;
        (*right)->next->prev = (*left);
        (*right)->next = (*left);
        tmp->next = (*right);
    }
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: pointer to head of doubly linked list of cards
 */
void sort_deck(deck_node_t **deck)
{
    deck_node_t *left, *right, *tmp;
    int left_val, right_val;

    if (!deck || !(*deck) || !((*deck)->next))
        return;

    for (tmp = *deck; tmp->next; tmp = tmp->next)
    {
        right = tmp->next;
        left = tmp;
        while (right)
        {
            left_val = _get_card_value(left->card->value);
            right_val = _get_card_value(right->card->value);
            if (right_val < left_val)
            {
                _sort_deck_node(&left, &right);
                if (!left->prev)
                    *deck = left;
                print_deck(*deck);
                left_val = _get_card_value(left->card->value);
            }
            right = left->next;
            left = left->prev;
        }
    }
}
