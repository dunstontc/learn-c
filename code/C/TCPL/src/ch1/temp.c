#include <stdio.h>

// print Fahrenheit-Celsius table for farh = 0, 20, ..., 300

int main()
{
    int fahrenheit, celsius;
    int start_num, end_num, current_step;

    start_num = 0;     // lower limit of temperature table
    end_num = 300;     // upper limit
    current_step = 20; // step size

    fahrenheit = start_num;

    while(fahrenheit <= end_num) {
        celsius = (5 * (fahrenheit-32) / 9);
        printf("%d\t%d\n", fahrenheit, celsius);
        fahrenheit = fahrenheit + current_step;
    }
}

