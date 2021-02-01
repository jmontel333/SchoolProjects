package sample;

import java.io.Serializable;
import java.util.ArrayList;

/**
 * SaveData
 * Allows for the game to be saved and restored
 *
 * @author J-Montel
 * @since 5/1/20
 */

public class SaveData implements Serializable {

    //fields
    private double[] money;
    private ArrayList<Item> playerItems;
    private int location;

    //constructors
    SaveData(){};

    SaveData(double[] money, ArrayList<Item> playerItems, int location){
        this.money = money;
        this.playerItems = playerItems;
        this.location = location;
    }

    //functions

    //getters

    /**
     *
     * @return money
     */
    public double getMoney() {
        return money[0];
    }

    /**
     *
     * @return location
     */
    public int getLocation() {
        return location;
    }

    /**
     *
     * @return playeritems
     */
    public ArrayList<Item> getPlayerItems() {
        return playerItems;
    }

    //setters

    /**
     * sets location
     * @param location as an int
     */
    public void setLocation(int location) {
        this.location = location;
    }

    /**
     * sets the player item array- useful for restoring game
     * @param playerItems- as an array
     */
    public void setPlayerItems(ArrayList<Item> playerItems) {
        this.playerItems = playerItems;
    }

    /**
     * sets the money to the first value in array
     * @param money as an array
     */
    public void setMoney(double[] money) {
        this.money = money;
    }
}
