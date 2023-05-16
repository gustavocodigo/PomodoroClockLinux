cmake_minimum_required(VERSION 3.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


project(ProgramFile)



# // libs linux
find_package(X11 REQUIRED)
	if(!X11_XTest_FOUND)
 		message(FATAL_ERROR "X11 extensions are required, but not found!")
	endif()
	if(!X11_Xfixes_LIB)
 		message(FATAL_ERROR "X11 fixes extension is required, but not found!")
	endif()
	find_package(Threads REQUIRED)
	set(${PROJECT_NAME}_PLATFORM_LIBS
		${X11_LIBRARIES}
		${X11_Xfixes_LIB}
		${X11_XTest_LIB}
		${X11_Xinerama_LIB}
		${CMAKE_THREAD_LIBS_INIT}
	)


set(SOURCES
    main.cpp


)





# // webview
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
pkg_check_modules(WEBKIT REQUIRED webkit2gtk-4.0)

pkg_check_modules(LIBNOTIFY REQUIRED libnotify)




include_directories(
	


    ${GTK3_INCLUDE_DIRS} ${WEBKIT_INCLUDE_DIRS} ${LIBNOTIFY_INCLUDE_DIRS}
)








file(GLOB SOURCES2 "screen_recorder/src_cpp/linux/*.cpp")
file(GLOB SOURCES3 "screen_recorder/src_cpp/*.c")
file(GLOB SOURCES4 "screen_recorder/src_cpp/*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES} ${SOURCES2} ${SOURCES3} ${SOURCES4})



target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_PLATFORM_LIBS} ${GTK3_LIBRARIES} ${WEBKIT_LIBRARIES} ${LIBNOTIFY_LIBRARIES})
