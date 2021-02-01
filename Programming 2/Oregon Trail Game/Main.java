package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.*;
import java.io.*;
import java.util.ArrayList;
import java.util.Optional;
import java.util.Scanner;

/**
 * Main
 * The main class of Oregon Trail
 */
public class Main extends Application {
    private SaveData restore, save;
    Label foodCountLabel;
    Label ammoCountLabel;
    Label moneyCountLabel;
    @Override
    public void start(Stage primaryStage) throws Exception {

        //array list of the players items
        ArrayList<Item> playerItems = new ArrayList<>();

        // Useful constants
        final int NUM_BUTTONS = 4;
        final int TRAIL_LENGTH = 2170;
        final double CROSSING_COST = 10.0;                                                                              // The price to cross an Obstacle with hired help

        // Constants used for setting pace and rations
        final int LOW = 1;
        final int MEDIUM = 2;
        final int HIGH = 3;

        double[] money = {800.0};                                                                                       // The starting money the player is given


        // Initializing UI elements
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        foodCountLabel = (Label) root.lookup("#foodCountLabel");
        ammoCountLabel = (Label) root.lookup("#ammoCountLabel");
        moneyCountLabel = (Label) root.lookup("#moneyCountLabel");
        Label distanceLabel = (Label) root.lookup("#distanceLabel");
        Label statusLabel = (Label) root.lookup("#statusLabel");
        Label outputLabel = (Label) root.lookup("#outputLabel");
        TextField inputField = (TextField) root.lookup("#inputField");
        ComboBox optionBox = (ComboBox) root.lookup("#optionBox");
        String statusLabelDef =("You are moving along the trail with: ");                                             // The default message to display on the status label

        //adding a FileChooser to load and save games
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Otrail Games");
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("SER files", "*.ser")
        );

        // Using for loop to create Buttons because I can
        Button[] buttons = new Button[NUM_BUTTONS];
        for (int i = 0; i < NUM_BUTTONS; i++) {
            buttons[i] = (Button) root.lookup(String.format("#button%d", i));
        }
        //creating the rest of the buttons
        Button saveButton = (Button) root.lookup("#saveButton");
        Button restoreButton = (Button) root.lookup("#restoreButton");
        Button aboutButton = (Button) root.lookup("#aboutButton");

        // Importing asset data from CSV files

        // Create the list of items a pioneer would take on the journey to Oregon
        // Importing the valid Items
        ArrayList<Item> items = new ArrayList<Item>();

        // Create an InputStreamReader to read in the data file for Items
        InputStreamReader itemIsr = null;
        try {
            itemIsr = new InputStreamReader(this.getClass().getResourceAsStream("/assets/Items.csv"));
        } catch (Exception e) {
            System.exit(1);
        }

        // Create a Scanner to read in individual data for setting up Items
        Scanner itemScr = new Scanner(itemIsr);

        // Take the first line of the text file and discard it because it is just a header
        String itemHeader = itemScr.nextLine();

        // Read from the Items file until it runs out of data
        while (itemScr.hasNext()) {

            // Create a Scanner to process the individual line of data
            Scanner itemData = new Scanner(itemScr.nextLine());
            itemData.useDelimiter(",");
            String type = itemData.next();
            double price = itemData.nextDouble();

            // Create a new Item based on the file data and add it to the list of existing Items
            Item newItem = new Item(type, price, 0);
            items.add(newItem);
            itemData.close();
        }
        itemScr.close();

        // Enter all items into a ComboBox that will be used for purchasing the items
        for (int i = 0; i < items.size(); i++) {
            optionBox.getItems().add(String.format("%s: $%.2f", items.get(i).getType(), items.get(i).getPrice()));
        }

        // Create the many Forts a pioneer would visit along the Trail
        // Importing the Forts
        ArrayList<Landmark> forts = new ArrayList<Landmark>();

        // Create an InputStreamReader to read in the data file for Forts
        InputStreamReader fortIsr = null;
        try {
            fortIsr = new InputStreamReader(this.getClass().getResourceAsStream("/assets/Forts.csv"));
        } catch (Exception e) {
            System.exit(2);
        }

        // Create a Scanner to read in individual data for setting up Forts
        Scanner fortScr = new Scanner(fortIsr);

