package sample;

import java.io.Serializable;

/**
 * Landmark
 * The parent class for Obstacle and Fort
 *
 * @author J-Montel
 * @since 3/20/2020
 */
public class Landmark implements Serializable {

    private String name;
    private int location;

    public Landmark(String name, int location){
        this.name = name;
        this.location = location;
    }
    /**
     *
     * @return the location as an int of miles
     */
    public int getLocation() {
        return location;
    }

    /**
     *
     * @return the string name.
     */
    public String getName() {
        return name;
    }

    private void setLocation(int location){
        this.location = location;
    }
}
