#include <stdio.h>
#include <ctype.h>

int main(void)
{
    double temperature;
    double celsius;
    double converted;
    char originalScale;
    char targetScale;

    printf("Enter the temperature value: ");

    if (scanf("%lf", &temperature) != 1)
    {
        printf("Invalid temperature input.\n");
        return 1;
    }

    printf("Enter the original scale (C, F, or K): ");

    if (scanf(" %c", &originalScale) != 1)
    {
        printf("Invalid original scale input.\n");
        return 1;
    }

    printf("Enter the scale to convert to (C, F, or K): ");

    if (scanf(" %c", &targetScale) != 1)
    {
        printf("Invalid target scale input.\n");
        return 1;
    }

    originalScale = toupper((unsigned char)originalScale);
    targetScale = toupper((unsigned char)targetScale);

    /* Convert the original temperature to Celsius first. */
    if (originalScale == 'C')
    {
        celsius = temperature;
    }
    else if (originalScale == 'F')
    {
        celsius = (temperature - 32.0) * 5.0 / 9.0;
    }
    else if (originalScale == 'K')
    {
        if (temperature < 0)
        {
            printf("Invalid temperature. Kelvin cannot be negative.\n");
            return 1;
        }

        celsius = temperature - 273.15;
    }
    else
    {
        printf("Invalid original scale.\n");
        return 1;
    }

    /* Temperatures below absolute zero are physically invalid. */
    if (celsius < -273.15)
    {
        printf("Invalid temperature. Temperature cannot be below absolute zero.\n");
        return 1;
    }

    /* Convert from Celsius to the requested scale. */
    if (targetScale == 'C')
    {
        converted = celsius;
    }
    else if (targetScale == 'F')
    {
        converted = (celsius * 9.0 / 5.0) + 32.0;
    }
    else if (targetScale == 'K')
    {
        converted = celsius + 273.15;
    }
    else
    {
        printf("Invalid target scale.\n");
        return 1;
    }

    printf("Converted temperature: %.2f %c\n",
           converted, targetScale);

    if (celsius < 0)
    {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay warm!\n");
    }
    else if (celsius < 10)
    {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket!\n");
    }
    else if (celsius < 25)
    {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: Enjoy the weather!\n");
    }
    else if (celsius < 35)
    {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    }
    else
    {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors!\n");
    }

    return 0;
}
