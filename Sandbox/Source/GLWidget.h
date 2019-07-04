#pragma once

#include <qgl.h>
#include <qtimer.h>
#include <Modular.h>
#include <QKeyEvent>
#include <vector>

class GLWidget : public QGLWidget
{
	Q_OBJECT

public:

	GLWidget(QWidget* parent = 0);
	~GLWidget();

	void initializeGL() override;
	void paintGL() override;

	void AddCube(float x);

	std::vector<Modular::Mesh*>* GetMeshes() { return m_Meshes; }

	Modular::Renderer* GetRenderer() { return m_Renderer; }
	Modular::Camera* GetCamera() { return m_Camera; }

public slots:

	void MainLoop();

private:

	float m_AspectRatio;

	float m_LeftOffsetX, m_LeftOffsetY;
	float m_MidOffsetX, m_MidOffsetY;

	float m_MidLastX, m_MidLastY;
	float m_LeftLastX, m_LeftLastY;

	bool m_LeftButton, m_MidButton;
	bool m_FirstLeft, m_FirstMid;

	QTimer* m_Timer;

	Modular::Renderer* m_Renderer;
	Modular::Camera* m_Camera;

	std::vector<Modular::Mesh*>* m_Meshes;

	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;
	void wheelEvent(QWheelEvent* event) override;

};