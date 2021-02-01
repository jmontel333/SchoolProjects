package sample;
import javafx.scene.control.ContentDisplay;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.*;
import javafx.geometry.Insets;
import javafx.scene.paint.Paint;
import java.util.Random;

class DieLabel extends Label{
    private Random      rand           	= new Random();
    private int         dieValue       	= 6;
    private final int   NUMBER_OF_SIDES	= 6;
    private Image[] 	dieImage		= new Image[ NUMBER_OF_SIDES + 1 ];
    private ImageView[] imageViews		= new ImageView[ NUMBER_OF_SIDES + 1 ];
    private boolean 	isHolding		= false;
    public DieLabel() {

        for ( int i = 1; i <= NUMBER_OF_SIDES; i++ ) {
            String filename = "\\sample\\die"+ i +".gif";
            dieImage[i] = new Image(filename);
            imageViews[i] = new ImageView(dieImage[i]);
        }
        setText(" ");
        setGraphic(imageViews[6]);
        setContentDisplay(ContentDisplay.TOP);
    }
    public int rollDie() {
        dieValue = rand.nextInt( NUMBER_OF_SIDES) + 1;
        setGraphic(imageViews[dieValue]);
        return dieValue;
    }
    public void holdDie(boolean v) {
        isHolding = v;
        if(isHolding == true) { setText("Held");}
        else {setText(" ");}
    }
    public int getDieValue() {
        return dieValue;
    }

    public boolean setDieValue( int value ) {
        if(value > 0 && value <= 6){
            dieValue = value;
            setGraphic(imageViews[value]);
            return true;
        }
        else{
            return false;
        }
    }
    public static void showDelayedMessage( Label widget, final String message ) {
        widget.setText( message );
    }

    public static void setDelayedForeground( Pane thePane,
                                             Paint  color ) {
        BackgroundFill bf = new BackgroundFill(color, CornerRadii.EMPTY, Insets.EMPTY);
        Background b = new Background(bf);
        thePane.setBackground(b);

    }
}
public class Player {
    private Random      rand           	= new Random();
    private final int   NUMBER_OF_SIDES	= 6;
    int intdie1;
    int intdie2;
    public int score = 99;
    public int turnScore = 0;
    DieLabel dieLabel = new DieLabel();

    /**
     * "rolls" 2 die
     * @param die1 value rollled by first die
     * @param die2 value rolled by 2nd die
     * @return returns their values added together
     */
    public int rollDice(DieLabel die1, DieLabel die2){
           intdie1 =  die1.rollDie();
           intdie2 =  die2.rollDie();
           return intdie1+intdie2;
    }

    /**
     * checks if the turn score is lost aka if the player rolled one 1
     * @return true if turn score lost false otherwise
     */
    public boolean isTurnScoreLost(){
        return intdie1 == 1 || intdie2 == 1;
    }

    /**
     * checks if the player has rolled a 1 losing their turn score
     * @param die1 value rolled by first die
     * @param die2 value rolled by 2nd die
     * @return true if turn score lost false otherwise
     * */
    public boolean isTurnScoreLost(int die1, int die2){
        return die1 == 1 || die2 == 1;
    }

    /**
     * checks if game score is lost aka 2 ones have been rolled
     * @return returns true if game score is lost false otherwise
     */
    public boolean isGameScoreLost(){
        return intdie1 == 1 && intdie2 == 1;
    }

    /**
     * checks if game score is lost aka 2 ones have been rolled
     * @param die1 value rolled by first die
     * @param die2 value rolled by 2nd die
     * @return true if game score lost false otherwise
     * */
    public boolean isGameScoreLost(int die1, int die2){
        return die1 == 1 && die2 == 1;
    }

    /**
     * checks if the player has won the game by amassing 100 or more points
     * @return returns true if the player has won false otherwise
     */
    public boolean hasWon(){
        return score >= 100;
    }

    /**
     * adds the players turn score to their game score
     * @return true if the game score changed false otherwise
     */
    public boolean addTurnScoreToGameScore(){
        score += turnScore;
        return turnScore > 0;
    }

    /**
     * gets the players turn score
     * @return the player's turn score
     */
    public int getTurnScore(){
        return turnScore;
    }

    /**
     * gets players game score
     * @return players game score
     */
    public int getGameScore(){
        return score;
    }

    /**
     * resets the game and turn score of the player (useful for creating new games)
     */
    public void reset(){
        score = 0;
        turnScore = 0;
    }

}
