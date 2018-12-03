package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.FileChooser;
import javafx.stage.Stage;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;

public class Controller {

    @FXML
    private Button chooseImg;

    @FXML
    private ImageView img;

    @FXML
    private Button close;

    @FXML
    private void initialize() {
        img.setDisable(true);
        close.setDisable(true);
        close.setOpacity(0);

        chooseImg.setOnAction(event -> {
            FileChooser fileChooser = new FileChooser();
            fileChooser.getExtensionFilters().addAll(
                    new FileChooser.ExtensionFilter("jpg","*.jpg"),
                    new FileChooser.ExtensionFilter("png", "*.png")
            );
            File file = fileChooser.showOpenDialog(new Stage());
            if (file != null) {
                try {
                    InputStream input = new FileInputStream(file);
                    Image image = new Image(input);

                    img.setDisable(false);
                    chooseImg.setDisable(true);
                    chooseImg.setOpacity(0);

                    img.setImage(image);
                    close.setDisable(false);
                    close.setOpacity(100);
                } catch (FileNotFoundException e) {
                    e.printStackTrace();
                }
            }
        });

        close.setOnAction(event -> {
            img.setImage(null);
            close.setDisable(true);
            close.setOpacity(0);
            img.setDisable(true);
            chooseImg.setDisable(false);
            chooseImg.setOpacity(100);
        });

    }

}