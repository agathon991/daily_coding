#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdint.h"
#include "stdlib.h"
#include <ctype.h>
#include <assert.h>

#define ALPHABET_SIZE 26
#define MAX_WORD_LENGTH 16

// Trie node
struct trie_node
{
    struct trie_node* node[ALPHABET_SIZE]{ NULL };
    char* remaining_chars{ NULL };
    bool end_of_word{ false };
};

const char * input_data[]{
    "aardvaxk", "dog", "deer", "deal", "blue", "red", "orange",
    "yellow", "volvo", "bmw", "ford", "mazda", "spike",
    "tom", "jerry" , "carcass"};

void add_to_trie(trie_node* trie, const char word[])
{
    if (!word)
    {
        // raise some errors, we should not have ended up here
    }

    char c = tolower(word ? word[0] : '\0');

    if (c)
    {
        // convert ascii value to an alphabet index
        c -= 'a';

        // have a character to add to the trie
        if (!trie->node[c])
        {
            trie->node[c] = new trie_node;
        }

        if (trie->node[c])
        {
            add_to_trie(trie->node[c], word + 1);
        }
    }
    else
    {
        trie->end_of_word = true;
    }
}

void match_in_trie(trie_node * trie, const char word[], char matched_word[], int len = 0, bool exact_match = false)
{
    char c = tolower(word ? word[0] : '\0');

    if (c)
    {
        // still matching the search term

        c -= 'a';
        if (trie->node[c])
        {
            matched_word[len] = c + 'a';
            match_in_trie(trie->node[c], word + 1, matched_word, len + 1, exact_match);
        }
    }
    else
    {
        if (trie->end_of_word)
        {
            // reached the end of our search word, at a node thats also an end of the word
            // we can also call some other routine to add this matched word to a list
            matched_word[len + 1] = '\0';
            printf("%s\n", matched_word);
        }

        if (!exact_match)
        {
            // done matching the pattern, dump all children words
            for (c = 0; c < ALPHABET_SIZE; c++)
            {
                if (trie->node[c])
                {
                    matched_word[len] = c + 'a';
                    match_in_trie(trie->node[c], "\0", matched_word, len + 1, exact_match);
                }
            }
        }
    }
    matched_word[len] = '\0';
}


uint32_t wild_match_in_trie(trie_node* trie, const char word[], uint32_t found_len, char matched_word[], int len = 0, bool matched = false)
{

    // This function is WIP

    char c = tolower(word ? word[found_len] : '\0');
    char d = tolower(word ? word[found_len+1] : '\0');

    if (c && d)
    {
        if (c == '*')
        {
            // continue looking for pattern through the trie
            for (uint32_t i = 0; i < ALPHABET_SIZE; i++)
            {
                if (trie->node[i])
                {
                    if (d == (i + 'a'))
                    {
                        // currently on a wildcard but matches the next character
                        found_len += 2;
                    }

                    matched_word[len] = i + 'a';
                    found_len = wild_match_in_trie(trie->node[i], word, found_len, matched_word, len + 1);
                }
            }
        }
        else
        {
            // still matching the search term
            c -= 'a';
            if (trie->node[c])
            {
                matched_word[len] = c + 'a';
                found_len = wild_match_in_trie(trie->node[c], word, found_len + 1, matched_word, len + 1);
            }
            else
            {
                if (found_len > 0)
                {
                    // we have matched a portion of the pattern but not are now failing
                    // do we a previous asterix that we can fall back to and continue?
                    for (uint32_t x = (found_len - 1); x >= 0; x--)
                    {
                        if (word[x] == '*')
                        {
                            return x;
                        }
                    }
                }

            }
        }
    }
    else
    {
        if (trie->end_of_word)
        {
            // reached the end of our search word, at a node thats also an end of the word
            // we can also call some other routine to add this matched word to a list
            matched_word[len + 1] = '\0';
            printf("%s\n", matched_word);
        }

        // done matching the pattern, dump all children words
        for (c = 0; c < ALPHABET_SIZE; c++)
        {
            if (trie->node[c])
            {
                matched_word[len] = c + 'a';
                found_len = wild_match_in_trie(trie->node[c], "\0", found_len, matched_word, len + 1);
            }
        }
    }
    return found_len;
}


int main(int argc, char** argv)
{
    char matched_word[MAX_WORD_LENGTH + 1] = {0};
    trie_node dictionary;

    for (auto x : input_data)
    {
        add_to_trie(&dictionary, x);
    }

    match_in_trie(&dictionary, "bmw", matched_word, 0, true);       // exact match for bmw
    match_in_trie(&dictionary, "de", matched_word, 0, false);       // all words starting with de

    //wild_match_in_trie(&dictionary, "*ax*", 0, matched_word);     // <-- WIP

    return 0;
}

