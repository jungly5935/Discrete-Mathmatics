#include <stdio.h>
#include <string.h>

FILE* fp, * op;
int monthday[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
char weekdate[7][5] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
char date1[4], date2[4];
int year1, month1, day1, year2, month2, day2, calendar1, calendar2;

void type0() {
    fscanf(fp, "%d-%d-%d", &year1, &month1, &day1);
    fscanf(fp, "%d-%d-%d", &year2, &month2, &day2);

    if (monthday[month1] < day1) {

        if (month1 == 2) {
            if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                if (day1 > monthday[month1] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }
    if (monthday[month2] < day2) {

        if (month2 == 2) {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                if (day2 > monthday[month2] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }

        else {
            fprintf(op, "-1\n");
            return;
        }
    }

    int i, j, k, l;

    calendar1 = (((year1 - 1) * 365) + ((year1 - 1) / 4) + ((year1 - 1) / 400)) - ((year1 - 1) / 100);
    calendar2 = (((year2 - 1) * 365) + ((year2 - 1) / 4) + ((year2 - 1) / 400)) - ((year2 - 1) / 100);



    for (i = 1; i < month1; i++) {
        calendar1 += monthday[i];
    }
    for (i = 1; i < month2; i++) {
        calendar2 += monthday[i];
    }

    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) calendar1 += 1;
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)) calendar2 += 1;
    calendar1 = calendar1 + day1;
    calendar2 = calendar2 + day2;

    if (calendar1 - calendar2 < 0) fprintf(op, "%d\n", -(calendar1 - calendar2));
    else fprintf(op, "%d\n", (calendar1 - calendar2));
}

void type1() {
    fscanf(fp, "%d-%d-%d", &year1, &month1, &day1);
    fscanf(fp, "%d-%d-%d-%s", &year2, &month2, &day2, date1);

    int i, j, k, l, c;

    calendar1 = (((year1 - 1) * 365) + ((year1 - 1) / 4) + ((year1 - 1) / 400)) - ((year1 - 1) / 100);
    calendar2 = (((year2 - 1) * 365) + ((year2 - 1) / 4) + ((year2 - 1) / 400)) - ((year2 - 1) / 100);

    if (monthday[month1] < day1) {

        if (month1 == 2) {
            if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                if (day1 > monthday[month1] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }

    for (i = 1; i < month1; i++) {
        calendar1 += monthday[i];
    }
    for (i = 1; i < month2; i++) {
        calendar2 += monthday[i];
    }

    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) calendar1 += 1;
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)) calendar2 += 1;
    calendar1 = calendar1 + day1;

    j = (calendar2 + 1) % 7;

    c = 0;
    for (i = 0; c < day2; i++) {
        if (!strcmp(weekdate[(j + i) % 7], date1)) {
            c++;
        }
    }

    if (monthday[month2] < i) {
        if (month2 == 2) {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                if (i > monthday[month2] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }
    calendar2 = calendar2 + i;

    if (calendar1 - calendar2 < 0) fprintf(op, "%d\n", -(calendar1 - calendar2));
    else fprintf(op, "%d\n", (calendar1 - calendar2));

}

void type2() {
    fscanf(fp, "%d-%d-%d-%s", &year1, &month1, &day1, date1);
    fscanf(fp, "%d-%d-%d", &year2, &month2, &day2);

    int i, j, k, l, c;

    calendar1 = (((year1 - 1) * 365) + ((year1 - 1) / 4) + ((year1 - 1) / 400)) - ((year1 - 1) / 100);
    calendar2 = (((year2 - 1) * 365) + ((year2 - 1) / 4) + ((year2 - 1) / 400)) - ((year2 - 1) / 100);

    if (monthday[month2] < day2) {

        if (month2 == 2) {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                if (day2 > monthday[month2] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }

        else {
            fprintf(op, "-1\n");
            return;
        }
    }


    for (i = 1; i < month1; i++) {
        calendar1 += monthday[i];
    }
    for (i = 1; i < month2; i++) {
        calendar2 += monthday[i];
    }

    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) calendar1 += 1;
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)) calendar2 += 1;
    calendar2 = calendar2 + day2;


    j = (calendar1 + 1) % 7;

    c = 0;
    for (i = 0; c < day1; i++) {
        if (!strcmp(weekdate[(j + i) % 7], date1)) {
            c++;
        }
    }

    if (monthday[month1] < i) {
        if (month1 == 2) {
            if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                if (i > monthday[month1] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }
    calendar1 = calendar1 + i;




    if (calendar1 - calendar2 < 0) fprintf(op, "%d\n", -(calendar1 - calendar2));
    else fprintf(op, "%d\n", (calendar1 - calendar2));


}

void type3() {
    fscanf(fp, "%d-%d-%d-%s", &year1, &month1, &day1, date1);
    fscanf(fp, "%d-%d-%d-%s", &year2, &month2, &day2, date2);
    int i, j, k, l, c;


    calendar1 = (((year1 - 1) * 365) + ((year1 - 1) / 4) + ((year1 - 1) / 400)) - ((year1 - 1) / 100);
    calendar2 = (((year2 - 1) * 365) + ((year2 - 1) / 4) + ((year2 - 1) / 400)) - ((year2 - 1) / 100);

    for (i = 1; i < month1; i++) {
        calendar1 += monthday[i];
    }
    for (i = 1; i < month2; i++) {
        calendar2 += monthday[i];
    }
    if (month1 > 2 && ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0)) calendar1 += 1;
    if (month2 > 2 && ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0)) calendar2 += 1;

    j = (calendar1 + 1) % 7;

    c = 0;
    for (i = 0; c < day1; i++) {
        if (!strcmp(weekdate[(j + i) % 7], date1)) {
            c++;
        }
    }

    if (monthday[month1] < i) {
        if (month1 == 2) {
            if ((year1 % 4 == 0 && year1 % 100 != 0) || year1 % 400 == 0) {
                if (i > monthday[month1] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }
    calendar1 = calendar1 + i;


    j = (calendar2 + 1) % 7;

    c = 0;
    for (i = 0; c < day2; i++) {
        if (!strcmp(weekdate[(j + i) % 7], date2)) {
            c++;
        }
    }

    if (monthday[month2] < i) {
        if (month2 == 2) {
            if ((year2 % 4 == 0 && year2 % 100 != 0) || year2 % 400 == 0) {
                if (i > monthday[month2] + 1) {
                    fprintf(op, "-1\n");
                    return;
                }
            }
            else {
                fprintf(op, "-1\n");
                return;
            }
        }
        else {
            fprintf(op, "-1\n");
            return;
        }
    }
    calendar2 = calendar2 + i;

    if (calendar1 - calendar2 < 0) fprintf(op, "%d\n", -(calendar1 - calendar2));
    else fprintf(op, "%d\n", (calendar1 - calendar2));
}

int main() {

    int type;

    fp = fopen("calendar.inp", "r");
    op = fopen("calendar.out", "w");

    while (1) {

        fscanf(fp, "%d", &type);

        if (type == 0) {
            type0();
        }
        else if (type == 1) {
            type1();
        }
        else if (type == 2) {
            type2();
        }
        else if (type == 3) {
            type3();
        }
        else {
            break;
        }
    }
}