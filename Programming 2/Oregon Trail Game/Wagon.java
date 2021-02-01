package sample;

import java.io.File;
import java.io.Serializable;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Wagon
 * The trusty wagon a pioneer uses to travel the Oregon Trail.
 *
 * @author j-montel
 * @since 3/28/20
 */
public class Wagon implements Serializable {
    private static final int MAX_PACE = 3;
    private static final int MAX_DAY_DIST = 30;
    private int location;
    private int pace;


    /**
     * Create a new wagon at the start of the Oregon Trail.
     */
    public Wagon() {
        this.location = 0;
        this.pace = 2;
    }

    /**
     * Get the current location of the wagon along the Trail in miles.
     * @return              The current location of the wagon.
     */
    public int getLocation() { return this.location; }

    /**
     * sets wagon location
     * @param location the location your setting the wagon too
     */
    public void setLocation(int location){
        this.location = location;
    }

    /**
     * Get the pace the wagon is set to move at. The valid range is 0-3 (inclusive) and is used to calculate the
     * distance traveled in a day.
     * @return              The pace of the wagon as an int in the range 0-3 (inclusive).
     */
    public int getPace() { return this.pace; }

    /**
     * Set the wagon's traveling pace. Accepts paces in the range 0-3 (inclusive).
     * @param pace          The pace to set.
     * @return              True if the pace is within the valid range, false if not.
     */
    public boolean setPace(int pace) {
        if (pace > MAX_PACE || pace < 0) {
            return false;
        }
        this.pace = pace;
        return true;
    }

    /**
     * Move the wagon along the trail for a day. The wagon stops when it has moved an entire day or it reaches a fort or obstacle.
     * @param nextLandmark  The location of the next fort or obstacle.
     * @return              The distance the wagon traveled.
     */
    public int move(int nextLandmark) {
        int oldLocation = this.location;
        int distance = (MAX_DAY_DIST * this.pace) / MAX_PACE;
        this.location += distance;
        if (this.location > nextLandmark) {
            this.location = nextLandmark;
        }
        return this.location - oldLocation;
    }
}
