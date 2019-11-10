cmake_minimum_required(VERSION 3.15)
project(Data_Structures_Project_UCLA_DCYT)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures_Project_UCLA_DCYT main.cpp Models/MVehiculo.cpp Models/MVehiculo.h Models/MBahia.cpp Models/MBahia.h Views/VBahia.cpp Views/VBahia.h Views/VVehiculo.cpp Views/VVehiculo.h Controllers/Controlador.cpp Controllers/Controlador.h)