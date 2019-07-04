#include "mainwindow.h"
#include "GLWidget.h"

MainWindow::MainWindow(QWidget* parent) :
    QMainWindow(parent), m_Ui(new Ui::MainWindow)
{
    m_Ui->setupUi(this);

	QObject::connect(m_Ui->btn_CreateCube, 
		SIGNAL(clicked()), this, SLOT(OnCreateCubeClick()));

	m_Ui->verticalLayout->setAlignment(Qt::Alignment::enum_type::AlignTop);

	m_Timer = new QTimer(this);
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(MainLoop()));

	m_Counter = 0;

	m_Timer->start(10);
}

MainWindow::~MainWindow()
{
    delete m_Ui;
}

void MainWindow::MainLoop()
{
	for (int i = 0; i < m_Widgets.size(); i++)
	{
		(*m_Ui->wid_GL->GetMeshes())[i]->MoveTo(
			glm::vec3((float) m_Widgets[i]->SliderX->value() / 10.0f, 
			(float) m_Widgets[i]->SliderY->value() / 10.0f,
			(float) m_Widgets[i]->SliderZ->value() / 10.0f));

		(*m_Ui->wid_GL->GetMeshes())[i]->Scale(
			glm::vec3((float) m_Widgets[i]->SliderWidth->value() / 10.0f,
			(float) m_Widgets[i]->SliderHeight->value() / 10.0f, 
			(float) m_Widgets[i]->SliderLength->value() / 10.0f));

		(*m_Ui->wid_GL->GetMeshes())[i]->ChangeColor(
			glm::vec3((float) m_Widgets[i]->SpinBoxR->value(), 
			(float ) m_Widgets[i]->SpinBoxG->value(), 
			(float) m_Widgets[i]->SpinBoxB->value()));
	}
}

