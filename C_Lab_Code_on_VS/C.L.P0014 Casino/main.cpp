/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: 000100000001011
 *
 * Created on January 13, 2019, 9:40 PM
 */

#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdlib.h>

using namespace std;
void program_casino(int urchoice, int &money, int &chips);
//random dice

int dice_random() {
    int totalDice,
            dice1,
            dice2;
    dice1 = 1 + rand() % (6);
    dice2 = 1 + rand() % (6);
    return totalDice = dice1 + dice2;
}

//Choice of players

int main(int argc, char** argv) {
    int urchoice, money = 1000, chips = 0;
    char enter;
    fflush(stdin);
    while (1) {
        printf("Welcome to the Casino. Here are your choices:\n");
        printf("1) Buy chips\n");
        printf("2) Sell chips\n");
        printf("3) Play Craps\n");
        printf("4) Play Arup's Game of Dice\n");
        printf("5) Status Report\n");
        printf("6) Quit\n");
        int flag = scanf("%d%c", &urchoice, &enter); //int flag = scanf("%d,%c", &urchoice, &enter); *dm... sai đoạn dấu [,] chỗ scanf làm tìm bug mấy cả gần 30p 
        if (flag == 0 || enter != '\n') {
            while (getchar() != '\n');
        } else if (urchoice < 1 || urchoice > 6) {
            // printf("Please! Hit your choice");
            return 0;
        }            //truyền tham chiếu
        else if (urchoice >= 1 && urchoice < 6) {
            program_casino(urchoice, money, chips);
        } else if (urchoice == 6) {
            program_casino(6, money, chips);
            break;
        }
    }
    getchar();
    return 0;
}

//Program that simulates a casino for a single player

