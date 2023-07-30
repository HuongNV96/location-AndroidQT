cmake_minimum_required(VERSION 3.16)

project(locationTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 6.4 REQUIRED COMPONENTS Quick)
find_package(Qt6 REQUIRED COMPONENTS Core Gui Network Positioning Qml Quick)

qt_standard_project_setup()

qt_add_executable(applocationTest
    main.cpp PermissonPresenter.h PermissonPresenter.cpp
    resource.qrc
    PermissionManager.h PermissionManager.cpp SingletonTemplate.hpp
    LocationPresenter.h LocationPresenter.cpp
)


# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(applocationTest PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.applocationTest
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    QT_ANDROID_PACKAGE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/android
)

target_link_libraries(applocationTest
    PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Network
        Qt::Positioning
        Qt::Qml
        Qt::Quick
        Qt6::CorePrivate
)

include(GNUInstallDirs)
install(TARGETS applocationTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
