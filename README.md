

<img src="https://github.com/GiovanniSorice/MLProject/blob/master/logo/neuradillo.jpg" height="200" width="300">


# Neuradillo
Neuradillo is a small C++ exploiting [Armadillo](http://arma.sourceforge.net/) numerical library to create and train feedforward neural network. We developed this library as a project for the Machine Learning [course](https://esami.unipi.it/esami2/programma.php?c=42276&aa=2019&docente=MICHELI&insegnamento=&sd=0). More information about the project and the algorithms we implemented can be found in the [report](https://github.com/GiovanniSorice/MLProject/blob/master/docs/report/relazione.pdf). 

## Getting started

### Prerequisites 
The project use [Cmake 3.16](https://cmake.org/) as building system and it can be downloaded [here](https://cmake.org/download/). 
The package manager used is [Conan](https://conan.io/). You can install it with the following commands:
` pip install conan` 

Running the following command to solve this [issue](https://docs.conan.io/en/latest/installation.html#install-with-pip-recommended): 
`source ~/.profile`  

### Armadillo installation 
1. Clone the following repo: https://github.com/darcamo/conan-armadillo;
2. Inside the cloned repo run: `conan create . armadillo/stable`
3. If Armadillo is installed correctly an example program is execute and you can start use it [through Conan](https://docs.conan.io/en/latest/using_packages/conanfile_txt.html#requires).

## Running the project
If CMake and Armadillo were installed correctly you have to create a directory where cmake store the configuration files needed to run the project:
`mkdir build && cd build `

Inside the build folder to generate the files that are needed by Conan type: 
 `conan install ..`

Then the for the CMake files type: 
 `cmake ..` 

In the end to build the project type: 
 `cmake --build .` 

If all the process is done correctly a */bin* folder is created with a binary file inside. This file can be executed with:
`./MLProject`

The error of the training set and validation set is print during the execution.

## Results
Here we show a learning curve plot we obtained during the training phase. 
 
<img src="/docs/report/img/Cup_loss_Reg_Zoom.png" height="50%" width="50%">

## Future works
- Serialization of NN: https://www.boost.org/doc/libs/1_72_0/libs/serialization 
- Plot with matplotlibcpp: https://github.com/lava/matplotlib-cpp 

## Authors
* **Giovanni Sorice**  :computer: - [Giovanni Sorice](https://github.com/GiovanniSorice)
* **Francesco Corti** :nerd_face: :computer: - [FraCorti](https://github.com/FraCorti)