void program_casino(int urchoice, int &money, int &chips) {
    srand(time(NULL)); // cho ra những số random khác nhau mỗi lần chạy,
    switch (urchoice) {
            //Buy chip
        case 1:
        {
            int money_buy_chip;
            char enter;
            while (1) {
                //check input
                printf("How much do you want to spend for chips?\n");
                float flag = scanf("%d%c", &money_buy_chip, &enter);
                if (flag == 0 || enter != '\n') {
                    while (getchar() != '\n');
                } else if (money_buy_chip <= 0);
                else if (money_buy_chip > money) {
                    printf("Sorry, you do not have that money. No chips bought.\n");
                    break;
                }                    //caculate money and chips after bought
                else if (money_buy_chip <= money) {
                    chips = money_buy_chip / 11;
                    money = money - money_buy_chip + money_buy_chip % 11; // money_buy_chip % 11 là đê tìm số tiền dư
                    break;
                }
            }
            break;
        }
            //Sell chips
        case 2:
        {
            int sell_chip;
            char enter;
            while (1) {
                //check input to sell
                fflush(stdin);
                printf("How many chips do you want to sell?\n");
                int flag = scanf("%d%c", &sell_chip, &enter);
                if (flag == 0 || enter != '\n') {
                    while (getchar() != '\n');
                } else if (sell_chip <= 0);
                else if (sell_chip > chips) {
                    printf("Sorry, you do not have that many chips. No chips sold. \n");
                    break;
                }                    //money and chips after sell
                else if (sell_chip <= chips) {
                    chips = chips - sell_chip;
                    money = money + sell_chip * 10;
                    break;
                }
                break;
            }
            break;
        }
            //Game Craps
        case 3:
        {
            int bet_chip;
            char enter;
            //-------------------------------
            //check input
            while (1) {
                fflush(stdin);
                printf("How many chips would you like to bet?\n");
                int flag = scanf("%d%c", &bet_chip, &enter);
                if (flag == 0 || enter != '\n') {
                    while (getchar() != '\n');
                } else if (bet_chip == 0) { // nghi ngo bug doan nay <=
                    printf("Sorry, that is not allowed. No game played.\n");
                    break;
                } else if (bet_chip > chips) {
                    printf("Sorry, you do not have that many chips. No chips bet.\n");
                    break;
                } else
                    break;
            }
            //----------------------------
            //begin play game
            if (bet_chip <= chips) {
                char r, enter;
                //check input for the first roll
                while (1) {
                    fflush(stdin);
                    printf("Press 'r' and hit enter for your first roll.\n");
                    int flag = scanf("%c%c", &r, &enter);
                    if (flag == 0 || enter != '\n') {
                        while (getchar() != '\n');
                    }                        //----------------------------
                        //random dice the first times
                    else if (r == 'r' || r == 'R') {
                        int dice1 = dice_random();
                        printf("You roll a %d\n", dice1);
                        if (dice1 == 7 || dice1 == 11) {
                            chips = chips + bet_chip;
                            printf("You win!\n");
                            break;
                        } else if (dice1 == 2 || dice1 == 3 || dice1 == 12) {
                            chips = chips - bet_chip;
                            printf("Sorry, you have lost!\n");
                            break;
                        }                            //------------------------
                            //random dice the next times
                        else {
                            char next_roll, enter;
                            int total_dice1 = dice1;
                            int dice2;
                            do {
                                //-----------------------------
                                //check input for the next roll                                
                                while (1) {
                                    fflush(stdin); //Cái này phải có nếu không nó sẽ yêu cầu nhập thêm 1 lần nữa "Press 'r' and hit enter for your next roll"
                                    printf("Press 'r' and hit enter for your next roll.\n");
                                    int flag = scanf("%c%c", &next_roll, &enter);
                                    if (flag == 0 || enter != '\n') {
                                        while (getchar() != '\n');
                                    }                                        //-----------------------------
                                        //begin random dice2 the next times 
                                    else if (next_roll == 'r' || next_roll == 'R') {
                                        dice2 = dice_random();
                                        printf("You roll a %d\n", dice2);
                                        if (dice2 == total_dice1) {
                                            chips = chips + bet_chip;
                                            printf("You win!\n");
                                            break;
                                        } else if (dice2 == 7) {
                                            chips = chips - bet_chip;
                                            printf("Sorry, you have lost!\n");
                                            break;
                                        }
                                    }
                                }
                            } while (dice2 != total_dice1 && dice2 != 7);
                        }
                        break;
                    }
                }
            }
            break;
        }
            //Game Arup's Game of Dice
        case 4:
        {
            int bet_chip;
            char enter;
            //-------------------------------
            //check input
            while (1) {
                fflush(stdin);
                printf("How many chips would you like to bet?\n");
                int flag = scanf("%d%c", &bet_chip, &enter);
                if (flag == 0 || enter != '\n') {
                    while (getchar() != '\n');
                } else if (bet_chip == 0) { // nghi ngo bug doan nay <=
                    printf("Sorry, that is not allowed. No game played.\n");
                    break;
                } else if (bet_chip > chips) {
                    printf("Sorry, you do not have that many chips. No chips bet.\n");
                    break;
                } else
                    break;
            }
            //----------------------------
            //begin play game
            if (bet_chip <= chips) {
                char r, enter;
                //check input for the first roll
                while (1) {
                    fflush(stdin);
                    printf("Press 'r' and hit enter for your first roll.\n");
                    int flag = scanf("%c%c", &r, &enter);
                    if (flag == 0 || enter != '\n') {
                        while (getchar() != '\n');
                    }//----------------------------
                        //random dice the first times
                    else if (r == 'r' || r == 'R') {
                        int dice1 = dice_random();
                        printf("You roll a %d\n", dice1);
                        if (dice1 == 11 || dice1 == 12) {
                            chips = chips + bet_chip;
                            printf("You win!\n");
                            break;
                        } else if (dice1 == 2) {
                            chips = chips - bet_chip;
                            printf("Sorry, you have lost!\n");
                            break;
                        }//------------------------
                            //random dice the next times
                        else {
                            char next_roll, enter;
                            int total_dice1 = dice1;
                            int dice2;
                            //-----------------------------
                            //check input for the next roll                                
                            while (1) {
                                fflush(stdin); //Cái này phải có nếu không nó sẽ yêu cầu nhập thêm 1 lần nữa "Press 'r' and hit enter for your next roll"
                                printf("Press 'r' and hit enter for your next roll.\n");
                                int flag = scanf("%c%c", &next_roll, &enter);
                                if (flag == 0 || enter != '\n') {
                                    while (getchar() != '\n');
                                } else if (next_roll == 'r' || next_roll == 'R') {
                                    dice2 = dice_random();
                                    printf("You roll a %d\n", dice2);
                                    if (dice2 > total_dice1) {
                                        chips = chips + bet_chip;
                                        printf("You win!\n");
                                        break;
                                    } else if (dice2 <= total_dice1) {
                                        chips = chips - bet_chip;
                                        printf("Sorry, you have lost!\n");
                                        break;
                                    }
                                    break;
                                }
                            }
                        }
                        break;
                    }
                }
                break;
            }
            break;
        }
            //Status Report
        case 5:
        {
            printf("You currently have $%d left and %d chips\n", money, chips);
            break;
        }
            //Quit
        case 6:
        {
            money = money + chips * 10;
            printf("After selling your chips, you have $%d. Thanks for playing!\n", money);
            break;
        }
            break;
    }
}