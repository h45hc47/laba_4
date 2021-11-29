#include <stdio.h>


void copy(char to[], char from[])
{
    int i = 0;
    while ((to[i] = from[i]) != '\0') i++;
}

int is_num(char c) {
    int i;
    char nums[] = { '0','1','2','3','4','5','6','7','8','9' };
    for (i = 0; i < 10; i++)
        if (c == nums[i])
            return 1;
    return 0;
}

void nums_replace(char str[100][124]) {
    char ch_nums[10][6] = { {'z','e','r','o'}, {'o','n','e'},
                            {'t','w','o'}, {'t','h','r','e','e'},
                            {'f','o','u','r'}, {'f','i','v','e'},
                            {'s','i','x'}, {'s','e','v','e','n'},
                            {'e','i','g','h','t'}, {'n','i','n','e'}, };
    char ch1, ch2;
    int inum;
    for (int i = 0; i != 100; i++) {
        ch1 = str[i][0];
        ch2 = str[i][1];
        inum = ch1 - '0';
        if (is_num(ch1) == 1 && ch2 == '\0') {
            switch (inum) {
                case 0: copy(str[i], ch_nums[0]);
                        break;
                case 1: copy(str[i], ch_nums[1]);
                    break;
                case 2: copy(str[i], ch_nums[2]);
                    break;
                case 3: copy(str[i], ch_nums[3]);
                    break;
                case 4: copy(str[i], ch_nums[4]);
                    break;
                case 5: copy(str[i], ch_nums[5]);
                    break;
                case 6: copy(str[i], ch_nums[6]);
                    break;
                case 7: copy(str[i], ch_nums[7]);
                    break;
                case 8: copy(str[i], ch_nums[8]);
                    break;
                case 9: copy(str[i], ch_nums[9]);
                    break;
                default: printf("Error\n");
            }
        }
    }
}


void str_convert(char* string, char str[100][124]) {
    char c;
    int k = 0, i = 0, j = 0, num_nw = 0, word = 0;
    while ((c = string[k]) != '\0') {
        if (c == ' ') {
            if (num_nw == 0 && word > 0) {
                str[i][j] = '\0';
                str[i++][j];
                j = 0;
            }
            num_nw++;
        }
        else {
            str[i][j++] = c;
            num_nw = 0;
            word++;
        }
        k++;
    }
    str[i][j++] = '\0';
}

int main() {
    char string[] = "0 1 2 3 asd 4 5 6 7 8 פûגûפגûפ 9";
    char str[100][124];

    str_convert(string, str);

    nums_replace(str);

    return 0;
}
