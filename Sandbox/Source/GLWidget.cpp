#include "GLWidget.h"

glm::vec3 lightPos(2.0f, 7.0f, 8.0f);

GLWidget::GLWidget(QWidget* parent)
	: QGLWidget(parent), m_AspectRatio((float)(this->width() / this->height())),
	  m_LeftOffsetX(0.0f), m_LeftOffsetY(0.0f), m_MidOffsetX(0.0f), m_MidOffsetY(0.0f),
	  m_MidLastX(0.0f), m_MidLastY(0.0f), m_LeftLastX(0.0f), m_LeftLastY(0.0f),
	  m_LeftButton(false), m_MidButton(false), m_FirstLeft(true), m_FirstMid(true)
{
	m_Timer = new QTimer(this);
	connect(m_Timer, SIGNAL(timeout()), this, SLOT(MainLoop()));

	setFocusPolicy(Qt::FocusPolicy::ClickFocus);
}

GLWidget::~GLWidget()
{
	delete m_Timer;
	delete m_Renderer;
	delete m_Camera;

	for (int i = 0; i < m_Meshes->size(); i++)
	{
		delete (*m_Meshes)[i];
	}

	m_Meshes->clear();
	delete m_Meshes;
}

void GLWidget::initializeGL()
{
	gladLoadGL();

	m_Renderer = new Modular::Renderer();
	m_Meshes = new std::vector<Modular::Mesh*>();
	m_Camera = new Modular::Camera(m_Meshes, 45.0f, m_AspectRatio);

	m_Camera->Move(Modular::Direction::Backwards, 7.0f);
	m_Camera->Move(Modular::Direction::Up, 6.1f);
	m_Camera->Move(Modular::Direction::Right, 0.4f);
	m_Camera->Rotate(Modular::Rotation::Yaw, 315.0f);
	m_Camera->Rotate(Modular::Rotation::Pitch, -175.0f);

	m_Timer->start(1);
}

void GLWidget::paintGL()
{
	m_Renderer->Clear(0.12f, 0.12f, 0.12f);

	for (int i = 0; i < m_Meshes->size(); i++)
	{
		m_Renderer->Draw((*m_Meshes)[i]);
	}
}

void GLWidget::AddCube(float x)
{
	m_Meshes->push_back(m_Renderer->CreateCube(
		new Modular::Shader("Resources/shaders/Main.vs",
		"Resources/shaders/Main.fs"), lightPos));

	m_Camera->UpdateMeshes(m_Meshes);
}

void GLWidget::MainLoop()
{
	updateGL();

	if (((float) this->width() / (float) this->height()) != m_AspectRatio)
	{
		m_AspectRatio = (float) this->width() / (float) this->height();
		m_Renderer->SetViewportSize(this->width(), this->height());
		m_Camera->AdjustAspectRatio(m_AspectRatio);
	}
}

void GLWidget::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) m_LeftButton = true;
	if (event->button() == Qt::MidButton) m_MidButton = true;
}

void GLWidget::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		m_LeftButton = false;
		m_FirstLeft = true;
	}

	if (event->button() == Qt::MidButton)
	{
		m_MidButton = false;
		m_FirstMid = true;
	}
}

void GLWidget::mouseMoveEvent(QMouseEvent* event)
{
	if (m_LeftButton)
	{
		if (m_FirstLeft)
		{
			m_LeftLastX = event->pos().x();
			m_LeftLastY = event->pos().y();
			m_FirstLeft = false;
		}

		m_LeftOffsetX = event->pos().x() - m_LeftLastX;
		m_LeftOffsetY = m_LeftLastY - event->pos().y();

		m_LeftLastX = event->pos().x();
		m_LeftLastY = event->pos().y();

		m_Camera->Rotate(Modular::Rotation::Yaw, m_LeftOffsetX);
		m_Camera->Rotate(Modular::Rotation::Pitch, m_LeftOffsetY);
	}

	if (m_MidButton)
	{
		if (m_FirstMid)
		{
			m_MidLastX = event->pos().x();
			m_MidLastY = event->pos().y();
			m_FirstMid = false;
		}

		m_MidOffsetX = event->pos().x() - m_MidLastX;
		m_MidOffsetY = m_MidLastY - event->pos().y();

		m_MidLastX = event->pos().x();
		m_MidLastY = event->pos().y();

		if (m_MidOffsetX > 0)
			m_Camera->Move(Modular::Direction::Right, abs(m_MidOffsetX / 100));

		else if (m_MidOffsetX < 0)
			m_Camera->Move(Modular::Direction::Left, abs(m_MidOffsetX / 100));

		if (m_MidOffsetY > 0)
			m_Camera->Move(Modular::Direction::Up, abs(m_MidOffsetY / 100));

		else if (m_MidOffsetY < 0)
			m_Camera->Move(Modular::Direction::Down, abs(m_MidOffsetY / 100));
	}
}

void GLWidget::wheelEvent(QWheelEvent* event)
{
	if (event->delta() > 0)
		m_Camera->Move(Modular::Direction::Forwards, 0.3f);

	else m_Camera->Move(Modular::Direction::Backwards, 0.3f);
}