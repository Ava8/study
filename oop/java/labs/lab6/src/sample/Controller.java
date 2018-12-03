package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.TextArea;

public class Controller {
    @FXML
    private TextArea textArea;

    @FXML
    private ChoiceBox<String> colorBox;

    @FXML
    private ChoiceBox<String> fontBox;

    @FXML
    private Button doneEdit;

    @FXML
    private void initialize() {
        ObservableList<String> color = FXCollections.observableArrayList("black","blue","red");
        ObservableList<String> font = FXCollections.observableArrayList("Times New Roman",
                                                                                "MS Sans Serif",
                                                                                "Courier New");
        colorBox.setItems(color);
        fontBox.setItems(font);
        colorBox.setValue("black");
        fontBox.setValue("MS Sans Serif");

        doneEdit.setOnAction(event -> {
            String chosenColor = colorBox.getValue();
            String chosenFont = fontBox.getValue();
            textArea.setStyle("-fx-text-fill: "+chosenColor+";"+"-fx-font-family: "+chosenFont+";");
        });
        
    }
}
