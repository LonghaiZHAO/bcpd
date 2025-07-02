#include <stdio.h>
#include <stdlib.h>

#ifdef USE_DUMMY_LAPACK

// Dummy LAPACK functions
int dgesv_(int *n, int *nrhs, double *a, int *lda, int *ipiv, double *b, int *ldb, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dgesv_ not available in this build.\n");
    return -1;
}

int dsyev_(char *jobz, char *uplo, int *n, double *a, int *lda, double *w, double *work, int *lwork, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dsyev_ not available in this build.\n");
    return -1;
}

int dgesvd_(char *jobu, char *jobvt, int *m, int *n, double *a, int *lda, double *s, double *u, int *ldu, double *vt, int *ldvt, double *work, int *lwork, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dgesvd_ not available in this build.\n");
    return -1;
}

int dposv_(char *uplo, int *n, int *nrhs, double *A, int *lda, double *B, int *ldb, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dposv_ not available in this build.\n");
    return -1;
}

int dpotrs_(char *uplo, int *n, int *nrhs, double *A, int *lda, double *B, int *ldb, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dpotrs_ not available in this build.\n");
    return -1;
}

int dpotrf_(char *uplo, int *n, double *A, int *lda, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dpotrf_ not available in this build.\n");
    return -1;
}

int dpotri_(char *uplo, int *n, double *A, int *lda, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dpotri_ not available in this build.\n");
    return -1;
}

int dgetrf_(int *m, int *n, double *A, int *lda, int *ipiv, int *info) {
    *info = -1;  // Indicate error
    fprintf(stderr, "Error: LAPACK function dgetrf_ not available in this build.\n");
    return -1;
}

#endif // USE_DUMMY_LAPACK