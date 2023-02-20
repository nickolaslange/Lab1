#include <stdio.h>

/*honestly I knew i wouldn't have time to finish this by midnight so im just turning it in even though its a mess*/

    /*find if it can be all safety's, if so print how many*/
    int safety (int num) {
        int safety_num;
        if (num % 2 == 0) {
            safety_num = num / 2;
            printf("0 TD + 2pt, 0 TD + FG, 0 TD, 0 3pt FG, %d Safety\n", safety_num);
        }
        return 0;
    }

    /*func to return how many safetys can be made, WIHTOUT PRINTING*/
    int safety_r (int num) {
        int safety_num;
        if (num % 2 == 0) {
            safety_num = num / 2;
            return safety_num;
        }
        return 0;
    }

    int field_goal(int num) {
        int safety_num = 0, field_goal_num;
        /*print if it is evenly divisble by field goals*/
        if (num % 3 == 0) {
            field_goal_num = num / 3;
            printf("0 TD + 2pt, 0 TD + FG, 0 TD, %d 3pt FG, 0 Safety\n", field_goal_num);
        }
        /*start by having one FG, check how many safeties, deincrement num until you reach < 3>*/
        int temp = num;
        while (temp >= 3) {
            field_goal_num++;
            temp -= 3;
            safety_num = safety_r(temp);
            if ((3*field_goal_num + 2*safety_num) == num) {
                printf("0 TD + 2pt, 0 TD + FG, 0 TD, %d 3pt FG, %d Safety\n", field_goal_num, safety_num);
            }
        }
        return 0;
    }

    /*returns field goal possibilites to other funcs*/
    int field_goal_r(int num) {
        int safety_num = 0, field_goal_num;
        /*print if it is evenly divisble by field goals*/
        if (num % 3 == 0) {
            field_goal_num = num / 3;
            printf("0 TD + 2pt, 0 TD + FG, 0 TD, %d 3pt FG, 0 Safety\n", field_goal_num);
        }

        
        /*start by having one FG, check how many safeties, deincrement num until you reach < 3>*/
        int temp = num;
        while (temp >= 3) {
            field_goal_num++;
            temp -= 3;
            safety_num = safety_r(temp);
            if ((3*field_goal_num + 2*safety_num) == num) {
                printf("0 TD + 2pt, 0 TD + FG, 0 TD, %d 3pt FG, %d Safety\n", field_goal_num, safety_num);
            }
        }
        return 0;

    }

    int touch_down (int num) {
        int safety_num = 0, field_goal_num = 0, touch_down_num = 0;
        if (num % 6 == 0) {
            touch_down_num = num / 6;
            printf("0 TD + 2pt, 0 TD + FG, %d TD, 0 3pt FG, 0 Safety\n", touch_down_num);
        }

        /*check if 1 TD and only safety's or FG works*/
        int temp = num;
        while (temp >= 6) {
            touch_down_num++;
            temp -= 6;
            if (temp % 2 == 0) {
                safety_num = safety(temp);
                printf("0 TD + 2pt, 0 TD + FG, %d TD, 0 3pt FG, %d Safety\n", touch_down_num, safety_num);
            }
            if (temp % 3 == 0) {
                field_goal_num = field_goal(temp);
                printf("0 TD + 2pt, 0 TD + FG, %d TD, %d 3pt FG, 0 Safety\n", touch_down_num, field_goal_num);
            }
            while (temp >= 2) {
                safety_num++;
                temp -= 2;
                if (temp % 2 == 0) {
                    printf("0 TD + 2pt, 0 TD + FG, %d TD, 0 3pt FG, %d Safety\n", touch_down_num, safety_num);
                }
                if (temp % 3 == 0) {
                    printf("0 TD + 2pt, 0 TD + FG, %d TD, %d 3pt FG, 0 Safety\n", touch_down_num, field_goal_num);
                }
            }

        }

        /*check 1 TD, increment FG, find safeties*/
        while (temp >= 6) {
            touch_down_num++;
            temp -= 6;
            safety_num++;
            temp -= 2;
            safety_num = safety(temp);
            printf("0 TD + 2pt, 0 TD + FG, %d TD, %d 3pt FG, 0 Safety\n", touch_down_num, field_goal_num);


        }

        return 0;

    }


int main() {


    int input = 2;

    /*while loop that stops only when input is 0 or 1*/
    while (input != 0 && input != 1) {

        /*print statement that prompts for input*/
        printf("\nEnter 0 or 1 to STOP");
        printf("\nEnter the NFL score: ");
        scanf("%d", &input);

        /*print all possibilites for current input*/
        safety(input);
        field_goal(input);
        touch_down(input);
    }

    return 0;
}