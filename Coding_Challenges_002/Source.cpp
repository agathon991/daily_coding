#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"      // for printf
#include "stdint.h"     // for uint32_t etc
#include "stdlib.h"     // for srand and rand
#include "time.h"       // for time

#define COUNT(x) (sizeof(x)/sizeof((x)[0]))

constexpr uint32_t histogram_size = 40;                 // number of bins in the histogram
constexpr uint32_t histogram_print_levels = 20;         // how many vertical levels to draw the graph with
constexpr uint32_t rand_numb_to_gen = 1000;             // how many random numbers to gen. to create a histogram
constexpr uint32_t max_randon_number = 100;             // range of values to generate (0-max_randon_number)
constexpr bool plot_range_only = false;                 // plot the entire histogram or just the range (min to max values)

uint32_t get_rand(uint32_t max)
{
    static bool is_seeded = false;
    if (!is_seeded)
    {
        srand((uint32_t)time(NULL));
        is_seeded = true;
    }

    return ((rand() % max));
}

int main(int argc, char* argv[])
{
    // storage for the histogram data
    uint32_t histogram[histogram_size] = { 0 };

    // populate the histogram data
    for (uint32_t i = 0; i < rand_numb_to_gen; i++)
    {
        // get a random number and put it in an appropriate bin
        histogram[(get_rand(max_randon_number) * histogram_size) / max_randon_number]++;
    }

    // get max and min values of the histogram
    // min value is set to 0 when not plotting the range only
    uint32_t max_val = 0;
    uint32_t min_val = plot_range_only ? (uint32_t)(-1) : 0;
    for (uint32_t i = 0; i < COUNT(histogram); i++)
    {
        max_val = histogram[i] > max_val ? histogram[i] : max_val;
        min_val = histogram[i] < min_val ? histogram[i] : min_val;
    }

    // how many vertical levels to plot for the histogram
    // if the range of value is smaller than the specified histogram height
    // then we'll reduce the histogram height to the range.
    // range is also adjusted based on the whether we are plotting the whole
    // histogram or just the range between min and max value
    uint32_t hist_level = histogram_print_levels;
    hist_level = ((max_val - min_val) > hist_level) ? hist_level : (max_val - min_val);

    // start drawing the histogram... line by line... 
    for (uint32_t level = hist_level; level > 0; level--)
    {
        uint32_t vert_label = ((max_val - min_val) * level) / (hist_level)+min_val;

        printf("%5d-|", vert_label);
        for (uint32_t hist_value = 0; hist_value < COUNT(histogram); hist_value++)
        {
            printf("%s", ((histogram[hist_value] - min_val) / (((max_val - min_val) * level) / hist_level) > 0) ? "*** " : "    ");
        }
        printf("\n");
    }

    // completed drawing the main graph idea and vertical axis. Now, draw the horizontal axis
    printf("-------");
    for (uint32_t hist_value = 0; hist_value < COUNT(histogram); hist_value++)
    {
        printf("----");
    }

    // put labels on the horizontal axis
    printf("\n     0|");
    for (uint32_t hist_value = 1; hist_value <= COUNT(histogram); hist_value++)
    {
        printf("%3d|", ((max_randon_number * hist_value) / histogram_size));
    }
    printf("\n");

    return 0; // all is well that ends well!
}