        // Take the first line of the text file and discard it because it is just a header
        String fortHeader = fortScr.nextLine();

        // Read from the Forts file until it runs out of data
        while (fortScr.hasNext()) {

            // Create a Scanner to process the individual line of data
            Scanner fortData = new Scanner(fortScr.nextLine());
            fortData.useDelimiter(",");
            String name = fortData.next();
            int location = fortData.nextInt();

            // Create a new Fort based on the file data and add it to the list of existing Forts
            Fort newFort = new Fort(name, location);
            forts.add(newFort);
            fortData.close();
        }
        fortScr.close();

        // Create all the Obstacles a pioneer would have to cross to get to Oregon
        // Importing the Obstacles
        ArrayList<Landmark> obstacles = new ArrayList<Landmark>();

        // Create an InputStreamReader to read in the data file for Obstacles
        InputStreamReader obstacleIsr = null;
        try {
            obstacleIsr = new InputStreamReader(this.getClass().getResourceAsStream("/assets/Obstacles.csv"));
        } catch (Exception e) {
            System.exit(3);
        }

        // Create a Scanner to read in individual data for setting up Obstacles
        Scanner obstacleScr = new Scanner(obstacleIsr);

        // Take the first line of the text file and discard it because it is just a header
        String obstacleHeader = obstacleScr.nextLine();

        // Read from the Obstacles file until it runs out of data
        while (obstacleScr.hasNext()) {

            // Create a Scanner to process the individual line of data
            Scanner obstacleData = new Scanner(obstacleScr.nextLine());
            obstacleData.useDelimiter(",");
            String name = obstacleData.next();
            int location = obstacleData.nextInt();
            int weightLimit = obstacleData.nextInt();

            // Create a new Obstacle based on the file data and add it to the list of existing Obstacles
            Obstacle newObstacle = new Obstacle(name, location, weightLimit);
            obstacles.add(newObstacle);
            obstacleData.close();
        }
        obstacleScr.close();

        // Create all the people a pioneer would travel with
        // Importing the People
        ArrayList<Person> people = new ArrayList<Person>();

        // Create an InputStreamReader to read in the Person data file
        InputStreamReader personIsr = null;
        try {
            personIsr = new InputStreamReader(this.getClass().getResourceAsStream("/assets/People.csv"));
        } catch (Exception e) {
            System.exit(4);
        }

        // Create a Scanner to read in individual data for setting up a Person
        Scanner personScr = new Scanner(personIsr);

        // Take the first line of the text file and discard it because it is just a header
        String personHeader = personScr.nextLine();

        // Read from the Person file until it runs out of data
        while (personScr.hasNext()) {

            // Create a Scanner to process the individual line of data
            Scanner personData = new Scanner(personScr.nextLine());
            personData.useDelimiter(",");
            String name = personData.next();
            String relation = personData.next();
            boolean isDiseased = Boolean.parseBoolean(personData.next());

            // Create a new Person based on the file data and add it to the list of existing People
            Person newPerson = new Person(name, relation, isDiseased);
            people.add(newPerson);
            personData.close();
        }
        personScr.close();

        // Create the Wagon the pioneers would take on their journey to Oregon
        Wagon wagon = new Wagon();

        // This stuff happens. Nobody ever told me how it works
        primaryStage.setTitle("Oregon Trail");
        primaryStage.setScene(new Scene(root, 500, 500));
        primaryStage.show();

        // Setting up the UI for the beginning of the simulation
        setButtons(buttons, "Buy Items");
        outputLabel.setText("Buy supplies to take on your journey to Oregon.");
        statusLabel.setText("You are stopped at " + forts.get(0).getName());
        playerItems.add(items.get(0));
        playerItems.add(items.get(1));

