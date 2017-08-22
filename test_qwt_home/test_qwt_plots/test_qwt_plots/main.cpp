//
//  main.cpp
//  test_qwt_plots
//
//  Created by Adam Willats on 8/14/17.
//  Copyright © 2017 Adam Willats. All rights reserved.
//
//#include </Users/adam/Documents/Rutaceae/qwt-6.1.3/qwt.prf>
#include <cmath>
//#include <QApplication>
#include <qwt_plot.h>
#include <qwt_plot_curve.h>

int main(int argc, char **argv)
{
    //QApplication a(argc, argv);
    QwtPlot plot(QwtText("CppQwtExample1"));
    plot.setGeometry(0,0,640,400);
    plot.setAxisScale(QwtPlot::xBottom, 0.0, 2.0*M_PI);
    plot.setAxisScale(QwtPlot::yLeft, -1.0, 1.0);
    
    QwtPlotCurve sine("Sine");
    std::vector<double> xs;
    std::vector<double> ys;
    for (double x=0; x<2.0*M_PI; x+=(M_PI/10.0)) {
        xs.push_back(x);
        ys.push_back(std::sin(x));
    }
    sine.setData(&xs[0], &ys[0], xs.size());
    sine.attach(&plot);
    
    plot.show();
    return a.exec();
}
