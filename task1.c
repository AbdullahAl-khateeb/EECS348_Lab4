#include <stdio.h>

int main(void)
{
    int score;

    while (1)
    {
        printf("Enter the NFL score (Enter 1 to stop): ");

        /* Check for non-integer input. */
        if (scanf("%d", &score) != 1)
        {
            int ch;

            printf("Invalid input. Please enter an integer score.\n");

            while ((ch = getchar()) != '\n' && ch != EOF)
            {
                /* Clear invalid input from the keyboard buffer. */
            }

            continue;
        }

        /* Stop when the user enters 1. */
        if (score == 1)
        {
            break;
        }

        /* Negative scores are invalid. */
        if (score < 0)
        {
            printf("Invalid score. Score cannot be negative.\n");
            continue;
        }

        printf("Possible combinations of scoring plays if a team's score is %d:\n",
               score);

        for (int td2 = 0; td2 * 8 <= score; td2++)
        {
            for (int td1 = 0;
                 td2 * 8 + td1 * 7 <= score;
                 td1++)
            {
                for (int td = 0;
                     td2 * 8 + td1 * 7 + td * 6 <= score;
                     td++)
                {
                    for (int fg = 0;
                         td2 * 8 + td1 * 7 + td * 6 + fg * 3 <= score;
                         fg++)
                    {
                        for (int safety = 0;
                             td2 * 8 + td1 * 7 + td * 6 +
                                 fg * 3 + safety * 2 <= score;
                             safety++)
                        {
                            int total = td2 * 8 +
                                        td1 * 7 +
                                        td * 6 +
                                        fg * 3 +
                                        safety * 2;

                            if (total == score)
                            {
                                printf("%d TD + 2pt, %d TD + FG, "
                                       "%d TD, %d 3pt FG, %d Safety\n",
                                       td2, td1, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