        // Top left Button EventHandler
        buttons[0].setOnAction(event -> {

            // Get the text currently displayed on the Button and use that to determine the function
            String buttonText = buttons[0].getText();
            setButtons(buttons, buttonText);
            switch (buttonText) {
                case "Move":

                    //kills player if they run out of food
                    for(int j= 0; j<playerItems.size(); j++){
                        if(playerItems.get(j).getType().equals("Food")){
                            playerItems.get(j).setQuantity(playerItems.get(j).getQuantity()-wagon.getPace()*3);
                            foodCountLabel.setText(playerItems.get(j).getQuantity()+"");
                            if(playerItems.get(j).getQuantity()<=0){
                                final Stage lose = new Stage();
                                lose.setTitle("loser!");
                                lose.initModality(Modality.APPLICATION_MODAL);
                                lose.initOwner(primaryStage);
                                VBox loseVBox = new VBox();
                                loseVBox.getChildren().add(new Text("you starved to death yikes"));
                                Scene loseScene = new Scene(loseVBox, 500, 500);
                                lose.setScene(loseScene);
                                lose.showAndWait();
                                System.exit(0);
                            }
                        }
                    }

                    // Find the next Fort and Obstacle the Wagon will arrive at
                    Landmark nextFort = findNext(wagon.getLocation(), forts);
                    Landmark nextObstacle = findNext(wagon.getLocation(), obstacles);

                    // Determine if the Wagon will reach the Fort or the Obstacle first and move the Wagon accordingly
                    if (nextObstacle.getLocation() < nextFort.getLocation()) {
                        wagon.move(nextObstacle.getLocation());
                    } else {
                        wagon.move(nextFort.getLocation());
                    }

                    // Update the text labels so the user knows what happened
                    distanceLabel.setText((TRAIL_LENGTH - wagon.getLocation()) + " miles to Oregon");
                    statusLabel.setText(statusLabelDef.toString());

                    //checks if you have won the game
                    if(wagon.getLocation() >= TRAIL_LENGTH){
                        final Stage win = new Stage();
                        win.setTitle("winner!");
                        win.initModality(Modality.APPLICATION_MODAL);
                        win.initOwner(primaryStage);
                        VBox winVBox = new VBox();
                        winVBox.getChildren().add(new Text("you have won congrats!!"));
                        Scene winScene = new Scene(winVBox, 500, 500);
                        win.setScene(winScene);
                        win.showAndWait();
                        System.exit(0);
                    }

                    // Check if the Wagon moved to an Obstacle and update the Buttons accordingly
                    if (wagon.getLocation() == nextObstacle.getLocation()) {
                        // Assume the Wagon moved to an Obstacle to save code
                        setButtons(buttons, "Stopped at Obstacle");
                        statusLabel.setText("You are stopped at the " + nextObstacle.getName());
                    }
                    // Check if the Wagon moved to a Fort and update the Buttons accordingly
                    else if (wagon.getLocation() == nextFort.getLocation()) {
                        setButtons(buttons, "Stopped at Fort");
                        statusLabel.setText("You are stopped at " + nextFort.getName());
                    }
                    break;
                case "Buy Items":
                    outputLabel.setText("Buy supplies to take on your journey to Oregon.");
                    inputField.setDisable(false);
                    optionBox.setDisable(false);
                    break;
                case "Cross Over":
                    // Find the Obstacle the wagon is at and try to cross it
                    Obstacle thisObstacle = (Obstacle) findNext(wagon.getLocation() - 1, obstacles);          // Subtracted 1 from wagon location so it doesn't skip to the next Obstacle

                    // Cross the Obstacle and see if the crossing was successful or not
                    if (thisObstacle.crossObstacle(items)) {
                        outputLabel.setText("You made the crossing successfully");
                    } else {
                        outputLabel.setText("You underestimated the " + thisObstacle.getName() + " and lost some supplies");
                        updateCounts(playerItems,money[0]);
                    }

                    // Update the Buttons
                    setButtons(buttons, "Moving");
                    break;
                case "Slow":
                    // Set a slow pace and keep moving.
                    setButtons(buttons, "Moving");
                    wagon.setPace(LOW);
                    break;
            }
        });

