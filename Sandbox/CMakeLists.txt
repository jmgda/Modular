cmake_minimum_required(VERSION 3.8)

project("Sandbox")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY 
	${CMAKE_HOME_DIRECTORY}/bin/${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt5_DIR "C:/Qt/5.13.0/msvc2017_64/lib/cmake/Qt5")

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Gui OpenGL)

set(project_ui UI/MainWindow.ui)

set(project_headers 
	Source/MainWindow.h 
	Source/GLWidget.h)

set(project_sources 
	Source/Main.cpp 
	Source/MainWindow.cpp 
	Source/GLWidget.cpp)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME}  
	${project_headers} 
	${project_sources} 
	${project_sources_moc} 
	${project_headers_wrapped})

target_link_libraries(${PROJECT_NAME} PUBLIC 
	Modular 
	Qt5::Core 
	Qt5::Gui 
	Qt5::Widgets 
	Qt5::OpenGL)

include_directories(${PROJECT_NAME} PUBLIC
	${CMAKE_HOME_DIRECTORY}/${PROJECT_NAME}/Source)