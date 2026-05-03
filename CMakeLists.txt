# cmake_minimum_required(VERSION 3.10)
# project(tmx VERSION 1.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)


# add_library(tmx INTERFACE)

# target_include_directories(tmx INTERFACE
#     $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/tmx>
#     $<INSTALL_INTERFACE:tmx>
# )

# target_compile_features(tmx INTERFACE cxx_std_20)

# # add_executable(tests tests/main.cpp)
# # target_link_libraries(tests PRIVATE tmx)


# if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    
#     message(STATUS "Mode développement : activation des tests.")

#     add_executable(math_sandbox tests/main.cpp)

#     target_link_libraries(math_sandbox PRIVATE tmx)

    
#     if (MSVC)
#         target_compile_options(math_sandbox PRIVATE /W4)
#     else()
#         target_compile_options(math_sandbox PRIVATE -Wall -Wextra -Wpedantic)
#     endif()

# endif()


# # include_directories(tmx)

# message(STATUS "CMake est setup !")




cmake_minimum_required(VERSION 3.10)
project(tmx VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# On définit la cible INTERFACE (header-only)
add_library(tmx INTERFACE)

# Configuration des inclusions
target_include_directories(tmx INTERFACE
    # On pointe vers le dossier PARENT de 'tmx' pour permettre 
    # l'inclusion propre : #include <tmx/header.hpp>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# On impose le C++20 à la lib et à ceux qui s'en servent
target_compile_features(tmx INTERFACE cxx_std_20)

# --- Section Tests ---
if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    
    message(STATUS "Mode développement : activation des tests.")

    # Vérifie que le fichier existe bien avant de créer la cible
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
        add_executable(tmx_tests main.cpp)
        target_link_libraries(tmx_tests PRIVATE tmx)

        # Alertes maximales pour coder proprement
        if (MSVC)
            target_compile_options(tmx_tests PRIVATE /W4)
        else()
            target_compile_options(tmx_tests PRIVATE -Wall -Wextra)
        endif()
    else()
        message(WARNING "Fichier main.cpp non trouvé, l'exécutable sandbox ne sera pas créé.")
    endif()

endif()

message(STATUS "Configuration de ${PROJECT_NAME} terminée !")