        // Top right Button EventHandler
        buttons[1].setOnAction(event -> {

            // Get the text currently displayed on the Button and use that to determine the function
            String buttonText = buttons[1].getText();
            setButtons(buttons, buttonText);
            switch (buttonText) {
                case "Meet the Locals":
                    // Realize that this functionality hasn't been implemented so I put something humorous instead
                    outputLabel.setText("Your social anxiety prevents you from interacting with the locals");
                    break;
                case "Check Weight Limit":
                    // Find the Obstacle the wagon is at and display its weight limit
                    Obstacle thisObstacle = (Obstacle) findNext(wagon.getLocation() - 1, obstacles);          // Subtracted 1 from wagon location so it doesn't skip to the next Obstacle
                    outputLabel.setText("The " + thisObstacle.getName() + " can be crossed with " +
                            thisObstacle.getWeightLimit() + " or fewer items");
                    break;
                case "Medium":
                    // Set a medium pace and keep moving
                    setButtons(buttons, "Moving");
                    wagon.setPace(MEDIUM);
                    break;
            }
        });

        // Bottom left Button EventHandler
        buttons[2].setOnAction(event -> {

            // Get the text currently displayed on the Button and use that to determine the function
            String buttonText = buttons[2].getText();
            setButtons(buttons, buttonText);
            switch (buttonText) {
                case "Check Supplies":
                    // Output all the items in the pioneer's wagon
                    statusLabel.setText("Supplies:\n");
                    for (int i = 0; i < playerItems.size(); i++) {
                        statusLabel.setText(statusLabel.getText() + playerItems.get(i).getType() +
                                ": " + playerItems.get(i).getQuantity() + " units\n");
                    }
                    break;
                case "Fast":
                    // Set a high pace and keep moving.
                    setButtons(buttons, "Moving");
                    wagon.setPace(HIGH);
                    break;
                case "Go Hunting":
                    //player selects amount of bullets and goes hunting
                    TextInputDialog huntingDialog = new TextInputDialog();
                    huntingDialog.setTitle("hunting");
                    huntingDialog.setHeaderText("how many bullets would you like to use on your hunt?");
                    huntingDialog.setContentText("bullets: ");
                    Optional<String> bulletString = huntingDialog.showAndWait();
                    String bulletResult = bulletString.get();
                    int bullet = Integer.parseInt(String.valueOf(bulletResult));
                    for(int j= 0; j<playerItems.size(); j++){
                    if(playerItems.get(j).getType().equals("Ammunition")) {
                        if (bullet <= playerItems.get(j).getQuantity()) {
                            playerItems.get(j).setQuantity(playerItems.get(j).getQuantity() - bullet);
                            for(int i= 0; i<playerItems.size(); i++){
                                if(playerItems.get(i).getType().equals("Food")) {
                                    playerItems.get(i).setQuantity(playerItems.get(i).getQuantity() + ((Integer) bullet*10));
                                    outputLabel.setText("you came back with " + ((Integer) bullet*10) + " pieces of food");
                                }
                            }
                        }
                        else{
                            outputLabel.setText("you don't have that many bullets");
                        }
                    }
                    }
                    updateCounts(playerItems,money[0]);
                    break;
            }
        });

        // Bottom right Button EventHandler
        buttons[3].setOnAction(event -> {

            // Get the text currently displayed on the Button and use that to determine the function
            String buttonText = buttons[3].getText();
            setButtons(buttons, buttonText);
            switch (buttonText) {
                case "Check the Map":
                    Landmark nextFort = findNext(wagon.getLocation(), forts);
                    int distance = nextFort.getLocation() - wagon.getLocation();
                    outputLabel.setText("The next fort is " + distance + " miles away");
                    break;
                case "Keep Moving":
                    // Update the Buttons and Labels
                    setButtons(buttons, "Moving");
                    statusLabel.setText(statusLabelDef.toString());
                    break;
                case "Leave the Shop":
                    // Update the Buttons and Labels
                    setButtons(buttons, "Stopped at Fort");
                    statusLabel.setText("You are stopped at a fort");
                    inputField.setDisable(true);
                    optionBox.setDisable(true);
                    break;
                case "Pay Someone to Help":
                    // Cross the Obstacle without checking whether the wagon can cross on its own.
                    outputLabel.setText(String.format("You payed $%.2f and made the crossing successfully", CROSSING_COST));
                    statusLabel.setText(statusLabelDef.toString());
                    money[0] -= CROSSING_COST;
                    setButtons(buttons, "Moving");
                    updateCounts(playerItems,money[0]);
                    break;
            }
        });

