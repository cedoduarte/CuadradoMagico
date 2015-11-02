#include "Widget.h"
#include "ui_Widget.h"
#include "NumeroEnteroDelegate.h"
#include <QStandardItemModel>
#include <QInputDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mModel = new QStandardItemModel(this);
    mSumaDeDiagonalPrincipal = 0;
    mSumaDeDiagonalSecundaria = 0;

    ui->tableView->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->tableView->addAction(ui->actionComenzarElCuadradoMagico);
    ui->tableView->setModel(mModel);
    ui->tableView->setItemDelegate(new NumeroEnteroDelegate(this));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_comprobarPushButton_clicked()
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    if (rowCount == 0) {
        return;
    }
    mModel->setHorizontalHeaderItem(colCount - 1, new QStandardItem("Suma"));
    mModel->setVerticalHeaderItem(rowCount - 1, new QStandardItem("Suma"));
    sumaFilas();
    sumaColumnas();
    sumaDiagonalPrincipal();
    sumaDiagonalSecundaria();
    if (compruebaCuadradoMagico()) {
        QMessageBox::information(this, "Cuadrado Mágico",
                                 "SÍ ES CUADRADO MÁGICO");
    } else {
        QMessageBox::critical(this, "Cuadrado Mágico",
                              "NO ES CUADRADO MÁGICO");
    }
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

void Widget::on_actionComenzarElCuadradoMagico_triggered()
{
    mModel->clear();
    mModel->setRowCount(0);
    mModel->setColumnCount(0);
    const int orden = QInputDialog::getInt(this, "Comenzar",
                         "Introduce el orden del cuadrado mágico", 2, 2);
    mModel->setRowCount(orden + 1);
    mModel->setColumnCount(orden + 1);
    ui->tableView->hideColumn(orden);
    ui->tableView->hideRow(orden);
}

void Widget::sumaFilas()
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    for (int ix = 0; ix <= rowCount - 2; ++ix) {
        int suma = 0;
        for (int jx = 0; jx <= colCount - 2; ++jx) {
            suma += obtieneElemento(ix, jx);
        }
        mModel->setItem(ix, colCount - 1,
                        new QStandardItem(QString::number(suma)));
    }
}

void Widget::sumaColumnas()
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    for (int jx = 0; jx <= colCount - 2; ++jx) {
        int suma = 0;
        for (int ix = 0; ix <= rowCount - 2; ++ix) {
            suma += obtieneElemento(ix, jx);
        }
        mModel->setItem(rowCount - 1, jx,
                        new QStandardItem(QString::number(suma)));
    }
}

void Widget::sumaDiagonalPrincipal()
{
    const int rowCount = mModel->rowCount();
    int suma = 0;
    for (int ix = 0; ix <= rowCount - 2; ++ix) {
        suma += obtieneElemento(ix, ix);
    }
    mSumaDeDiagonalPrincipal = suma;
}

void Widget::sumaDiagonalSecundaria()
{
    const int rowCount = mModel->rowCount();
    int ix = (rowCount - 1) - 1;
    int jx = 0;
    int suma = 0;
    for (; ix >= 0 && jx <= (rowCount - 2); --ix, ++jx) {
        suma += obtieneElemento(ix, jx);
    }
    mSumaDeDiagonalSecundaria = suma;
}

bool Widget::compruebaCuadradoMagico() const
{
    const int rowCount = mModel->rowCount();
    const int colCount = mModel->columnCount();
    const int valor = mSumaDeDiagonalPrincipal;
    int elemento;
    // comprobación
    for (int jx = 0; jx < colCount - 1; ++jx) {
        elemento = obtieneElemento(rowCount - 1, jx);
        if (elemento != valor) {
            return false;
        }
    }
    for (int ix = 0; ix < rowCount - 1; ++ix) {
        elemento = obtieneElemento(ix, colCount - 1);
        if (elemento != valor) {
            return false;
        }
    }
    // resultado
    return valor == mSumaDeDiagonalSecundaria;
}

int Widget::obtieneElemento(int fila, int col) const
{
    auto item = mModel->item(fila, col);
    if (!item) {
        return 0;
    }
    return item->text().toInt();
}
