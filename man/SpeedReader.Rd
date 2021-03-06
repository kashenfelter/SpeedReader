% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/Package_Documentation.R
\docType{package}
\name{SpeedReader}
\alias{SpeedReader}
\alias{SpeedReader-package}
\title{SpeedReader: functions to facilitate high performance text processing in R.}
\description{
SpeedReader: functions to facilitate high performance text processing in R.
}
\section{SpeedReader functions}{

To use this package, You will first want to check out the generate_document_term_vectors() function which will take raw data and transform it into document term vectors. You will then likely want to generate a document term matri using either generate_document_term_matrix() or generate_sparse_large_document_term_matrix() depending on the number of documents you are dealing with. After that, this package provides a number of other functions for simple pointwise mututal information based analysis and links to the MALLET libraries for topic modeling with billions of tokens.
}

