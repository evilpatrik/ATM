package com.example.yinyang;

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;

import java.util.Objects;

public class mainPan extends Application {

    public static Squre[][] square = new Squre[6][6];


    @Override
    public void start(Stage stage) throws Exception {
        Group g = new Group(pane);
        Scene scene = new Scene(g);
        stage.setScene(scene);
        //readFile();
        stage.show();
        String Color = Objects.requireNonNull(getClass().getClassLoader().getResource("Color.css")).toExternalForm();
        scene.getStylesheets().add(Color);

    }

    public static void main(String[] args) throws Exception {

        launch(args);
    }

    Rectangle rec;
    StackPane pane;

    public mainPan() {
        pane = new StackPane();
        pane.setMaxSize(580, 580);
        pane.setMinSize(580, 580);
        rec = new Rectangle();
        rec.setHeight(580);
        rec.setWidth(580);
        rec.setFill(Color.AQUA);
        pane.getChildren().add(rec);
        pane.setAlignment(Pos.TOP_LEFT);
        addSquareToPanel();


    }

    public void addSquareToPanel() {

        for (int row = 0; row < 6; row++) {
            for (int col = 0; col < 6; col++) {
                square[row][col] = new Squre();
                Squre sq = square[row][col];
                pane.getChildren().add(sq.getButton());
                sq.getButton().setTranslateX((85 * row) + (row * 14));
                sq.getButton().setTranslateY((85 * col) + (col * 14));
                sq.curX = row;
                sq.curY = col;

            }
        }
    }


}


