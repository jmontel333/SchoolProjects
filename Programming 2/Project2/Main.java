package sample;

import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Parent;
import javafx.scene.PointLight;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import javafx.util.Duration;

import javax.swing.*;
import java.util.Random;

import static javax.swing.JOptionPane.*;

public class Main extends Application {
    private int        diceTotal      = 12;
    private final int  NUMBER_OF_DICE = 2;
    private DieLabel[] myDiceSet      = new DieLabel[ NUMBER_OF_DICE + 1 ];
    int turnCount = 2;//allows for the turns to go back and forth between players

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("MP2GUI.fxml"));
        myDiceSet[1] = new DieLabel();
        myDiceSet[2] = new DieLabel();
        Label player1Score = (Label) root.lookup("#player1Score");
        Label player2Score = (Label) root.lookup("#player2Score");
        Button stopButton = (Button) root.lookup("#stopButton");
        Label turnScoreLabel = (Label) root.lookup("#turnScoreLabel");
        HBox dieLeft = (HBox) root.lookup("#dieLeft");
        dieLeft.getChildren().addAll(myDiceSet[1]);
        HBox dieRight = (HBox) root.lookup("#dieRight");
        dieRight.getChildren().addAll(myDiceSet[2]);
        Label resultLabel = (Label) root.lookup("#resultLabel");
        Button rollButton = (Button) root.lookup("#rollButton");
        primaryStage.setTitle("Roll 'em Pigs");
        primaryStage.setScene(new Scene(root, 600, 400));
        String playerUno = JOptionPane.showInputDialog("What is your name player one?", "");
        Label playerOne = (Label) root.lookup("#playerOne");
        String playerNumberTwo = JOptionPane.showInputDialog("What is your name player two?", "");
        Label playerTwo = (Label) root.lookup("#playerTwo");
        playerTwo.setText(playerNumberTwo);
        playerOne.setText(playerUno);
        primaryStage.show();
        Player player1 = new Player();
        Player player2 = new Player();
        playerOne.setTextFill(Color.RED);//gives player1 the first turn on the first game... player2 will go first in game 2
            rollButton.setOnAction((event) -> {//this handles the players rolling the die
                if(turnCount%2 == 0) {//player1's turn
                    Random random = new Random();//rolls the die
                    Timeline timeline = new Timeline(new KeyFrame(Duration.seconds(.1), (actionEvent) -> {
                        resultLabel.setText("Result is ... ");
                        if (myDiceSet[1].getText().equals(" ")) {
                            myDiceSet[1].rollDie();
                        }
                        if (myDiceSet[2].getText().equals(" ")) {
                            myDiceSet[2].rollDie();
                        }
                    }));

                    timeline.setCycleCount(random.nextInt(33) + 1);//animates the die roll
                    timeline.play();

                    timeline.setOnFinished(actionEvent -> {
                        diceTotal = 0;
                        for (int i = 1; i <= NUMBER_OF_DICE; i++) {//updates die total
                            //System.out.println("myDIceSet" + myDiceSet[i].getDieValue());
                            diceTotal += myDiceSet[i].getDieValue();
                        }
                        if (myDiceSet[1].getDieValue() + myDiceSet[2].getDieValue() == 2) {//checks if the game score needs reset
                            player1.turnScore = 0;
                            player1.score = 0;
                            player1Score.setText("" + player1.score);
                            turnCount++;
                            playerOne.setTextFill(Color.BLACK);
                            playerTwo.setTextFill(Color.RED);
                        }
                        else if (player1.isTurnScoreLost(myDiceSet[1].getDieValue(), myDiceSet[2].getDieValue())) {//checks if turn score is lost
                            player1.turnScore = 0;
                            turnCount++;
                            playerOne.setTextFill(Color.BLACK);
                            playerTwo.setTextFill(Color.RED);
                        } else {//if no 1s have been rolled score gets added on
                            player1.turnScore += diceTotal;
                            turnScoreLabel.setText("Turn total: " + player1.turnScore);
                        }
                        DieLabel.showDelayedMessage(resultLabel, "Result is " + diceTotal);
                    });
                }
                else if(turnCount%2 == 1) {//exactly the same and previous block just if player2's turn
                    Random random = new Random();
                    Timeline timeline = new Timeline(new KeyFrame(Duration.seconds(.1), (actionEvent) -> {

                        resultLabel.setText("Result is ... ");
                        if (myDiceSet[1].getText().equals(" ")) {
                            myDiceSet[1].rollDie();
                        }
                        if (myDiceSet[2].getText().equals(" ")) {
                            myDiceSet[2].rollDie();
                        }
                    }));
                    timeline.setCycleCount(random.nextInt(33) + 1);
                    timeline.play();
                    timeline.setOnFinished(actionEvent -> {
                        diceTotal = 0;
                        for (int i = 1; i <= NUMBER_OF_DICE; i++) {
                            //System.out.println("myDIceSet" + myDiceSet[i].getDieValue());
                            diceTotal += myDiceSet[i].getDieValue();
                        }
                        if (myDiceSet[1].getDieValue() + myDiceSet[2].getDieValue() == 2) {
                            player2.turnScore = 0;
                            player2.score = 0;
                            player2Score.setText("" + player2.score);
                            turnCount++;
                            playerTwo.setTextFill(Color.BLACK);
                            playerOne.setTextFill(Color.RED);
                        }
                        else if (player2.isTurnScoreLost(myDiceSet[1].getDieValue(), myDiceSet[2].getDieValue())) {
                            player2.turnScore = 0;
                            turnCount++;
                            playerTwo.setTextFill(Color.BLACK);
                            playerOne.setTextFill(Color.RED);
                        }  else {
                            player2.turnScore += diceTotal;
                            turnScoreLabel.setText("Turn total: " + player2.turnScore);
                        }
                        DieLabel.showDelayedMessage(resultLabel, "Result is " + diceTotal);
                    });
                }
            });
            stopButton.setOnAction((actionEvent ->{//if the player chooses to end their turn and "bank" their points this will handle that
                if(turnCount%2 == 0) {//if player1's turn
                    player1.score += player1.turnScore;//updates player score
                    player1Score.setText("" + player1.score);//updates scoreboard
                    player1.turnScore = 0;//resets turn score so it doesn't stack
                    turnCount++;
                    playerOne.setTextFill(Color.BLACK);//swaps the colors of the the turn indicator
                    playerTwo.setTextFill(Color.RED);
                    if (player1.hasWon()) {//if the game has been won sends out a popup and allows for a new game or ending the program
                        int a = JOptionPane.showConfirmDialog(null, "congrats " + playerUno + " you won, wanna play again?", "winner", YES_NO_OPTION);
                        if (a == YES_OPTION) {
                            player1.reset();
                            player2.reset();
                            player1Score.setText(""+player1.score);
                            player2Score.setText(""+player2.score);
                        }
                        if (a == NO_OPTION) {
                            System.exit(0);
                        }
                    }
                }
                else if(turnCount%2 == 1) {//same and previous if block just swapped to be player2's turn.
                    player2.score += player2.turnScore;
                    player2Score.setText("" + player2.score);
                    turnCount++;
                    player2.turnScore = 0;
                    playerTwo.setTextFill(Color.BLACK);
                    playerOne.setTextFill(Color.RED);
                    if (player2.hasWon()) {
                        int a = JOptionPane.showConfirmDialog(null, "congrats " + playerNumberTwo + " you won, wanna play again?", "winner", YES_NO_OPTION);
                        if (a == YES_OPTION) {
                            player1.reset();
                            player2.reset();
                            player1Score.setText(""+player1.score);
                            player2Score.setText(""+player2.score);
                        }
                        if (a == NO_OPTION) {
                            System.exit(0);
                        }
                    }
                }
            }));

        }


    public static void main(String[] args) {
        launch(args);
    }

}
