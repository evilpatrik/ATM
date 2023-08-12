package com.example.yinyang;

import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.input.MouseButton;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.stage.Stage;

public class Squre {
    static int numberW;
    static int numberB;
    int curX;
    int curY;
    private final static String WHITE = "white";
    private final static   String BLACK = "black";
    private final static String GREY = "gray";
    Button button ;
    String color = "gray";         // default status
    boolean firstSquare;
    public Button getButton(){

        return button;
    }
    public Squre(){
      button = new Button();
        button.setMinSize(85,85);
        button.getStyleClass().add("buttonGrey");
        button.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent mouseEvent) {
                if(mouseEvent.getButton() == MouseButton.PRIMARY){
                    if (nextColor()==WHITE && numberW==0){
                        firstSquare =true;
                    }else if(nextColor()==BLACK && numberB==0) {
                        firstSquare=true;
                    }else{
                        firstSquare =false;
                    }
                    if(twoXTwo(curX, curY, nextColor()) && secondRoll(curX ,curY ,nextColor(),firstSquare) && justOne(curX ,curY )){
                        changeColor();
                        if(numberW+numberB==36){
                            showMessage("YOU WIN");
                        }

                    }
                }
                    if (mouseEvent.getButton() == MouseButton.SECONDARY) {
                        if(justOne(curX,curY)) {
                        backToGrey();
                    }
                }
            }
        });
    }

    public void changeColor(){
        if(!color.equals(WHITE)){
            if(color.equals(GREY)) {
                numberW++;
            }
                if(color.equals(BLACK)){
                    numberW++;
                    numberB--;
                }
                color = WHITE;
                button.getStyleClass().removeAll("buttonGrey", "buttonBlack");
                button.getStyleClass().add("buttonWhite");

        }else{
                numberB++;
                numberW--;
            color = BLACK;
            button.getStyleClass().add("buttonBlack");
            }

        }

        public String nextColor(){
        if(!color.equals(WHITE)) return WHITE;
        return BLACK;
        }
    public void backToGrey(){
        if(color.equals(WHITE)){
            numberW--;
        }
        if(color.equals(BLACK)){
            numberB--;
        }
        button.getStyleClass().removeAll("buttonWhite", "buttonBlack");
        button.getStyleClass().add("buttonGrey");
        color = GREY;
    }


    public static boolean twoXTwo(int i, int j, String nextColor){
        boolean upL, upR, downL, downR;
        try{

            upL= (nextColor.equals(mainPan.square[i][j-1].color) && nextColor.equals(mainPan.square[i-1][j].color) && nextColor.equals(mainPan.square[i-1][j-1].color));
        }catch (ArrayIndexOutOfBoundsException e){upL = false;}
        try{
            upR = (nextColor.equals(mainPan.square[i][j+1].color) && nextColor.equals(mainPan.square[i-1][j].color) && nextColor.equals(mainPan.square[i-1][j+1].color));
        }catch (ArrayIndexOutOfBoundsException e){ upR = false;}

        try{
            downL = (nextColor.equals(mainPan.square[i][j-1].color) && nextColor.equals(mainPan.square[i+1][j].color) && nextColor.equals(mainPan.square[i+1][j-1].color));
        }catch(ArrayIndexOutOfBoundsException e){downL = false;}

        try{
            downR = (nextColor.equals(mainPan.square[i][j+1].color) && nextColor.equals(mainPan.square[i+1][j].color) && nextColor.equals(mainPan.square[i+1][j+1].color));
        }catch (ArrayIndexOutOfBoundsException e) {downR = false;}

        boolean result = !(upL || upR || downR || downL);
        if(!result) showMessage("2x2 Is Not Right");

        return result;
    }
    //secondRoll function
    public boolean secondRoll(int i , int j, String nextColor,boolean firstSquare){
        if(firstSquare)return true;

        boolean up=false,down=false,left=false,right=false;

        try{
            up= (nextColor.equals(mainPan.square[i-1][j].color));

        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            down=(nextColor.equals(mainPan.square[i+1][j].color));
        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            left=(nextColor.equals(mainPan.square[i][j-1].color));
        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            right=(nextColor.equals(mainPan.square[i][j+1].color));
        }catch (ArrayIndexOutOfBoundsException e){}

        boolean result = (up || down || left || right);
        if(!result) showMessage("Continuity Is Not Right");
        return result;
    }

    public boolean justOne(int i, int j){

        String color= mainPan.square[i][j].color;
        if(color.equals(GREY))return true;
        int count=0;
        boolean up=false ,down=false ,left=false ,right=false;

        try{
            up= (color.equals(mainPan.square[i-1][j].color));

        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            down=(color.equals(mainPan.square[i+1][j].color));
        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            left=(color.equals(mainPan.square[i][j-1].color));
        }catch (ArrayIndexOutOfBoundsException e){}
        try{
            right=(color.equals(mainPan.square[i][j+1].color));
        }catch (ArrayIndexOutOfBoundsException e){}

        if(up)count++;
        if(down)count++;
        if(left)count++;
        if(right)count++;
        boolean result = count<=1;
        if(!result) showMessage("Continuity Is Not Right");
        return result;
    }

    public static void showMessage(String message){
        Stage s = new Stage();
        Group g = new Group();
        Scene scene = new Scene(g);
        Label labelOne = new Label(message);
        labelOne.setTranslateX(20);
        labelOne.setTranslateY(20);
        labelOne.setFont(Font.font(40));
        labelOne.setTextFill(Color.GREEN);
        Pane pane = new Pane();
        pane.setMaxSize(100, 100);
        pane.getChildren().add(labelOne);
        g.getChildren().add(pane);
        s.setScene(scene);
        s.show();
    }

}


