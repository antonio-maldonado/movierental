#ifndef MENU_PELICULAS_H
#define MENU_PELICULAS_H

#include <QStackedWidget>

namespace Ui {
class menu_peliculas;
}

class menu_peliculas : public QStackedWidget
{
    Q_OBJECT

public:
    explicit menu_peliculas(QWidget *parent = 0);
    ~menu_peliculas();

private:
    Ui::menu_peliculas *ui;
};

#endif // MENU_PELICULAS_H
