#include <QApplication>
#include <QWidget>

class MyWidget : public QWidget
{
public:
    MyWidget(QWidget *parent = nullptr) : QWidget(parent)
    {
        // Create a label
        QLabel *label = new QLabel("Hello, world!");

        // Set the label's position
        label->setGeometry(100, 100, 100, 30);

        // Show the widget
        show();
    }
};

int main(int argc, char *argv[])
{
    // Create an application
    QApplication a(argc, argv);

    // Create a widget
    MyWidget w;

    // Show the widget
    w.show();

    // Run the application
    return a.exec();
}
