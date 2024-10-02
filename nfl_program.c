#include <stdio.h>

void scoreCombos(int score, int *combo, int *countCombo, int n, int track);        //declares the function before its definition has been written

int main() {
    /*declares all the values that will be needed for the program*/
    int score;                                                         // set starting declaration to 2
    int combo[] = {8,7,6,3,2};                                         // These are the numerical score values from canvas, listed in an array
    int n = sizeof(combo) / sizeof(combo[0]);                          // This gives the length of the combo array so we can iterate through all 5 scoring options
    int countCombo[5] = {0};                                           // an array of 5 numbers all starting at 0
    
    while (1){
        printf("\nEnter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score == 0 || score == 1){
            break;
        }
        else{
        scoreCombos(score, combo, countCombo, n, 0);
        }
    }
    return 0;
}

/*Use recursion to find combinations of scores*/
void scoreCombos(int score, int *combo, int *countCombo, int n, int track){                     //recursive function
    if (score == 0) {                                                                           //base case
        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", countCombo[0], countCombo[1], countCombo[2], countCombo[3], countCombo[4]);
        return;
    }
    
    //Iteration
    for (int i = track; i<n; i++){
        if (score - combo[i] >= 0){             //checks to see if the score doesn't go negative after placing a value into TD, Safety, etc. 
            countCombo[i]++;                    //raises the value of countCombo array by 1 to track TD, safety, etc.
            scoreCombos(score - combo[i], combo, countCombo, n, i);     //re-iterate
            countCombo[i]--;
        }
    }
}

