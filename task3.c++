#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>

class TicTacToe : public QWidget {
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = nullptr) : QWidget(parent) {
        initializeUI();
    }

private slots:
    void handleButtonClick(int row, int col);

private:
    void initializeUI();
    void resetGame();
    bool checkForWin();
    bool checkForDraw();

    QGridLayout *gridLayout;
    QVector<QVector<QPushButton*>> buttons;
    char currentPlayer;
};

void TicTacToe::initializeUI() {
    gridLayout = new QGridLayout(this);
    currentPlayer = 'X';

    for (int i = 0; i < 3; ++i) {
        QVector<QPushButton*> rowButtons;
        for (int j = 0; j < 3; ++j) {
            QPushButton *button = new QPushButton(this);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setFont(QFont("Arial", 20));
            connect(button, &QPushButton::clicked, [this, i, j]() { handleButtonClick(i, j); });
            rowButtons.push_back(button);
            gridLayout->addWidget(button, i, j);
        }
        buttons.push_back(rowButtons);
    }

    resetGame();
    setLayout(gridLayout);
}

void TicTacToe::resetGame() {
    currentPlayer = 'X';
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            buttons[i][j]->setText("");
        }
    }
}

void TicTacToe::handleButtonClick(int row, int col) {
    if (buttons[row][col]->text().isEmpty()) {
        buttons[row][col]->setText(QString(currentPlayer));

        if (checkForWin()) {
            QMessageBox::information(this, "Game Over", QString("Player ") + currentPlayer + " wins!");
            resetGame();
        } else if (checkForDraw()) {
            QMessageBox::information(this, "Game Over", "It's a draw!");
            resetGame();
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

bool TicTacToe::checkForWin() {
    
    for (int i = 0; i < 3; ++i) {
        if (buttons[i][0]->text() == currentPlayer &&
            buttons[i][1]->text() == currentPlayer &&
            buttons[i][2]->text() == currentPlayer) {
            return true; 
        }
        if (buttons[0][i]->text() == currentPlayer &&
            buttons[1][i]->text() == currentPlayer &&
            buttons[2][i]->text() == currentPlayer) {
            return true; 
        }
    }
    if (buttons[0][0]->text() == currentPlayer &&
        buttons[1][1]->text() == currentPlayer &&
        buttons[2][2]->text() == currentPlayer) {
        return true;
    }
    if (buttons[0][2]->text() == currentPlayer &&
        buttons[1][1]->text() == currentPlayer &&
        buttons[2][0]->text() == currentPlayer) {
        return true; 
    }
    return false;
}

bool TicTacToe::checkForDraw() {
   
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (buttons[i][j]->text().isEmpty()) {
                return false;
            }
        }
    }
    return true; 
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    TicTacToe game;
    game.setWindowTitle("Tic-Tac-Toe");
    game.resize(300, 300);
    game.show();

    return app.exec();
}

#include "main.moc"


