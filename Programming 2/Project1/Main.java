package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.TextField;
import javafx.stage.Stage;
import javafx.scene.control.Label;
import javafx.scene.control.Button;

import javax.swing.*;

import static javax.swing.JOptionPane.showConfirmDialog;

public class Main extends Application {
    int turnCounter = 0;                                                                //int that caps users turns at 10
    RandomMooValue turn = new RandomMooValue();
    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("MP1UI.fxml"));
        primaryStage.setTitle("MOOmoo");
        primaryStage.setScene(new Scene(root, 350, 300));
        primaryStage.show();
        Button randomButton = (Button) root.lookup("#randomButton");
        Label mooDisplayer = (Label) root.lookup("#mooDisplayer");
        Label winOrLoseDisplay = (Label) root.lookup("#winOrLoseDisplay");
        Label previousGuesses = (Label) root.lookup("#previousGuesses");
        Label numberofGuesses = (Label) root.lookup("#numberOfGuesses");
        TextField guessTextField = (TextField) root.lookup("#guessTextField");
        turn.setSecretValue();                                                          //randomizes the secret value
        guessTextField.setOnAction(event ->
        {
            turnCounter++;                                                             //incriments the turn
            numberofGuesses.setText(""+turnCounter);
            String stringGuess = guessTextField.getText();
            int guess = Integer.parseInt(stringGuess);


            int bigMoo = turn.getBigMooCount(guess);                                    //gets number of moos
            int littleMoo = turn.getLittleMooCount(guess);


            mooDisplayer.setText(""+ "MOO! " + bigMoo   + "moo " + littleMoo);//displays moos if any
            if(littleMoo == 0 && bigMoo == 0)                                           //displays cowbells if no moos
            {
                mooDisplayer.setText("you hear nothing but cowbells");
            }
            if(turn.isCorrectGuess(guess))                                              //ends game if guess is correct
            {
                winOrLoseDisplay.setText("LaurieMOO!");
               int win = JOptionPane.showConfirmDialog(null,"LaurieMOO!! would you like to play again?");
                if(win == JOptionPane.YES_OPTION)                                       //creates a popup that asks the user if they wish to play again will exit if they say no
                {
                    turn.newTurn();
                    turnCounter = 0;
                    numberofGuesses.setText(""+turnCounter);
                    mooDisplayer.setText("-");
                    winOrLoseDisplay.setText("-");
                    turn.resetMoos();
                }
                else
                {
                  System.exit(0);
                }
            }
            if(turnCounter == 10) {                                                     //ends game if turns reach 10, same window as before but says that they lost the game
                winOrLoseDisplay.setText("Boo hoo -- no LaurieMOO: " + turn.getSecretValue());
                int lose = showConfirmDialog(null, "Boo hoo -- no LaurieMOO: " + turn.getSecretValue() + " would you like to play again?");
                if(lose == JOptionPane.YES_OPTION){
                    turn.newTurn();
                    turnCounter = 0;
                    numberofGuesses.setText(""+turnCounter);
                    mooDisplayer.setText("-");
                    winOrLoseDisplay.setText("-");
                    turn.resetMoos();;
                }
                else
                {
                    System.exit(0);
                }
           }
            turn.resetMoos();                                                            //resets moos inbetween guesses
        });
       randomButton.setOnAction(actionEvent ->{                                          //resests game if they press the new game button
           turn.newTurn();
           turnCounter = 0;
           numberofGuesses.setText(""+turnCounter);
           mooDisplayer.setText("-");
           winOrLoseDisplay.setText("-");
       });
    }



    public static void main(String[] args) { launch(args);


    }


}