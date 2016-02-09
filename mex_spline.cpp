#include <mex.h>
#include <matrix.h>
#include "spline_gsl.cpp"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[]) {
	double *yy, *YY;
	double *X, *Y;
	int *x;
	int m1, n1;
	int m2, n2;
	double *SZ1, *SZ2;

	/* parse input arguments */
	X  = mxGetPr(prhs[0]);
	m1 = mxGetM(prhs[0]);
	n1 = mxGetN(prhs[0]);
	int l1 = m1 * n1;

	Y  = mxGetPr(prhs[1]);
	m2 = mxGetM(prhs[1]);
	n2 = mxGetN(prhs[1]);
	int l2 = m2 * n2;

	SZ1  = mxGetPr(prhs[2]);
	SZ2  = mxGetPr(prhs[3]);
	int sz1 = (int)SZ1[0];
	int sz2 = (int)SZ2[0];

	/* initialize arrays */
	yy = new double[(int)*SZ2];
	YY = new double[(int)*SZ2];
	x = new int[sz1];


	for (int i = 0; i < sz1; i++)
		x[i] = X[i];

	/* create output arguments */
	plhs[0] = mxCreateDoubleMatrix(1, sz2, mxREAL);
	YY = mxGetPr(plhs[0]);

	/* call core function */
	spline(yy, x, Y, sz1, sz2);



	for(int i = 0; i < (int)*SZ2; i++) {
		YY[i] = yy[i];
	}


}