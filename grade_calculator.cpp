#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    QObject::connect( ui->hw1 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->hw2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() ) );
    QObject::connect( ui->hw3 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->hw4 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() ) );
    QObject::connect( ui->hw5 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->hw6 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() ) );
    QObject::connect( ui->hw7 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->hw8 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() ) );

    QObject::connect( ui->mt1 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->mt2 ,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() ) );
    QObject::connect( ui->fn,SIGNAL( valueChanged(int) ),
                      this, SLOT( compute_sum() )  );

}

grade_calculator::~grade_calculator()
{
    delete ui;
}

void grade_calculator::compute_sum() const {

    double hw = ui->hw1 -> value() + ui->hw2 -> value() + ui->hw3 -> value() + ui->hw4 -> value() + ui->hw5 -> value() + ui->hw6 -> value() + ui->hw7 -> value() + ui->hw8 -> value() ;
    double mt1 = ui->mt1-> value() ;
    double mt2 = ui->mt2-> value() ;
    double fn = ui ->fn-> value() ;

    QString text(
                  QString::number( 0.25 * hw /8 + 0.2*mt1 + 0.2 * mt2 + 0.35 * fn )
                );
    ui->score->setText(text);
}
