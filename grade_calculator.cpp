#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grade_calculator)
{
    ui->setupUi(this);

    ui->scheme1->setChecked(true);

    ui->scheme1->setCheckable(true);

    ui->scheme2->setCheckable(true);


    ////connect change of course
    ///
    QObject::connect( ui -> course, SIGNAL(currentIndexChanged(int)),
                      ui -> hw_wedge, SLOT(setCurrentIndex(int)));

    QObject::connect( ui -> course, SIGNAL(currentIndexChanged(int)),
                      ui -> mt_wedge, SLOT(setCurrentIndex(int)));

    QObject::connect( ui -> course, SIGNAL(currentIndexChanged(int)),
                      this, SLOT(reset()));
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw1, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw2, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw3, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw4, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw5, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw6, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw7, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->hw8, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->mt1, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->mt2, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->fn, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->mt, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->fe, SLOT( setValue(int) ) );
    QObject::connect( this, SIGNAL( SomeValueChanged(int ) ),
                      ui->fp, SLOT( setValue(int) ) );


    /// connect update
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

    QObject::connect( ui->mt ,SIGNAL( valueChanged(int)),
                      this, SLOT( compute_sum() ) );

    QObject::connect( ui->fe,SIGNAL( valueChanged(int)),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->fp,SIGNAL( valueChanged(int)),
                      this, SLOT( compute_sum() )  );

    QObject::connect( ui->scheme1 ,SIGNAL( clicked(bool)),
                      this, SLOT( compute_sum() ) );

    QObject::connect( ui->scheme2,SIGNAL( clicked(bool) ),
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
    double mx = mt1;
    if (mt2 > mt1){
        mx = mt2;
    }

    double fn = ui ->fn-> value() ;

    QString text(QString::number( 0.25 * hw /8 + 0.2*mt1 + 0.2 * mt2 + 0.35 * fn ));
    if ( ui -> course ->currentIndex() == 0){
         if ( ui -> scheme2 -> isChecked()){
            text=QString(QString::number( 0.25 * hw /8 + 0.3 * mx + 0.44 * fn ));
         }
    }
    else if (ui -> course ->currentIndex() == 1){
        mt1 = ui -> mt -> value();
        mt2 = ui -> fe -> value();
        fn = ui -> fp -> value();
        if ( ui -> scheme2 -> isChecked()){
           text=QString(QString::number( 0.15 * hw /3 + 0.5 * mt1 + .35 * fn));
        }
        else{
           text=QString(QString::number( 0.15 * hw /3 + 0.25*mt1 + 0.3 * mt2 + 0.35 * fn ));
        }
    }

    ui->score->setText(text);
}

