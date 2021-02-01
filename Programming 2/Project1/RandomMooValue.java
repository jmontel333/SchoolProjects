package sample;

import java.util.concurrent.ThreadLocalRandom;

public class RandomMooValue {
    int[] guessArray = new int[4]; //array to hold the guesses
    boolean[] boolArrayForLocations = new boolean[] {true, true, true, true};//array to stop locations being used twice
    boolean[] boolArrayForNumbers = new boolean[] {true, true, true, true};//array to stop numbers from being used twice
    int[] secretNumberArray = new int[4];//holds the secret number
    int bigMoos = 0;//amount of big moos

    /**
     * will fill the secret number array with random numbers from 0-9
     * @param none
     * @return int array of secretNumberArray
     */
    public int[] RandomMooValue(){
        for(int j = 0; j < 4; j++) {
            secretNumberArray[j] = ThreadLocalRandom.current().nextInt(0, 9 + 1);//sets secret number array to random numbers 0-9
        }
        return secretNumberArray;
    }
    /**
    * will attain he big moo count from the guess
    * @return number of bigmoos
    * @param guess in integer form
     */
    public int getBigMooCount(int guess){
        String stringGuess = Integer.toString(guess);
        if(guess < 1000){
            if(guess < 100){
                if(guess < 10){
                    stringGuess = "000"+stringGuess;
                }
                stringGuess = "00"+stringGuess;
            }
            stringGuess = "0"+stringGuess;
        }//adds 0s onto the string to prevent out of range errors
        int firstNumber = Character.getNumericValue(stringGuess.charAt(0));
        int secondNumber = Character.getNumericValue(stringGuess.charAt(1));
        int thirdNumber = Character.getNumericValue(stringGuess.charAt(2));
        int fourthNumber = Character.getNumericValue(stringGuess.charAt(3));
        guessArray[0] = firstNumber;
        guessArray[1] = secondNumber;
        guessArray[2] = thirdNumber;
        guessArray[3] = fourthNumber;
        for(int j = 0; j<4;j++) {//checks entire array for bigMoos
        if(secretNumberArray[j] == guessArray[j]){
            boolArrayForNumbers[j] = false;//sets these to false to help with little moo counting
            boolArrayForLocations[j] = false;//sets these to false to help with little moo counting
            bigMoos++;
        }
        }
        return bigMoos;
    }

    /**
     * will count up the little moos from the guess
     * @param guess
     * @return little moos in integer form
     */
    public int getLittleMooCount(int guess){
        int littleMoos = 0;
        String stringGuess = Integer.toString(guess);
        if(guess < 1000){
            if(guess < 100){
                if(guess < 10){
                    stringGuess = "000"+stringGuess;
                }
                stringGuess = "00"+stringGuess;
            }
            stringGuess = "0"+stringGuess;
        }//adds 0 back onto the string to prevent range errors
        int firstNumber = Character.getNumericValue(stringGuess.charAt(0));
        int secondNumber = Character.getNumericValue(stringGuess.charAt(1));
        int thirdNumber = Character.getNumericValue(stringGuess.charAt(2));
        int fourthNumber = Character.getNumericValue(stringGuess.charAt(3));
        guessArray[0] = firstNumber;
        guessArray[1] = secondNumber;
        guessArray[2] = thirdNumber;
        guessArray[3] = fourthNumber;
        if(boolArrayForLocations[3]) {//checks position 3 of the array for little moos (as long as position 3 is available)
            for(int j = 0; j<4; j++)
            {
                if(boolArrayForNumbers[j]) {
                    if (j != 3) {
                        if (guessArray[j] == secretNumberArray[3]) {
                            littleMoos++;
                            boolArrayForNumbers[j] = false;
                        }
                    }
                }
            }
        }
        if(boolArrayForLocations[0]) {//checks position 0 of the array for little moos (as long as position 0 is available)
            for(int j = 0; j<4; j++) {
                if (boolArrayForNumbers[j]) {
                    if (j != 0) {
                        if (guessArray[j] == secretNumberArray[0]) {
                            littleMoos++;
                            boolArrayForNumbers[j] = false;
                            break;
                        }
                    }
                }
            }
        }
        if(boolArrayForLocations[1]) {//checks position 1 of the array for little moos (as long as position 1 is available)
            for(int j = 0; j<4; j++)
            {
                if(boolArrayForNumbers[j]) {
                    if (j != 1) {
                        if (guessArray[j] == secretNumberArray[1]) {
                            littleMoos++;
                            boolArrayForNumbers[j] = false;
                            break;
                        }
                    }
                }
            }
        }
        if(boolArrayForLocations[2]) {//checks position 2 of the array for little moos (as long as position 2 is available)
            for(int j = 0; j<4; j++)
            {
                if(boolArrayForNumbers[j]) {
                    if (j != 2) {
                        if (guessArray[j] == secretNumberArray[2]) {
                            littleMoos++;
                            boolArrayForNumbers[j] = false;
                            break;
                        }
                    }
                }
            }
        }
        return littleMoos;
    }