void MainWindow::OnCreateCubeClick()
{
	m_Ui->wid_GL->AddCube(0.0f);

	std::string sliderStyle =
		"QSlider::groove:horizontal\n"
		"{\n"
		"    border: none;\n"
		"    height: 5px;\n"
		"    background: rgb(70, 70, 70);\n"
		"}\n"
		"\n"
		"QSlider::handle:horizontal\n"
		"{\n"
		"    background: rgb(100, 100, 100);\n"
		"    border: none;\n"
		"    width: 10px;\n"
		"    margin: -2px 0;\n"
		"    border-radius: 3px;\n"
		"}";

	std::string spinBoxStyle =
		"QSpinBox\n"
		"{\n"
		"	background-color: rgb(100, 100, 100);\n"
		"	border: 1px solid rgb(30, 30, 30);\n"
		"}";

	m_Counter++;

	QWidget* widget = new QWidget();
	widget->setObjectName(QString::fromUtf8("widget"));
	widget->setMinimumSize(QSize(0, 30));
	widget->setMaximumSize(QSize(16777215, 30));

	QFrame* frame = new QFrame(widget);
	frame->setObjectName(QString::fromUtf8("frame"));
	frame->setGeometry(QRect(-1, 2, 222, 25));
	frame->setStyleSheet(QString::fromUtf8("background-color: rgb(56, 56, 56);"));
	frame->setFrameShape(QFrame::StyledPanel);
	frame->setFrameShadow(QFrame::Raised);
	frame->raise();

	QPushButton* btn_Open = new QPushButton(widget);
	btn_Open->setObjectName(QString::fromUtf8("btn_Open"));
	btn_Open->setGeometry(QRect(1, 3, 51, 23));
	btn_Open->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	btn_Open->setFlat(true);
	btn_Open->setText(("Shape " + std::to_string(m_Counter)).c_str());

	btn_Open->setStyleSheet(QString::fromUtf8(
		"QPushButton\n"
		"{\n"
		"	color: rgb(255, 255, 255);\n"
		"	background-color: transparent;\n"
		"	border: none;\n"
		"}\n"
		"\n"
		"QPushButton::hover:!pressed\n"
		"{\n"
		"	background-color: rgb(35, 35, 35);\n"
		"	border: none;\n"
		"}\n"
		"\n"
		"QPushButton::pressed\n"
		"{\n"
		"	background-color: rgb(30, 30, 30);\n"
		"	border: none;\n"
		"}"));

	QPushButton* btn_Minimize = new QPushButton(widget);
	btn_Minimize->setObjectName(QString::fromUtf8("btn_Minimize"));
	btn_Minimize->setGeometry(QRect(182, 9, 15, 15));
	btn_Minimize->setMinimumSize(QSize(15, 15));
	btn_Minimize->setMaximumSize(QSize(15, 15));
	btn_Minimize->setVisible(false);
	btn_Minimize->setText("^");

	btn_Minimize->setStyleSheet(QString::fromUtf8(
		"QPushButton\n"
		"{\n"
		"	color: rgb(255, 255, 255);\n"
		"	background-color: transparent;\n"
		"	border: none;\n"
		"}\n"));

	QPushButton* btn_Delete = new QPushButton(widget);
	btn_Delete->setObjectName(QString::fromUtf8("btn_Delete"));
	btn_Delete->setGeometry(QRect(8, 233, 190, 24));
	btn_Delete->raise();
	btn_Delete->setText("Delete");

	btn_Delete->setStyleSheet(QString::fromUtf8(
		"QPushButton\n"
		"{\n"
		"	color: rgb(255, 255, 255);\n"
		"	background-color: rgb(50, 50, 50);\n"
		"	border: none;\n"
		"}\n"
		"\n"
		"QPushButton::hover:!pressed\n"
		"{\n"
		"	background-color: rgb(35, 35, 35);\n"
		"	border: none;\n"
		"}\n"
		"\n"
		"QPushButton::pressed\n"
		"{\n"
		"	background-color: rgb(30, 30, 30);\n"
		"	border: none;\n"
		"}"));

	QSlider* slider1 = new QSlider(widget);
	slider1->setObjectName(QString::fromUtf8("slider1"));
	slider1->setGeometry(QRect(35, 41, 164, 22));
	slider1->setMinimumSize(QSize(100, 0));
	slider1->setMaximumSize(QSize(200, 16777215));
	slider1->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider1->setOrientation(Qt::Horizontal);
	slider1->setValue(40);

	QSlider* slider2 = new QSlider(widget);
	slider2->setObjectName(QString::fromUtf8("slider2"));
	slider2->setGeometry(QRect(35, 61, 164, 22));
	slider2->setMinimumSize(QSize(100, 0));
	slider2->setMaximumSize(QSize(200, 16777215));
	slider2->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider2->setOrientation(Qt::Horizontal);
	slider2->setValue(40);

	QSlider* slider3 = new QSlider(widget);
	slider3->setObjectName(QString::fromUtf8("slider3"));
	slider3->setGeometry(QRect(35, 81, 164, 22));
	slider3->setMinimumSize(QSize(100, 0));
	slider3->setMaximumSize(QSize(200, 16777215));
	slider3->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider3->setOrientation(Qt::Horizontal);
	slider3->setValue(40);

	QSlider* slider4 = new QSlider(widget);
	slider4->setObjectName(QString::fromUtf8("slider4"));
	slider4->setGeometry(QRect(55, 110, 144, 22));
	slider4->setMinimumSize(QSize(100, 0));
	slider4->setMaximumSize(QSize(200, 16777215));
	slider4->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider4->setOrientation(Qt::Horizontal);
	slider4->setValue(10);

	QSlider* slider5 = new QSlider(widget);
	slider5->setObjectName(QString::fromUtf8("slider5"));
	slider5->setGeometry(QRect(55, 130, 144, 22));
	slider5->setMinimumSize(QSize(100, 0));
	slider5->setMaximumSize(QSize(200, 16777215));
	slider5->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider5->setOrientation(Qt::Horizontal);
	slider5->setValue(10);

	QSlider* slider6 = new QSlider(widget);
	slider6->setObjectName(QString::fromUtf8("slider5"));
	slider6->setGeometry(QRect(55, 150, 144, 22));
	slider6->setMinimumSize(QSize(100, 0));
	slider6->setMaximumSize(QSize(200, 16777215));
	slider6->setStyleSheet(QString::fromUtf8(sliderStyle.c_str()));
	slider6->setOrientation(Qt::Horizontal);
	slider6->setValue(10);

	QLabel* label1 = new QLabel(widget);
	label1->setObjectName(QString::fromUtf8("label1"));
	label1->setGeometry(QRect(7, 43, 16, 16));
	label1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label1->setText("X:");

	QLabel* label2 = new QLabel(widget);
	label2->setObjectName(QString::fromUtf8("label2"));
	label2->setGeometry(QRect(7, 63, 16, 16));
	label2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label2->setText("Y:");

	QLabel* label3 = new QLabel(widget);
	label3->setObjectName(QString::fromUtf8("label3"));
	label3->setGeometry(QRect(7, 83, 16, 16));
	label3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label3->setText("Z:");

	QLabel* label4 = new QLabel(widget);
	label4->setObjectName(QString::fromUtf8("label4"));
	label4->setGeometry(QRect(7, 112, 41, 16));
	label4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label4->setText("Width:");

	QLabel* label5 = new QLabel(widget);
	label5->setObjectName(QString::fromUtf8("label5"));
	label5->setGeometry(QRect(7, 132, 41, 16));
	label5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label5->setText("Height:");

	QLabel* label6 = new QLabel(widget);
	label6->setObjectName(QString::fromUtf8("label6"));
	label6->setGeometry(QRect(7, 152, 41, 16));
	label6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label6->setText("Length:");

	QLabel* label7 = new QLabel(widget);
	label7->setObjectName(QString::fromUtf8("label7"));
	label7->setGeometry(QRect(7, 190, 41, 16));
	label7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
	label7->setText("Color:");

	QSpinBox* spinBox1 = new QSpinBox(widget);
	spinBox1->setObjectName(QString::fromUtf8("spinBox1"));
	spinBox1->setGeometry(QRect(56, 188, 42, 22));
	spinBox1->setFrame(false);
	spinBox1->setStyleSheet(QString::fromUtf8(spinBoxStyle.c_str()));
	spinBox1->setMaximum(255);
	spinBox1->setValue(0);

	QSpinBox* spinBox2 = new QSpinBox(widget);
	spinBox2->setObjectName(QString::fromUtf8("spinBox2"));
	spinBox2->setGeometry(QRect(107, 188, 42, 22));
	spinBox2->setFrame(false);
	spinBox2->setStyleSheet(QString::fromUtf8(spinBoxStyle.c_str()));
	spinBox2->setMaximum(255);
	spinBox2->setValue(0.5f * 255.0f);

	QSpinBox* spinBox3 = new QSpinBox(widget);
	spinBox3->setObjectName(QString::fromUtf8("spinBox3"));
	spinBox3->setGeometry(QRect(158, 188, 42, 22));
	spinBox3->setFrame(false);
	spinBox3->setStyleSheet(QString::fromUtf8(spinBoxStyle.c_str()));
	spinBox3->setMaximum(255);
	spinBox3->setValue(0.31f * 255.0f);

	m_Ui->verticalLayout->addWidget(widget);

	ListWidget* listWidget = new ListWidget(widget, spinBox1, spinBox2, spinBox3, 
		slider1, slider2, slider3, slider4, slider5, slider6);

	m_Widgets.push_back(listWidget);

	connect(btn_Open, &QPushButton::clicked, [widget, btn_Minimize]()
	{
		widget->setFixedHeight(269);
		btn_Minimize->setVisible(true);
	});

	connect(btn_Minimize, &QPushButton::clicked, [widget, btn_Minimize]()
	{
		widget->setFixedHeight(30);
		btn_Minimize->setVisible(false);
	});

	std::vector<ListWidget*>* widgets = &m_Widgets;

	Ui::MainWindow* ui = m_Ui;

	connect(btn_Delete, &QPushButton::clicked, [widget, widgets, ui]()
	{
		int j = 0;

		for (int i = 0; i < widgets->size(); i++)
		{
			if (widget == (*widgets)[i]->Widget)
			{
				widgets->erase(widgets->begin() + i);
				j = i;
			}
		}

		delete widget;

		ui->wid_GL->GetMeshes()->erase(ui->wid_GL->GetMeshes()->begin() + j);
	});
}