        inputField.setOnAction(event -> {

            // Process input for purchasing Items
            String input = inputField.getText();
            try {
                int numItems = Integer.parseInt(input);
                String choice = (String) optionBox.getValue();
                int indexOfColon = choice.indexOf(':');
                if (indexOfColon > 0) {

                    // Check the selected Item against all the existing Items
                    String itemName = choice.substring(0, indexOfColon);
                    Item toBuy = null;
                    for (int i = 0; i < items.size(); i++) {
                        toBuy = items.get(i);
                        if (toBuy.getType().equals(itemName)) {

                            // Buy the Items that match the choice
                            money[0] = toBuy.buyItem(money[0], numItems);
                            Item bought = (items.get(i));
                            if (playerHasItem(playerItems, itemName)) {
                                for (int j = 0; j < playerItems.size(); j++) {
                                    if (playerItems.get(j).getType().equals(itemName)) {
                                        playerItems.get(j).setQuantity(toBuy.getQuantity());
                                    }
                                }
                            }
                            else{
                                bought.setQuantity(toBuy.getQuantity());
                                playerItems.add(toBuy);

                            }
                            updateCounts(playerItems,money[0]);
                        }
                    }
                } else {
                    outputLabel.setText("Not a valid choice");
                }
            } catch (NumberFormatException nfe) {
                outputLabel.setText("Enter a valid number");
            }
            inputField.setText("");
        });

        //handling the about button
        aboutButton.setOnAction(actionEvent ->{
            final Stage aboutDialog = new Stage();
            aboutDialog.initModality(Modality.APPLICATION_MODAL);
            aboutDialog.initOwner(primaryStage);
            VBox aboutVBox = new VBox();
            aboutVBox.getChildren().add(new Text("-- About the Author --\n" +
                    "This program was written by Jesse Montel \n" +
                    "Jesse is currently a Freshman Programing student attending Ohio Northern University \n" +
                    "This is Jesse's first large length program written in java \n" +
                    "The author wishes Dr. Estell and Dr. Stephany a great and safe summer \n" +
                    "to close this dialog simply click the 'x' in the upper right of the box"));
            Scene aboutScene = new Scene(aboutVBox, 500, 500);
            aboutDialog.setScene(aboutScene);
            aboutDialog.setTitle("||About||");
            aboutDialog.show();
        });

        //implements the save button
        saveButton.setOnAction(actionEvent -> {
            save = new SaveData(money,playerItems,wagon.getLocation());
            File selectedFile = fileChooser.showSaveDialog(primaryStage);
            try {
                FileOutputStream fs = new FileOutputStream(selectedFile);
                ObjectOutputStream os = new ObjectOutputStream(fs);
                os.writeObject(save);
                os.close();
            } catch (IOException e) { e.printStackTrace(); }
        });

