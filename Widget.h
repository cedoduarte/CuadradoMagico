#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_comprobarPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
    void on_actionComenzarElCuadradoMagico_triggered();
private:
    void sumaFilas();
    void sumaColumnas();
    void sumaDiagonalPrincipal();
    void sumaDiagonalSecundaria();
    bool compruebaCuadradoMagico() const;
    int obtieneElemento(int fila, int col) const;

    Ui::Widget *ui;
    QStandardItemModel *mModel;
    int mSumaDeDiagonalPrincipal;
    int mSumaDeDiagonalSecundaria;
};

#endif // WIDGET_H
