#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(Bubbling_clicked()));

    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(Select_clicked()));

    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(Insert_clicked()));

    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(Merge_clicked()));

    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(Fast_clicked()));

    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(Hill_clicked()));

    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(Pile_clicked()));

    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(Base_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Bubbling_clicked()
{
    qDebug()<<"你点击了冒泡按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//冒泡排序主代码，时间复杂度O(n^2)，空间复杂度O(1)

    for (int i = 0; i < list.size(); ++i) {
            for (int j = 0; j < list.size() - 1 - i; ++j) {
                if (a[j] > a[j + 1]) {
                    swap(a[j], a[j + 1]);
                }
            }
        }
///////////////////////////////////////

    OutPut();
}

void MainWindow::Select_clicked()
{
    qDebug()<<"你点击了选择按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//选择排序主代码，时间复杂度O(n^2)，空间复杂度O(1)
    int minIndex = -1;

        for (int i = 0; i < list.size(); ++i) {

            minIndex = i;

            for (int j = 0; j < list.size() - i; ++j) {

                if (a[j + i] < a[minIndex]) {

                    minIndex = j + i;
                }
            }
            swap(a[i], a[minIndex]);
        }
///////////////////////////////////////

        OutPut();

}

void MainWindow::Insert_clicked()
{
    qDebug()<<"你点击了插入按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//插入排序主代码，时间复杂度O(n^2)，空间复杂度O(1)
    for (int i = 1; i < list.size(); ++i) {

            for (int j = 0; j < i + 1; ++j) {

                if (a[j] > a[i]) {

                    int tem = a[i];

                    for (int k = 0; k < i - j; ++k) {

                        a[i - k] = a[i - k - 1];
                    }
                    a[j] = tem;

                    break;
                }
            }
        }
///////////////////////////////////////

    OutPut();

}

void MainWindow::Merge_clicked()
{
    qDebug()<<"你点击了归并按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//合并排序主代码，时间复杂度O(n^logn)，空间复杂度O(n)

        mergesort(a,list.size());

////////////////////////////////////////////

    OutPut();

}

void MainWindow::Fast_clicked()
{
    qDebug()<<"你点击了快速按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//快速排序主代码，时间复杂度O(n^logn)，空间复杂度最小为O(logn)，空间复杂度最大为O(n)

    fast_sort(a, 0, list.size());

////////////////////////////////////////////

    OutPut();
}

void MainWindow::Hill_clicked()
{
    qDebug()<<"你点击了希尔按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//希尔排序主代码，时间复杂度O(n^logn)，同时时间复杂度依赖于步长的选择，空间复杂度最小为O(1)

    shellSort(a, list.size(),INCRGAP);

////////////////////////////////////////////

    OutPut();

}

void MainWindow::Pile_clicked()
{
    qDebug()<<"你点击了堆按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//堆排序主代码，时间复杂度O(n^logn)，空间复杂度最小为O(logn)，空间复杂度最大为O(n)

    heap_sort(a,list.size());

////////////////////////////////////////////

    OutPut();
}

void MainWindow::Base_clicked()
{
    qDebug()<<"你点击了基数按钮";

    qstring_conform_int(QString(ui->lineEdit->text()),a);

//基数排序主代码，时间复杂度O(n)，空间复杂度为O(m),m为桶的数量

    radixsort(a,list.size());

////////////////////////////////////////////

    OutPut();
}


void MainWindow::qstring_conform_int(QString str,int a[30]){

    list = str.split(" ",QString::SkipEmptyParts);

    for(int i=0;i<list.size();i++){

        a[i]=list[i].toInt();
    }
}

void MainWindow::swap(int &b,int &c){

    int a=b;

    b=c;

    c=a;

}

void MainWindow::OutPut(){

    for(int j=0;j<list.size();j++){

        QString cc = QString("%1  ").arg(a[j]);

        str.append(cc);

    }

    ui->label_2->setText(str);

    str="排序后的结果为：";
}

void MainWindow::mergesort(int*a,int length){

    int step;

    int *p,*q,*t;

    int i,j,k,len1,len2;

    int *temp;

        step=1;

    p=a;

    q=(int*)malloc(sizeof(int)*length);

    temp=q;

    while(step<length){

        i=0;

        j=i+step;

        k=i;

        len1=i+step<length?i+step:length;

        len2=j+step<length?j+step:length;

        while(i<length){

            while(i<len1&&j<len2){

                q[k++]=p[i]<p[j]?p[i++]:p[j++];
            }
            while(i<len1){

                q[k++]=p[i++];
            }
            while(j<len2){

                q[k++]=p[j++];
            }
            i=j;

            j=i+step;

            k=i;

            len1=i+step<length?i+step:length;

            len2=j+step<length?j+step:length;
        }
        step*=2;

        t=p;

        p=q;

        q=t;
    }

    if(a!=p){

        memcpy(a,p,sizeof(int)*length);
    }

    free(temp);
}

void MainWindow::fast_sort(int arr[], int low, int high){

    if (high <= low) return;

    int i = low;

    int j = high + 1;

    int key = arr[low];

    while (true)
    {
        /*从左向右找比key大的值*/
        while (arr[++i] < key)
        {
            if (i == high){

                break;
            }
        }
        /*从右向左找比key小的值*/
        while (arr[--j] > key)
        {
            if (j == low){

                break;
            }
        }
        if (i >= j) break;
        /*交换i,j对应的值*/
        int temp = arr[i];

        arr[i] = arr[j];

        arr[j] = temp;
    }
    /*中枢值与j对应值交换*/
    int temp = arr[low];

    arr[low] = arr[j];

    arr[j] = temp;

    fast_sort(arr, low, j - 1);

    fast_sort(arr, j + 1, high);
}



void MainWindow::shellSort(int a[],int len,const int INCRGAP)
{
    int insertNum = 0;

    unsigned gap = len/INCRGAP; // 步长初始化

    while(gap) // while gap>=1
    {
        for (int i = gap; i < len; ++i) // 分组，在每个子序列中进行插入排序
        {
            insertNum = a[i];//将当前的元素值先存起来方便后面插入

            unsigned j = i;

            while (j >= gap && insertNum < a[j-gap])//寻找插入位置
            {
                a[j] = a[j - gap];

                j -= gap;
            }
            a[j] = insertNum;
        }
        gap = gap/INCRGAP;
    }
}

void MainWindow::max_heapify(int arr[], int start, int end)
{
    //建立父节点指标和子节点指标
    int dad = start;

    int son = dad * 2 + 1;

    while (son <= end)  //若子节点指标在范围内才做比较
    {
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的

            son++;

        if (arr[dad] > arr[son]) //如果父节点大於子节点代表调整完毕，直接跳出函数

            return;

        else  //否则交换父子内容再继续子节点和孙节点比较
        {
            swap(arr[dad], arr[son]);

            dad = son;

            son = dad * 2 + 1;
        }
    }
}

void MainWindow::heap_sort(int arr[], int len)
{
    //初始化，i从最後一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)

    max_heapify(arr, i, len - 1);

    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        max_heapify(arr, 0, i - 1);
    }
}

int MainWindow::maxbit(int data[], int n) //辅助函数，求数据的最大位数
{
    int d = 1; //保存最大的位数
    
    int p = 10;
    
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            
            ++d;
        }
    }
    return d;
}
void MainWindow::radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    
    int *tmp = new int[n];
    
    int *count = new int[10]; //计数器
    
    int i, j, k;
    
    int radix = 1;
    
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            
            count[j] = 0; //每次分配前清空计数器
        
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            
            tmp[count[k] - 1] = data[j];
            
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            
            data[j] = tmp[j];
        
        radix = radix * 10;
    }
    delete[]tmp;
    
    delete[]count;
}

