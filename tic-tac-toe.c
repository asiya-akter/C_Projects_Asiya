/*Name: Mst. Asiya Akter

Project name: TIC-TAC-TOE
*/


#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>
//farabe.bracucse@gmail.com
char square[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8','9'};
int checkWinner();
void drawBoard();
char symbol1,symbol2;

int main()
{
    system("color 4f");
    int player = 1, i;
    char choice;
    char mark; // mark will be either 'X' OR '0'
    //char asymbol, bsymbol;

    printf("\n\n\t\t\t\t\t\tTIC TAC TOE \n\n");
    //PlaySound(TEXT("C:\\Users\\Mominul Islam\\Desktop\\PRITY\\OS Project\\SOUNDS\\welcome.wav"), NULL, SND_SYNC);
    printf("ABOUT TIC-TAC-TOE:\n\nTic-Tac-Toe is a long beloved classic game for two players.\nThis simple and fun game is played on a 3x3 grid.\nVariations of Tic Tac Toe have been played since the Roman Empire\nand 3 in a row games can be traced all the way back to ancient Egypt!");
    printf("\n\n\nRULES OF TIC-TAC-TOE:\n\nEach player's goal is to make 3 in a row.\nPlayer-1 starts first on the first game and Player-2 starts first on the next game.\nThe starting player continues to alternate from game to game.\nThis helps keep gameplay fair over time.\n\nPlayers take turns placing their Mark, X or O, on an open square in the grid.\nThe first player to make 3 of their own mark in a row vertically, horizontally, or diagonally wins the game.\n\nIf all 9 squares are filled and neither player has 3 in a row, the game is considered a Tie.");
    printf("\n\n\n\nPRESS ENTER TO START THE GAME:\n");

    getch();
    system("cls");
    //printf("Symbols are:\n\n\t  1) X\n\t  2) 0\n");
    printf("\n\nChoose a symbol for the first player (between 'X' or '0'): ");
    //printf("\nEnter choice for the first player: ");
    scanf(" %c",&symbol1 );

    if(symbol1 == 'X' || symbol1 == 'x'){

        symbol1 = 'X';
        symbol2 = '0';
    }
    else{
        symbol1 = '0';
        symbol2 = 'X';
    }




    do{
      drawBoard();
    player = (player % 2) ? 1: 2;
      printf("\nplayer %d, Enter the choice: ", player);
      scanf(" %c", &choice);
      mark = (player == 1) ? symbol1 : symbol2;

      //s_a = asymbol;
      //s_b = bsymbol;


      /*if(player == 1)
        mark =  s_a;
      else
        mark = s_b;*/

      if(choice == '1' && square[1] == '1' )
        square[1] = mark;
        else if (choice == '2' && square[2] == '2' )
        square[2] = mark;
        else if (choice == '3' && square[3] == '3' )
        square[3] = mark;
        else if (choice == '4' && square[4] == '4' )
        square[4] = mark;
        else if (choice == '5' && square[5] == '5' )
        square[5] = mark;
        else if (choice == '6' && square[6] == '6' )
        square[6] = mark;
        else if (choice == '7' && square[7] == '7' )
        square[7] = mark;
        else if (choice == '8' && square[8] == '8' )
        square[8] = mark;
        else if (choice == '9' && square[9] == '9' )
        square[9] = mark;
        else
        {
            printf("\nINVALID OPTION !!!");
            PlaySound(TEXT("C:\\Users\\Mominul Islam\\Desktop\\PRITY\\OS Project\\SOUNDS\\error.wav"), NULL, SND_SYNC);
            player--;
            getch();
        }

        i = checkWinner();
        player++;

    }while(i == -1);

    drawBoard();

    if(i==1)
        {
        printf("\n==> PLAYER %d IS THE WINNER !!!\n", --player);
        PlaySound(TEXT("C:\\Users\\Mominul Islam\\Desktop\\PRITY\\OS Project\\SOUNDS\\win1.wav"), NULL, SND_SYNC);
        }
    else{
        printf("\n==> GAME DRAW !!!\n");
        PlaySound(TEXT("C:\\Users\\Mominul Islam\\Desktop\\PRITY\\OS Project\\SOUNDS\\draw.wav"), NULL, SND_SYNC);
    }
        getch();
        return 0;
}

int checkWinner()
{
    if(square[1] == square[2] && square[2] == square[3])
        return 1;
    else if(square[4] == square[5] && square[5] == square[6])
        return 1;
    else if(square[7] == square[8] && square[8] == square[9])
        return 1;
    else if(square[1] == square[4] && square[4] == square[7])
        return 1;
    else if(square[2] == square[5] && square[5] == square[8])
        return 1;
    else if(square[3] == square[6] && square[6] == square[9])
        return 1;
    else if(square[1] == square[5] && square[5] == square[9])
        return 1;
    else if(square[3] == square[5] && square[5] == square[7])
        return 1;
    else if(square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else
        return -1;
}




void drawBoard(){
    system("cls");
    printf("\nSo the symbol for the first player is '%c' and the symbol for the second player is '%c'\n", symbol1, symbol2);
    printf("\n\n\t\t\tPlayer-1 (%c) : Player-2 (%c) \n\n\n", symbol1, symbol2);

    printf("\n\n\t\t\t TIC TAC TOE BOARD\n\n\n");
    //printf("\t\t\t\t   |   |   \n");
    printf("\t\t\t\t %c | %C | %c  \n", square[1], square[2], square[3]);
    printf("\t\t\t\t___|___|___\n");
    printf("\t\t\t\t   |   |   \n");
    printf("\t\t\t\t %c | %C | %c  \n", square[4], square[5], square[6]);
    printf("\t\t\t\t___|___|___\n");
    printf("\t\t\t\t   |   |   \n");
    printf("\t\t\t\t %c | %C | %c  \n", square[7], square[8], square[9]);
    //printf("____|____|____\n");
    //printf("    |    |    \n");

}
