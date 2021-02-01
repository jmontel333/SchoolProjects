package sample;

import java.io.Serializable;
import java.util.ArrayList;

/**
 * Fort
 * The forts along the Oregon Trail that pioneers would use to purchase supplies and rest in safety.
 *
 * @author C-Zimmerman
 * @since 3/25/20
 */
public class Fort extends Landmark implements Serializable {
    private final int ITEM_LIMIT = 100;

    /**
     * Create a new fort with a name, location along the trail in miles, and given assortment of items to purchase.
     *
     * @param name          The name of the fort as a String.
     * @param location      The location of the fort as an int.
     */
    public Fort(String name, int location) {
        super(name,location);
    }
}
