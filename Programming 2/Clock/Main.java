package sample;

import com.sun.source.tree.ContinueTree;
import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.beans.EventHandler;
import java.time.Clock;
import java.time.LocalTime;
import javax.swing.Timer;
import static javafx.scene.paint.Color.*;

public class Main extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        primaryStage.setTitle("Clock");
        HBox hbox = new HBox(root);
        primaryStage.setScene(new Scene(hbox, 600, 400));
        BackgroundFill backround_fill = new BackgroundFill(BLACK, CornerRadii.EMPTY, Insets.EMPTY);
        Background background = new Background(backround_fill);
        hbox.setAlignment(Pos.CENTER);
        hbox.setBackground(background);
        primaryStage.show();
        Label half = (Label) root.lookup("#half");
        Label ten = (Label) root.lookup("#ten");
        Label quarter = (Label) root.lookup("#quarter");
        Label twenty = (Label) root.lookup("#twenty");
        Label five = (Label) root.lookup("#five");
        Label to = (Label) root.lookup("#to");
        Label minutes = (Label) root.lookup("#minutes");
        Label past = (Label) root.lookup("#past");
        Label two = (Label) root.lookup("#two");
        Label three = (Label) root.lookup("#three");
        Label one = (Label) root.lookup("#one");
        Label fiveclock = (Label) root.lookup("#fiveclock");
        Label four = (Label) root.lookup("#four");
        Label six = (Label) root.lookup("#six");
        Label seven = (Label) root.lookup("#seven");
        Label eight = (Label) root.lookup("#eight");
        Label nine = (Label) root.lookup("#nine");
        Label tenclock = (Label) root.lookup("#tenclock");
        Label eleven = (Label) root.lookup("#eleven");
        Label twelve = (Label) root.lookup("#twelve");
        Label dotsone = (Label) root.lookup("#dotsone");
        Label dotstwo = (Label) root.lookup("#dotstwo");
        Label dotsthree = (Label) root.lookup("#dotsthree");
        Label dotsfour = (Label) root.lookup("#dotsfour");
        Clocker clocker = new Clocker();
            ActionListener repeat = evt -> {
                LocalTime time = LocalTime.now();
                int minute = time.getMinute();
                int hour = time.getHour();
                    if (minute < 30) {
                        if (minute == 0) {
                            clocker.setGray(minutes);
                        }
                        clocker.setGreen(past);
                        clocker.setGray(to);
                        clocker.setGray(five);
                        clocker.setGreen(minutes);
                        if (minute < 10 && minute >= 5) {
                            clocker.setGreen(five);
                            clocker.setGreen(minutes);
                        }
                        if (minute < 15 && minute >= 10) {
                            clocker.setGreen(ten);
                            clocker.setGreen(minutes);
                            clocker.setGray(five);
                        }
                        if (minute < 20 && minute >= 15) {
                            clocker.setGreen(quarter);
                            clocker.setGray(minutes);
                            clocker.setGray(ten);
                        }
                        if (minute < 25 && minute >= 20) {
                            clocker.setGray(quarter);
                            clocker.setGreen(twenty);
                            clocker.setGreen(minutes);
                        }
                        if (minute >= 25) {
                            clocker.setGreen(minutes);
                            clocker.setGreen(twenty);
                            clocker.setGreen(five);
                        }
                        switch (hour % 12) {
                            case 0:
                                clocker.setGreen(twelve);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                break;
                            case 1:
                                clocker.setGreen(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 2:
                                clocker.setGreen(two);
                                clocker.setGray(one);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 3:
                                clocker.setGreen(three);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 4:
                                clocker.setGreen(four);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 5:
                                clocker.setGreen(fiveclock);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 6:
                                clocker.setGreen(six);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 7:
                                clocker.setGreen(seven);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 8:
                                clocker.setGreen(eight);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 9:
                                clocker.setGreen(nine);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 10:
                                clocker.setGreen(tenclock);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 11:
                                clocker.setGreen(eleven);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(twelve);
                                break;
                        }
                        switch (minute % 5) {
                            case 0:
                                clocker.setGray(dotsone);
                                clocker.setGray(dotstwo);
                                clocker.setGray(dotsthree);
                                clocker.setGray(dotsfour);
                                break;
                            case 1:
                                clocker.setGreen(dotsone);
                                break;
                            case 2:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                break;
                            case 3:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                clocker.setGreen(dotsthree);
                                break;
                            case 4:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                clocker.setGreen(dotsthree);
                                clocker.setGreen(dotsfour);
                                break;
                        }
                    }
                    if (minute > 29) {
                        clocker.setGray(past);
                        clocker.setGreen(to);
                        if (minute < 35) {
                            clocker.setGreen(half);
                            clocker.setGray(minutes);
                            clocker.setGray(twenty);
                            clocker.setGray(five);
                            clocker.setGray(to);
                            clocker.setGreen(past);
                        }
                        if (minute < 40 && minute >= 35) {
                            clocker.setGray(half);
                            clocker.setGray(past);
                            clocker.setGreen(to);
                            clocker.setGreen(minutes);
                            clocker.setGreen(twenty);
                            clocker.setGreen(five);
                        }
                        if (minute < 45 && minute >= 40) {
                            clocker.setGreen(minutes);
                            clocker.setGreen(twenty);
                            clocker.setGray(five);
                        }
                        if (minute < 50 && minute >= 45) {
                            clocker.setGreen(quarter);
                            clocker.setGray(twenty);
                            clocker.setGray(minutes);
                        }
                        if (minute < 55 && minute >= 50) {
                            clocker.setGray(quarter);
                            clocker.setGreen(minutes);
                            clocker.setGreen(ten);
                        }
                        if (minute >= 55) {
                            clocker.setGray(ten);
                            clocker.setGreen(minutes);
                            clocker.setGreen(five);
                        }
                        switch (hour % 12) {
                            case 11:
                                clocker.setGreen(twelve);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                break;
                            case 0:
                                clocker.setGreen(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 1:
                                clocker.setGreen(two);
                                clocker.setGray(one);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 2:
                                clocker.setGreen(three);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 3:
                                clocker.setGreen(four);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 4:
                                clocker.setGreen(fiveclock);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 5:
                                clocker.setGreen(six);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 6:
                                clocker.setGreen(seven);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 7:
                                clocker.setGreen(eight);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 8:
                                clocker.setGreen(nine);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(tenclock);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 9:
                                clocker.setGreen(tenclock);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(eleven);
                                clocker.setGray(twelve);
                                break;
                            case 10:
                                clocker.setGreen(eleven);
                                clocker.setGray(one);
                                clocker.setGray(two);
                                clocker.setGray(three);
                                clocker.setGray(four);
                                clocker.setGray(fiveclock);
                                clocker.setGray(six);
                                clocker.setGray(seven);
                                clocker.setGray(eight);
                                clocker.setGray(nine);
                                clocker.setGray(tenclock);
                                clocker.setGray(twelve);
                                break;
                        }
                        switch (minute % 5) {
                            case 0:
                                clocker.setGray(dotsone);
                                clocker.setGray(dotstwo);
                                clocker.setGray(dotsthree);
                                clocker.setGray(dotsfour);
                                break;
                            case 1:
                                clocker.setGreen(dotsone);
                                break;
                            case 2:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                break;
                            case 3:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                clocker.setGreen(dotsthree);
                                break;
                            case 4:
                                clocker.setGreen(dotsone);
                                clocker.setGreen(dotstwo);
                                clocker.setGreen(dotsthree);
                                clocker.setGreen(dotsfour);
                                break;
                        }
                    }
                };new Timer(1000, repeat).start();
    }




    public static void main(String[] args) { launch(args); }

}
