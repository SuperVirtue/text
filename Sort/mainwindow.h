#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void Bubbling_clicked();
    void Select_clicked();
    void Insert_clicked();
    void Merge_clicked();
    void Fast_clicked();
    void Hill_clicked();
    void Pile_clicked();
    void Base_clicked();

    void qstring_conform_int(QString str,int a[30]);
    void swap(int &b,int &c);
    void OutPut();
    void mergesort(int*a,int length);
    void fast_sort(int arr[], int low, int high);
    void shellSort(int a[],int len,const int INCRGAP);
    void max_heapify(int arr[], int start, int end);
    void heap_sort(int arr[], int len);
    int maxbit(int data[], int n);
    void radixsort(int data[], int n);
private:
    Ui::MainWindow *ui;
    QString str="排序后的结果为：";
    int a[30];
    QStringList list;
    const int INCRGAP = 2;//希尔排序的步进

};
#endif // MAINWINDOW_H
