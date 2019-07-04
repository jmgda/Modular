#pragma once

#include "ui_MainWindow.h"
#include <Modular.h>
#include <qtimer.h>
#include <QMainWindow>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

struct ListWidget
{
	QWidget* Widget;
	QSpinBox* SpinBoxR, *SpinBoxG, *SpinBoxB;
	QSlider* SliderX, *SliderY, *SliderZ, *SliderWidth, *SliderHeight, *SliderLength;

	ListWidget(QWidget* widget, QSpinBox* spinBoxR, QSpinBox* spinBoxG,
		QSpinBox* spinBoxB, QSlider* sliderX, QSlider* sliderY,
		QSlider* sliderZ, QSlider* sliderWidth,
		QSlider* sliderHeight, QSlider* sliderLength)

		: Widget(widget), SpinBoxR(spinBoxR), SpinBoxG(spinBoxG), SpinBoxB(spinBoxB), 
		  SliderX(sliderX), SliderY(sliderY), SliderZ(sliderZ), SliderWidth(sliderWidth), 
		  SliderHeight(sliderHeight), SliderLength(sliderLength) {}
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget* parent = 0);

    ~MainWindow();

private:

    Ui::MainWindow* m_Ui;

	QTimer* m_Timer;

	std::vector<ListWidget*> m_Widgets;

	unsigned int m_Counter;

private slots:

	void MainLoop();

	void OnCreateCubeClick();

};