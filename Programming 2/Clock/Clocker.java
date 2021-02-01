package sample;
import javafx.css.converter.PaintConverter;
import javafx.scene.control.Label;
import javafx.scene.paint.Color;

import java.time.LocalTime;

public class Clocker {
javafx.scene.paint.Color green = javafx.scene.paint.Color.color(0,1,0.0313);
javafx.scene.paint.Color gray = javafx.scene.paint.Color.color(0.82745,0.82745,0.82745);
    public void setGray(Label label){
        label.setTextFill(gray);
    }
    public void setGreen(Label label){
        label.setTextFill(green);
    }
}

