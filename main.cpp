#include <iostream>
#include "armadillo"
#include "src/preprocessing/preprocessing.h"
#include "src/network/network.h"
#include "src/activationFunction/tanhFunction.h"
#include "src/activationFunction/logisticFunction.h"
#include "src/load/loadDataset.h"

int main() {

  Preprocessing a("../../data/monk/monks-formatted.csv");
  arma::mat trainingSet;
  arma::mat validationSet;
  arma::mat testSet;

  a.GetSplit(60, 20, 20, std::move(trainingSet), std::move(validationSet), std::move(testSet));
  int labelCol = 1;
  // Split the data from the training set.
  arma::mat trainLabels = arma::mat(trainingSet.memptr() + (trainingSet.n_cols - labelCol) * trainingSet.n_rows,
                                    trainingSet.n_rows,
                                    labelCol,
                                    false,
                                    false);
  // Split the labels from the training set.
  arma::mat
      trainingData = arma::mat(trainingSet.memptr(), trainingSet.n_rows, trainingSet.n_cols - labelCol, false, false);

  Network net;
  TanhFunction tanhFunction;
  LogisticFunction logisticFunction;

  Layer firstLayer(trainingData.n_cols, 3, tanhFunction);
  Layer secondLayer(3, 4, tanhFunction);
  Layer lastLayer(4, 1, logisticFunction);
  net.Add(firstLayer);
  net.Add(secondLayer);
  net.Add(lastLayer);

  net.Init(-1, 1);
  net.Train(std::move(trainingData), std::move(trainLabels), 7);
/*

  arma::mat dataSetTest = trainingData.submat(0, 0,
                                              0, trainingData.n_cols - 1);
  arma::mat labelSetTest = trainLabels.submat(0, 0,
                                              0, trainLabels.n_cols - 1);

  dataSetTest.print("dataSetTest");
  arma::mat weightTest = 0 + arma::randu<arma::mat>(18, 1) * (1 - 0);
  arma::mat biasTest = 0 + arma::randu<arma::mat>(1, 1) * (1 - 0);
  weightTest.print("weightTest");
  biasTest.print("biasTest");

  arma::mat moltiplicazione = dataSetTest * weightTest;
  moltiplicazione.each_row() += biasTest;

  moltiplicazione.print("moltiplicazione");
  arma::mat activationFunctionResult;
  logisticFunction.Compute(moltiplicazione, std::move(activationFunctionResult));
  activationFunctionResult.print("activationFunctionResult");

  arma::mat moltiplicazione2 = weightTest * dataSetTest;

  std::cout << moltiplicazione2.n_rows << " righe " << moltiplicazione2.n_cols << " colonne " << std::endl;

  arma::mat A(1, 3, arma::fill::randu);

  arma::mat B(4, 3, arma::fill::ones);
  arma::mat C = A % arma::sum(B);
  A.print("A");
  B.print("B");

  C.print("C");
  std::cout << C.n_rows << " righe " << C.n_cols << " colonne " << std::endl;
*/
  return 0;
}