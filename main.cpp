#include <iostream>
#include "armadillo"
#include "src/preprocessing/preprocessing.h"
#include "src/network/network.h"
#include "src/activationFunction/tanhFunction.h"
#include "src/activationFunction/logisticFunction.h"
#include "src/lossFunction/meanSquaredError.h"
#include "src/lossFunction/binaryCrossentropy.h"
#include "src/activationFunction/reluFunction.h"
#include "src/load/loadDataset.h"
#include "src/activationFunction/linearFunction.h"
#include "src/gridSearch/gridSearch.h"
#include "src/crossValidation/crossValidation.h"
#include "src/gridSearch/parallelGridSearch.h"

int main() {
  arma::cout.precision(10);
  arma::cout.setf(arma::ios::fixed);
/*
  LoadDataset loadDS;
  loadDS.Load("../../data/monk/monk1_testset.csv");
  loadDS.explodeMonkDataset();
*/

  Preprocessing a("../../data/ML-CUP19-TR_formatted.csv");
  arma::mat trainingSet;
  arma::mat validationSet;
  arma::mat testSet;

  a.GetSplit(60, 20, 20, std::move(trainingSet), std::move(validationSet), std::move(testSet));

  //testSet.load("../../data/ML-CUP19-TR_formatted.csv");
  /*
   std::cout << trainingSet.n_rows << " " << trainingSet.n_cols << " " << validationSet.n_rows << " "
            << validationSet.n_cols
            << " " << testSet.n_rows << " " << testSet.n_cols << std::endl;

   */
  int labelCol = 2;
  // Split the data from the training set.
  arma::mat trainingLabels = arma::mat(trainingSet.memptr() + (trainingSet.n_cols - labelCol) * trainingSet.n_rows,
                                       trainingSet.n_rows,
                                       labelCol,
                                       false,
                                       false);
  // Split the labels from the training set.
  arma::mat trainingData = arma::mat(trainingSet.memptr(),
                                     trainingSet.n_rows,
                                     trainingSet.n_cols - labelCol,
                                     false,
                                     false);


  //Split the labels from the test set
  arma::mat
      validationLabels = arma::mat(validationSet.memptr() + (validationSet.n_cols - labelCol) * validationSet.n_rows,
                                   validationSet.n_rows,
                                   labelCol,
                                   false,
                                   false);

  //Split the data from the test test
  arma::mat validationData = arma::mat(validationSet.memptr(),
                                       validationSet.n_rows,
                                       validationSet.n_cols - labelCol,
                                       false,
                                       false);


  //Split the labels from the test set
  arma::mat testLabels = arma::mat(testSet.memptr() + (testSet.n_cols - labelCol) * testSet.n_rows,
                                   testSet.n_rows,
                                   labelCol,
                                   false,
                                   false);

  //Split the data from the test test
  arma::mat testData = arma::mat(testSet.memptr(),
                                 testSet.n_rows,
                                 testSet.n_cols - labelCol,
                                 false,
                                 false);

  double learningRateMin = 0.001;
  double learningRateMax = 0.004;
  double learningRateStep = 0.001;
  double lambdaMin = 0;
  double lambdaMax = 0.0004;
  double lambdaStep = 0.0001;
  double momentumMin = 0.0;
  double momentumMax = 0.4;
  double momentumStep = 0.1;
  int unitMin = 5;
  int unitMax = 20;
  int unitStep = 5;
  int epochMin = 5;
  int epochMax = 20;
  int epochStep = 5;

  ParallelGridSearch gridSearch;
  gridSearch.SetEpochMin(epochMin);
  gridSearch.SetEpochMax(epochMax);
  gridSearch.SetEpochStep(epochStep);
  gridSearch.SetLambdaMin(lambdaMin);
  gridSearch.SetLambdaMax(lambdaMax);
  gridSearch.SetLambdaStep(lambdaStep);
  gridSearch.SetLearningRateMin(learningRateMin);
  gridSearch.SetLearningRateMax(learningRateMax);
  gridSearch.SetLearningRateStep(learningRateStep);
  gridSearch.SetMomentumMin(momentumMin);
  gridSearch.SetMomentumMax(momentumMax);
  gridSearch.SetMomentumStep(momentumStep);
  gridSearch.SetUnitMin(unitMin);
  gridSearch.SetUnitMax(unitMax);
  gridSearch.SetUnitStep(unitStep);

  //int netAnalyzed = gridSearch.NetworkAnalyzed();
  //std::cout << "netAnalyzed" << netAnalyzed << std::endl;
  //arma::mat result = arma::zeros(netAnalyzed, 7);   // 4 hyperparams and error
  gridSearch.Run(trainingData, trainingLabels);




/*
  Network net;
 net.SetLossFunction("meanSquaredError");

  Layer firstLayer(trainingSet.n_cols - labelCol, 200, "tanhFunction");
  Layer lastLayer(200, 2, "linearFunction");
 net.Add(firstLayer);
 net.Add(lastLayer);

  net.Init(0.7, -0.7);

  net.Train(validationData,
            validationLabels,
            trainingSet,
            trainingLabels.n_cols,
            3000,
            trainingSet.n_rows,
            0.001,
            0.0,
            0.0);
 arma::mat mat;
  net.Test(std::move(validationData), std::move(validationLabels), std::move(mat));
  //net.Test(std::move(testData), std::move(testLabels), std::move(mat));
 mat.print("errore finale");


  CrossValidation cross_validation;
  arma::mat error = arma::zeros(1, trainingLabels.n_cols);
  cross_validation.run(trainingData,
                       trainingLabels,
                       3,
                       net,
                       800,
                       trainingData.n_rows,
                       0.9,
                       0,
                       0.5,
                       std::move(error));
 */
  return 0;
}