cmake_minimum_required(VERSION 3.15)
project(Data_Structures_Project_UCLA_DCYT)

set(CMAKE_CXX_STANDARD 14)

include_directories(Controllers)
include_directories(Libs/Cola)
include_directories(Libs/Genericas)
include_directories(Libs/Lista)
include_directories(Libs/Pila)
include_directories(Models)
include_directories(Views)


add_executable(Data_Structures_Project_UCLA_DCYT main.cpp Models/MVehiculo.cpp Models/MVehiculo.h Models/MBahia.cpp Models/MBahia.h Views/VBahia.cpp Views/VBahia.h Views/VVehiculo.cpp Views/VVehiculo.h Controllers/Controlador.cpp Controllers/Controlador.h Models/MEstacion.cpp Models/MEstacion.h Views/VEstacion.cpp Views/VEstacion.h
        Libs/Cola/Cola.cpp
        Libs/Cola/Cola.h
        Libs/Genericas/VGeneral.cpp
        Libs/Genericas/VGeneral.h
        Libs/Lista/Lista.cpp
        Libs/Lista/Lista.h
        Libs/Pila/Pila.cpp
        Libs/Pila/Pila.h)