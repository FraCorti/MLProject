cmake_minimum_required(VERSION 3.15)
project(MLProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS_DEBUG "-Wall -Wextra -O0 -fsanitize=thread -fstack-check -fstack-protector-strong -fno-omit-frame-pointer -g -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3") # "-ftree-vectorize -fopt-info-vec" to view vectorization optimization
set(THREADS_PREFER_PTHREAD_FLAG ON)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else ()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install first")
endif ()

add_library(Neuradillo
        STATIC
        src/layer/layer.cpp
        src/layer/layer.h
        src/network/network.cpp
        src/network/network.h
        src/preprocessing/preprocessing.cpp
        src/preprocessing/preprocessing.h
        src/preprocessing/preprocessing.cpp
        src/preprocessing/preprocessing.h
        src/activationFunction/activationFunction.h
        src/activationFunction/tanhFunction.cpp
        src/activationFunction/tanhFunction.h
        src/activationFunction/logisticFunction.cpp
        src/activationFunction/logisticFunction.h
        src/load/loadDataset.cpp
        src/load/loadDataset.h
        src/lossFunction/lossFunction.h
        src/lossFunction/meanSquaredError.cpp
        src/lossFunction/meanSquaredError.h
        src/activationFunction/reluFunction.cpp
        src/activationFunction/reluFunction.h
        src/lossFunction/binaryCrossentropy.cpp
        src/lossFunction/binaryCrossentropy.h
        src/gridSearch/gridSearch.cpp
        src/gridSearch/gridSearch.h
        src/activationFunction/linearFunction.cpp
        src/activationFunction/linearFunction.h
        src/crossValidation/crossValidation.cpp
        src/crossValidation/crossValidation.h
        src/lossFunction/meanEuclideanError.cpp
        src/lossFunction/meanEuclideanError.h
        src/gridSearch/parallelGridSearch.cpp
        src/gridSearch/parallelGridSearch.h
        )

add_executable(main main.cpp)
target_link_libraries(main Neuradillo)
target_link_libraries(Neuradillo ${CONAN_LIBS})