    /**
     * returns the secret number in integer form
     * @return the secret number
     */
    public int getSecretValue(){
        return (secretNumberArray[0]*1000)+(secretNumberArray[1]*100)+(secretNumberArray[2]*10)+(secretNumberArray[3]);
    }
    /**
     * fills the secret array with random numbers 0-9 in each spot
     * @param none
     * @return the newly filled secret array
     */
    public boolean setSecretValue(){
        for(int j = 0; j < 4; j++) {
            secretNumberArray[j] = ThreadLocalRandom.current().nextInt(0, 9 + 1);
        }
        return true;
    }
    /**
     * fills the secret array with integer n in the individual spots
     * @param int n which is what the seret value will be set to
     * @return the newly filled secret array
     */
    public boolean setSecretValue(int n){
        if(n>999 && n <= 9999){
            secretNumberArray[3] =  n %10;
            n = n/10;
            secretNumberArray[2] = n%10;
            n = n/10;
            secretNumberArray[1] = n%10;
            n = n/10;
            secretNumberArray[0] = n%10;
            return true;
        }
        if(n>99 && n<=999)
        {
            secretNumberArray[3] =  n %10;
            n = n/10;
            secretNumberArray[2] = n%10;
            n = n/10;
            secretNumberArray[1] = n%10;
            secretNumberArray[0] = 0;
            return true;
        }
        if(n>9 && n<=99)
        {
            secretNumberArray[3] =  n %10;
            n = n/10;
            secretNumberArray[2] = n%10;
            secretNumberArray[1] = 0;
            secretNumberArray[0] = 0;
            return true;
        }
        if(n>=0 && n <=9)
        {
            secretNumberArray[3] =  n %10;
            secretNumberArray[2] = 0;
            secretNumberArray[1] = 0;
            secretNumberArray[0] = 0;
            return true;
        }
        return false;
    }

    /**
     * will check if the users guess is correct
     * @param guess- the users guess
     * @return returns true if guess is correct false otherwise
     */
    public boolean isCorrectGuess(int guess)
    {

        {
            if(guess == getSecretValue())
            return true;
        }
            return false;
    }

    /**
     * will reset all the needed values for the turn
     * @param none
     * @return none
     */
    public void newTurn()
    {
        bigMoos = 0;
        for(int j = 0; j<4;j++)
        {
            guessArray[j] = 0;
            boolArrayForLocations[j] = true;//reopens all the spaces
            boolArrayForNumbers[j] = true;
            for(int i = 0; i < 4; i++) {
                secretNumberArray[i] = ThreadLocalRandom.current().nextInt(0, 9 + 1);//new random number
            }
        }
    }

    /**
     * resets the moo values so that they don't stack across turns... also resets location and number arrays
     */
    public void resetMoos(){
        bigMoos = 0;
        for(int j = 0; j<4;j++)
        {
            boolArrayForLocations[j] = true;
            boolArrayForNumbers[j] = true;
        }
    }
}