        //implements the restore button
        restoreButton.setOnAction(actionEvent -> {
            File selectedFile = fileChooser.showOpenDialog(primaryStage);
            try{
                FileInputStream is = new FileInputStream(selectedFile);
                ObjectInputStream oi = new ObjectInputStream(is);
                restore = (SaveData) oi.readObject();
                oi.close();
                money[0] = restore.getMoney();
                wagon.setLocation(restore.getLocation());
                playerItems.addAll(restore.getPlayerItems());
                distanceLabel.setText((TRAIL_LENGTH - wagon.getLocation()) + " miles to Oregon");
                statusLabel.setText(statusLabelDef);
                updateCounts(playerItems,money[0]);
                setButtons(buttons,"Moving");
                // moves wagon back one to check if the wagon is currently at a fort when the game is loaded in
                Landmark nextFort = findNext(wagon.getLocation()-1, forts);
                Landmark nextObstacle = findNext(wagon.getLocation()-1, obstacles);
                // Check if the Wagon moved to an Obstacle and update the Buttons accordingly
                if (wagon.getLocation() == nextObstacle.getLocation()) {
                    // Assume the Wagon moved to an Obstacle to save code
                    setButtons(buttons, "Stopped at Obstacle");
                    statusLabel.setText("You are stopped at the " + nextObstacle.getName() + "\n with " +
                            numOfItemsInInventory(playerItems) + " items " + playerItems.size());
                }
                // Check if the Wagon moved to a Fort and update the Buttons accordingly
                else if (wagon.getLocation() == nextFort.getLocation()) {
                    setButtons(buttons, "Stopped at Fort");
                    statusLabel.setText("You are stopped at " + nextFort.getName());
                }
            }
            catch (Exception e) {e.printStackTrace();}
        });
    }

    /**
     * Update the UI Buttons based on the state of the game.
     *
     * @param buttons The array of Buttons to update. Contains 4 elements.
     * @param state   A String representing the state the menu needs to represent.
     */
    public void setButtons(Button[] buttons, String state) {
        // Switch through all the possible Strings that can be entered
        switch (state) {
            case "Moving":
                // Button functions while the Wagon is on the open trail
                buttons[0].setText("Move");
                buttons[1].setText("Set Pace");
                buttons[2].setText("Go Hunting");
                buttons[3].setText("Check the Map");
                break;
            case "Stopped at Fort":
                // Button functions when the Wagon is stopped at a Fort
                buttons[0].setText("Buy Items");
                buttons[1].setText("");
                buttons[2].setText("");
                buttons[3].setText("Keep Moving");
                break;
            case "Buy Items":
                // Button functions when the user decides to buy Items
                buttons[0].setText("");
                buttons[1].setText("");
                buttons[2].setText("");
                buttons[3].setText("Leave the Shop");
                break;
            case "Stopped at Obstacle":
                // Button functions when the Wagon is stopped at an Obstacle
                buttons[0].setText("Cross Over");
                buttons[1].setText("Check Weight Limit");
                buttons[2].setText("");
                buttons[3].setText("Pay Someone to Help");
                break;
            case "Set Pace":
                // Button functions when the user wants to change the Wagon's pace
                buttons[0].setText("Slow");
                buttons[1].setText("Medium");
                buttons[2].setText("Fast");
                buttons[3].setText("");
                break;
            default:
                return;
        }
    }

    /**
     * Find the next Landmark that the Wagon will arrive at. Assumes the ArrayList is properly
     * sorted and the CSV that was loaded was formatted with Landmarks in ascending distances.
     *
     * @param wagonLoc  The location of the Wagon in an integer number of miles.
     * @param landmarks The ArrayList holding all the Landmarks to check.
     * @return The Landmark object that the Wagon will arrive at next.
     */
    public Landmark findNext(int wagonLoc, ArrayList<Landmark> landmarks) {
        for (int i = 0; i < landmarks.size(); i++) {
            if (landmarks.get(i).getLocation() > wagonLoc) {
                return landmarks.get(i);
            }
        }
        // Return the last landmark by default. Valid CSV file will have Oregon at the end of every Landmark ArrayList
        return landmarks.get(landmarks.size() - 1);
    }

    /**
     * checks if the item is already in the players inventory
     * @return true if the player already has that item false otherwise
     */
    public boolean playerHasItem(ArrayList<Item> playerItems, String itemName) {
        for (int j = 0; j < playerItems.size(); j++) {
            if (playerItems.get(j).getType().equals(itemName)) {
                return true;
            }
        }
        return false;
    }

    /**
     * gets how many items the player has
     * @param playerItems
     * @return the numeber of items the player has
     */
    public int numOfItemsInInventory(ArrayList<Item> playerItems){
        int numItems = 0;
        for (int j = 0; j < playerItems.size(); j++) {
           numItems += playerItems.get(j).getQuantity();
        }
        return numItems;
    }

    /**
     * updates the display of the players items
     * @param playerItems- the array of the players held items
     * @param money- the money currently owned by the player
     */
    public void updateCounts(ArrayList<Item> playerItems, double money){
        if(playerHasItem(playerItems,"Ammunition")){
            for(int j= 0; j<playerItems.size(); j++){
                if(playerItems.get(j).getType().equals("Ammunition")){
                    ammoCountLabel.setText(playerItems.get(j).getQuantity()+"");
                }
            }
        }
        if(playerHasItem(playerItems,"Food")){
            for(int j= 0; j<playerItems.size(); j++){
                if(playerItems.get(j).getType().equals("Food")){
                    foodCountLabel.setText(playerItems.get(j).getQuantity()+"");
                }
            }
        }
        moneyCountLabel.setText(money+"");
    }

    public static void main(String[] args) {
        launch(args);
    }
}