#include <RcppArmadillo.h>
//[[Rcpp::depends(RcppArmadillo)]]
using namespace Rcpp;

// [[Rcpp::export]]
arma::mat Generate_Document_Term_Matrix(
    int number_of_documents,
    int number_of_unique_words,
    std::vector<std::string> unique_words,
    List Document_Words,
    arma::vec Document_Lengths,
    int using_wordcounts,
    List Document_Word_Counts
){

  arma::mat document_word_matrix = arma::zeros(number_of_documents,number_of_unique_words);

  for(int n = 0; n < number_of_documents; ++n){
    Rcpp::Rcout << "Current Document: " << n << std::endl;
    int length = Document_Lengths[n];
    if(length > 0){
      std::vector<std::string> current = Document_Words[n];
      arma::vec current_counts = Document_Word_Counts[n];
      for(int i = 0; i < length; ++i){
        int already = 0;
        int counter = 0;
        while(already == 0){
          if(counter == number_of_unique_words ){
            already = 1;
          }else{
            if(unique_words[counter] == current[i]){
                if(using_wordcounts == 1){
                    document_word_matrix(n,counter) += current_counts[i];
                }else{
                    document_word_matrix(n,counter) += 1;
                }
              already = 1;
            }
            counter +=1;
          }

        }
      }
    }
  }

  //return
  return document_word_matrix;

}

